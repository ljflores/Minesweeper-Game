#include "Rules.h"

void Rules::setBoard(SquareBoard *b) {
    gameBoard = b;
}

SquareBoard *Rules::getBoard() {
    return gameBoard;
}
