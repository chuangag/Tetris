#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QBasicTimer>
#include <QFrame>
#include <QPointer>
#include <QWidget>
#include <QtGui>

#include "GameBlock.h"

class QLabel;

struct bound{
	int right;//offset from currentX to right bound
	int left;//offset from currentX to left bound
	int top;
	int bottom;
};

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
  struct bound currentBound;//offset from currentX to bound
  int nextBlock[4][4];
  int nextBlock_type;
}

#endif
