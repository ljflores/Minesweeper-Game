#include <iostream>
#include "Rules.h"
#include "Board.h"
#include "Tile.h"
#include "Generate.h"
#include "Rules.h"
using namespace std;

#ifndef MINESWEEPERBUILDER_GAMEPLAN_H
#define MINESWEEPERBUILDER_GAMEPLAN_H

// The interface that will be returned from the builder. All methods are pure virtual.
class GamePlan {
public:
    virtual void setRules(Rules* rules)=0;
    virtual void setBoard(Board* board)=0;
    virtual void setTile(Tile* tile)=0;
    virtual void setGeneration(Generate* generation)=0;
};

#endif //MINESWEEPERBUILDER_GAMEPLAN_H
