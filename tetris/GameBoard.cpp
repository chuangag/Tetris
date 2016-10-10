#include "GameBoard.h"
#include <iostream>
GameBoard::GameBoard(){
	//initialize blocks
	//initialized member: track, to_start_point, y, type
	//to be init: x
	//Important: the type is from 1 to 7 while the index of array is from 0 to 6
	for(int i=0;i<7;i++){
		defaultBlock[i].track[5]=D_END;
		defaultBlock[i].y=4;//start from 0!
		defaultBlock[i].x=2;
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
	//initialize the board and tempBoard
	tempBoard=new int*[20];
	for(int i=0;i<20;i++){
		tempBoard[i]=new int[10];
		for(int j=0;j<10;j++){
		  landedBoard[i][j]=0;
		}
	}
}

GameBoard::~GameBoard(){
	for(int i=0;i<20;i++){
		delete [] tempBoard[i];
	}
	delete [] tempBoard;
}

void GameBoard::tryleft(){
	tempBlock=currentBlock;
	tempBlock.y--;
	if(checkDirection(tempBlock.track, tempBlock.x, tempBlock.y)){
		currentBlock=tempBlock;
	}
	emit repaint();
	
}

void GameBoard::tryright(){
	tempBlock=currentBlock;
	tempBlock.y++;
	if(checkDirection(tempBlock.track, tempBlock.x, tempBlock.y)){
		currentBlock=tempBlock;
	}
	emit repaint();
}

void GameBoard::trydown(){
	tempBlock=currentBlock;
	tempBlock.x++;
	if(checkDirection(tempBlock.track, tempBlock.x, tempBlock.y)){
		currentBlock=tempBlock;
		emit repaint();
	}
	else{
		update_blocks();
	}
}

void GameBoard::tryrotateCounterclock(){
	tempBlock=currentBlock;
	for(int i=0;i<6;i++){
		changeDirection(tempBlock.track[i], false);
	}
	if(checkDirection(tempBlock.track, tempBlock.x, tempBlock.y)){
		currentBlock=tempBlock;
	}
	emit repaint();
}

void GameBoard::tryrotateClock(){
	tempBlock=currentBlock;
	for(int i=0;i<6;i++){
		changeDirection(tempBlock.track[i], true);
	}
	if(checkDirection(tempBlock.track, tempBlock.x, tempBlock.y)){
		currentBlock=tempBlock;
	}
	emit repaint();
}

bool GameBoard::checkDirection(int* direction, int x, int y){
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

int** GameBoard::getTempBoard(){
	for(int i=0;i<20;i++){
		for(int j=0;j<10;j++){
			tempBoard[i][j]=landedBoard[i][j];
		}
	}
	int i=0;
	tempBlock=currentBlock;
	while(tempBlock.track[i]!=D_END){
		switch(tempBlock.track[i]){
			case D_UP:
				tempBlock.x--;
				break;
			case D_DOWN:
				tempBlock.x++;
				break;
			case D_LEFT:
				tempBlock.y--;
				break;
			case D_RIGHT:
				tempBlock.y++;
		}
		tempBoard[tempBlock.x][tempBlock.y]=tempBlock.type;
		i++;
	}
	return tempBoard;
}

void GameBoard::update_blocks(){
	
	//check if the player fail the game
	for(int i=0;i<2;i++){
		for(int j=0;j<10;j++){
			if(landedBoard[i][j]){
				//emit game fail signal
				for(int k=0;k<20;k++){
					for(int l=0;l<10;l++){
						landedBoard[k][l]=0;
					}
				}
				currentBlock.type=0;
				nextBlock.type=0;
				emit fail();
				return;
			}
		}
	}
	//first check if there is blocks to be disappered
	combo=0;
	for(int i=0;i<20;i++){
		successful=true;
		for(int j=0;j<10;j++){
			if(!landedBoard[i][j]){
				successful=false;
				break;
			}
		}
		if(successful){
			combo++;
			//then move down all the line
			for(int j=i-1;j>0;j--){
				for(int k=0;k<10;k++){
					landedBoard[j+1][k]=landedBoard[j][k];
				}
				for(int k=0;k<10;k++){
					landedBoard[0][k]=0;
				}
				i--;//stay here and check again
			}
		}
	}
	if(combo){
		score+=10*combo*combo;
		emit changeScore(score);
		//emit score change signal
	}
	
	//then move down the block
	tempBlock=currentBlock;
	tempBlock.x++;
	if(checkDirection(tempBlock.track, tempBlock.x, tempBlock.y)){
		currentBlock=tempBlock;
	}
	else{
		int i=0;
		tempBlock.x--;
		while(tempBlock.track[i]!=D_END){
			switch(tempBlock.track[i]){
				case D_UP:
					tempBlock.x--;
					break;
				case D_DOWN:
					tempBlock.x++;
					break;
				case D_LEFT:
					tempBlock.y--;
					break;
				case D_RIGHT:
					tempBlock.y++;
			}
			landedBoard[tempBlock.x][tempBlock.y]=tempBlock.type;
			i++;
		}
		currentBlock=nextBlock;
		srand(time(0));
		nextBlock=defaultBlock[rand()%7];
	}
	//check if the player fail the game
	for(int i=0;i<2;i++){
		for(int j=0;j<10;j++){
			if(landedBoard[i][j]){
				//emit game fail signal
				currentBlock.type=0;
				nextBlock.type=0;
				emit fail();
				return;
			}
		}
	}
	emit sendNextBlock(nextBlock);
	emit repaint();
	
}


void GameBoard::start(){
	//score
	score=0;
	emit changeScore(score);
	//block
	srand(time(0));
	currentBlock=defaultBlock[rand()%7];
	nextBlock=defaultBlock[rand()%7];
	//board
	for(int k=0;k<20;k++){
		for(int l=0;l<10;l++){
			landedBoard[k][l]=0;
		}
	}
}
