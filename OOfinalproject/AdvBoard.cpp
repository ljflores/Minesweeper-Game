#include "Board.h"
#include <iostream>
using namespace std;

// Defines what a Advanced board must do.
class AdvBoard : public Board {
    
public:
    AdvBoard():Board(13,13,1) {
        
    }

    void printBoard() {
        cout<<"X value: " << this->getxsize()<<endl;
        cout<<"Y value: " << this->getysize()<<endl;
        cout<<" # of mines" << this->getnummines()<<endl;
        cout<<"AdvancedBoard: 13X13 "<<endl;
    }
};

