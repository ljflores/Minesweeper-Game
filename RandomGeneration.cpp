
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
    cout<<"set bombs"<<endl;
    cout<<this->getBoard()->getnummines()<<endl;
    int *shuffledRows = this->shuffle(this->getBoard()->getysize());
    int *shuffledCols = this->shuffle(this->getBoard()->getxsize());

    for (int i=0; i<this->getBoard()->getnummines(); i++) {
        Tile *t = this->getBoard()->GetTileAtPoint(shuffledRows[i], shuffledCols[i]);
        cout<<"Row: "<<shuffledRows[i]<<endl;
        cout<<"Column: "<<shuffledCols[i]<<endl;
        t->setMine();
    }
}
