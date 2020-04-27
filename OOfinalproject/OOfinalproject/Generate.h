
#ifndef MINESWEEPERBUILDER_GENERATE_H
#define MINESWEEPERBUILDER_GENERATE_H

// This interface defines what all Generations must do (Can be a Random generation, Planned generation, etc.)
class Generate {
public:
    virtual void printGenerate()=0;
};

#endif //MINESWEEPERBUILDER_GENERATE_H
