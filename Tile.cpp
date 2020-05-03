//
// Created by James Christensen on 4/30/20.
//

#include "Tile.h"
Tile::Tile(){
    status = "unflipped"; // when the board is initalized, all the tiles are unflipped.
    isMine = false; // at first, all the mines are safe.
    number = "0"; // all tiles are marked with a 0 since all of the tiles are currently safe.
    display = " "; // since the tiles are all initially unflipped, there should be no number or letter displayed on the tile.
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
/*
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
*/

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

void Tile::setTrack(int t) {
    track = t;
}

int Tile::getTrack() {
    return track;
}

