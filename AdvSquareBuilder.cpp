//
//  AdvSquareBuilder.cpp
//  OOfinalproject
//
//  Created by James Christensen on 4/27/20.
//  Copyright © 2020 James Christensen. All rights reserved.
//

#include "GameBuilder.h"
#include "AdvSquareRules.h"

#include "SquareTile.h"
#include "RandomGeneration.h"
#include "PlannedGeneration.h"
// A  concrete builder class that assembles the parts of a specific type of game - in this case, Simple Square.
// There will be many more of these classes that define different types of games.
class AdvSquareBuilder : public GameBuilder {
    Game* game;
public:
    AdvSquareBuilder() {
        this->game = new Game();
    }

    void buildRules() {
        SquareRules* advsqrules = new AdvSquareRules();
        game->setRules(advsqrules);
    }
    
    void buildTile() {
        Tile* squareTile = new SquareTile();
        game->setTile(squareTile);
    }
    void buildBoard() {
        SquareBoard* advBoard = new SquareBoard(13, 13, 12);
        advBoard->FillBoardWithTiles();//fills board with square tiles
        advBoard->GenerateAllNeighbors();//generates neighbors for each tile
        game->setBoard(advBoard);
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


