//
// Created by James Christensen on 5/9/20.
//

#include "Board.h"

Board::Board(int mines) {
    this->mines = mines;
}

int Board::getnummines()  {
    return mines;
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
