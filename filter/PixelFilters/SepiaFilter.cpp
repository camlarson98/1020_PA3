#include "SepiaFilter.h"

SepiaFilter::SepiaFilter(string name) : PixelFilter(name) {

}

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

    return Pixel(outR, outG, outB);
}
