#include <QCoreApplication>
#include <QList>

#include <ImageMagick/Magick++.h>
#include <stdexcept>


#include "resolutions.hpp"
#include "resolution.hpp"

#include <QDebug>


int main()
{
    qDebug() << "start";

    QString filePath("");
    QString newFilePath;

    Resolutions * resolutions = new Resolutions();

    QList<Resolution *> * lRes = new QList<Resolution *>;
    *lRes << new Resolution( 2560, 1440 );
    *lRes << new Resolution( 1920, 1440 );
    *lRes << new Resolution( 1920, 1200 );
    *lRes << new Resolution( 1920, 1080 );
    *lRes << new Resolution( 1680, 1200 );
    *lRes << new Resolution( 1680, 1050 );
    *lRes << new Resolution( 1600, 1200 );
    *lRes << new Resolution( 1440, 900 );
    *lRes << new Resolution( 1440, 1050 );
    *lRes << new Resolution( 1280, 1024 );
    *lRes << new Resolution( 1280, 960 );
    *lRes << new Resolution( 1280, 800 );
    *lRes << new Resolution( 1280, 720 );
    *lRes << new Resolution( 1152, 864 );
    *lRes << new Resolution( 1024, 1024 );
    *lRes << new Resolution( 1024, 768 );
    *lRes << new Resolution( 800, 600 );
    *lRes << new Resolution( 800, 480 );
    *lRes << new Resolution( 640, 480 );
    *lRes << new Resolution( 320, 480 );


    Magick::Image img, img2;
    Magick::Geometry geometry;
    Magick::Geometry resGeometry;
    Magick::Geometry * cropGeometry = 0;

    try {
        img.read(filePath.toStdString());
    }
    catch( std::exception &error_ ) {
        qDebug() << error_.what();
        return 0;
    }

    geometry = img.size();

    for(int i = 0; i < lRes->size(); i++) {
        img2 = img;
        newFilePath = filePath;
        newFilePath.insert( (newFilePath.size() - 4), '-' );
        newFilePath.insert( (newFilePath.size() - 4), QString::number( lRes->at(i)->getWidth() ) );
        newFilePath.insert( (newFilePath.size() - 4), 'x' );
        newFilePath.insert( (newFilePath.size() - 4), QString::number( lRes->at(i)->getHeight() ) );
        qDebug() << "-----------------";
        qDebug() << newFilePath;

        resGeometry.width( lRes->at(i)->getWidth() );
        resGeometry.height( lRes->at(i)->getHeight() );
        cropGeometry = resolutions->needCrop( geometry.width(), geometry.height(), resGeometry.width(), resGeometry.height() );

        if( cropGeometry ) {
            img2.crop( *cropGeometry );
            delete( cropGeometry );
        }

        img2.resize( resGeometry );
        img2.write( newFilePath.toStdString() );
    }

    delete( resolutions );
    delete( lRes );
    qDebug() << "finish";
}
