#include "GameEngineer.cpp"
int main() {
    // Get a GameBuilder of type SimpleSquareBuilder
    GameBuilder* simpleSquareGame = new SimpleSquareBuilder();

    // Pass the SimpleSquareBuilder specification to the engineer
    GameEngineer* gameEngineer = new GameEngineer(simpleSquareGame);

    // Tell the engineer to make the Game using the specifications of the
    // SimpleSquareBuilder class
    gameEngineer->makeGame();

    // The engineer returns the right robot based off of the spec sent to it.
    Game* firstGame = gameEngineer->getGame();

    cout<<"Game built."<<endl;
    firstGame->getRules();
    firstGame->getBoard();
    firstGame->getTile();
    firstGame->getGeneration();

    return 0;
}

