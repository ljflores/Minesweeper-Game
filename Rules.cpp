//
// Created by lajef on 4/30/2020.
//

#include "Rules.h"

void Rules::flipTile() {
    cout<<"Tile flipped."<<endl; // Print statements for now. Will need implementation later.

    Tile* t = this->getBoard()->GetTileAtPoint(1,2);
    t->ChangeDisplay("x ");
    this->getBoard()->printBoard();
    cout<<"X: "<<t->getxcord()<<endl;
    cout<<"Y: "<<t->getycord()<<endl;
}

void Rules::flagTile() {
    cout<<"Tile flagged."<<endl;

    Tile* t = this->getBoard()->GetTileAtPoint(1,2);
    t->ChangeDisplay("f ");
    this->getBoard()->printBoard();
    cout<<"X: "<<t->getxcord()<<endl;
    cout<<"Y: "<<t->getycord()<<endl;
}

void Rules::unflagTile() {
    cout<<"Tile unflagged."<<endl;

    Tile* t = this->getBoard()->GetTileAtPoint(1,2);
    t->ChangeDisplay("[]");
    this->getBoard()->printBoard();
    cout<<"X: "<<t->getxcord()<<endl;
    cout<<"Y: "<<t->getycord()<<endl;
}

void Rules::printRules() {
    cout<<"(1) flip -- flips a tile of your choosing"<<endl;
    cout<<"(2) flag -- flags a tile of your choosing"<<endl;
    cout<<"(3) unflag -- unflags a tile of your choosing"<<endl;
    cout<<"(4) rules -- prints the rules"<<endl;
    cout<<"(5) stop -- stops the game"<<endl;
}

void Rules::setBoard(Board *b) {
    gameBoard = b;
}

Board *Rules::getBoard() {
    return gameBoard;
}
