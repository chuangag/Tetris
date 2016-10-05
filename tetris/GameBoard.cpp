#include "GameBoard.h"

GameBoard::GameBoard(){
	//initialize blocks
	//initialized member: track, to_start_point, y, type
	//to be init: x
	//Important: the type is from 1 to 7 while the index of array is from 0 to 6
	for(int i=0;i<7;i++){
		defaultBlock[i].to_start_point[1]=D_END;
		defaultBlock[i].track[4]=D_END;
		defaultBlock[i].y=5;
		defaultBlock[i].type=i+1;
	}
	defaultBlock[0].to_start_point[0]=D_DOWN;
	defaultBlock[0].track[0]=D_UP;
	defaultBlock[0].track[1]=D_UP;
	defaultBlock[0].track[2]=D_UP;
	defaultBlock[0].track[3]=D_END;
	defaultBlock[1].to_start_point[0]=D_END;
	defaultBlock[1].track[0]=D_LEFT;
	defaultBlock[1].track[1]=D_DOWN;
	defaultBlock[1].track[2]=D_RIGHT;
	defaultBlock[1].track[3]=D_END;
	defaultBlock[2].to_start_point[0]=D_UP;
	defaultBlock[2].track[0]=D_DOWN;
	defaultBlock[2].track[1]=D_RIGHT;
	defaultBlock[2].track[2]=D_DOWN;
	defaultBlock[2].track[3]=D_END;
	defaultBlock[3].to_start_point[0]=D_DOWN;
	defaultBlock[3].track[0]=D_UP;
	defaultBlock[3].track[1]=D_RIGHT;
	defaultBlock[3].track[2]=D_UP;
	defaultBlock[3].track[3]=D_END;
	defaultBlock[4].to_start_point[0]=D_UP;
	defaultBlock[4].track[0]=D_DOWN;
	defaultBlock[4].track[1]=D_DOWN;
	defaultBlock[4].track[2]=D_RIGHT;
	defaultBlock[4].track[3]=D_END;
	defaultBlock[5].to_start_point[0]=D_UP;
	defaultBlock[5].track[0]=D_DOWN;
	defaultBlock[5].track[1]=D_DOWN;
	defaultBlock[5].track[2]=D_LEFT;
	defaultBlock[5].track[3]=D_END;
	defaultBlock[6].to_start_point[0]=D_LEFT;
	defaultBlock[6].track[0]=D_RIGHT;
	defaultBlock[6].track[1]=D_UP;
	defaultBlock[6].track[2]=D_DOWN;
	defaultBlock[6].track[3]=D_RIGHT;
	//initialize the board
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
	//....
	setNextBlock();
}

void GameBoard::setNextBlock(){
	srand(time(0));
	nextBlock=defaultBlock[rand()*100%7];
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
	tempBlock=currentBlock;
	changeDirection(tempBlock.to_start_point[0], true);
	for(int i=0;i<4;i++){
		changeDirection(tempBlock.track[i], true);
	}
	//to be added: emit a signal for UI to repaint
}



void GameBoard::changeDirection(int& d,bool is_clockwise){
	if(is_clockwise){
		switch(d){
			case D_UP:
				d=D_RIGHT;
				break;
			case D_DOWN:
				d=D_LEFT;
				break;
			case D_RIGHT:
				d=D_DOWN;
				break;
			case D_LEFT:
				d=D_UP;
		}
	}
	else{
		switch(d){
			case D_UP:
				d=D_LEFT;
				break;
			case D_DOWN:
				d=D_RIGHT;
				break;
			case D_RIGHT:
				d=D_UP;
				break;
			case D_LEFT:
				d=D_DOWN;
		}
	}
}
