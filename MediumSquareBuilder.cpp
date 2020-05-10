//
//  MediumSquareBuilder.cpp
//  OOfinalproject
//
//  Created by James Christensen on 4/28/20.
//  Copyright © 2020 James Christensen. All rights reserved.
//


#include "GameBuilder.h"
#include "MediumSquareRules.h"

#include "MediumBoard.cpp"
#include "SquareTile.h"
#include "RandomGeneration.h"
#include "PlannedGeneration.h"
// A  concrete builder class that assembles the parts of a specific type of game - in this case, Medium Square.
// There will be many more of these classes that define different types of games.
class MediumSquareBuilder : public GameBuilder {
    Game* game;
public:
    MediumSquareBuilder() {
        this->game = new Game();
    }

    void buildRules() {
        SquareRules* mediumsquarerules = new MediumSquareRules();
        game->setRules(mediumsquarerules);
    }

    void buildBoard() {
        SquareBoard* mediumB = new MediumBoard();
        mediumB->FillBoardWithTiles();//builds the board with square tiles
        mediumB->GenerateAllNeighbors();
        game->setBoard(mediumB);
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



