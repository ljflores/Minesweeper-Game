#include "SquareTile.h"
#include "Board.h"

#ifndef MINESWEEPERBUILDER_BOARD_H
#define MINESWEEPERBUILDER_BOARD_H

// An interface that defines what all kinds of Boards need.
class SquareBoard : public Board {
private:
    int xsize;
    int ysize;
    int unflippedTracker; // Checks to see how many tiles are currently unflipped; will be referenced to know if the user won the game
    Tile ***c; //pointer to our 2D array

public:
    SquareBoard(int xsize, int ysize, int mines);

    // might consider making the destructors in base classes virtual to avoid memory leaks in derived classes.
    int getxsize();
    int getysize();


    Tile*** get2dArray();
    void set2dArray(int size);

    bool WithenBounds(int p);

    void setUnflippedTracker(int u);
    int getUnflippedTracker();
    void decrementUnflippedTracker();
    void printBoard();
    Tile* GetTileAtPoint(int x,int y);
    void FillBoardWithTiles();//fillboard will be the same for all types of boards //TODO: rename as "fillBoardWithTiles"
    //make a pure virtual to make sure all derived classes implement it.
    void displayalltiles();
    void GenerateAllNeighbors();
};

#endif //MINESWEEPERBUILDER_BOARD_H
