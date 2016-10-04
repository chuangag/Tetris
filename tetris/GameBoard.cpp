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
	break;
      case Qt::Key_Right:
	break;
      case Qt::Key_Up:
	break;
      case Qt::Key_Down:
	break;
      case Qt::Key_Z:
	break;
      case Qt::Key_X:
	break;
    }
}