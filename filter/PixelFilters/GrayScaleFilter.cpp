#include "GrayScaleFilter.h"

GrayScaleFilter::GrayScaleFilter(string name) : PixelFilter(name) {}

Pixel GrayScaleFilter::apply_transform(const Pixel& pix) const {
    uint8_t lum = pix.luminance();
    Pixel newPix(lum, lum, lum);
    return newPix;
}