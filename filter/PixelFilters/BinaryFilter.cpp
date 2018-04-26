#include "BinaryFilter.h"

// Parameter constructor with initializer for name
BinaryFilter::BinaryFilter(string name) : PixelFilter(name) {}

// Default destructor
BinaryFilter::~BinaryFilter() {}

// Parameter constructor with rgb values of the two colors for the filter as parameters
BinaryFilter::BinaryFilter(int red1, int green1, int blue1, int red2, int green2, int blue2) : PixelFilter(name) {
    // Make sure all input values fit in 0 to 255 range
    red1 = Filter::clamp(0, 255, red1);
    green1 = Filter::clamp(0, 255, green1);
    blue1 = Filter::clamp(0, 255, blue1);
    red2 = Filter::clamp(0, 255, red2);
    green2 = Filter::clamp(0, 255, green2);
    blue2 = Filter::clamp(0, 255, blue2);
    this->color1 = Pixel(red1, green1, blue1);
    this->color2 = Pixel(red2, green2, blue2);
}

// Makes each pixel one of the two input colors - the first color
// if luminance is > half the maximum luminance, the second if
// luminance is < half the maximum luminance
Pixel BinaryFilter::apply_transform(const Pixel& pix) const{
    // Create a pixel with max luminance
    Pixel white(255, 255, 255);
    // Determine value of max luminance
    uint8_t maxLum = white.luminance();
    // If luminance of input pixel is < half maximum luminance, make it color1
    if(pix.luminance() < maxLum / 2){
        return this->color1;
    }
        // Otherwise make input pixel color2
        else{
            return this->color2;
        }
}