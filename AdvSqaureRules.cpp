//
//  AdvSqaureRules.cpp
//  OOfinalproject
//
//  Created by James Christensen on 4/28/20.
//  Copyright © 2020 James Christensen. All rights reserved.
//

#include "AdvSquareRules.h"
#include "iostream"
using namespace std;

AdvSquareRules::AdvSquareRules(){}

void AdvSquareRules::printRules(){
    cout<<"Valid commands for a Advanced Square game include: "<<endl;
    Rules::printRules();
    cout<<"(6) revealT -- reveals one tile of your choosing"<<endl;
    cout<<"(7) revealB -- reveals 1 bomb of your choosing"<<endl;
    cout<<"\n";
}

int AdvSquareRules::playGame() {
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
        else if (command == "revealT") {
            this->revealTile();
        }
        else if (command == "revealB") {
            this->revealBomb();
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

void AdvSquareRules::revealTile() {
    cout<<"Tile revealed."<<endl;
}

void AdvSquareRules::revealBomb() {
    cout<<"Bomb revealed"<<endl;
}
