#include "Board.h"
#include <iostream>
using namespace std;

// Defines what a Advanced board must do.
class AdvBoard : public Board {
    
public:
    AdvBoard():Board(13,13,13) {
        
    }

    void printBoard() {

        cout<<"    ";
        for (int k = 1;k<14;k++){ // printing column numbers
            cout<<k<<"  ";
        }
        cout<<endl;
        for(int i = 0; i < 13;i++){ // printing row numbers
            cout<<i+1<<"  ";
            for (int j = 0;j<13;j++){
                get2dArray()[i][j]->printTile(); // printing the tile shape, which is, for now, 2 brackets.
            }
            cout<<endl;
        }
    }
    Tile* GetTileAtPoint(int x, int y){
        return get2dArray()[y-1][x-1];
    }

};

