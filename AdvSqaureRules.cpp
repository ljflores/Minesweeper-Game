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
    cout<<"\n";
}

int AdvSquareRules::playGame() {
    string command = "placeholder";
    bool keepGoing = true;
    while (keepGoing) {
        if(getBoard()->getUnflippedTracker() == 0) { // Checks to see if the user won the game
            cout<<endl<<endl;
            cout<<"Congratulations! You win."<<endl;
            this->getBoard()->displayalltiles();
            this->getBoard()->printBoard();//prints the board with all of the tiles flipped to revel bombs
            exit(0);
        }
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
            cout<<"Thank You For Playing our Advanced Square Game"<<endl<<"Here is the SquareBoard with all the tiles flipped"<<endl;
            this->getBoard()->displayalltiles();
            this->getBoard()->printBoard();//prints the board with all of the tiles flipped to revel bombs
            break;
        }
        else {
            cout<<"Please enter a correct command."<<endl;
        }
    }
    return 0;
}
