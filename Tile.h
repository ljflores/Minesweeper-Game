#ifndef MINESWEEPERBUILDER_TILE_H
#define MINESWEEPERBUILDER_TILE_H
using namespace std;
#include<iostream>
// An interface that defines what all tiles must do.
class Tile {

public:
    Tile();
    ~Tile();

    virtual void printTile()=0; // print out the tile on the terminal
    virtual void changeDisplay(string s)=0; // changes what the tile displays
    virtual void setMine()=0; // Make a tile a mine
    virtual void setNeighbors()=0; // set the neighbors of a tile
};

#endif //MINESWEEPERBUILDER_TILE_H
