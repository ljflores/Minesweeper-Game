
#ifndef MINESWEEPERBUILDER_RULES_H
#define MINESWEEPERBUILDER_RULES_H

// An interface that define what all Rules should have. Can be inherited by SimpleSquareRules
//and other derived Rules classes.
class Rules {
public:
    virtual void printRules()=0;
};

#endif //MINESWEEPERBUILDER_RULES_H
