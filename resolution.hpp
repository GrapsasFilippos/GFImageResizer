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
