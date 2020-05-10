//
// Created by lajef on 5/2/2020.
//

#ifndef OBJECT_ORIENTED_SOFTWARE_DESIGN_FINAL_PROJECT_PLANNEDGENERATION_H
#define OBJECT_ORIENTED_SOFTWARE_DESIGN_FINAL_PROJECT_PLANNEDGENERATION_H
#include "Generate.h"
class PlannedGeneration : public Generate {
public:
    PlannedGeneration();
    void setBombs();
    void setBombshelper(int x,int y);
};

#endif //OBJECT_ORIENTED_SOFTWARE_DESIGN_FINAL_PROJECT_PLANNEDGENERATION_H
