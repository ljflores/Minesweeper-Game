
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
    int counter = 0;
 //   cout<<this->getBoard()->getnummines()<<endl;
    int *shuffledRows = this->shuffle(this->getBoard()->getysize());
    // testing which numbers are in the shuffled row array
    cout<<"Shuffled Rows:"<<endl;
    for(int i=0; i<this->getBoard()->getysize(); i++)
        cout<<shuffledRows[i]<<" ";
    cout<<"\n";
    //--------------------------------------------------------//
    int *shuffledCols = this->shuffle(this->getBoard()->getxsize());
    // testing which numbers are in the shuffled col array
    cout<<"Shuffled Cols:"<<endl;
    for(int i=0; i<this->getBoard()->getxsize(); i++)
        cout<<shuffledCols[i]<<" ";
    cout<<"\n";
    //--------------------------------------------------------------------//
    Tile *t;
    cout<<"Num mines: "<<this->getBoard()->getnummines()<<endl;
    for (int i=0; i<this->getBoard()->getnummines(); i++) {
        t = this->getBoard()->GetTileAtPoint(shuffledRows[i]+1, shuffledCols[i]+1);
        cout<<"Row: "<<shuffledRows[i]+1<<endl;
        cout<<"Column: "<<shuffledCols[i]+1<<endl;
        t->setMine();
        counter++;
    }
    cout<<counter<<endl;
}