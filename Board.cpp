//
// Created by James Christensen on 5/9/20.
//

#include "Board.h"

Board::Board(int mines) {
    this->mines = mines;
}

int Board::getNumMines() {
    return mines;
}
