GameBoard::GameBoard(){
  for(int i=0;i<10;i++){
    for(int j=0;j<20;j++){
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
