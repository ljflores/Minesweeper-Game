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
    c = new Tile**[getxsize()]; //creating space for nows
    for (int i = 0;i<getxsize();i++){
        c[i] = new Tile*[getysize()];//creating space for colums
        for (int j = 0; j<getysize();j++){
            c[i][j] = new SquareTile();//fulling up the 2d array with square tiles;
        }

    }

}
