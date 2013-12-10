/*
 * GFImageResizer
 * Copyright (C) 2013  Grapsas A. Filippos
 *
 * GFImageResizer is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
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

