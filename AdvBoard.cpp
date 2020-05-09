#include "SquareBoard.h"
#include <iostream>
using namespace std;

// Defines what a Advanced board must do.
class AdvBoard : public SquareBoard {
    
public:
    AdvBoard(): SquareBoard(13, 13, 12) {
    }
};

