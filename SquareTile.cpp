#include "SquareTile.h"
#include <sstream>

SquareTile::SquareTile(){
    status = "unflipped"; // when the board is initialized, all the tiles are unflipped.
    isMine = false; // at first, all the mines are safe.
    number = "0"; // all tiles are marked with a 0 since all of the tiles are currently safe.
    display = " "; // since the tiles are all initially unflipped, there should be no number or letter displayed on the tile.
    bombTracker = 0;
    shape = "[ ]";
}

SquareTile::~SquareTile() {
    cout<<"SquareTile destructor. For testing"<<endl;
    for (int i=0; i<9; i++) {
        delete neighbors[i]; // neighbors is a double pointer on the heap,
                                // so each pointer needs to be deleted.
    }
}

//method that changes the display of the tile
//to what ever you want it to be. 
void SquareTile::changeDisplay(string s) {
    this->setDisplay(s);
    shape = "[" + this->getDisplay() + "]";
}

void SquareTile::printTile() {
    cout<<shape;
}

void SquareTile::setDisplay(string n) {
    this->display = n;
}

string SquareTile::getDisplay() {
    return this->display;
}

void SquareTile::setNumber(string n) {
    number = n;
}

string SquareTile::getNumber() {
    return number;
}

string SquareTile::getStatus() {
    return this->status;
}
void SquareTile::setStatus(string s) {
    this->status = s;
}

bool SquareTile::IsMine() {
    return isMine;
}

void SquareTile::setCoord(int x,int y){
    this->xcord = x;
    this->ycord = y;
}
int SquareTile::getXCoord() {
    return this->xcord;
}
int SquareTile::getYCoord() {
    return this->ycord;
}

SquareTile **SquareTile::getNeighbors() {
    return neighbors;
}

void SquareTile::setMine() {
    this->isMine = true;
    this->number = "B";
    this->bombTracker = 1;
    SquareTile* t;
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

void SquareTile::setNeighbors() {
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

int SquareTile::getrowNeighbors(int i) {
    return rowNeighbors[i];
}

int SquareTile::getcolNeighbors(int i) {
    return colNeighbors[i];
}

void SquareTile::setBombTracker(int i) {
    bombTracker = i;
}

int SquareTile::getBombTracker() {
    return bombTracker;
}


