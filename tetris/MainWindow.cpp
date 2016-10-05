//#include <QtWidgets>
#include <QLayout>
#include "GameBoard.h"
#include "MainWindow.h" 

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
  boardLabel.setPixmap(QPixmap::fromImage(ui));
  
  setLayout(layout);
  setWindowTitle(tr("Tetris"));
  resize(300,400);
  
}

QLabel *MainWindow::createLabel(const QString &text){
  QLabel *lbl = new QLabel(text);
  return lbl;
}

void MainWindow::update_label(){
	
}
