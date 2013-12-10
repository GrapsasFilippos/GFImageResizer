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
#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP

class Geometry
{
    public:
        Geometry();
        Geometry( int w, int h, int x, int y);
        void width( int w );
        int width();
        void height( int h );
        int height();
        void xOff( int x );
        int xOff();
        void yOff( int y );
        int yOff();

     private:
        void init( int w, int h, int x, int y );
        int _width;
        int _height;
        int _xOffset;
        int _yOffset;
};

#endif // GEOMETRY_HPP
