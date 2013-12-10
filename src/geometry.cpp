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
