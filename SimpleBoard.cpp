#include "SquareTile.h"
#include "Board.h"
#include <iostream>
using namespace std;

// Defines what a Simple board must do.
class SimpleBoard : public Board {
private:
public:
    SimpleBoard()
    :Board(7,7,1) {}

    void printBoard() {
        cout<<"    ";
        for (int k = 1;k<8;k++){ // printing column numbers
            cout<<k<<"  ";
        }
        cout<<endl;
        for(int i = 0; i < 7 ;i++){ // printing row numbers
            cout<<i+1<<"  ";
            for (int j = 0;j<7;j++){
                get2dArray()[i][j]->printTile(); // printing the tile shape, which is, for now, 2 brackets.
            }
            cout<<endl;
        }
    }
    Tile* GetTileAtPoint(int x,int y){
        return get2dArray()[y-1][x-1];
    }

};

