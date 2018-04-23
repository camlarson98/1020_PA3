#include "Menu.h"

Menu::Menu(){}

Menu::~Menu(){}

void Menu::displayMenu(ifstream& in){
    //Temporary for testing
    Image puppy(in);
    //Vector of ints to hold inputs
    vector<int> input;
    int i = 0, j = 0;
    //Temporary
    cout << setw(70) << setfill(' ') << left << "Welcome!" << endl;
    //Temporary
    cout << "Which filter would you like to use? Enter -1 when finished" << endl;
    //Loop for entering and applying filters
    while(j != -1){
        
        //User input
        cin >> j;
        //Add user input to int array
        input.push_back(j);
        //If input was valid, continue
        if(input.at(i) > 0 && input.at(i) < 8){
            //this->addFilter(input.at(i));
        }
        //If input was -1, apply filters
        else if(input.at(i) == -1){
            cout << "Applying filters!" << endl;
            this->addFilter(input, puppy);
        }
        //Catch any invalid inputs
        else{
            cout << "Invalid number entered. Please try again." << endl;
            input.pop_back();
        }
        i++;
    }
    ofstream out("output.ppm");
    puppy.write_to(out);
}

void Menu::addFilter(vector<int> f, Image& img){
    //Filter* newFilter;
    for(int i = 0; i < f.size(); i++){
        if(f.at(i) == 1){
            this->filters.push_back(new SharpenFilter("Sharp"));
            static_cast<SharpenFilter*>(this->filters.at(i))->apply(img);
        }
            else if(f.at(i) == 2){
                this->filters.push_back(new BlurFilter("Blur"));
                static_cast<BlurFilter*>(this->filters.at(i))->apply(img);
            }
            else if(f.at(i) == 3){
                this->filters.push_back(new HFlipFilter("HFlip"));
                static_cast<HFlipFilter*>(this->filters.at(i))->apply(img);
            }
            else if(f.at(i) == 4){
                this->filters.push_back(new VFlipFilter("VFlip"));
                static_cast<VFlipFilter*>(this->filters.at(i))->apply(img);
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
            /*case 5: Filter* newFilter = new BinaryFilter("Binary");
            case 6: Filter* newFilter = new GrayScaleFilter("Gray");
            case 7: Filter* newFilter = new SepiaFilter("Sepia");
            default: Filter* newFilter = 0;
                 break;
        }*/
    }
    //this->filters.push_back(newFilter);
}

void Menu::applyFilters(int i, Image& img){
    int j = 0;
    while(i > 0){
        
        i--;
    }
}