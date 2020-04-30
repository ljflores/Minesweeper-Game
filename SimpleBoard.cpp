#include "Board.h"
#include <iostream>
using namespace std;

// Defines what a Simple board must do.
class SimpleBoard : public Board {
    
public:
    SimpleBoard():Board(7,7,1) {
        
    }

    void printBoard() {
        cout<<"X value: " << this->getxsize()<<endl;
        cout<<"Y value: " << this->getysize()<<endl;
        cout<<" # of mines" << this->getnummines()<<endl;
        cout<<"Simple board: 7 x 7"<<endl;
    }
    Tile* GetTileAtPoint(int x,int y){
        return NULL;
        //have to fill in later
    }

};

