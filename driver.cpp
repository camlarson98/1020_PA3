#include "filter/Filter.h"
#include "filter/KernelFilter.h"
#include "filter/KernelFilters/SharpenFilter.h"
#include "filter/KernelFilters/BlurFilter.h"
#include "image/Header.h"
#include "image/Image.h"
#include "image/Pixel.h"

int main(int argc, char* argv[]){
    //Check for proper usage
    if(argc != 3){
        cerr << "USAGE: ./out <in.ppm> <out.ppm>" << std::endl;
        return 1;
    }
    // Open input file
    ifstream in(argv[1]);

    //Check to see if input file could be opened
    if (!(in)) {
        std::cerr << "ERROR: Could not open input for reading." << std::endl;
        return 1;
    }
    // Open output file
    ofstream out(argv[2]);

    // Check to see if output file could be opened
    if (!out) {
        std::cerr << "ERROR: Could not open output for writing." << std::endl;
        return 1;
    }

    // Create input image with input file
    Image puppy(in);
    // Create the sharpen filter
    //SharpenFilter imageFilter("sharpen");
    BlurFilter imageFilter("blur");

    // Apply the sharpen filter to the input image
    imageFilter.apply(puppy);
    // Write the filtered image to the ouput file
    puppy.write_to(out);

    // Close input and output files
    in.close();
    out.close();
    
  
    return 0;
    
}