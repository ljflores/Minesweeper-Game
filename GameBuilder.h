#include "Game.h"
#ifndef MINESWEEPERBUILDER_GAMEBUILDER_H
#define MINESWEEPERBUILDER_GAMEBUILDER_H

// Defines methods needed for creating parts of a Game. It's an interface with all pure virtuals.
class GameBuilder {
public:
    virtual void buildRules()=0;
    virtual void buildBoard()=0;
    virtual void buildTile()=0;
    virtual void buildGeneration()=0;

    virtual Game* getGame()=0;
};

#endif //MINESWEEPERBUILDER_GAMEBUILDER_H
