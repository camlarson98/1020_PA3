#include "VFlipFilter.h"

//Default constructor
VFlipFilter::VFlipFilter() : SimpleFilter("") {}

//Parameter constructor
VFlipFilter::VFlipFilter(string name) : SimpleFilter(name) {}

//Destructor
VFlipFilter::~VFlipFilter() {}

// Flips the input image vertically
void VFlipFilter::apply(Image& img) const {
    int i = 0, j = 0;
    for(i = 0; i < img.header().height() / 2; i++){
        for(j = 0; j < img.header().width(); j++){
            swap(img(j, i), img(j, img.header().height() - i - 1));
        }
    }
}
