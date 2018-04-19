#include "filter/Filter.h"
#include "filter/KernelFilter.h"
#include "filter/KernelFilters/SharpenFilter.h"
#include "filter/KernelFilters/BlurFilter.h"
#include "image/Header.h"
#include "image/Image.h"
#include "image/Pixel.h"
#include "Menu/Menu.h"

int main(int argc, char* argv[]){
    Menu menu;
    menu.displayMenu();
    return 0;
    /*bool cont = true;
    while(cont){
        //Check for proper usage
        if(argc != 3){
            cerr << "USAGE: ./out <in.ppm> <out.ppm>" << std::endl;
            return 1;
        }
        // Open input file
        ifstream in(argv[1]);
        ifstream in2(argv[1]);

        //Check to see if input file could be opened
        if (!(in)) {
            std::cerr << "ERROR: Could not open input for reading." << std::endl;
            return 1;
        }
        // Open output file
        ofstream out(argv[2]);
        ofstream out2("test.ppm");

        // Check to see if output file could be opened
        if (!out) {
            std::cerr << "ERROR: Could not open output for writing." << std::endl;
            return 1;
        }

        // Create input image with input file
        Image puppy(in);
        Image puppy2(in2);
        // Create the filters
        SharpenFilter sharpFilter("sharpen");
        BlurFilter blurFilter("blur");

        // Apply the filters to the input image
        sharpFilter.apply(puppy2);
        blurFilter.apply(puppy);
        // Write the filtered image to the ouput file
        puppy.write_to(out);
        puppy2.write_to(out2);


        // Close input and output files
        in.close();
        out.close();
    
  
        return 0;
    }*/
}