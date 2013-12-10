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
