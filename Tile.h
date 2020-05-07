#ifndef MINESWEEPERBUILDER_TILE_H
#define MINESWEEPERBUILDER_TILE_H
using namespace std;
#include<iostream>
// An interface that defines what all tiles must do.
class Tile {
    string status;
    int xcord;
    int ycord;
    bool isMine;//tells if tile is a mine
    string number; // underlying number (1, 2, 3) or letter (B) that indicates the bombs in the vicinity
                            // or a Bomb.
    string display; // what is actually displayed on the tile
    Tile** neighbors = new Tile*[8];

    int rowNeighbors[8];
    int colNeighbors[8];

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
    void setMine();

    void setCoord(int x,int y);//set the cordinates just in case
    int getXCoord();
    int getYCoord();
    Tile** getNeighbors();
    void setNeighbors();
    int getrowNeighbors(int i);//returns the number at a given index
    int getcolNeighbors(int i);//returns the number of col at given index
};

#endif //MINESWEEPERBUILDER_TILE_H
