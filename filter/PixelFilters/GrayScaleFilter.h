#ifndef GRAYSCALEFILTER_H
#define GRAYSCALEFILTER_H
#include "../PixelFilter.h"

class GrayScaleFilter : public PixelFilter {
    private:
        // Default and copy constructors - unused
        GrayScaleFilter();
        GrayScaleFilter(const GrayScaleFilter&);
        
    public:
        // Parameter constructor with name input
        GrayScaleFilter(string);
        // Finds GrayScale values of input pixel
        virtual Pixel apply_transform(const Pixel&) const;
        // Virtual destructor
        virtual ~GrayScaleFilter();

};



#endif