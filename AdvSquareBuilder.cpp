//
//  AdvSquareBuilder.cpp
//  OOfinalproject
//
//  Created by James Christensen on 4/27/20.
//  Copyright © 2020 James Christensen. All rights reserved.
//

#include "GameBuilder.h"
#include "SimpleSquareRules.cpp"
#include "AdvBoard.cpp"
#include "SquareTile.cpp"
#include "RandomGeneration.cpp"

// A  concrete builder class that assembles the parts of a specific type of game - in this case, Simple Square.
// There will be many more of these classes that define different types of games.
class AdvSquareBuilder : public GameBuilder {
    Game* game;
public:
    AdvSquareBuilder() {
        this->game = new Game();
    }

    void buildRules() {
        Rules* simpleSquareRules = new SimpleSquareRules();
        game->setRules(simpleSquareRules);
    }

    void buildBoard() {
        Board* AdvBoard = new AdvBoard();
        game->setBoard(AdvBoard);
    }

    void buildTile() {
        Tile* squareTile = new SquareTile();
        game->setTile(squareTile);
    }

    void buildGeneration() {
        Generate* randomGeneration = new RandomGeneration();
        game->setGeneration(randomGeneration);
    }

    Game* getGame() {
        return this->game;
    }
};

