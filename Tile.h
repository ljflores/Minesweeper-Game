#ifndef MINESWEEPERBUILDER_TILE_H
#define MINESWEEPERBUILDER_TILE_H
using namespace std;
#include<iostream>
// An interface that defines what all tiles must do.
class Tile {
    string status;
public:
    Tile();
    virtual void printTile()=0;
    virtual void ChangeDisplay(string s)=0;//change the way the tile works
    bool IsMine();//checks if tile is a mine
    string GetStatus();//gets status of Tiles
    void SetStatus(string);//sets status of string
};

#endif //MINESWEEPERBUILDER_TILE_H
