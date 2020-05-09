//
//  Game.h
//  OOfinalproject
//
//  Created by James Christensen on 4/28/20.
//  Copyright © 2020 James Christensen. All rights reserved.
//

#ifndef Game_h
#define Game_h
#include <iostream>
#include "Rules.h"
#include "SquareBoard.h"
#include "Tile.h"
#include "Generate.h"
using namespace std;
// The concrete class that is based on the GamePlan interface. Defines getters and setters for classes Rules,
// SquareBoard, Tile, and Generation.
class Game {
private:
    Rules* gameRules;
    SquareBoard* gameBoard;
    Tile* gameTile;
    Generate* gameGeneration;
public:
// Setters and getters //
    void setRules(Rules*);
    void getRules();
    void setBoard(SquareBoard*);
    void getBoard();
    void setTile(Tile*);
    void getTile();
    void setGeneration(Generate*);
    void getGeneration();


    SquareBoard* rboard();//returns the board

    int playGame(); // handles user input to make changes to the game
};

#endif /* Game_h */
