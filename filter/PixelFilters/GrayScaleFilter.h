#ifndef GRAYSCALEFILTER_H
#define GRAYSCALEFILTER_H
#include "../PixelFilter.h"

class GrayScaleFilter : public PixelFilter {
    private:
        GrayScaleFilter();
        GrayScaleFilter(const GrayScaleFilter&);
        
    public:
        GrayScaleFilter(string);
        virtual Pixel apply_transform(const Pixel&) const;

};



#endif