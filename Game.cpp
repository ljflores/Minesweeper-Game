#include "Game.h"
//using namespace std;


void Game::setRules(SquareRules *rules) {
    gameRules = rules;
}

void Game::getRules() {
    return gameRules->printRules();
}

void Game::setBoard(SquareBoard *board) {
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

SquareBoard* Game::rboard() {
    return this->gameBoard;
}
//---------------------------------------------------------//

int Game::playGame() {
    cout<<"Game built."<<endl;

    this->getRules();
    this->getBoard();
    this->getTile();

    gameGeneration->setBoard(this->rboard());
    gameGeneration->setBombs();
    cout<<"--------------------------------------------------------------------------------"<<endl;
    gameRules->setBoard(gameGeneration->getBoard());
    gameRules->playGame(); // see SquareRules.cpp for implementation
    return 0;
}


