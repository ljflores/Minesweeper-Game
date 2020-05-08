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

AdvSquareRules::AdvSquareRules()
:Rules() {}

void AdvSquareRules::printRules(){
    cout<<"Valid commands for a Advanced Square game include: "<<endl;
    Rules::printRules();
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
        else if (command == "stop") {
            cout<<"Thank You For Playing our Advanced Square Game"<<endl<<"Here is the Board with all the tiles flipped"<<endl;
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

void AdvSquareRules::rows_and_columns() {
    int gameRow = 0;
    int gameCol = 0;

    bool keepGoing = true;
    while (keepGoing) {
        cout << "What row would you like? Enter a number between 1 and 13: " << endl;
        cin >> gameRow;
        if ((gameRow < 1) || (gameRow > 13)) {
            cout << "Please enter a number in the correct range." << endl;
        } else {
            break;
        }
    }
    while (keepGoing) {
        cout<<"What column would you like? enter a number between 1 and 13: "<<endl;
        cin >> gameCol;
        if ((gameCol < 1) || (gameCol > 13)) {
            cout << "Please enter a number in the correct range." << endl;
        }
        else {
            break;
        }
    }

    this->setRow(gameRow);
    this->setCol(gameCol);
}
