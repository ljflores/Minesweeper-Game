
#ifndef MINESWEEPERBUILDER_GENERATE_H
#define MINESWEEPERBUILDER_GENERATE_H
#include "SquareBoard.h"
// This interface defines what all Generations must do (Can be a Random generation, Planned generation, etc.)
class Generate {
    SquareBoard* gameBoard;
public:
    void setBoard(SquareBoard* b);
    SquareBoard* getBoard();
    virtual void setBombs()=0;
};

#endif //MINESWEEPERBUILDER_GENERATE_H
