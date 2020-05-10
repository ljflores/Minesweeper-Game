//
// Created by James Christensen on 5/9/20.
//

#ifndef OBJECT_ORIENTED_SOFTWARE_DESIGN_FINAL_PROJECT_BOARD_H
#define OBJECT_ORIENTED_SOFTWARE_DESIGN_FINAL_PROJECT_BOARD_H
#include "Tile.h"

class Board {
private:
    int mines;
    int unflippedTracker; // Checks to see how many tiles are currently unflipped; will be referenced to know if the user won the game
public:
    Board(int mines);
    int getnummines();
    void setUnflippedTracker(int u);
    int getUnflippedTracker();
    void decrementUnflippedTracker();

    virtual void printBoard()=0;
    virtual void FillBoardWithTiles()=0;//fillboard will be the same for all types of boards
    //make a pure virtual to make sure all derived classes implement it.
    virtual void displayalltiles()=0;
    virtual void GenerateAllNeighbors()=0;
};


#endif //OBJECT_ORIENTED_SOFTWARE_DESIGN_FINAL_PROJECT_BOARD_H
