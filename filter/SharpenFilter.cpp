#include "SharpenFilter.h"

// Declares the matrix to be used in the filter
const Matrix SharpenFilter::K3 = {
    {0, -1, 0},
    {-1, 5,-1},
    {0, -1, 0}
  };

// Parameter constructor of sharpen filter, initializer 
// list with KernelFilter parameter constructor
SharpenFilter::SharpenFilter(string name) : 
  KernelFilter(name) {}

/* Simple function that is called in main, takes input parameter
 * and add the matrix to the call to the KernelFilter apply()
 */
void SharpenFilter::apply(Image& img) const {
  KernelFilter::apply(img, K3);
}

// Destructor
SharpenFilter::~SharpenFilter(){}