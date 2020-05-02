//
//  MediumSquareRules.cpp
//  OOfinalproject
//
//  Created by James Christensen on 4/28/20.
//  Copyright © 2020 James Christensen. All rights reserved.
//

#include <stdio.h>
#include "MediumSquareRules.h"
#include <iostream>
using namespace std;
MediumSquareRules::MediumSquareRules(Board* b)
:Rules(b) {}

void MediumSquareRules::printRules(){
    cout<<"Valid commands for a Medium Square game include: "<<endl;
    Rules::printRules();
    cout<<"\n";
}

int MediumSquareRules::playGame() {
    string command = "placeholder";
    bool keepGoing = true;
    while (keepGoing) {
        cout<<"Enter a command: ";
        cin >> command;
        if (command == "flip") {
            this->flipTile();
        }
        else if (command == "flag") {
            this->flagTile();
        }
        else if (command == "unflag") {
            this->unflagTile();
        }
        else if (command == "rules") {
            this->printRules();
        }
        else if (command == "stop") {
            break;
        }
        else {
            cout<<"Please enter a correct command."<<endl;
        }
    }
    return 0;
}

