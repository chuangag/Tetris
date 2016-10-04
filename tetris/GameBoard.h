#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QBasicTimer>
#include <QFrame>
#include <QPointer>
#include <QWidget>
#include <QtGui>

#include "GameBlock.h"

class QLabel;

class GameBoard : public QFrame
{
  Q_OBJECT
  
public:
  GameBoard();
  //void renderBoard();
  int** getTempBoard();//return board array
  void trydown();
  void tryleft();
  void tryright();
  void tryrotateClock();
  void tryrotateCounterclock();
  void setNextBlock();
  void getNextBlock();
  
public slots:
  void start();
  void update_blocks();//update status every second
  
signals:
  void changeScore(int score);
  void changeLevel(int level);
 
protected:
  void keyPressEvent(QKeyEvent *);
  //void keyReleaseEvent(QKeyEvent *);
  
private:
  int landedBoard[20][10];//10*20 board
  int tempBoard[20][10];//landed blocks + moving blocks
  int currentX;//center's x coordinate
  int currentY;//center's y coordinate
  //int currentBlock[4][4];//any blocks can be put in a 4*4 grid
  int nextBlock[4][4];
  int nextBlock_type;
}

#endif
