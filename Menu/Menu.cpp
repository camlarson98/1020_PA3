#include "Menu.h"

Menu::Menu(){}

Menu::~Menu(){}

void Menu::displayMenu(ifstream& in){
    // Variables for loops and tests
    int i = 0, n = 0;
    char c = 'y';
    // Needs to be fancied up
    cout << setw(70) << setfill(' ') << left << "Welcome!" << endl;
    // Loop to keep creating new images when the user wants to
    while(c == 'y'){
        // Initialize new image
        Image img(in);
        i = 0;
        // Temporary - needs to have the rest added when implemented
        cout << "Which filter would you like to use? Enter -1 when finished\n1 = Sharpen\n2 = Blur\n\
3 = Horizontal flip\n4 = Vertical flip\n5 = Binary" << endl;
        // loop to keep adding filters until -1 is entered
        while(i != -1){
            // User input
            cin >> i;
            // If input was valid, add that filter to Filter* vector
            if(i > 0 && i < 7){
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
                cout << "Invalid number entered. Please try again." << endl;
            }
        }
        n++;
        stringstream ss;
        // Create output file name
        ss << "EC_" << n << ".ppm";
        // Open output file
        ofstream out(ss.str());
        // Clear stringstream to be used again
        ss.clear();
        // Write image to output file and close output file
        img.write_to(out);
        out.close();
        
        //  Test if user wants to create another output image
        cout << "Make another image? Enter y or n" << endl;
        bool valid = false;
        //  Loop to make sure user answer is valid
        while(!valid){
            //  Clear c
            c = 0;
            //  Get user answer
            cin >> c;
            //  If user wants to continue
            if(c == 'y'){
                //  Update to exit loop
                valid = true;
                //  Reset i to 0
                i = 0;
                // Clear filters vector
                this->filters.clear();
                // Remove !eof flag from input file
                in.clear();
                // Reset pointer to beginning of input file
                in.seekg(0, ios::beg);
                
            }
                //  If user wants to exit
                else if(c == 'n'){
                    valid = true;
                }
                //  User input invalid
                else{
                    cout << "Invalid input. Please enter y or n" << endl;
                }
        }
    }
    //  Close input file
    in.close();
}


void Menu::addFilter(int f){
    if(f == 1){
        // SharpenFilter Sharp("");
        this->filters.push_back(new SharpenFilter(""));
        cout << this->filters.size() << endl;
        // static_cast<SharpenFilter*>(this->filters.at(i))->apply(img);
    }
        else if(f == 2){
            this->filters.push_back(new BlurFilter(""));
            // static_cast<BlurFilter*>(this->filters.at(i))->apply(img);
        }
        else if(f == 3){
            this->filters.push_back(new HFlipFilter(""));
            // static_cast<HFlipFilter*>(this->filters.at(i))->apply(img);
        }
        else if(f == 4){
            this->filters.push_back(new VFlipFilter(""));
            // static_cast<VFlipFilter*>(this->filters.at(i))->apply(img);
        }
        else if(f == 5){
            cout << "Please enter the integer rgb values of the colors you want to use." << endl;
            int r1, g1, b1, r2, g2, b2;
            cin >> r1 >> g1 >> b1 >> r2 >> g2 >> b2;
            this->filters.push_back(new BinaryFilter(r1, g1, b1, r2, g2, b2));
            // static_cast<BinaryFilter*>(this->filters.at(i))->apply(img);
        }    
}

void Menu::applyFilters(Image& img){
    unsigned int i = 0;
    //  Applies each filter individually
    while(i < this->filters.size()){
        this->filters.at(i)->apply(img);
        i++;
    }
}