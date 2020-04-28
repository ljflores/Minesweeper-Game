//
//  AdvSquareBuilder.cpp
//  OOfinalproject
//
//  Created by James Christensen on 4/27/20.
//  Copyright © 2020 James Christensen. All rights reserved.
//

#include "GameBuilder.h"
#include "AdvSquareRules.h"

#include "AdvBoard.cpp"
#include "SquareTile.h"
#include "RandomGeneration.h"
// A  concrete builder class that assembles the parts of a specific type of game - in this case, Simple Square.
// There will be many more of these classes that define different types of games.
class AdvSquareBuilder : public GameBuilder {
    Game* game;
public:
    AdvSquareBuilder() {
        this->game = new Game();
    }

    void buildRules() {
        Rules* advsqrules = new AdvSquareRules();
        game->setRules(advsqrules);
    }

    void buildBoard() {
        Board* advBoard = new AdvBoard();
        game->setBoard(advBoard);
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


