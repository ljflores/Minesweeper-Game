#include "SquareTile.h"
#include "Board.h"
#include <iostream>
using namespace std;

// Defines what a MediumBoard board must do.
class MediumBoard : public Board {
private:
    SquareTile ***c;
public:
    MediumBoard():Board(10,10,1) {
        this->fillboard();
    }
    void printBoard() {
        cout<<" ";
        for (int k = 1;k<11;k++){
            cout<<k<<" ";
        }
        cout<<endl;
        for(int i = 0; i < 10 ;i++){
            cout<<i+1<<" ";
            for (int j = 0;j<10;j++){
                c[i][j]->printTile();
            }
            cout<<endl;
        }
    }
    void fillboard(){
        c = new SquareTile**[getxsize()];
        for(int i = 0; i < 10 ;i++){
            c[i] = new SquareTile*[getysize()];
            for (int j = 0;j<10;j++){
                c[i][j] = new SquareTile();
            }
        }
    }
    //funtion to get a tile at a point.
    Tile* GetTileAtPoint(int x,int y){
        return c[y-1][x-1];
    }
    
};
