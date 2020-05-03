#include "Game.h"
//using namespace std;


void Game::setRules(Rules *rules) {
    gameRules = rules;
}

void Game::getRules() {
    return gameRules->printRules();
}

void Game::setBoard(Board *board) {
    gameBoard = board;
}

void Game::getBoard() {
    gameBoard->printBoard();
}

void Game::setTile(Tile *tile) {
    gameTile = tile;
}

void Game::getTile() {
    //gameTile->printTile();
}

void Game::setGeneration(Generate *generation) {
    gameGeneration = generation;
}

void Game::getGeneration() {
    gameGeneration->printBoard();
}
Board* Game::rboard() {
    return this->gameBoard;
}
//---------------------------------------------------------//

int Game::playGame() {
    gameRules->setBoard(this->rboard());
    gameRules->playGame(); // see Rules.cpp for implementation
    return 0;
}


