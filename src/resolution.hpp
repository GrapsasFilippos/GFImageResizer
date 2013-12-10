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
#ifndef RESOLUTION_HPP
#define RESOLUTION_HPP


class Resolution
{
    public:
        Resolution();
        Resolution( int w, int h );
        void setWidth( const int w );
        int getWidth() const;
        void setHeight( const int h );
        int getHeight() const;
        double getAspectRatio() const;

    private:
        void init( int w, int h );
        void calculateAspectRatio();
        int width;
        int height;
        double aspectRatio;
};


#endif // RESOLUTION_HPP
