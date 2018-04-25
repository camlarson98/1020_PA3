#ifndef BINARYFILTER_H
#define BINARYFILTER_H
#include "../PixelFilter.h"

class BinaryFilter : public PixelFilter {
    private:
        // Default and copy constructor - unused
        BinaryFilter();
        BinaryFilter(const BinaryFilter&);
        // "Pixels" to hold values of the colors to be applied
        Pixel color1, color2;

    public:
        // Parameter constructor with just an input name
        BinaryFilter(string);
        // Parameter constructor with input ints for the 
        // colors to be applied to the image
        BinaryFilter(int, int, int, int, int, int);
        // Applies colors to pixels based on luminance
        virtual Pixel apply_transform(const Pixel&) const;
        // Virtual destructor
        ~BinaryFilter();

};


#endif
