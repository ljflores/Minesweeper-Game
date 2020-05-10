//
//  SimpleSquareRules.h
//  OOfinalproject
//
//  Created by James Christensen on 4/28/20.
//  Copyright © 2020 James Christensen. All rights reserved.
//
#include "SquareRules.h"


#ifndef SimpleSquareRules_h
#define SimpleSquareRules_h
class SimpleSquareRules : public SquareRules {
public:
    SimpleSquareRules();
    
    void printRules();
    int playGame();
    void revealTile();
    void revealBomb();
};


#endif /* SimpleSquareRules_h */
