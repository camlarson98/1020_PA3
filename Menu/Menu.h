#ifndef MENU_H
#define MENU_H
#include <vector>
#include <iomanip>
#include <iostream>
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
        vector<Filter*> filters;
        
    public:
        Menu();
        ~Menu();
        void displayMenu(ifstream&);
        void addFilter(vector<int>, Image&);
        int getFilter();
        void applyFilters(int, Image&);

};

#endif