#include "Game.h"
using namespace std;

void Game::setRules(Rules *rules) {
    gameRules = rules;
}

Rules* Game::getRules() {
    return gameRules;
}

void Game::setBoard(Board *board) {
    gameBoard = board;
}

Board* Game::getBoard() {
    return gameBoard;
}

void Game::setTile(Tile *tile) {
    gameTile = tile;
}

Tile* Game::getTile() {
    return gameTile;
}

void Game::setGeneration(Generate *generation) {
    gameGeneration = generation;
}

Generate* Game::getGeneration() {
    return gameGeneration;
}
