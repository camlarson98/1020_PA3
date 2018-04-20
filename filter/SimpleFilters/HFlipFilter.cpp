#include "HFlipFilter.h"

//Default constructor
HFlipFilter::HFlipFilter() : SimpleFilter("") {}

//Parameter constructor
HFlipFilter::HFlipFilter(string name) : SimpleFilter(name) {}

//Destructor
HFlipFilter::~HFlipFilter() {}

// Flips the input image horizontally
void HFlipFilter::apply(Image& img) const {
    int i = 0, j = 0;
    for(i = 0; i < img.header().height(); i++){
        for(j = 0; j < img.header().width() / 2; j++){
            swap(img(j, i), img(img.header().width() - j - 1, i));
        }
    }
}
