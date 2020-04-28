
#include "Board.h"
#include <iostream>
using namespace std;

// Defines what a MediumBoard board must do.
class MediumBoard : public Board {
    
public:
    MediumBoard():Board(10,10,1) {
        
    }

    void printBoard() {
        cout<<"X value: " << this->getxsize()<<endl;
        cout<<"Y value: " << this->getysize()<<endl;
        cout<<" # of mines" << this->getnummines()<<endl;
        cout<<"MediumBoard: 13x13"<<endl;
    }
};
