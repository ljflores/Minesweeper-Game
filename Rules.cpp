//
// Created by lajef on 4/30/2020.
//

#include "Rules.h"

int Rules::flipTileNoInput(Tile *t) {

    if (t->getBombTracker() != 0) { // if the bombTracker is 1, 2, 3, etc:
        t->changeDisplay(t->getNumber()); // flip the tile, that's all.
        t->setStatus("flipped");
        getBoard()->decrementUnflippedTracker(); // unflippedTracker--
        return 0;
    }
    else { // if the bombTracker is 0, flip the tile and the tile's neighbors.
        t->changeDisplay(t->getNumber()); // flip the tile
        t->setStatus("flipped");
        getBoard()->decrementUnflippedTracker(); // unflippedTracker--

        Tile* n;
        for (int j=0; j<8; j++) { // looking at each of the tile's 8 neighbors
            n = t->getNeighbors()[j];
            if ((n != NULL) && !n->IsMine() && (n->getStatus() == "unflipped")) { // if the neighbor is a valid tile, is not a mine, and is unflipped
                n->changeDisplay(n->getNumber()); // flip the neighbor tile // flip the tile
                n->setStatus("flipped");
                flipTileNoInput(n); // send this tile in to get its neighbors checked as well.
            }
        }
        return 0;
    }
}

void Rules::flipTile() {
    this->rows_and_columns(); // asks for user input

    Tile* t = this->getBoard()->GetTileAtPoint(this->getCol(),this->getRow()); // gets the tile based on user input

    if (t->IsMine()) { // If you hit a mine, it exits the program and prints out the board.
        cout<<endl<<endl;
        cout<<"Game over. You hit a mine."<<endl;
        t->changeDisplay(t->getNumber()); // flip the tile
        this->getBoard()->printBoard();//prints the board with all of the tiles flipped to revel bombs
        exit(0);
    }

    if (t->getStatus() == "unflipped") {
        if (t->getBombTracker() != 0) { // Tile is safe, has a number other than 0.
            t->changeDisplay(t->getNumber()); // flip the tile and change the status.
            t->setStatus("flipped");
            getBoard()->decrementUnflippedTracker(); // unflippedTracker--
        }
        else { // If the tile is safe and has 0 bombs in its neighborhood:
            flipTileNoInput(t); // see above
        }
        this->getBoard()->printBoard();
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
