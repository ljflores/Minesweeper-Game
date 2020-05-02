//
// Created by James Christensen on 4/30/20.
//

#include "Tile.h"
Tile::Tile(){
    this->mine = false;
}
bool Tile::IsMine() {
    //just making it work, need to change later
    return mine;
}
string Tile::GetStatus() {
    return this->status;
}
void Tile::SetStatus(string s) {
    this->status = s;
}
void Tile::SetCord(int x,int y){
    this->xcord = x;
    this->ycord = y;
}
int Tile::getxcord() {
    return this->xcord;
}
int Tile::getycord() {
    return this->ycord;
}

void Tile::SetDisplayVar(int n) {
    this->displayvar = n;
}

int Tile::GetDisplayVar() {
    return this->displayvar;
}
