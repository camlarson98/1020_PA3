#include "Menu.h"

Menu::Menu(){}

Menu::~Menu(){}

void Menu::displayMenu(){
    string input;
    int i = 0;
    cout << setw(70) << setfill(' ') << left << "Welcome!" << endl;
    while(this->filterType.at(i) != -1){
        cout << "Which filter would you like to use? Enter -1 to exit" << endl;
        cin >> input;
}