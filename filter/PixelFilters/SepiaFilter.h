#ifndef SEPIAFILTER_H
#define SEPIAFILTER_H
#include "../PixelFilter.h"

class SepiaFilter : public PixelFilter {
    private:

    public:
        // Constructors
        SepiaFilter();
        SepiaFilter(string);
        SepiaFilter(const SepiaFilter&);
        // Destructor
        ~SepiaFilter();
        // Finds sepia equivalent of input pixel
        virtual Pixel apply_transform(const Pixel&) const;
};

#endif
