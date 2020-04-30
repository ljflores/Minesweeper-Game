#include "SquareTile.h"

SquareTile::SquareTile() {
    shape = "[]";
}
//this method is just a temp method
void SquareTile::setshape(string s){
    shape = s;
}

void SquareTile::printTile() {
    cout<<shape;
}


