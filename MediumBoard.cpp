#include "SquareTile.h"
#include "SquareBoard.h"
#include <iostream>
using namespace std;

// Defines what a MediumBoard board must do.
class MediumBoard : public SquareBoard {
private:

public:
    MediumBoard(): SquareBoard(10, 10, 9) {
    }
};

