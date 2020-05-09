#include "SquareBoard.h"
#include <iostream>
using namespace std;

// Defines what a Advanced board must do.
class AdvBoard : public SquareBoard {
    
public:
    AdvBoard(): SquareBoard(13, 13, 12) {
        
    }

    void printBoard() {

        cout<<"    ";
        for (int k = 1;k<9;k++){ // printing column numbers
            cout<<k<<"  ";
        }
        for (int k=9; k<14; k++) {
            cout<<k<<" ";
        }
        cout<<endl;
        for(int i = 0; i < 13;i++){ // printing row numbers
            //this if else statement just fixes the SquareBoard
            if(i+1 >= 10){
                cout<<i+1<<" ";
            }
            else {
                cout << i + 1 << "  ";
            }
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

