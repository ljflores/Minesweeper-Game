//
//  RandomGeneration.h
//  OOfinalproject
//
//  Created by James Christensen on 4/28/20.
//  Copyright © 2020 James Christensen. All rights reserved.
//

#ifndef RandomGeneration_h
#define RandomGeneration_h
#include "Generate.h"
#include <iostream>
using namespace std;

// Defines what a random generation must do.
class RandomGeneration : public Generate {
public:
    RandomGeneration();

    int * shuffle(int upperBound);
    void setBombs();
};



#endif /* RandomGeneration_h */
