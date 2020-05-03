#ifndef MINESWEEPERBUILDER_TILE_H
#define MINESWEEPERBUILDER_TILE_H
using namespace std;
#include<iostream>
// An interface that defines what all tiles must do.
class Tile {
    string status;
 //   int xcord;
 //   int ycord;
    int track; // keeps track of which tile to reference
    bool isMine;//tells if tile is a mine
    string number; // underlying number (1, 2, 3) or letter (B) that indicates the bombs in the vicinity
                            // or a Bomb.
    string display; // what is actually displayed on the tile

public:
    Tile();

    void setDisplay(string n);
    string getDisplay();

    void setNumber(string n);
    string getNumber();

    void setStatus(string s);//sets status of string
    string getStatus();//gets status of Tiles

    virtual void printTile()=0;

    virtual void changeDisplay(string s)=0; // changes what the tile displays

    bool IsMine(); //checks if tile is a mine

    void setTrack(int t); // assigns a number to the tile to keep track of it
    int getTrack();

    /*
    void setCoord(int x,int y);//set the cordinates just in case
    int getXCoord();
    int getYCoord();
    */
};

#endif //MINESWEEPERBUILDER_TILE_H
