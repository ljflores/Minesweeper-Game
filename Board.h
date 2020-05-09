//
// Created by James Christensen on 5/9/20.
//

#ifndef OBJECT_ORIENTED_SOFTWARE_DESIGN_FINAL_PROJECT_BOARD_H
#define OBJECT_ORIENTED_SOFTWARE_DESIGN_FINAL_PROJECT_BOARD_H
#include "Tile.h"

class Board {
private:
    int mines;
public:
    Board(int mines);
    int getNumMines();
    virtual void printBoard()=0;
    virtual Tile* GetTileAtPoint(int x,int y)=0;
    virtual void fillboardwithsquares()=0;//fillboard will be the same for all types of boards //TODO: rename as "fillBoardWithTiles"
    //make a pure virtual to make sure all derived classes implement it.
    virtual void displayalltiles()=0;
    virtual void GenerateAllNeighbors()=0;
};


#endif //OBJECT_ORIENTED_SOFTWARE_DESIGN_FINAL_PROJECT_BOARD_H
