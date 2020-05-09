//#include "Rules.h"
#include <iostream>
#include "SimpleSquareRules.h"

using namespace std;


SimpleSquareRules::SimpleSquareRules(){}

void SimpleSquareRules::revealTile() {
    this->rows_and_columns();

    Tile* t = this->getBoard()->GetTileAtPoint(this->getCol(),this->getRow());
    t->changeDisplay("r");
    this->getBoard()->printBoard();
    cout<<"Row: "<<t->getYCoord()<<endl;
    cout<<"Column: "<<t->getXCoord()<<endl;

    cout<<"Tile revealed."<<endl;
}

void SimpleSquareRules::revealBomb() {
    this->rows_and_columns();

    Tile* t = this->getBoard()->GetTileAtPoint(this->getCol(),this->getRow());
    t->changeDisplay("B");
    this->getBoard()->printBoard();
    cout<<"Row: "<<t->getYCoord()<<endl;
    cout<<"Column: "<<t->getXCoord()<<endl;

    cout<<"Bomb revealed."<<endl;
}

void SimpleSquareRules::rows_and_columns() {
    int gameRow = 0;
    int gameCol = 0;

    bool keepGoing = true;
    while (keepGoing) {
        cout << "What row would you like? Enter a number between 1 and 7: " << endl;
        cin >> gameRow;
        if ((gameRow < 1) || (gameRow > 7)) {
            cout << "Please enter a number in the correct range." << endl;
        }
        else {
            break;
        }
    }
    while (keepGoing) {
        cout<<"What column would you like? enter a number between 1 and 7: "<<endl;
        cin >> gameCol;
        if ((gameCol < 1) || (gameCol > 7)) {
            cout << "Please enter a number in the correct range." << endl;
        }
        else {
            break;
        }
    }

    this->setRow(gameRow);
    this->setCol(gameCol);
}

void SimpleSquareRules::printRules() {
    cout<<"Valid commands for a Simple Square game include: "<<endl;
    Rules::printRules();
    cout<<"(6) revealT -- reveals one tile of your choosing"<<endl;
    cout<<"(7) revealB -- reveals 1 bomb of your choosing"<<endl;
    cout<<"\n";
}

int SimpleSquareRules::playGame() {
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
        else if (command == "revealT") {
            this->revealTile();
        }
        else if (command == "revealB") {
            this->revealBomb();
        }
        else if (command == "stop") {
            cout<<endl<<endl;
            cout<<"Thank You For Playing our Simple Square Game"<<endl<<"Here is the Board with all the tiles flipped"<<endl;
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


