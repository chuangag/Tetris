#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFrame>
#include <QWidget>
#include <QLabel>
#include <QtGui>

class QLabel;

class GameBoard;

class MainWindow: public QWidget{
  Q_OBJECT

public:
  MainWindow();
  void renderBoard();
private:
  QLabel *createLabel(const QString &text);//reduce repeatitve process
 
  QLabel *nextBlockLabel;
  QLabel *levelLabel;
  QLabel *scoreLabel;
  GameBoard *gameboard;
 //level slot and score slot
 //show text function
  
};
#endif
