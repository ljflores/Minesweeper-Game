
#ifndef MINESWEEPERBUILDER_RULES_H
#define MINESWEEPERBUILDER_RULES_H

// An interface that define what all Rules should have. Can be inherited by SimpleSquareRules
//and other derived Rules classes.
class Rules {
    // instance variable to access the game that the player is currently playing
public:
    virtual void printRules()=0; // prints the rules out for the Player if they type in a key word, such as "rules".
                                 //     Should definitely be a pure virtual since the Rules description will be different
                                 //     for each type of game.
    // flipTile();               // No "virtual" because flipTile() will likely be the same implementation
                                // across the board for all types of games. We can provide implementation in the Rules class.
    // flagTile(); // same as above
    // unflagTile(); // same as above
//-----------------------HINTS---------------------------//
    // revealTile();
    // revealBomb(); // Not sure yet if these should be pure virtual or not. Depends on whether we want to require
                     // all derived Rules classes to implement them, or if we would rather decide on a case-by-case
                     // basis.
};

#endif //MINESWEEPERBUILDER_RULES_H


// The Rules class needs to have methods in it that allow the user to use hints, such as revealing a tile to see
// what's under it, or revealing one bomb with no penalties.

// It also might involve methods like flipTile(), flagTile(), unflagTile(), etc. Basically, just methods that are
// accessed after the game is constructed and the user is actually playing the game.

// We also might want to have a method that prints the rules out for the user, like in a paragraph, if they don't
// know how to play the game.