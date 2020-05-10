#ifndef MINESWEEPERBUILDER_TILE_H
#define MINESWEEPERBUILDER_TILE_H
using namespace std;
#include<iostream>
// An interface that defines what all tiles must do.
class Tile {

public:
    Tile();

    virtual void printTile()=0; // print out the tile on the terminal
    virtual void changeDisplay(string s)=0; // changes what the tile displays
    virtual void setMine()=0; // Make a tile a mine

    virtual bool IsMine()=0; // checks to see if a tile is a mine

    virtual int getBombTracker()=0;
    virtual void setBombTracker(int b)=0;
    virtual void setNumber(string n)=0;
    virtual string getNumber()=0;
    virtual void setStatus(string s)=0;
    virtual string getStatus()=0;
    virtual Tile** getNeighbors()=0;
    virtual void setNeighbors()=0; // set the neighbors of a tile
};

#endif //MINESWEEPERBUILDER_TILE_H
