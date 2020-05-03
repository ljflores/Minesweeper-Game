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
    int t = 1; // will update the track number

    c = new Tile**[getxsize()]; //creating space for columns

    for (int i = 0;i<getxsize();i++){
        c[i] = new Tile*[getysize()];//creating space for rows

        for (int j = 0; j<getysize();j++){
            c[i][j] = new SquareTile();//filling up the 2d array with square tiles;
            // c[i][j]->setCoord(j+1,i+1);//just helping us remember the cords
            c[i][j]->setTrack(t); // sets the track number for the tile
            t++; // increments the track number
        }
    }

}
