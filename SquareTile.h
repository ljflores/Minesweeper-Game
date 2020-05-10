//
//  SquareTile.h
//  OOfinalproject
//
//  Created by James Christensen on 4/28/20.
//  Copyright © 2020 James Christensen. All rights reserved.
//

#ifndef SquareTile_h
#define SquareTile_h
#include "Tile.h"
#include <iostream>
using namespace std;

// Defines what makes a square tile.
class SquareTile : public Tile {
private:
    string shape;
    string status;
    int xcord;
    int ycord;
    bool isMine;//tells if tile is a mine
    string number; // underlying number (1, 2, 3) or letter (B) that indicates the bombs in the vicinity
    // or a Bomb.
    string display; // what is actually displayed on the tile
    SquareTile** neighbors = new SquareTile*[8];
    int rowNeighbors[8];
    int colNeighbors[8];
    int bombTracker;

public:
    SquareTile();
    ~SquareTile();

    void setDisplay(string n);
    string getDisplay();

    void setNumber(string n);
    string getNumber();

    void setStatus(string s);//sets status of string
    string getStatus();//gets status of Tiles

    bool IsMine(); //checks if tile is a mine
    void setMine();

    void setCoord(int x,int y);//set the cordinates just in case
    int getXCoord();
    int getYCoord();

    SquareTile** getNeighbors();
    void setNeighbors();

    int getrowNeighbors(int i);//returns the number at a given index
    int getcolNeighbors(int i);//returns the number of col at given index

    void setBombTracker(int i);
    int getBombTracker();

    void changeDisplay(string s);
    void printTile();
};

#endif /* SquareTile_h */
