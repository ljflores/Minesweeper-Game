//
//  SquareTile.h
//  OOfinalproject
//
//  Created by James Christensen on 4/28/20.
//  Copyright © 2020 James Christensen. All rights reserved.
//

#ifndef SquareTile_h
#define SquareTile_h
#include "Tile.h"
#include <iostream>
using namespace std;

// Defines what makes a square tile.
class SquareTile : public Tile {
public:
    SquareTile() {}

    void printTile() {
        cout<<"Square tile"<<endl;
    }
};


#endif /* SquareTile_h */
