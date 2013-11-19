#ifndef RESOLUTIONS_HPP
#define RESOLUTIONS_HPP


#include <QDebug>

#include <ImageMagick/Magick++.h>


class Resolutions
{
    public:
        Resolutions();
        Magick::Geometry * needCrop( int fW, int fH, int tW, int tH );
};


#endif // RESOLUTIONS_HPP
