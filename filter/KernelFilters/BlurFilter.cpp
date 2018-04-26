#include "BlurFilter.h"

// Declares the matrix to be used in the filter
const Matrix BlurFilter::blur = {
    {0.0625, 0.125, 0.0625},
    {0.125,  0.25,  0.125},
    {0.0625, 0.125, 0.0625}
  };

// Parameter constructor of Blur filter, initializer
// list with KernelFilter parameter constructor
BlurFilter::BlurFilter(string name) :
  KernelFilter(name) {}

// Simple function that is called in main, takes input parameter
// and add the matrix to the call to the KernelFilter apply()
void BlurFilter::apply(Image& img) const {
  KernelFilter::apply(img, blur);
}

// Destructor
BlurFilter::~BlurFilter(){}
