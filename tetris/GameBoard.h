#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QBasicTimer>
#include <QFrame>
#include <QPointer>

#include "GameBlock.h"

class QLabel;

class GameBoard : public QFrame
{
  Q_OBJECT
  
public:
  GameBoard();
  //void renderBoard();
  int getTempBoard();
  void trydown();
  void tryleft();
  void tryright();
  void tryrotateClock();
  void tryrotateCounterclock();
  void setNextBlock();
  
public slots:
  void start();
  
signals:
  void changeScore(int score);
  void changeLevel(int level);
  
private:
  int landedBoard[9][19];//10*20 board
  int tempBoard[9][19];//landed blocks + moving blocks
  int currentX;//center's x coordinate
  int currentY;//center's y coordinate
  int currentBlock[4][4];//any blocks can be put in a 4*4 grid
  int nextBlock[4][4];
}

#endif
