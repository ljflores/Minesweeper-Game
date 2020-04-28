#include "Rules.h"
#include <iostream>
using namespace std;

// Rules that apply to a Simple Square Game; inherits the Rules interface.
class SimpleSquareRules : public Rules {
public:
    SimpleSquareRules() {}

    void printRules() {
        cout<<"Simple square rules"<<endl;
    }
};

