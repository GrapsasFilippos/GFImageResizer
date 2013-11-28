#ifndef RESOLUTIONS_HPP
#define RESOLUTIONS_HPP


//#include <QDebug>

#include "geometry.hpp"


class Resolutions
{
    public:
        Resolutions();
        Geometry * needCrop( int fW, int fH, int tW, int tH );
};


#endif // RESOLUTIONS_HPP
