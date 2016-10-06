//#include <QtWidgets>
#include <QLayout>
#include "GameBoard.h"
#include "MainWindow.h"
#include <QTimerEvent> 



MainWindow::MainWindow(){
  //gameboard can be used directly
  boardLabel = new QLabel(tr("hi"));
  nextBlockLabel = new QLabel;
  levelLabel = new QLabel;
  scoreLabel = new QLabel;
  
  QGridLayout *layout = new QGridLayout;
  layout->addWidget(boardLabel,0,0,8,4);
  layout->addWidget(createLabel("Next:"),1,4,1,2);
  layout->addWidget(nextBlockLabel,2,4,2,2);
  layout->addWidget(createLabel("Level:"),4,4);
  layout->addWidget(createLabel("Score:"),6,4);
  layout->addWidget(levelLabel,4,5);
  layout->addWidget(scoreLabel,6,5);
  
  ui.load("background.bmp");
  qPainter.begin(&ui);
  boardLabel->setPixmap(QPixmap::fromImage(ui));
  timer = new QTimer(this);
  
  QObject::connect(timer, SIGNAL(timeout()), &gameboard, SLOT(update_blocks()));
  QObject::connect(&gameboard, SIGNAL(repaint()), this, SLOT(renderBoard()));
  QObject::connect(&gameboard, SIGNAL(fail()), this, SLOT(fail()));
  QObject::connect(&gameboard, SIGNAL(changeScore(int)), this, SLOT(changeScore(int)));

  setLayout(layout);
  setWindowTitle(tr("Tetris"));
  resize(300,400);
  
}

QLabel *MainWindow::createLabel(const QString &text){
  QLabel *lbl = new QLabel(text);
  return lbl;
}

void MainWindow::renderBoard(){
  int** tempBoard = gameboard.getTempBoard();
  qPainter.end();
  ui.load("background.bmp");
  qPainter.begin(&ui);//to be checked if it can be used to refresh
  qPainter.setPen(Qt::black);
  for(int i=0;i<20;i++){
	  for(int j=0;j<10;j++){
		  switch(tempBoard[i][j]){
			case 0:
				continue;
			case 1:
				qPainter.setBrush(Qt::red);
				break;
			case 2:
				qPainter.setBrush(Qt::green);
				break;
			case 3:
				qPainter.setBrush(Qt::blue);
				break;
			case 4:
				qPainter.setBrush(Qt::yellow);
				break;
			case 5:
				qPainter.setBrush(Qt::cyan);
				break;
			case 6:
				qPainter.setBrush(Qt::gray);
				break;
			case 7:
				qPainter.setBrush(Qt::magenta);
				break;
		  }
		  qPainter.drawRect(j*20,i*20,20,20);
	  }
  }
  boardLabel->setPixmap(QPixmap::fromImage(ui));
}

void MainWindow::keyPressEvent(QKeyEvent *event){
	if(game_started){
		switch(event->key()){
		  case Qt::Key_Left:
			gameboard.tryleft();
			break;
		  case Qt::Key_Right:
			gameboard.tryright();
			break;
		  case Qt::Key_Down:
			gameboard.trydown();
			break;
		  case Qt::Key_Z:
			gameboard.tryrotateCounterclock();
			break;
		  case Qt::Key_X:
			gameboard.tryrotateClock();
			break;
		}
	}
	else if (event->key() == Qt::Key_Up){
		start();
	}
}

void MainWindow::start(){
  gameboard.start();
  level=1;
  printf("start\n");fflush(stdout);
  levelLabel->setText(QString::number(level));
  timer->start(1000-(level-1)*100);
  game_started = true;
}

void MainWindow::fail(){
  printf("fail\n");fflush(stdout);
  game_started = false;
  timer->stop();
}

void MainWindow::changeScore(int s){
	if(s>=level*100){
		level++;
		levelLabel->setText(QString::number(level));
		timer->setInterval(1000-(level-1)*100);
	}
	scoreLabel->setText(QString::number(s));
}
