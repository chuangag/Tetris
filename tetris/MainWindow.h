#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFrame>
#include <QWidget>
#include <QLabel>
#include <QtGui>
#include <QTimerEvent>
#include "GameBoard.h"

class QLabel;

class MainWindow: public QWidget{
  Q_OBJECT

public:
  MainWindow();
  ~MainWindow();

public slots:
  void renderBoard();
  void setNextBlock(struct block);
  void fail();
  void changeScore(int);

protected:
  void keyPressEvent(QKeyEvent *);
  void start();

private:
  QLabel *createLabel(const QString &text);//reduce repeatitve process
  QLabel *nextBlockLabel;
  QLabel *levelLabel;
  QLabel *scoreLabel;
  GameBoard gameboard;
  QLabel *boardLabel;
  QImage ui;
  QPixmap nxtBlock;
  
  QPainter qPainter;
  QPainter nxtPainter;
  QTimer *timer;
  bool game_started;
  int level;
  int x,y;//for next block
 //level slot and score slot
 //show text function
  
};
#endif
