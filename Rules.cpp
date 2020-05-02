//
// Created by lajef on 4/30/2020.
//

#include "Rules.h"

void Rules::flipTile() {
    this->rows_and_columns();

    Tile* t = this->getBoard()->GetTileAtPoint(this->getCol(),this->getRow());
    t->ChangeDisplay("[x]");
    this->getBoard()->printBoard();
    cout<<"Row: "<<t->getycord()<<endl;
    cout<<"Column: "<<t->getxcord()<<endl;

    cout<<"Tile flipped."<<endl;
}

void Rules::flagTile() {
    this->rows_and_columns();

    Tile* t = this->getBoard()->GetTileAtPoint(this->getCol(),this->getRow());
    t->ChangeDisplay("[f]");
    this->getBoard()->printBoard();
    cout<<"Row: "<<t->getycord()<<endl;
    cout<<"Column: "<<t->getxcord()<<endl;

    cout<<"Tile flagged."<<endl;
}

void Rules::unflagTile() {
    this->rows_and_columns();

    Tile* t = this->getBoard()->GetTileAtPoint(this->getCol(),this->getRow());
    t->ChangeDisplay("[u]");
    this->getBoard()->printBoard();
    cout<<"Row: "<<t->getycord()<<endl;
    cout<<"Column: "<<t->getxcord()<<endl;

    cout<<"Tile unflagged."<<endl;
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

void Rules::setRow(int r) {
    row = r;
}

void Rules::setCol(int c) {
    col = c;
}

int Rules::getRow() {
    return row;
}

int Rules::getCol() {
    return col;
}
