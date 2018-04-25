#include "menu/Menu.h"

int main(int argc, char* argv[]){
    //Check for proper usage
    if(argc != 2){
        cerr << "USAGE: ./out <in.ppm>" << std::endl;
        return 1;
    }
    // Open input file
    ifstream in(argv[1]);

    //Check to see if input file could be opened
    if (!(in)) {
        std::cerr << "ERROR: Could not open input for reading." << std::endl;
        return 1;
    }

    // Create an instance of a Menu class
    Menu menu;
    // Performs the rest of the work basically for this program
    menu.displayMenu(in);
    return 0;
    
}
