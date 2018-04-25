#ifndef MENU_H
#define MENU_H
#include <vector>
#include <iomanip>
#include <iostream>
#include <sstream>
#include "../filter/KernelFilters/BlurFilter.h"
#include "../filter/KernelFilters/SharpenFilter.h"
#include "../filter/SimpleFilters/HFlipFilter.h"
#include "../filter/SimpleFilters/VFlipFilter.h"
#include "../filter/PixelFilters/BinaryFilter.h"
#include "../filter/PixelFilters/GrayScaleFilter.h"
#include "../filter/PixelFilters/SepiaFilter.h"
#include "../image/Image.h"

using namespace std;

class Menu {
    private:
        // Vector to hold filters
        vector<Filter*> filters;
        
    public:
        // Default constructor
        Menu();
        // Default destructor
        ~Menu();
        // Menu display
        void displayMenu(ifstream&);
        // Adds filters to filter vector based on input int
        void addFilter(int);
        // Applies filters to input image with filter vector
        void applyFilters(Image&);
};

#endif