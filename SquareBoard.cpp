//
//  SquareBoard.cpp
//  OOfinalproject
//
//  Created by James Christensen on 4/27/20.
//  Copyright © 2020 James Christensen. All rights reserved.
//

#include <stdio.h>
#include "SquareBoard.h"

using namespace std;

SquareBoard::SquareBoard(int xsize, int ysize, int mines)
: Board(mines){
    this->xsize = xsize;
    this->ysize = ysize;
    this->setUnflippedTracker(((xsize * ysize) - mines)); // initialized to the number of tiles in the board minus the number of mines
}
int SquareBoard::getxsize(){
    return this->xsize;
}
int SquareBoard::getysize(){
    return this->ysize;
}

void SquareBoard::FillBoardWithTiles() {
    set2dArray(getxsize());

    for (int i = 0;i<getxsize();i++){
        get2dArray()[i] = new SquareTile*[getysize()];//creating space for rows

        for (int j = 0; j<getysize();j++){
            get2dArray()[i][j] = new SquareTile();//filling up the 2d array with square tiles;
            get2dArray()[i][j]->setCoord(j+1,i+1);//just helping us remember the cords
            get2dArray()[i][j]->setNeighbors();
        }
    }

}

SquareTile ***SquareBoard::get2dArray() {
    return c;
}

void SquareBoard::set2dArray(int size) {
    c = new SquareTile**[size];
}
//this changes the display of all of the tiles to thier number 
void SquareBoard::displayalltiles() {
    SquareTile* t;
    for (int i = 0;i<getxsize();i++){
        for (int j = 0; j<getysize();j++){
           t = this->GetTileAtPoint(i+1,j+1);
           t->changeDisplay(t->getNumber());
        }
    }
}

void SquareBoard::GenerateAllNeighbors() {
    SquareTile* t;
    for (int i = 0; i<getxsize();i++){//goes through each file in array
        for (int j = 0;j<getysize();j++){
            t = this->GetTileAtPoint(i+1,j+1);//gets the current tile
            for(int k = 0;k<8;k++){//fills in the Neighbors array with all neighboring tiles.
                //makes sure the Neighbor is even within the bounds of the board
                if(WithenBounds(t->getrowNeighbors(k))==true && WithenBounds(t->getcolNeighbors(k))== true){
                    t->getNeighbors()[k]=this->GetTileAtPoint(t->getcolNeighbors(k),t->getrowNeighbors(k));
                }
                else{
                    t->getNeighbors()[k] = NULL;
                }
            }
        }
    }
}
//checks if the given int is whithin the boards bounds
bool SquareBoard::WithenBounds(int p){
    if (p >= 1 && p<=this->getysize()){
        return true;
    }
    else{
        return false;
    }
}

void SquareBoard::printBoard() {

    cout<<"    ";
    for (int k = 1;k<this->getysize()+1;k++){ // printing column numbers
        cout<<k<<"  ";
    }
    cout<<endl;
    for(int i = 0; i < this->getysize() ;i++){ // printing row numbers
        //this if else statement just fixes the SquareBoard
        if(i+1 >= this->getysize()){
            cout<<i+1<<" ";
        }
        else{
            cout << i + 1 << "  ";
        }
        for (int j = 0;j<this->getysize();j++){
            get2dArray()[i][j]->printTile(); // printing the tile shape, which is, for now, 2 brackets.
        }
        cout<<endl;
    }
}

SquareTile *SquareBoard::GetTileAtPoint(int x, int y) {
    return get2dArray()[y-1][x-1];
}
