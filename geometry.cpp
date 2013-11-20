#include "geometry.hpp"

void Geometry::init(int w, int h, int x, int y) {
    _width = w;
    _height = h;
    _xOffset = x;
    _yOffset = y;
}


Geometry::Geometry() {
    init( 0, 0, 0, 0 );
}


Geometry::Geometry(int w, int h, int x, int y) {
    init( w, h, x, y );
}


void Geometry::width(int w) {
    _width = w;
}


int Geometry::width() {
    return _width;
}


void Geometry::height(int h) {
    _height = h;
}


int Geometry::height() {
    return _height;
}

void Geometry::xOff(int x) {
    _xOffset = x;
}


int Geometry::xOff() {
    return _xOffset;
}


void Geometry::yOff(int y) {
    _yOffset = y;
}


int Geometry::yOff() {
    return _yOffset;
}
