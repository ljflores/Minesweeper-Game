//
// Created by lajef on 5/9/2020.
//

#ifndef OBJECT_ORIENTED_SOFTWARE_DESIGN_FINAL_PROJECT_RULES_H
#define OBJECT_ORIENTED_SOFTWARE_DESIGN_FINAL_PROJECT_RULES_H


#include "SquareBoard.h"

class Rules {
    SquareBoard* gameBoard;
public:
    void setBoard(SquareBoard* b);
    SquareBoard* getBoard();

    virtual void flipTile()=0;
    virtual void flagTile()=0;
    virtual void unflagTile()=0;

    virtual void printRules()=0;
    virtual int playGame()=0;
};


#endif //OBJECT_ORIENTED_SOFTWARE_DESIGN_FINAL_PROJECT_RULES_H
