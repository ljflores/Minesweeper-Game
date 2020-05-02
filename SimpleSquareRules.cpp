//#include "Rules.h"
#include <iostream>
#include "SimpleSquareRules.h"

using namespace std;


SimpleSquareRules::SimpleSquareRules(){}

void SimpleSquareRules::printRules() {
    cout<<"Valid commands for a Simple Square game include: "<<endl;
    Rules::printRules();
    cout<<"\n";
}

int SimpleSquareRules::playGame() {
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


