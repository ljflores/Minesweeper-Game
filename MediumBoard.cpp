#include "SquareTile.h"
#include "Board.h"
#include <iostream>
using namespace std;

// Defines what a MediumBoard board must do.
class MediumBoard : public Board {
private:

public:
    MediumBoard():Board(10,10,10) {

    }
    void printBoard() {

        cout<<"    ";
        for (int k = 1;k<11;k++){ // printing column numbers
            cout<<k<<"  ";
        }
        cout<<endl;
        for(int i = 0; i < 10 ;i++){ // printing row numbers
            cout<<i+1<<"  ";
            for (int j = 0;j<10;j++){
                get2dArray()[i][j]->printTile(); // printing the tile shape, which is, for now, 2 brackets.
            }
            cout<<endl;
        }
    }

    //funtion to get a tile at a point.
    Tile* GetTileAtPoint(int x,int y){
        return get2dArray()[y-1][x-1];                 // maybe write a case to handle incorrect coordinates
    }
    
};


/* Notes:
 *      Maybe write a case to handle incorrect coordinates in GetTileAtPoint()
 *      Correct the Tile class so each Tile object contains information about their neighbors
 *      Do we need to consider making this a "MediumSquareBoard" class? Either that, or making "MediumBoard" more
 *         generalized, and creating another class called MediumSquareBoard to inherit MediumBoard.
 */