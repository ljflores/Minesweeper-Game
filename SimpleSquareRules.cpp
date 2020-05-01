//#include "Rules.h"
#include <iostream>
#include "SimpleSquareRules.h"

using namespace std;


SimpleSquareRules::SimpleSquareRules(Board* b)
: Rules(b){}

void SimpleSquareRules::printRules() {
    cout<<"Simple square rules"<<endl;
}


