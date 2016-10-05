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
  qPainter.begin(&ui);//to be checked if it can be used to refresh
  qPainter.setBrush(Qt::blue);
    qPainter.setPen(Qt::black);
    
    for(int i=0;i<200;i+=20){
		qPainter.drawRect(i,0,20,20);
	}
  boardLabel->setPixmap(QPixmap::fromImage(ui));
  //for test
  timer = new QTimer(this);
  QObject::connect(timer, SIGNAL(timeout()), this, SLOT(renderBoard()));
  timer->start(1000);

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
  boardLabel->setPixmap(QPixmap::fromImage(ui));
}
