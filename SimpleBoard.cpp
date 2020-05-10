#include "SquareTile.h"
#include "SquareBoard.h"
#include <iostream>
using namespace std;

// Defines what a Simple board must do.
class SimpleBoard : public SquareBoard {
private:
public:
    SimpleBoard()
    : SquareBoard(7, 7, 5) {}
};

