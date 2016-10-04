#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QBasicTimer>
#include <QFrame>
#include <QPointer>
#include <QWidget>
#include <QtGui>

#include "GameBlock.h"

class QLabel;

struct block{
	/* Direction code:
	 * 0: End of Direction code
	 * 1: Left
	 * 2: Right
	 * 3: Up
	 * 4: Down
	 */
	int to_start_point[2];
	int track[5];
	int type;//From 1 to 7
	int x;//center's x coordinate
	int y;//center's y coordinate
};

class GameBoard : public QFrame
{
  Q_OBJECT
  
public:
  GameBoard();
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
  
private:
  int landedBoard[20][10];//10*20 board
  int tempBoard[20][10];//landed blocks + moving blocks
  struct block currentBlock;//data of moving block
  struct block nextBlock;
}

#endif
