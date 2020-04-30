//
// Created by James Christensen on 4/30/20.
//

#include "Tile.h"
Tile::Tile(){

}
bool Tile::IsMine() {
    //just making it work, need to change later
    return false;
}
string Tile::GetStatus() {
    return this->status;
}
void Tile::SetStatus(string s) {
    this->status = s;
}