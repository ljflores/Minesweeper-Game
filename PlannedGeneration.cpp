//
// Created by lajef on 5/2/2020.
//

#include "PlannedGeneration.h"

PlannedGeneration::PlannedGeneration() {}

void PlannedGeneration::setBombs() {
    int PNumMines = this ->getBoard()->getnummines();
    switch (PNumMines){
        case 5:
            setBombshelper(1,1);
            setBombshelper(7,7);
            setBombshelper(3,3);
            setBombshelper(2,3);
            setBombshelper(5,5);
            break;
        case 9:
            setBombshelper(1,1);
            setBombshelper(10,10);
            setBombshelper(2,1);
            setBombshelper(5,5);
            setBombshelper(3,3);
            setBombshelper(9,4);
            setBombshelper(3,5);
            setBombshelper(4,1);
            setBombshelper(6,1);
            break;
        case 12:
            setBombshelper(1,1);
            setBombshelper(10,10);
            setBombshelper(2,1);
            setBombshelper(5,5);
            setBombshelper(3,3);
            setBombshelper(9,4);
            setBombshelper(3,5);
            setBombshelper(4,1);
            setBombshelper(6,1);
            setBombshelper(13,13);
            setBombshelper(12,1);
            setBombshelper(2,10);
            break;
    }

}

void PlannedGeneration::setBombshelper(int x, int y) {
    Tile *t;
    t = this->getBoard()->GetTileAtPoint(x,y);
    t->setMine();
}



