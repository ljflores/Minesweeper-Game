#include "Rules.h"
#include "SquareBoard.h"

#ifndef MINESWEEPERBUILDER_RULES_H
#define MINESWEEPERBUILDER_RULES_H
<<<<<<<< HEAD:Rules.h
// An interface that define what all Rules should have. Can be inherited by SimpleSquareRules
//and other derived Rules classes.
class Rules {
========
// An interface that define what all SquareRules should have. Can be inherited by SimpleSquareRules
//and other derived SquareRules classes.
class SquareRules : public Rules {
>>>>>>>> parent of 5943f50... Changed the "Rules" class to be named "SquareRules":SquareRules.h
    SquareBoard* gameBoard;
    int row;
    int col;
    int flipTileNoInput(SquareTile* t); // accessed inside flipTile()

public:
    SquareRules();
    void rows_and_columns();

    SquareBoard* getBoard();
    void setBoard(SquareBoard* b);

    void setRow(int r);
    int getRow();
    int getCol();
    void setCol(int c);

    void printRules();

    void flipTile();
    void flagTile();
    void unflagTile();
};

<<<<<<<< HEAD:Rules.h
#endif //MINESWEEPERBUILDER_RULES_H


// The Rules class needs to have methods in it that allow the user to use hints, such as revealing a tile to see
// what's under it, or revealing one bomb with no penalties.

// It also might involve methods like flipTile(), flagTile(), unflagTile(), etc. Basically, just methods that are
// accessed after the game is constructed and the user is actually playing the game.

// We also might want to have a method that prints the rules out for the user, like in a paragraph, if they don't
// know how to play the game.
========
#endif //MINESWEEPERBUILDER_RULES_H
>>>>>>>> parent of 5943f50... Changed the "Rules" class to be named "SquareRules":SquareRules.h
