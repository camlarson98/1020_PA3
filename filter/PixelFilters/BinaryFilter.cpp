#include "BinaryFilter.h"

BinaryFilter::BinaryFilter(string name) : PixelFilter(name) {

}


BinaryFilter::BinaryFilter(int red1, int green1, int blue1, int red2, int green2, int blue2) : PixelFilter(name) {
    this->color1 = Pixel(red1, green1, blue1);
    this->color2 = Pixel(red2, green2, blue2);
}


Pixel BinaryFilter::apply_transform(const Pixel& pix) const{
    Pixel white(255, 255, 255);
    uint8_t maxLum = white.luminance();
    if(pix.luminance() < maxLum / 2 + 1){
        return this->color1;
    }
        else{
            return this->color2;
        }
}