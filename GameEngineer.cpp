#include "SimpleSquareBuilder.cpp"
#include "AdvSquareBuilder.cpp"
#include "MediumSquareBuilder.cpp"
// This class creates a game using the builder interface that is defined.
class GameEngineer {
    GameBuilder* gameBuilder;
public:
    // SimpleSquareBuilder specification is sent to the engineer
    GameEngineer(GameBuilder *gameBuilder) {
        this->gameBuilder = gameBuilder;
    }

    // Return the Game made from the SimpleSquareBuilder spec
    Game* getGame() {
        return this->gameBuilder->getGame();;
    }

    // Execute the methods specific to the GameBuilder that implements
    // GameBuilder (SimpleSquareBuilder)
    void makeGame() {
        this->gameBuilder->buildRules();
        this->gameBuilder->buildBoard();
        this->gameBuilder->buildTile();
        this->gameBuilder->buildGeneration();
    }
};
