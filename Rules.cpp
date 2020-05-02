//
// Created by lajef on 4/30/2020.
//

#include "Rules.h"

void Rules::flipTile() {
    cout<<"Tile flipped."<<endl; // Print statements for now. Will need implementation later.
}

void Rules::flagTile() {
    cout<<"Tile flagged."<<endl;
}

void Rules::unflagTile() {
    cout<<"Tile unflagged."<<endl;
}

void Rules::printRules() {
    cout<<"(1) flip -- flips a tile of your choosing"<<endl;
    cout<<"(2) flag -- flags a tile of your choosing"<<endl;
    cout<<"(3) unflag -- unflags a tile of your choosing"<<endl;
    cout<<"(4) rules -- prints the rules"<<endl;
    cout<<"(5) stop -- stops the game"<<endl;
}
