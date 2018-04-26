/* Trey Brazil & Cameron Larson
 * CPSC 1020-001, SP18
 * rbrazil@clemson.edu clarson@clemson.edu
 */

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
    // Display menu, which takes in image, applies filters, and writes
    menu.displayMenu(in);
    return 0;

}
