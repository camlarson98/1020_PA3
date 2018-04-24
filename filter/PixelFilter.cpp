#include "PixelFilter.h"

PixelFilter::PixelFilter(string name) :
  Filter(name) {}

// Applies a filter to an image 
void PixelFilter::apply(Image& img) const{
    for(int i = 0; i < img.header().height(); i++){
        for(int j = 0; j < img.header().width(); j++){
            this->apply_transform(img(j, i));
        }
    }
}

PixelFilter::~PixelFilter() {}