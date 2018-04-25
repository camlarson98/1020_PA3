#ifndef SEPIAFILTER_H
#define SEPIAFILTER_H
#include "../PixelFilter.h"

class SepiaFilter : public PixelFilter {
    private:

    public:
        SepiaFilter();
        SepiaFilter(string);
        SepiaFilter(const SepiaFilter&);
        virtual Pixel apply_transform(const Pixel&) const;
};

#endif
