#include "GamePlan.h"

// The concrete class that is based on the GamePlan interface. Defines getters and setters for classes Rules,
// Board, Tile, and Generation.
class Game : public GamePlan {
private:
    Rules* gameRules;
    Board* gameBoard;
    Tile* gameTile;
    Generate* gameGeneration;
public:
    void setRules(Rules* rules) {gameRules = rules;}
    virtual void getRules() {gameRules->printRules();}

    void setBoard(Board* board) {gameBoard = board;}
    virtual void getBoard() {gameBoard->printBoard();}

    void setTile(Tile* tile) {gameTile = tile;}
    virtual void getTile() {gameTile->printTile();}

    void setGeneration(Generate* generation) {gameGeneration = generation;}
    virtual void getGeneration() {gameGeneration->printGenerate();}
};


