#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QBasicTimer>
#include <QFrame>
#include <QPointer>
#include <QWidget>
#include <QtGui>

#define D_END 0
#define D_LEFT 1
#define D_RIGHT 2
#define D_UP 3
#define D_DOWN 4

class QLabel;

struct block{
	/* Direction code:
	 * 0: End of Direction code
	 * 1: Left
	 * 2: Right
	 * 3: Up
	 * 4: Down
	 */
	int track[6];
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
  int getNextBlock();
  long getScore();
  void start();
  
public slots:
  void update_blocks();//update status every second
  
signals:
  void changeScore(int);
  //void changeLevel(int level);
  void repaint();
  void fail();
 
protected:
  void changeDirection(int& d, bool is_clockwise);
  bool checkDirection(int* direction, int x, int y);//temporary block!
  
private:
  int landedBoard[20][10];//10*20 board
  int** tempBoard;
  int score;
  int combo;
  bool successful;
  struct block currentBlock;//data of moving block
  struct block nextBlock;
  struct block tempBlock;//the temporary block for trying
  struct block defaultBlock[7];
};

#endif
