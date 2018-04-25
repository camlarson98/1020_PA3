#include "PixelFilter.h"

// Parameter constructor with an initializer list for name
PixelFilter::PixelFilter(string name) : Filter(name) {}

// Applies a filter to an image by looping through each pixel individually
// and calling the appropriate base class filter on that pixel
void PixelFilter::apply(Image& img) const{
    for(int i = 0; i < img.header().height(); i++){
        for(int j = 0; j < img.header().width(); j++){
            img(j, i) = this->apply_transform(img(j, i));
        }
    }
}

// Default destructor
PixelFilter::~PixelFilter() {}