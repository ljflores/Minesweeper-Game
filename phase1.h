#ifndef PHASE1_PHASE1_H
#define PHASE1_PHASE1_H
#include <iostream>
using namespace std;

//------------All classes related to Game_Generate-------------------//
// Generate.h
class Generate {
    Board* gameBoard; // Generate will have access to a Board, which is made out of Tiles, so the Board can be
                        // appropriately printed out.
public:
    Generate();
    virtual ~Generate();

    void setBoard(Board* b); // initializes gameBoard
    Board* getBoard(); // returns the board after it has been generated.
    virtual void printBoard()=0; // Prints out the generation of the board, Random or Planned.
};

// RandomGeneration.h
class RandomGeneration : public Generate {
public:
    RandomGeneration();
    ~RandomGeneration();

    void printBoard(); // Will print out a randomly-generated Board.
};

// PlannedGeneration.h
class PlannedGeneration : public Generate {
    PlannedGeneration();
    ~PlannedGeneration();

    void printBoard(); // For testing purposes. Prints out a pre-planned Board.
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
    virtual ~Tile();

    virtual void printTile()=0; // Prints brackets [] for a square shape, and another symbol for another shape.
    virtual void ChangeDisplay(string s)=0; // Marks the tile to signify that it has been flipped, flagged, etc.
    bool IsMine();//checks if tile is a mine
    string GetStatus();//gets status of Tiles
    void SetStatus(string s);//sets status of string
    void SetCord(int x,int y);//set the coordinates just in case
    int getxcord(); // Returns the X coordinate of a Tile
    int getycord(); // Returns the Y coordinate of a Tile
    void SetDisplayVar(int n); // Sets the number, 1, 2, or 3, within a tile that marks the # of mines in the vicinity
    int GetDisplayVar(); // Returns the display variable.
};

// SquareTile.h
class SquareTile : public Tile {
private:
    string shape; // Defines the shape of a particular tile, in this case, brackets [] for Square.
public:
    SquareTile();
    ~SquareTile();

    void ChangeDisplay(string s); // See above
    void printTile(); // Prints the Tile for the terminal.
};

//----------------All classes related to Board------------------------------//
class Board {
private:
    int xsize; // Holds the number of columns for a Board
    int ysize; // Holds the number of columns for a Board
    int mines; // Holds the number of mines in a Board
    Tile ***c; //pointer to a 2D array of Tiles
public:
    Board(int xsize,int ysize,int mines);
    virtual ~Board();

    Tile*** getTile(); // returns the 2D array of Tiles
    int getxsize(); // returns the number of columns
    int getysize(); // returns the number of rows
    int getnummines(); // returns the number of minds
    virtual Tile* GetTileAtPoint(int x,int y)=0; // Accesses a Tile at a specific coordinate
    void FillBoardWithTiles(); // Creates the board, filling it with square objects
};

// SimpleBoard.cpp
class SimpleBoard : public Board {
public:
    SimpleBoard();
    ~SimpleBoard();

    Tile* GetTileAtPoint(int x,int y); // Gets a tile at a particular point; Accounts for the bounds of a Simple Board
};

// MediumBoard.cpp
class MediumBoard : public Board {
public:
    MediumBoard();
    ~MediumBoard();

    Tile* GetTileAtPoint(int x,int y); // Gets a tile at a particular point; Accounts for the bounds of a Medium board
};

// AdvancedBoard.cpp //
class AdvBoard : public Board {
public:
    AdvBoard();
    ~AdvBoard();

    Tile* GetTileAtPoint(int x, int y); // Gets a tile at a particular point; Accounts for the bounds of a Medium board
};
//--------------Everything related to the Rules class-------------------------------//
// Rules.h //
class Rules {
    Board* gameBoard; // Holds the finished Board created by the GameEngineer class.
    int row; // Will hold the row of the Tile the user wants to access; based on user input.
    int col; // Will hold the column of the Tile the user wants to access; based on user input.
public:
    Rules();
    virtual ~Rules;

    virtual void rows_and_columns()=0; // Gets the user input for the row and column of the Tile they want to access
    void setBoard(Board* b); // playGame() in the Game class passes a Board here for the Rules class to edit
    void setRow(int r); // Sets the row based on user input
    int getRow(); // Gets the row
    int getCol(); // Gets the column
    void setCol(int c); // Sets the column based on user input

    Board* getBoard(); // Returns a pointer to the Board

    virtual void printRules(); // Prints the rules of a particular game based on a command from the user
    virtual int playGame()=0; // Handles the "flip", "flag", "unflag", etc. commands input by the user.
    void flipTile(); // Flips a tile based on a command from the user
    void flagTile(); // Flags a tile based on a command from the user
    void unflagTile(); // Unflags a tile based on a command from the user
};

// SimpleSquareRules.h
class SimpleSquareRules : public Rules {
public:
    SimpleSquareRules();
    ~SimpleSquareRules();

    void printRules(); // Prints SimpleSquare Rules for the user based on user input
    int playGame(); // Handles user commands
    void rows_and_columns(); // Sets the row and column the user wants to access based on user input
    void revealTile(); // A hint that reveals a tile of the player's choosing
    void revealBomb(); // A hint that reveals a bomb for the user without penalty
};

// MediumSquareRules.h
class MediumSquareRules : public Rules {
public:
    MediumSquareRules();
    ~MediumSquareRules();

    void printRules(); // Prints MediumSquare Rules for the user based on user input
    int playGame(); // Handles user commands
    void rows_and_columns(); // Sets the row and column the user wants to access based on user input
};

// AdvancedSquareRules.h
class AdvSquareRules : public Rules {
public:
    AdvSquareRules();
    ~AdvSquareRules();

    void printRules(); // Prints AdvSquare Rules for the user based on user input
    int playGame(); // Handles user input
    void rows_and_columns(); // Sets the row and column the user wants to access based on user input
};

//----------The Game class------------------------------//
// Game.h //
class Game {
private:
    Rules* gameRules; // pointer to the correct rule
    Board* gameBoard; // pointer to the correct board
    Tile* gameTile; // pointer to the correct tile
    Generate* gameGeneration; // pointer to the correct game generation
public:
    Game();
    ~Game();
// Setters and getters //
    void setRules(Rules*); // sends the rule pointer to the appropriate game builder
    void getRules(); // returns a pointer to the rules
    void setBoard(Board*); // sends the board pointer to the appropriate game builder
    void getBoard(); // returns a pointer to the board
    void setTile(Tile*); // sends the tile pointer to the appropriate game builder
    void getTile(); // returns a pointer to the Tile
    void setGeneration(Generate*); // sends the generation pointer to the appropriate game builder
    void getGeneration(); // returns a pointer to the generation
    Board* rboard();//returns the board
    int playGame(); // handles user input to make changes to the game
};

//---------------Everything related to GameBuilder class----------------------//
// GameBuilder.h //
class GameBuilder {
public:
    GameBuilder();
    virtual ~GameBuilder();

    virtual void buildRules()=0; // Initializes Rules with the appropriate constructor
    virtual void buildBoard()=0; // Initializes Board with the appropriate constructor
    virtual void buildTile()=0; // Initializes Tile with the appropriate constructor
    virtual void buildGeneration()=0; // Initializes Generation with the appropriate constructor
    virtual Game* getGame()=0; // Returns a pointer to the game
};

// SimpleSquareBuilder.cpp
class SimpleSquareBuilder : public GameBuilder {
    Game* game; // Pointer to the game; will eventually be sent to GameEngineer
public:
    SimpleSquareBuilder();
    ~SimpleSquareBuilder();

    void buildRules(); // Initializes Rules with a SimpleSquareRules constructor
    void buildBoard(); // Initializes Board with a SimpleBoard constructor
    void buildTile(); // Initializes Tile with a SquareTile constructor
    void buildGeneration(); // Initializes Rules with a RandomGeneration constructor
    Game* getGame(); // Returns a pointer to the game
};

// MediumSquareBuilder.cpp
class MediumSquareBuilder : public GameBuilder {
    Game* game; // Pointer to the game; eventually goes to the GameEngineer
public:
    MediumSquareBuilder();
    ~MediumSquareBuilder();

    void buildRules(); // Initializes Rules with a MediumSquareRules constructor
    void buildBoard(); // Initializes Board with a MediumBoard constructor
    void buildTile(); // Initializes Tile with a Square constructor
    void buildGeneration(); // Initializes Generation with a RandomGeneration constructor
    Game* getGame(); // returns a pointer to the game
};

// AdvnacedSquareBuilder.cpp
class AdvSquareBuilder : public GameBuilder {
    Game* game; // Pointer to the game; eventually goes to the GameEngineer
public:
    AdvSquareBuilder();
    ~AdvSquareBuilder();

    void buildRules(); // Initializes Rules with a AdvSquareRules constructor
    void buildTile(); // Initializes Tile with a Square constructor
    void buildBoard(); // Initializes Board with an AdvBoard constructor
    void buildGeneration(); // Initializes Generation with a RandomGeneration constructor
    Game* getGame(); // Returns a pointer to the game
};

//----------------GameEngineer class------------------//
class GameEngineer {
    GameBuilder* gameBuilder; // Pointer to a GameBuilder object
public:
    // GameBuilder specification is sent to the engineer
    GameEngineer(GameBuilder *gameBuilder);
    ~GameEngineer();

    // Return the Game made from the SimpleSquareBuilder spec
    Game* getGame(); // Returns the finished game
    void makeGame(); // Build methods are called on the GameBuilder object
};

#endif //PHASE1_PHASE1_H
