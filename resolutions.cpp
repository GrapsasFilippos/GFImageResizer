#include "resolutions.hpp"

Resolutions::Resolutions() {
}


Geometry * Resolutions::needCrop(int fW, int fH, int tW, int tH) {

    Geometry * newGeometry = new Geometry();

    const double wDiff = (double)fW / (double)tW;
    const double hDiff = (double)fH / (double)tH;

    //qDebug() << "width:" << fW << "height:" << fH;
    //qDebug() << "wDiff:" << wDiff << "hDiff:" << hDiff;

    if( wDiff < hDiff ) {
        //qDebug() << "no crop width";
        newGeometry->width( fW );
        newGeometry->height( tH * wDiff );
        newGeometry->xOff(0);
        newGeometry->yOff( (fH - newGeometry->height()) / 2 );
    }
    else if( hDiff < wDiff ) {
        //qDebug() << "no crop height";
        newGeometry->height( fH );
        newGeometry->width( tW * hDiff) ;
        newGeometry->yOff(0);
        newGeometry->xOff( (fW - newGeometry->width()) / 2 );
    }
    else {
        //qDebug() << "no crop at all";
        delete( newGeometry );
        return 0;
    }

    //qDebug() << "crop to:" << newGeometry->width() << "x" << newGeometry->height();

    return newGeometry;
}

