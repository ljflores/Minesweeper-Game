#include "GameBuilder.h"
#include "SimpleSquareRules.h"
#include "SimpleBoard.cpp"
#include "SquareTile.h"
#include "RandomGeneration.h"
#include "PlannedGeneration.h"
// A  concrete builder class that assembles the parts of a specific type of game - in this case, Simple Square.
// There will be many more of these classes that define different types of games.
class SimpleSquareBuilder : public GameBuilder {
    Game* game;
public:
    SimpleSquareBuilder() {
        this->game = new Game();
    }

    void buildRules() {
        SquareRules* simpleSquareRules = new SimpleSquareRules();
        game->setRules(simpleSquareRules);
    }

    void buildBoard() {
        SquareBoard* simpleBoard = new SimpleBoard();
        simpleBoard->FillBoardWithTiles();//fills board with square tiles
        simpleBoard->GenerateAllNeighbors();//generates the neighbors for each tile
        game->setBoard(simpleBoard);
    }

    void buildTile() {
        Tile* squareTile = new SquareTile();
        game->setTile(squareTile);
    }

    void buildGeneration() {
        cout<<"Do you want the generation to be Random or Planned"<<endl;
        cout<<"(1): Random Generation "<<endl<<"(2): Planned Generation"<<endl;
        int useri = 0;
        cin>>useri;
        while(useri < 1 || useri > 2){
            cout<<"You Entered in a incompatible number please try again"<<endl;
            cout<<"Do you want the generation to be Random or Planned"<<endl;
            cout<<"(1): Random Generation "<<endl<<"(2): Planned Generation"<<endl;
            cin>>useri;
        }
        if(useri == 1) {
            Generate *randomGeneration = new RandomGeneration();
            game->setGeneration(randomGeneration);
        }
        if(useri == 2){
            Generate *plannedGeneration = new PlannedGeneration();
            game->setGeneration(plannedGeneration);
        }
    }

    Game* getGame() {
        return this->game;
    }
};

