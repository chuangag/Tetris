#include <QtWidgets>
#include <QLayout>
#include "GameBoard.h"
#include "MainWindow.h" 

MainWindow::MainWindow(){
  gameboard = new GameBoard;
  nextBlockLabel = new QLabel;
  levelLabel = new QLabel;
  scoreLabel = new QLabel;
  
  
  QGridLayout *layout = new QGridLayout;
  layout->addWidget(gameboard,0,0,8,4);
  layout->addWidget(createLabel("Next:"),1,4,1,2);
  layout->addWidget(nextBlockLabel,2,4,2,2);
  layout->addWidget(createLabel("Level:"),4,4);
  layout->addWidget(createLabel("Score:"),6,4);
  layout->addWidget(levelLabel,4,5);
  layout->addWidget(scoreLabel,6,5);
  
  setLayout(layout);
  setWindowTitle(tr("Tetris"));
  resize(300,400);
  
}

QLabel *MainWindow::createLabel(const QString &text){
  QLabel *lbl = new QLabel(text);
  return lbl;
}