#include "GameBoard.h"

GameBoard::GameBoard(){
	for(int i=0;i<7;i++){
		defaultBlock[i].y=5;
	}
	
	for(int i=0;i<20;i++){
		for(int j=0;j<10;j++){
		  landedBoard[i][j]=0;
		}
	}
}

void KeyPress::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()){
      case Qt::Key_Left:
		tryleft();
		break;
      case Qt::Key_Right:
		tryright();
		break;
      case Qt::Key_Up:
		//start?
		break;
      case Qt::Key_Down:
		trydown();
		break;
      case Qt::Key_Z:
		tryrotateCounterclock();
		break;
      case Qt::Key_X:
		tryrotateClock();
		break;
    }
}

void GameBoard::getNextBlock(){
	
	setNextBlock();
}

void GameBoard::setNextBlock(){
	srand(time(0));
	nextBlock_type=rand()*100%7;
	//to be continue
}

void GameBoard::tryleft(){
	//reminder: change the direction code of block
}

void GameBoard::tryright(){
	//reminder: change the direction code of block
}

void GameBoard::trydown(){
	//reminder: change the direction code of block
}

void GameBoard::tryrotateCounterclock(){
	//reminder: change the direction code of block
}

void GameBoard::tryrotateClock(){

}
