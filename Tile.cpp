//
// Created by James Christensen on 4/30/20.
//

#include "Tile.h"
#include <sstream>

Tile::Tile(){
    status = "unflipped"; // when the board is initialized, all the tiles are unflipped.
    isMine = false; // at first, all the mines are safe.
    number = "0"; // all tiles are marked with a 0 since all of the tiles are currently safe.
    display = " "; // since the tiles are all initially unflipped, there should be no number or letter displayed on the tile.
    bombTracker = 0;
}

bool Tile::IsMine() {
    return isMine;
}
string Tile::getStatus() {
    return this->status;
}
void Tile::setStatus(string s) {
    this->status = s;
}

void Tile::setCoord(int x,int y){
    this->xcord = x;
    this->ycord = y;
}
int Tile::getXCoord() {
    return this->xcord;
}
int Tile::getYCoord() {
    return this->ycord;
}

void Tile::setDisplay(string n) {
    this->display = n;
}

string Tile::getDisplay() {
    return this->display;
}

void Tile::setNumber(string n) {
    number = n;
}

string Tile::getNumber() {
    return number;
}

void Tile::setMine() {
    this->isMine = true;
    this->number = "B";
    this->bombTracker = 1;
    Tile* t;
   cout<<"("<<this->getYCoord()<<", "<<this->getXCoord()<<")"<<endl; //UNCOMMENT IF YOU WANT TO SEE THE BOMBS
    for (int i=0; i<8; i++) {
        t = this->getNeighbors()[i];
        if ((t != NULL) && !t->IsMine()) { // checks if the neighbor is valid AND is not a bomb itself
            //cout<<"("<<t->getYCoord()<<", "<<t->getXCoord()<<")"<<endl; // UNCOMMENT IF YOU WANT TO SEE THE NEIGHBORS
            t->setBombTracker(t->getBombTracker()+1);
            int num = t->getBombTracker();
            // change num to string
            string str;
            stringstream ss;
            ss << num;
            ss >> str;
            // set number to str
            t->setNumber(str);
        }
    }
}

Tile **Tile::getNeighbors() {
    return neighbors;
}

void Tile::setNeighbors() {
    int counter = 0;
    int CurrRow = this->getYCoord();
    int CurrCol = this->getXCoord();
    for (int i = CurrRow-1; i<= CurrRow+1; i++) {
        for (int j = CurrCol-1; j<= CurrCol+1; j++) {
            if (!((i == CurrRow) && (j == CurrCol))) {
                rowNeighbors[counter]=i;
                colNeighbors[counter]=j;
                counter++;
            }
        }
    }
}

int Tile::getrowNeighbors(int i) {
    return rowNeighbors[i];
}

int Tile::getcolNeighbors(int i) {
    return colNeighbors[i];
}

void Tile::setBombTracker(int i) {
    bombTracker = i;
}

int Tile::getBombTracker() {
    return bombTracker;
}
