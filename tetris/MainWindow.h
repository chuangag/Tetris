#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFrame>
#include <QWidget>
#include <QLabel>
#include <QtGui>
#include "GameBoard.h"

class QLabel;

class GameBoard;

class MainWindow: public QWidget{
  Q_OBJECT

public:
  MainWindow();
  //void renderBoard();
  
protected:
  void update_label();

private:
  QLabel *createLabel(const QString &text);//reduce repeatitve process
  QLabel *nextBlockLabel;
  QLabel *levelLabel;
  QLabel *scoreLabel;
  GameBoard gameboard;
  QLabel *boardLabel;
  QImage ui;
  QPainter qPainter;
 //level slot and score slot
 //show text function
  
};
#endif
