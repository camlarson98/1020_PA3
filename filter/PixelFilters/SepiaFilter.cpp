#include "SepiaFilter.h"

// Parameter constructor with initializer list for name
SepiaFilter::SepiaFilter(string name) : PixelFilter(name) {

}

// Default destructor
SepiaFilter::~SepiaFilter() {}

// Takes input pixel and returns the respective value of that pixel
// in sepia
Pixel SepiaFilter::apply_transform(const Pixel& pix) const{
    double red, green, blue;
    double outR, outG, outB;

    //Convert pixels to sRGB space and call gamma_expansion
    red = Pixel::gamma_expansion(pix.r()/255.0);
    green = Pixel::gamma_expansion(pix.g()/255.0);
    blue = Pixel::gamma_expansion(pix.b()/255.0);

    //Sepia filter hue
    outR = (red * .393) + (green *.769) + (blue * .189);
  	outG = (red * .349) + (green *.686) + (blue * .168);
  	outB = (red * .272) + (green *.534) + (blue * .131);

    //Bring back into RGB space
    outR = outR > 1.0 ? Pixel::inverse_gamma(1.0) : Pixel::inverse_gamma(outR);
    outG = outG > 1.0 ? Pixel::inverse_gamma(1.0) : Pixel::inverse_gamma(outG);
    outB = outB > 1.0 ? Pixel::inverse_gamma(1.0) : Pixel::inverse_gamma(outB);
    outR *= 255;
    outG *= 255;
    outB *= 255;
    
    // Make sure output values fit in 0 to 255 range
    outR = Filter::clamp(0.0, 255.0, outR);
    outG = Filter::clamp(0.0, 255.0, outG);
    outB = Filter::clamp(0.0, 255.0, outB);

    return Pixel(outR, outG, outB);
}
