#include "GrayScaleFilter.h"

// Parameter constructor with initializer
GrayScaleFilter::GrayScaleFilter(string name) : PixelFilter(name) {}

// Default destructor
GrayScaleFilter::~GrayScaleFilter() {}

// Takes input pixel and returns its grayscale equivalent
Pixel GrayScaleFilter::apply_transform(const Pixel& pix) const {
    // Determine luminance of input pixel
    uint8_t lum = pix.luminance();
    // Create new pixel with found luminance for each color value
    Pixel newPix(lum, lum, lum);
    return newPix;
}