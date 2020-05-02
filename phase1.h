#ifndef PHASE1_PHASE1_H
#define PHASE1_PHASE1_H
#include <iostream>
using namespace std;

//------------All classes related to Game_Generate-------------------//
// Generate.h
class Generate {
public:
    virtual void printGenerate()=0;
};

// RandomGeneration.h
class RandomGeneration : public Generate {
public:
    RandomGeneration();
    void printGenerate();
};

//-------------All classes related to Tile-----------------------------//
class Tile {
    string status;
    int xcord;
    int ycord;
    bool mine;//tells if tile is a mine
    int displayvar;//displays number away from closet mine
public:
    Tile();
    virtual void printTile()=0;
    virtual void ChangeDisplay(string s)=0;//change the way the tile works
    bool IsMine();//checks if tile is a mine
    string GetStatus();//gets status of Tiles
    void SetStatus(string s);//sets status of string
    void SetCord(int x,int y);//set the cordinates just in case
    int getxcord();
    int getycord();
    void SetDisplayVar(int n);
    int GetDisplayVar();
};

// SquareTile.h
class SquareTile : public Tile {
private:
    string shape;
public:
    SquareTile();
    //temp method
    void ChangeDisplay(string s);
    void printTile();
};

//----------------All classes related to Board------------------------------//
class Board {
private:
    int xsize;
    int ysize;
    int mines;
public:
    Tile ***c;//pointer to our 2D array
    virtual void printBoard()=0;
    Board(int xsize,int ysize,int mines);
    // might consider making the destructors in base classes virtual to avoid memory leaks in derived classes.
    int getxsize();
    int getysize();
    int getnummines();
    virtual Tile* GetTileAtPoint(int x,int y)=0;
    void fillboardwithsquares();//fillboard will be the same for all types of boards
    //make a pure virtual to make sure all derived classes implement it.
};

// SimpleBoard.cpp
class SimpleBoard : public Board {
public:
    SimpleBoard();
    void printBoard();
    Tile* GetTileAtPoint(int x,int y);
};

// MediumBoard.cpp
class MediumBoard : public Board {
public:
    MediumBoard();
    void printBoard();
    Tile* GetTileAtPoint(int x,int y);
};

// AdvancedBoard.cpp //
class AdvBoard : public Board {
public:
    AdvBoard();
    void printBoard();
    Tile* GetTileAtPoint(int x, int y);
};
//--------------Everything related to the Rules class-------------------------------//
// Rules.h //
class Rules {
    Board* gameBoard;
    int row;
    int col;
public:
    virtual void rows_and_columns()=0;
    void setBoard(Board* b);
    void setRow(int r);
    int getRow();
    int getCol();
    void setCol(int c);

    Board* getBoard();

    virtual void printRules();
    virtual int playGame()=0;
    void flipTile();
    void flagTile();
    void unflagTile();
};

// SimpleSquareRules.h
class SimpleSquareRules : public Rules {
public:
    SimpleSquareRules();
    void printRules();
    int playGame();
    void rows_and_columns();
};

// MediumSquareRules.h
class MediumSquareRules : public Rules {
public:
    MediumSquareRules();
    void printRules();
    int playGame();
    void rows_and_columns();
};

// AdvancedSquareRules.h
class AdvSquareRules : public Rules {
public:
    AdvSquareRules();

    void printRules();
    int playGame();
    void rows_and_columns();
    void revealTile();
    void revealBomb();
};

//----------The Game class------------------------------//
// Game.h //
class Game {
private:
    Rules* gameRules;
    Board* gameBoard;
    Tile* gameTile;
    Generate* gameGeneration;
public:
// Setters and getters //
    void setRules(Rules*);
    void getRules();
    void setBoard(Board*);
    void getBoard();
    void setTile(Tile*);
    void getTile();
    void setGeneration(Generate*);
    void getGeneration();
    Board* rboard();//returns the board
    int playGame(); // handles user input to make changes to the game
};

//---------------Everything related to GameBuilder class----------------------//
// GameBuilder.cpp //
class GameBuilder {
public:
    virtual void buildRules()=0;
    virtual void buildBoard()=0;
    virtual void buildTile()=0;
    virtual void buildGeneration()=0;
    virtual Game* getGame()=0;
};

// SimpleSquareBuilder.cpp
class SimpleSquareBuilder : public GameBuilder {
    Game* game;
public:
    SimpleSquareBuilder();
    void buildRules();
    void buildBoard();
    void buildTile();
    void buildGeneration();
    Game* getGame();
};

// MediumSquareBuilder.cpp
class MediumSquareBuilder : public GameBuilder {
    Game* game;
public:
    MediumSquareBuilder();
    void buildRules();
    void buildBoard();
    void buildTile();
    void buildGeneration();
    Game* getGame();
};

// AdvnacedSquareBuilder.cpp
class AdvSquareBuilder : public GameBuilder {
    Game* game;
public:
    AdvSquareBuilder();
    void buildRules();
    void buildTile();
    void buildBoard();
    void buildGeneration();
    Game* getGame();
};

//----------------GameEngineer class------------------//
class GameEngineer {
    GameBuilder* gameBuilder;
public:
    // SimpleSquareBuilder specification is sent to the engineer
    GameEngineer(GameBuilder *gameBuilder);
    // Return the Game made from the SimpleSquareBuilder spec
    Game* getGame();
    void makeGame();
};

#endif //PHASE1_PHASE1_H
