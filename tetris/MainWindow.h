#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFrame>
#include <QWidget>
#include <QLabel>
#include <QtGui>
#include <qtimer.h>

class QLabel;

class GameBoard;

class MainWindow: public QWidget{
  Q_OBJECT

public:
  MainWindow();
  ~MainWindow();
  void renderBoard();
public slots:
  void updateBoard();
  void updateLevel();
  void updateScore();
private:
  QLabel *createLabel(const QString &text);//reduce repeatitve process
 
  QLabel *nextBlockLabel;
  QLabel *levelLabel;
  QLabel *scoreLabel;
  QTimer *timer;
  QImage boardImage;
  //QGraphicsScene *graphicBoard;
  //QGraphicsView *viewBoard(graphicBoard);
  GameBoard *gameboard;
  int boardToRender[20][10];
 
 //show text function
  
};
#endif
