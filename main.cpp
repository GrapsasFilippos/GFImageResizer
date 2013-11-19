#include <QApplication>
#include <QList>

#include <ImageMagick/Magick++.h>
#include <stdexcept>

#include "GUI/mainwindow.hpp"

#include <QDebug>


int main( int argc, char *argv[] )
{
    qDebug() << "start";
    QApplication app(argc, argv);


    MainWindow mainWin;
    mainWin.show();


    qDebug() << "finish";
    return app.exec();
}
