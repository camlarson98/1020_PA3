#include "BinaryFilter.h"

BinaryFilter::BinaryFilter(string name) : PixelFilter(name) {

}

/*BinaryFilter::BinaryFilter(string name, string first, string second) : PixelFilter(name) {
    this->color1 = stringConvert(first);
    this->color2 = stringConvert(second);
}*/

BinaryFilter::BinaryFilter(int red1, int green1, int blue1, int red2, int green2, int blue2) : PixelFilter(name) {
    this->color1 = Pixel(red1, green1, blue1);
    this->color2 = Pixel(red2, green2, blue2);
}

/*Pixel& BinaryFilter::stringConvert(string color){
    Pixel pix;
    if(color == "white"){
        pix = WHITE;
    }
        else if(color == "black"){
            pix = BLACK;
        }
        else if(color == "red"){
            pix = RED;
        }
        else if(color == "orange"){
            pix = ORANGE;
        }
        else if(color == "blue"){
            pix = BLUE;
        }
        else if(color == "purple"){
            pix = PURPLE;
        }
        else if(color == "green"){
            pix = GREEN;
        }
        else if(color == "yellow"){
            pix = YELLOW;
        }
        else{
            cout << "Invalid color entered - using black" << endl;
            pix = BLACK;
        }
    return pix;
}*/

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