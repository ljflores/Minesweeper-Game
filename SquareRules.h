#include "SquareBoard.h"
#ifndef MINESWEEPERBUILDER_RULES_H
#define MINESWEEPERBUILDER_RULES_H
// An interface that define what all SquareRules should have. Can be inherited by SimpleSquareRules
//and other derived SquareRules classes.
class SquareRules {
    SquareBoard* gameBoard;
    int row;
    int col;

public:
    virtual void rows_and_columns()=0;
    void setBoard(SquareBoard* b);
    void setRow(int r);
    int getRow();
    int getCol();
    void setCol(int c);

    SquareBoard* getBoard();

    virtual void printRules();
    virtual int playGame()=0;
    void flipTile();
    void flagTile();
    void unflagTile();

    int flipTileNoInput(Tile* t);
};

#endif //MINESWEEPERBUILDER_RULES_H


// The SquareRules class needs to have methods in it that allow the user to use hints, such as revealing a tile to see
// what's under it, or revealing one bomb with no penalties.

// It also might involve methods like flipTile(), flagTile(), unflagTile(), etc. Basically, just methods that are
// accessed after the game is constructed and the user is actually playing the game.

// We also might want to have a method that prints the rules out for the user, like in a paragraph, if they don't
// know how to play the game.