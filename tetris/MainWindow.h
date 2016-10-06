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

public slots:
  void renderBoard();
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
  QPainter qPainter;
  QTimer *timer;
  bool game_started;
  int level;
 //level slot and score slot
 //show text function
  
};
#endif
