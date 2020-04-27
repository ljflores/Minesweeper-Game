#include "Board.h"
#include <iostream>
using namespace std;

// Defines what a Simple board must do.
class SimpleBoard : public Board {
public:
    SimpleBoard() {}

    void printBoard() {
        cout<<"Simple board: 7 x 7"<<endl;
    }
};

