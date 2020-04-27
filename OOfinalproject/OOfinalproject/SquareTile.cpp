#include "Tile.h"
#include <iostream>
using namespace std;

// Defines what makes a square tile.
class SquareTile : public Tile {
public:
    SquareTile() {}

    void printTile() {
        cout<<"Square tile"<<endl;
    }
};