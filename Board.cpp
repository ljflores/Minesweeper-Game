//
//  Board.cpp
//  OOfinalproject
//
//  Created by James Christensen on 4/27/20.
//  Copyright © 2020 James Christensen. All rights reserved.
//

#include <stdio.h>
#include "Board.h"

using namespace std;

Board::Board(int xsize, int ysize,int mines){
    this->xsize = xsize;
    this->ysize = ysize;
    this->mines = mines;
    this->unflippedTracker = ((xsize * ysize) - mines); // initialized to the number of tiles in the board minus the number of mines
}
int Board::getxsize(){
    return this->xsize;
}
int Board::getysize(){
    return this->ysize;
}
int Board::getnummines(){
    return this->mines;
}

void Board::fillboardwithsquares() {
    set2dArray(getxsize());

    for (int i = 0;i<getxsize();i++){
        get2dArray()[i] = new Tile*[getysize()];//creating space for rows

        for (int j = 0; j<getysize();j++){
            get2dArray()[i][j] = new SquareTile();//filling up the 2d array with square tiles;
            get2dArray()[i][j]->setCoord(j+1,i+1);//just helping us remember the cords
            get2dArray()[i][j]->setNeighbors();
        }
    }

}

Tile ***Board::get2dArray() {
    return c;
}

void Board::set2dArray(int size) {
    c = new Tile**[size];
}
//this changes the display of all of the tiles to thier number 
void Board::displayalltiles() {
    Tile* t;
    for (int i = 0;i<getxsize();i++){
        for (int j = 0; j<getysize();j++){
           t = this->GetTileAtPoint(i+1,j+1);
           t->changeDisplay(t->getNumber());
        }
    }
}

void Board::GenerateAllNeighbors() {
    Tile* t;
    for (int i = 0; i<getxsize();i++){//goes through each file in array
        for (int j = 0;j<getysize();j++){
            t = this->GetTileAtPoint(i+1,j+1);//gets the current tile
            for(int k = 0;k<8;k++){//fills in the Neighbors array with all neighboring tiles.
                //makes sure the Neighbor is even within the bounds of the board
                if(WithenBounds(t->getrowNeighbors(k))==true && WithenBounds(t->getcolNeighbors(k))== true){
                    t->getNeighbors()[k]=this->GetTileAtPoint(t->getcolNeighbors(k),t->getrowNeighbors(k));
                }
                else{
                    t->getNeighbors()[k] = NULL;
                }
            }
        }
    }
}
//checks if the given int is whithin the boards bounds
bool Board::WithenBounds(int p){
    if (p >= 1 && p<=this->getysize()){
        return true;
    }
    else{
        return false;
    }
}

void Board::setUnflippedTracker(int u) {
    unflippedTracker = u;
}

int Board::getUnflippedTracker() {
    return unflippedTracker;
}

void Board::decrementUnflippedTracker() {
    unflippedTracker--;
}
