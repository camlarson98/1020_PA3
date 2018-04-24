#include "Menu.h"

Menu::Menu(){}

Menu::~Menu(){}

void Menu::displayMenu(ifstream& in){
    //Vector of ints to hold inputs
    //vector<int> input;
    int i = 0, j = 0, n = 0;
    char c = 'y';
    //Temporary
    cout << setw(70) << setfill(' ') << left << "Welcome!" << endl;
    while(c == 'y'){
        
        //Temporary for testing
        Image puppy(in);
        //Loop for entering and applying filters
        i = 0;
        //Temporary
        cout << "Which filter would you like to use? Enter -1 when finished\n1 = Sharpen\n2 = Blur\n \
3 = Horizontal flip\n4 = Vertical flip\n5 = Binary" << endl;
        while(j != -1){
            //User input
            cin >> j;
            //Add user input to int array
            //input.push_back(j);
            //If input was valid, continue
            if(j > 0 && j < 8){
                this->addFilter(j);
                cout << "Next filter? Or enter -1 to exit" << endl;
            }
            //If input was -1, apply filters
            else if(j == -1){
                //input.pop_back();
                i--;
                cout << "Applying filters!" << endl;
                this->applyFilters(puppy);
            }
            //Catch any invalid inputs
            else{
                cout << "Invalid number entered. Please try again." << endl;
                //input.pop_back();
                i--;
            }
            i++;
        }
        n++;
        stringstream ss;
        //Create output file name
        ss << "EC_" << n << ".ppm";
        ofstream out(ss.str());
        ss.clear();
        puppy.write_to(out);
        out.close();
        
        cout << "Make another image? Enter y or n" << endl;
        bool valid = false;
        while(!valid){
            c = 0;
            cin >> c;
            if(c == 'y'){
                valid = true;
                j = 0;
                //Clear filters vector
                this->filters.clear();
                //Remove !eof flag from input file
                in.clear();
                //Reset pointer to beginning of input file
                in.seekg(0, ios::beg);
                
            }
                else if(c == 'n'){
                    valid = true;
                }
                else{
                    cout << "Invalid input. Please enter y or n" << endl;
                }
        }
    }
    in.close();
}


void Menu::addFilter(int f){
    //Filter* newFilter;
    //for(unsigned int i = 0; i < this->filters.size(); i++){
        if(f == 1){
            //SharpenFilter Sharp("");
            this->filters.push_back(new SharpenFilter(""));
            cout << this->filters.size() << endl;
            //static_cast<SharpenFilter*>(this->filters.at(i))->apply(img);
        }
            else if(f == 2){
                this->filters.push_back(new BlurFilter(""));
                //static_cast<BlurFilter*>(this->filters.at(i))->apply(img);
            }
            else if(f == 3){
                this->filters.push_back(new HFlipFilter(""));
                //static_cast<HFlipFilter*>(this->filters.at(i))->apply(img);
            }
            else if(f == 4){
                this->filters.push_back(new VFlipFilter(""));
                //static_cast<VFlipFilter*>(this->filters.at(i))->apply(img);
            }
            else if(f == 5){
                cout << "Please enter the integer rgb values of the colors you want to use." << endl;
                int r1, g1, b1, r2, g2, b2;
                cin >> r1 >> g1 >> b1 >> r2 >> g2 >> b2;
                this->filters.push_back(new BinaryFilter(r1, g1, b1, r2, g2, b2));
                //static_cast<BinaryFilter*>(this->filters.at(i))->apply(img);
            }
        /*switch(f.at(i)){
            case 1: this->filters.push_back(new SharpenFilter("Sharp"));
                    static_cast<SharpenFilter*>(this->filters.at(i))->apply(img);
            case 2: this->filters.push_back(new BlurFilter("Blur"));
                    static_cast<BlurFilter*>(this->filters.at(i))->apply(img);
            case 3: this->filters.push_back(new HFlipFilter("HFlip"));
                    static_cast<HFlipFilter*>(this->filters.at(i))->apply(img);
            case 4: this->filters.push_back(new VFlipFilter("VFlip"));
                    static_cast<VFlipFilter*>(this->filters.at(i))->apply(img);
            case 5: Filter* newFilter = new BinaryFilter("Binary");
            case 6: Filter* newFilter = new GrayScaleFilter("Gray");
            case 7: Filter* newFilter = new SepiaFilter("Sepia");
            default: Filter* newFilter = 0;
                 break;
        }*/
    //}
    //cout << this->filters.size() << endl;
}

void Menu::applyFilters(Image& img){
    unsigned int i = 0;
    while(i < this->filters.size()){
        this->filters.at(i)->apply(img);
        i++;
    }
}