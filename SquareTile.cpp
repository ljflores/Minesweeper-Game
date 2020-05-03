#include "SquareTile.h"

SquareTile::SquareTile(){
    shape = "[ ]";
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


