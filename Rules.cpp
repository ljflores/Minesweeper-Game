//
// Created by lajef on 4/30/2020.
//

#include "Rules.h"

void Rules::flipTile() {
    this->rows_and_columns();

    Tile* t = this->getBoard()->GetTileAtPoint(this->getCol(),this->getRow());

    if (t->getStatus() == "unflipped") {
        t->changeDisplay(t->getNumber()); // change the display to show the underlying number / bomb
        t->setStatus("flipped"); // update the status
        this->getBoard()->printBoard();

        cout<<"Row: "<<t->getYCoord()<<endl;
        cout<<"Column: "<<t->getXCoord()<<endl;
        cout<<"Tile flipped."<<endl;
    }
    else {
        cout<<"Tile cannot be flipped."<<endl;
    }

}

void Rules::flagTile() {
    this->rows_and_columns();

    Tile* t = this->getBoard()->GetTileAtPoint(this->getCol(),this->getRow());

    if (t->getStatus() == "unflipped") {
        t->changeDisplay("f"); // change the tile display to indicate that it's flagged
        t->setStatus("flagged"); // update the status
        this->getBoard()->printBoard();

        cout<<"Row: "<<t->getYCoord()<<endl;
        cout<<"Column: "<<t->getXCoord()<<endl;
        cout<<"Tile flagged."<<endl;
    }

    else {
        cout<<"Tile cannot be flagged."<<endl;
    }

}

void Rules::unflagTile() {
    this->rows_and_columns();

    Tile* t = this->getBoard()->GetTileAtPoint(this->getCol(),this->getRow());

    if (t->getStatus() == "flagged") {
        t->changeDisplay(" "); // changes the display back to a blank tile
        t->setStatus("unflipped"); // updates the status back to unflipped
        this->getBoard()->printBoard();

        cout<<"Row: "<<t->getYCoord()<<endl;
        cout<<"Column: "<<t->getXCoord()<<endl;
        cout<<"Tile unflagged."<<endl;
    }

    else {
        cout<<"Tile cannot be unflagged."<<endl;
    }

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
