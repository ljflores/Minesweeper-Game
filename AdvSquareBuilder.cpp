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
        Rules* advsqrules = new AdvSquareRules(game->rboard()); // sends the board to the Rules class
        game->setRules(advsqrules);
    }
    
    void buildTile() {
        Tile* squareTile = new SquareTile();
        game->setTile(squareTile);
    }
    void buildBoard() {
        Board* advBoard = new AdvBoard();
        advBoard->fillboardwithsquares();//fills board with square tiles
        game->setBoard(advBoard);
    }

    

    void buildGeneration() {
        Generate* randomGeneration = new RandomGeneration();
        game->setGeneration(randomGeneration);
    }

    Game* getGame() {
        return this->game;
    }
};


