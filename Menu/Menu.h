#ifndef MENU_H
#define MENU_H
#include <vector>
#include <iomanip>
#include <iostream>

using namespace std;

class Menu {
    private:
        vector<int> filterType;
        
    public:
        Menu();
        ~Menu();
        void displayMenu();
        void setFilter(int);
        int getFilter();

};

#endif