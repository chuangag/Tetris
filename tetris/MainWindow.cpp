//#include <QtWidgets>
#include <QLayout>
#include "GameBoard.h"
#include "MainWindow.h" 

MainWindow::MainWindow(){
  gameboard = new GameBoard;
  nextBlockLabel = new QLabel;
  levelLabel = new QLabel;
  scoreLabel = new QLabel;
  /*
  timer = new QTimer(this);
  boardImage.load("penguin.png");
  QPainter qPainter(&boardImage);
  */
  //QGraphicsScene *graphicBoard;
  //QGraphicsView *viewBoard(graphicBoard);
  /*
  QObject::connect(timer,SIGNAL(timeout()),this,SLOT(UpdateText()));
  timer->start(1000,false);//ms
  */
  QGridLayout *layout = new QGridLayout;
  layout->addWidget(boardImage,0,0,8,4);
  layout->addWidget(createLabel("Next:"),1,4,1,2);
  layout->addWidget(nextBlockLabel,2,4,2,2);
  layout->addWidget(createLabel("Level:"),4,4);
  layout->addWidget(createLabel("Score:"),6,4);
  layout->addWidget(levelLabel,4,5);
  layout->addWidget(scoreLabel,6,5);
  
  
  //renderBoard();
  
  
  
  
  setLayout(layout);
  
  setWindowTitle(tr("Tetris"));
  resize(300,400);
  
}

MainWindow::~MainWindow(){
  delete timer;
  delete gameboard;
}

void MainWindow::renderBoard(){
  
  //boardToRender=gameboard->getTempBoard();
  for(i=0;i<20;i++){
    for(j=0;j<10;j++){
      boardToRender[i][j]=1;
    }
    
  }
  
  
  boardImage.load("penguin.png");
  QPainter qPainter(&boardImage);
  int i=0,j=0;
  for(i=0;i<20;i++){
    for(j=0;j<10;j++){
      switch (boardToRender[i][j])
	case 0:
	  qPainter.setBrush(Qt::NoBrush);	 
	  qPainter.drawRect(10*i,10*j,10,10);
	  layout->addWidget(boardImage,0,0,8,4);
	  setLayout(layout);
	  break;
	case 1:
	  qPainter.setBrush(Qt::red);	 
	  qPainter.drawRect(10*i,10*j,10,10);
	  layout->addWidget(boardImage,0,0,8,4);
	  setLayout(layout);
	  break;
	case 2:
	  qPainter.setBrush(Qt::NoBrush);	 
	  qPainter.drawRect(10*i,10*j,10,10);
	  layout->addWidget(boardImage,0,0,8,4);
	  setLayout(layout);
	  break;
	case 3:
	  break;
	case 4:
	  break;
	case 5:
	  break;
	case 6:
	  break;
	case 7:
	  break;
      
  }
}

void MainWindow::updateBoard(){
  
}

void MainWindow::updateLevel(){
  
}

void MainWindow::updateScore(){
  
}

QLabel *MainWindow::createLabel(const QString &text){
  QLabel *lbl = new QLabel(text);
  return lbl;
}
