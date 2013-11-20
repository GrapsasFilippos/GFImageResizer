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
