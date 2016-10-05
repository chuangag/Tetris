#include "GameBoard.h"

GameBoard::GameBoard(){
	//initialize blocks
	//initialized member: track, to_start_point, y, type
	//to be init: x
	//Important: the type is from 1 to 7 while the index of array is from 0 to 6
	for(int i=0;i<7;i++){
		defaultBlock[i].track[5]=D_END;
		defaultBlock[i].y=5;
		defaultBlock[i].type=i+1;
	}
	defaultBlock[0].track[0]=D_DOWN;
	defaultBlock[0].track[1]=D_UP;
	defaultBlock[0].track[2]=D_UP;
	defaultBlock[0].track[3]=D_UP;
	defaultBlock[0].track[4]=D_END;
	defaultBlock[1].track[0]=D_LEFT;
	defaultBlock[1].track[1]=D_DOWN;
	defaultBlock[1].track[2]=D_RIGHT;
	defaultBlock[1].track[3]=D_UP;
	defaultBlock[1].track[4]=D_END;
	defaultBlock[2].track[0]=D_UP;
	defaultBlock[2].track[1]=D_DOWN;
	defaultBlock[2].track[2]=D_RIGHT;
	defaultBlock[2].track[3]=D_DOWN;
	defaultBlock[2].track[4]=D_END;
	defaultBlock[3].track[0]=D_DOWN;
	defaultBlock[3].track[1]=D_UP;
	defaultBlock[3].track[2]=D_RIGHT;
	defaultBlock[3].track[3]=D_UP;
	defaultBlock[3].track[4]=D_END;
	defaultBlock[4].track[0]=D_UP;
	defaultBlock[4].track[1]=D_DOWN;
	defaultBlock[4].track[2]=D_DOWN;
	defaultBlock[4].track[3]=D_RIGHT;
	defaultBlock[4].track[4]=D_END;
	defaultBlock[5].track[0]=D_UP;
	defaultBlock[5].track[1]=D_DOWN;
	defaultBlock[5].track[2]=D_DOWN;
	defaultBlock[5].track[3]=D_LEFT;
	defaultBlock[5].track[4]=D_END;
	defaultBlock[6].track[0]=D_LEFT;
	defaultBlock[6].track[1]=D_RIGHT;
	defaultBlock[6].track[2]=D_UP;
	defaultBlock[6].track[3]=D_DOWN;
	defaultBlock[6].track[4]=D_RIGHT;
	//initialize the board
	for(int i=0;i<20;i++){
		for(int j=0;j<10;j++){
		  landedBoard[i][j]=0;
		}
	}
}

void KeyPress::keyPressEvent(QKeyEvent *event){
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

int GameBoard::getNextBlock(){
	return nextBlock.type;
}

void GameBoard::tryleft(){
	tempBlock=currentBlock;
	tempBlock.y--;
	if(checkDirection(tempBlock.track, tempBlock.x, tempBlock.y){
		currentBlock=tempBlock;
	}
	//to be added: emit a signal for UI to repaint
}

void GameBoard::tryright(){
	tempBlock=currentBlock;
	tempBlock.y++;
	if(checkDirection(tempBlock.track, tempBlock.x, tempBlock.y){
		currentBlock=tempBlock;
	}
	//to be added: emit a signal for UI to repaint
}

void GameBoard::trydown(){
	tempBlock=currentBlock;
	tempBlock.x++;
	if(checkDirection(tempBlock.track, tempBlock.x, tempBlock.y){
		currentBlock=tempBlock;
	}
	//to be added: emit a signal for UI to repaint
}

void GameBoard::tryrotateCounterclock(){
	tempBlock=currentBlock;
	for(int i=0;i<6;i++){
		changeDirection(tempBlock.track[i], false);
	}
	if(checkDirection(tempBlock.track, tempBlock.x, tempBlock.y){
		currentBlock=tempBlock;
	}
	//to be added: emit a signal for UI to repaint
}

void GameBoard::tryrotateClock(){
	tempBlock=currentBlock;
	for(int i=0;i<6;i++){
		changeDirection(tempBlock.track[i], true);
	}
	if(checkDirection(tempBlock.track, tempBlock.x, tempBlock.y){
		currentBlock=tempBlock;
	}
	//to be added: emit a signal for UI to repaint
}

bool checkDirection(int* direction, int x, int y){
	int i=0;
	while(direction[i]!=D_END){
		switch(direction[i]){
			case D_UP:
				x--;
				break;
			case D_DOWN:
				x++;
				break;
			case D_LEFT:
				y--;
				break;
			case D_RIGHT:
				y++;
		}
		if( x<0 || x>19 || y<0 || y>9 ) return false;
		if(landedBoard[x][y]) return false;
		i++;
	}
	return true;
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

int** const GameBoard::getTempBoard(){
	for(int i=0;i<20;i++){
		for(int j=0;j<10;j++){
			tempBoard[i][j]=landedBoard[i][j];
		}
	}
	i=0;
	while(currentBlock.track[i]!=D_END){
		switch(currentBlock.track[i]){
			case D_UP:
				currentBlock.x--;
				break;
			case D_DOWN:
				currentBlock.x++;
				break;
			case D_LEFT:
				currentBlock.y--;
				break;
			case D_RIGHT:
				currentBlock.y++;
		}
		tempBoard[currentBlock.x][currentBlock.y]=currentBlock.type;
		i++;
	}
	return tempBoard;
}

void GameBoard::update_blocks(){
	tempBlock=currentBlock;
	tempBlock.x++;
	if(checkDirection(tempBlock.track, tempBlock.x, tempBlock.y){
		currentBlock=tempBlock;
	}
	else{
		i=0;
		while(currentBlock.track[i]!=D_END){
			switch(currentBlock.track[i]){
				case D_UP:
					currentBlock.x--;
					break;
				case D_DOWN:
					currentBlock.x++;
					break;
				case D_LEFT:
					currentBlock.y--;
					break;
				case D_RIGHT:
					currentBlock.y++;
			}
			landedBoard[currentBlock.x][currentBlock.y]=currentBlock.type;
			i++;
		}
	}
	currentBlock=nextBlock;
	srand(time(0));
	nextBlock=defaultBlock[rand()*100%7];
}
