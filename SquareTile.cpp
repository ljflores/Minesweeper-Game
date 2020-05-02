#include "SquareTile.h"

SquareTile::SquareTile() {
    shape = "[ ]";
}
//method that changes the display of the tile
//to what ever you want it to be. 
void SquareTile::ChangeDisplay(string s) {
    shape = s;
}

void SquareTile::printTile() {
    cout<<shape;
}


