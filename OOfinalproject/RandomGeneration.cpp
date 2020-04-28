#include "Generate.h"
#include <iostream>
using namespace std;

// Defines what a random generation must do.
class RandomGeneration : public Generate {
public:
    RandomGeneration() {}

    void printGenerate() {
        cout<<"Randomly generated"<<endl;
    }
};

