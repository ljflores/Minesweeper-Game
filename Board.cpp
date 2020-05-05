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

    //c = new Tile**[getxsize()]; //creating space for columns
    set2dArray(getxsize());

    for (int i = 0;i<getxsize();i++){
        get2dArray()[i] = new Tile*[getysize()];//creating space for rows

        for (int j = 0; j<getysize();j++){
            get2dArray()[i][j] = new SquareTile();//filling up the 2d array with square tiles;
            get2dArray()[i][j]->setCoord(j+1,i+1);//just helping us remember the cords
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

