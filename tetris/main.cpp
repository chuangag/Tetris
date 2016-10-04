#include <QApplication>
#include <QtWidgets>
#include <stdlib.h>
#include "MainWindow.h"
 #include <q3mainwindow.h>
#include <qapplication.h>
#include <qpixmap.h>
#include <qtimer.h>
//Added by qt3to4:
#include <QPaintEvent>
#include <QLabel>
#include <QtGui>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;
    window.show();
    //qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    return app.exec();
} 
