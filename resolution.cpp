#include "resolution.hpp"

Resolution::Resolution() {
    init( 0, 0 );
}


Resolution::Resolution(int w, int h) {
    init( w, h );
}


void Resolution::init(int w, int h) {
    width = w;
    height = h;
    aspectRatio = 0;
    calculateAspectRatio();
}


void Resolution::setWidth(const int w) {
    width = w;
    calculateAspectRatio();
}


int Resolution::getWidth() const {
    return width;
}


void Resolution::setHeight(const int h) {
    height = h;
    calculateAspectRatio();
}


int Resolution::getHeight() const {
    return height;
}


double Resolution::getAspectRatio() const {
    return aspectRatio;
}


void Resolution::calculateAspectRatio() {
    if( ( width == 0 ) || ( height == 0 ) )
        return;

    aspectRatio = width / height;
}
