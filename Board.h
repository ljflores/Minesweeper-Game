#include "SquareTile.h"
#ifndef MINESWEEPERBUILDER_BOARD_H
#define MINESWEEPERBUILDER_BOARD_H

// An interface that defines what all kinds of Boards need.
class Board {
private:
    int xsize;
    int ysize;
    int mines;
    int unflippedTracker; // Checks to see how many tiles are currently unflipped; will be referenced to know if the user won the game
    Tile ***c; //pointer to our 2D array

public:
    Board(int xsize,int ysize,int mines);

    virtual void printBoard()=0;
    // might consider making the destructors in base classes virtual to avoid memory leaks in derived classes.
    int getxsize();
    int getysize();
    int getnummines();
    virtual Tile* GetTileAtPoint(int x,int y)=0;
    void fillboardwithsquares();//fillboard will be the same for all types of boards
    //make a pure virtual to make sure all derived classes implement it.

    Tile*** get2dArray();
    void set2dArray(int size);
    void displayalltiles();
    void GenerateAllNeighbors();
    bool WithenBounds(int p);

    void setUnflippedTracker(int u);
    int getUnflippedTracker();
    void decrementUnflippedTracker();
};

#endif //MINESWEEPERBUILDER_BOARD_H
