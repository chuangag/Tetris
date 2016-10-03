#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFrame>
#include <QWidget>
class QLabel;

class GameBoard;

class MainWindow: public QWidget{
  Q_OBJECT

public:
  MainWindow();
private:
  QLabel *createLabel(const QString &text);//reduce repeat process
  
  QLabel *nextBlockLabel;
  QLabel *levelLabel;
  QLabel *scoreLabel;
  GameBoard *gameboard;
  
  
};
#endif
