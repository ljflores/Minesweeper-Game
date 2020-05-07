
#include "RandomGeneration.h"
#include <algorithm>    // std::random_shuffle
#include<time.h>

RandomGeneration::RandomGeneration() {}

void RandomGeneration::printBoard() {
    cout<<"Randomly generated."<<endl;
}

int * RandomGeneration::shuffle(int upperBound) {

    srand(time(0)); //srand(time(o)) will set the seed to current time
    //srand(100);    //srand(100) will set the seed to 100;

    //declare an array with a number of elements, elements, 0 to upperBound-1
    int *a = new int[upperBound];
    for(int i=0; i<upperBound; i++)
        a[i] = i;
    random_shuffle(a, a + upperBound);

    return a;
}

void RandomGeneration::setBombs() {
    int *shuffledRows = this->shuffle(this->getBoard()->getysize());
    int *shuffledCols = this->shuffle(this->getBoard()->getxsize());
    Tile *t;
    int j = getBoard()->getxsize()-1;
    for (int i=0; i<this->getBoard()->getnummines(); i++) {
        t = this->getBoard()->GetTileAtPoint(shuffledRows[i]+1,shuffledCols[j]+1);
        t->setMine();
        j--;
    }
}