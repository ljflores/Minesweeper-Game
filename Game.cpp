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
    gameGeneration->printGenerate();
}
Board* Game::rboard() {
    return this->gameBoard;
}
//---------------------------------------------------------//
void Game::flipTile() {
    gameRules->flipTile();
}

void Game::flagTile() {
    gameRules->flagTile();
}

void Game::unflagTile() {
    gameRules->unflagTile();
}


