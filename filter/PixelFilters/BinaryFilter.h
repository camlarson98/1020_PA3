#ifndef BINARYFILTER_H
#define BINARYFILTER_H
#include "../PixelFilter.h"

/*Pixel WHITE(255, 255, 255);
Pixel BLACK(0, 0, 0);
Pixel RED(255, 0, 0);
Pixel YELLOW(255, 255, 0);
Pixel GREEN(0, 255, 255);
Pixel BLUE(0, 0, 255);
Pixel PURPLE(255, 0, 255);
Pixel ORANGE(255, 165, 0);*/

class BinaryFilter : public PixelFilter {
    private:
        BinaryFilter();
        BinaryFilter(const BinaryFilter&);
        Pixel color1, color2;

    public:
        BinaryFilter(string);
        BinaryFilter(int, int, int, int, int, int);
        virtual Pixel apply_transform(const Pixel&) const;

};


#endif
