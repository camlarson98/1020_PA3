#include "Menu.h"

Menu::Menu(){}

Menu::~Menu(){}

void Menu::displayMenu(ifstream& in){
    // Variables for loops and tests
    int i = 0, n = 0;
    char c = 'y';

    cout << endl << "###-----------| Welcome |-----------###" << endl;

    // Master loop takes in images until user terminates (n)
    while(c == 'y'){
        // Initialize new image
        Image img(in);
        i = 0;

        // Actual menu UI
        cout << "=======================================" << endl
             << "| Which filter would you like to use? |" << endl
             << "|  You may use the same filter more   |" << endl
             << "|             than once.              |"
             << "|       Enter -1 when finished        |" << endl
             << "=======================================" << endl
             << "|    1) Sharpen                       |" << endl
             << "|    2) Blur                          |" << endl
             << "|    3) Horizontal flip               |" << endl
             << "|    4) Vertical flip                 |" << endl
             << "|    5) Binary                        |" << endl
             << "|    6) Grayscale                     |" << endl
             << "|    7) Sepia                         |" << endl
             << "=======================================" << endl;

        // Loop to keep adding filters until user terminates (-1)
        //Is it possible to take multiple inputs at once?
        while(i != -1){
            // User input
            cin >> i;
            // If input was valid, add that filter to Filter* vector
            if(i > 0 && i < 8){
                this->addFilter(i);
                cout << "Next filter? Or enter -1 to exit" << endl;
            }
            // If input was -1, apply filters to image
            else if(i == -1){
                cout << "Applying filters!" << endl;
                this->applyFilters(img);
            }
            // Catch any invalid inputs
            else{
                // Skip past a single line of invalid input
                cin.clear();
                cin.ignore(999, '\n');
                cout << "Invalid number entered. Please try again." << endl;
            }
        }

        n++;
        stringstream ss;
        // Create output file name
        ss << "EC_" << n << ".ppm";
        // Open output file
        ofstream out(ss.str());
        if(!out){
            cerr << "Could not open output file. Exiting..." << endl;
            exit(0);
        }
        // Clear stringstream to be used again
        ss.clear();
        // Write image to output file and close output file
        img.write_to(out);
        out.close();

        // Test if user wants to create another output image
        cout << "Make another image? Enter y or n" << endl;
        bool valid = false;
        // Loop to make sure user answer is valid
        while(!valid){
            // Clear c
            c = 0;
            // Get user answer
            cin >> c;
            // If user wants to continue
            if(c == 'y'){
                // Update to exit loop
                valid = true;
                // Reset i to 0
                i = 0;
                // Clear filters vector
                this->filters.clear();
                // Remove !eof flag from input file
                in.clear();
                // Reset pointer to beginning of input file
                in.seekg(0, ios::beg);

            }
            // If user wants to exit
            else if(c == 'n'){
                valid = true;
            }
            // User input invalid
            else{
                cout << "Invalid input. Please enter y or n" << endl;
            }
        }
    }
    // Close input file
    in.close();
}

// Takes the inputted int and adds the appropriate filter
// to the vector of Filter*
void Menu::addFilter(int f){
    bool v = 0;
    // Add a sharpen filter
    if(f == 1){
        this->filters.push_back(new SharpenFilter(""));
    }
    // Add a blur filter
    else if(f == 2){
        this->filters.push_back(new BlurFilter(""));
    }
    // Add an HFlipFilter
    else if(f == 3){
        this->filters.push_back(new HFlipFilter(""));
    }
    // Add a VFlipFilter
    else if(f == 4){
        this->filters.push_back(new VFlipFilter(""));
    }
    // Add a Binary Filter and get user colors
    else if(f == 5){
        while(!v){
            cout << "Please enter the integer rgb values between 0 " <<
                    "and 255 of the colors you want to use. " <<
                    "Integers not in this range will be clamped." << endl;
            int r1, g1, b1, r2, g2, b2;
            cin >> r1 >> g1 >> b1 >> r2 >> g2 >> b2;
            if(!cin){
                // Skip past a single line of invalid input
                cin.clear();
                cin.ignore(999, '\n');
                cout << "Invalid input. Please try again." << endl;
            }
            else{
              this->filters.push_back(new BinaryFilter(r1, g1, b1, r2, g2, b2));
              v = 1;
            }
        }
    }
    // Add a GrayScale filter
    else if(f == 6){
        this->filters.push_back(new GrayScaleFilter(""));
    }
    // Add a Sepia filter
    else if(f == 7){
        this->filters.push_back(new SepiaFilter(""));
    }
}

// Takes the input image and applies the filters from the
// vector of Filter* with polymorphism
void Menu::applyFilters(Image& img){
    unsigned int i = 0;
    // Applies each filter individually
    while(i < this->filters.size()){
        this->filters.at(i)->apply(img);
        i++;
    }
}
