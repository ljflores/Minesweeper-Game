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
