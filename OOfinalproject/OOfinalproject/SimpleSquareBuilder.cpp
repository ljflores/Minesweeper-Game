#include "GameBuilder.h"
#include "SimpleSquareRules.cpp"
#include "SimpleBoard.cpp"
#include "SquareTile.cpp"
#include "RandomGeneration.cpp"

// A  concrete builder class that assembles the parts of a specific type of game - in this case, Simple Square.
// There will be many more of these classes that define different types of games.
class SimpleSquareBuilder : public GameBuilder {
    Game* game;
public:
    SimpleSquareBuilder() {
        this->game = new Game();
    }

    void buildRules() {
        Rules* simpleSquareRules = new SimpleSquareRules();
        game->setRules(simpleSquareRules);
    }

    void buildBoard() {
        Board* simpleBoard = new SimpleBoard();
        game->setBoard(simpleBoard);
    }

    void buildTile() {
        Tile* squareTile = new SquareTile();
        game->setTile(squareTile);
    }

    void buildGeneration() {
        Generate* randomGeneration = new RandomGeneration();
        game->setGeneration(randomGeneration);
    }

    Game* getGame() {
        return this->game;
    }
};

