//
//  SimpleSquareRules.h
//  OOfinalproject
//
//  Created by James Christensen on 4/28/20.
//  Copyright © 2020 James Christensen. All rights reserved.
//
#include "Rules.h"


#ifndef SimpleSquareRules_h
#define SimpleSquareRules_h
class SimpleSquareRules : public Rules {
public:
    SimpleSquareRules();
    
    void printRules();
    int playGame();
    void rows_and_columns();
    void revealTile();
    void revealBomb();
};


#endif /* SimpleSquareRules_h */
