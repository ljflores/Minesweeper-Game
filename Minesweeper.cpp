#include<iostream>
#include <sstream>
#include <algorithm>
#include<time.h>
using namespace std;

//-------------Tile classes-----------------//
class Tile {
public:
    Tile(){}
    virtual ~Tile() {}

    virtual void printTile()=0; // print out the tile on the terminal
    virtual void changeDisplay(string s)=0; // changes what the tile displays
    virtual void setMine()=0; // Make a tile a mine by setting IsMine to "true" and setting the bombTracker to 1
    virtual bool IsMine()=0; // checks to see if a tile is a mine

    virtual int getBombTracker()=0; // returns bombTracker, an instance variable to help with the recursive part in flip
    virtual void setBombTracker(int b)=0; // sets the bombTracker to whatever you want
    virtual void setNumber(string n)=0; // Updates the character (1-8, or 'B') that will eventually displayed in the terminal
    virtual string getNumber()=0; // gets the number that will eventually be displayed in the terminal
    virtual void setStatus(string s)=0; // sets the status to a string to indicate whether the tile is "flipped", "unflipped", etc.
    virtual string getStatus()=0; // returns a string, the status of a tile
    virtual Tile** getNeighbors()=0; // stores the neighbors of a Tile
    virtual void setNeighbors()=0; // set the neighbors of a tile
};

class SquareTile : public Tile {
private:
    string shape; // Stores the shape of a tile. For SquareTile, that's two brackets [ ]
    string status; // Tells whether the tile is flipped, unflipped, etc.
    int xcord; // For square tiles, they are marked by an x coordinate and a y coordinate.
    int ycord; // see above
    bool isMine;// Tells if tile is a mine
    string number; // underlying number (1, 2, 3) or letter (B) that indicates the bombs in the vicinity
    // or a Bomb.
    string display; // What is actually displayed on the tile. After initialization, the display is marked by a space to indicate an unflipped tile.
    Tile** neighbors = new Tile*[8]; //2-D array that holds a square tile's 8 neighbors.

    int rowNeighbors[8]; // Holds integers indicating the row of a neighbor. Used to input tiles into the neighbors 2-D array.
    int colNeighbors[8]; // Same as above, but for columns.

    int bombTracker; // Indicates whether or not a tile needs to enter recursion when flipped. It does if the bombTracker is 0.
public:
    SquareTile() {
        status = "unflipped"; // When the board is initialized, all the tiles are unflipped.
        isMine = false; // At first, all the mines are safe.
        number = "0"; // All tiles are marked with a 0 since all of the tiles are currently safe.
        display = " "; // Since the tiles are all initially unflipped, there should be no number or letter displayed on the tile.
        bombTracker = 0; // The bombTracker is initalized to 0 since there are no bombs/mines set at this point.
        shape = "[ ]"; // The brackets will show up in the terminal to indicate an unflipped tile.
    }

    ~SquareTile(){
        for(int i=0; i<9; i++) { // Deletes the neighbors 2-D array
            delete neighbors[i];
        }
        delete []neighbors;
    }

    void printTile() {cout<<shape;}

    void setStatus(string s) {this->status = s;}
    string getStatus() {return this->status;}

    void setCoord(int x,int y){
        this->xcord = x;
        this->ycord = y;
    }
    int getXCoord(){return this->xcord;}
    int getYCoord(){return this->ycord;}

    bool IsMine(){return isMine;}
    void setMine(){
        this->isMine = true;
        this->number = "B";
        this->bombTracker = 1;
        Tile* t;
        for (int i=0; i<8; i++) {
            t = this->getNeighbors()[i];
            if ((t != NULL) && !t->IsMine()) { // checks if the neighbor is valid AND is not a bomb itself
                t->setBombTracker(t->getBombTracker()+1);
                int num = t->getBombTracker();
                // change num to string
                string str;
                stringstream ss;
                ss << num;
                ss >> str;
                // set number to str
                t->setNumber(str);
            }
        }
    }

    void setNumber(string n) {number = n;}
    string getNumber() {return number;}

    void setDisplay(string n) {this->display = n;}
    string getDisplay() {return this->display;}
    void changeDisplay(string s) {
        this->setDisplay(s);
        shape = "[" + this->getDisplay() + "]";
    }

    Tile** getNeighbors(){return neighbors;}
    void setNeighbors(){
        int counter = 0;
        int CurrRow = this->getYCoord();
        int CurrCol = this->getXCoord();
        for (int i = CurrRow-1; i<= CurrRow+1; i++) {
            for (int j = CurrCol-1; j<= CurrCol+1; j++) {
                if (!((i == CurrRow) && (j == CurrCol))) {
                    rowNeighbors[counter]=i;
                    colNeighbors[counter]=j;
                    counter++;
                }
            }
        }
    }

    int getrowNeighbors(int i){return rowNeighbors[i];}
    int getcolNeighbors(int i){return colNeighbors[i];}

    void setBombTracker(int i){bombTracker = i;}
    int getBombTracker(){return bombTracker;}
};

//--------------Board Classes-----------------------//
class Board {
private:
    int mines; // Every Board has a certain number of mines in it.
    int unflippedTracker; // Every Board needs a tracker to tell how many Tiles are still unflipped. This will help with telling the player
                          // when they've won the game.
public:
    Board(int mines){this->mines = mines;} // The constructor of a Board initializes the number of mines.
    virtual ~Board(){}

    int getnummines(){return mines;}

    void setUnflippedTracker(int u){unflippedTracker = u;}
    int getUnflippedTracker(){return unflippedTracker;}
    void decrementUnflippedTracker(){unflippedTracker--;} // This is accessed when a tile is flipped.

    virtual int getSize()=0; //Returns the size of a Board, however the size is implemented.
    virtual Tile* GetTileAtPoint(int x,int y)=0; // Every board needs to access a specific tile.
    virtual void printBoard()=0; // Prints the Board, however it needs to be printed.
    virtual void FillBoardWithTiles()=0; // Every board needs to be filled with some kind of Tile.
    virtual void displayalltiles()=0; // The tiles eventually need to be displayed in the terminal.
    virtual void GenerateAllNeighbors()=0; // The neighbors of all the tiles need to be generated.
};

class SquareBoard : public Board {
private:
    int xsize;// Square boards have an x and a y size
    int ysize;
    SquareTile ***c; //pointer to our 2D array

public:
    SquareBoard(int xsize, int ysize, int mines)
            : Board(mines){
        this->xsize = xsize;
        this->ysize = ysize;
        this->setUnflippedTracker(((xsize * ysize) - mines)); // The unflipped tracker is set to the number of tiles minus the number of mines.
                                                              // This way, the game knows when all of the safe tiles have been flipped, and it knows
                                                              // to end the game.
    }

    ~SquareBoard() {
        for (int i=0; i<getSize(); i++) { // Deletes 2D array pointer to square tiles
            for (int j=0; j<getSize(); j++) {
                delete c[i][j];
            }
        }
        delete []c;
    }

    int getxsize(){return this->xsize;}
    int getysize(){return this->ysize;}

    SquareTile*** get2dArray(){return c;}
    void set2dArray(int size){c = new SquareTile**[size];}

    int getSize(){return getxsize();}

    bool WithenBounds(int p){ // Checks to see if a number, a coordinate perhaps, is within the bounds of the board.
        if (p >= 1 && p<=this->getysize()){
            return true;
        }
        else{
            return false;
        }
    }

    void printBoard(){
        cout<<"    ";
        for (int k = 1;k<this->getysize()+1;k++){ // printing column numbers
            if (k>=10){
                cout<<k<<" ";
            }
            else{
                cout<<k<<"  ";
            }
        }
        cout<<endl;
        for(int i = 0; i < this->getysize() ;i++){ // printing row numbers
            //this if else statement just fixes the SquareBoard
            if(i+1 >= 10){
                cout<<i+1<<" ";
            }
            else{
                cout << i + 1 << "  ";
            }
            for (int j = 0;j<this->getysize();j++){
                get2dArray()[i][j]->printTile(); // printing the tile shape, which is 2 brackets.
            }
            cout<<endl;
        }
    }

    SquareTile* GetTileAtPoint(int x,int y){return get2dArray()[y-1][x-1];} //Gets a tile at a specific point

    void FillBoardWithTiles(){ // This implementation fills the board with Square tiles.
        set2dArray(getxsize());

        for (int i = 0;i<getxsize();i++){
            get2dArray()[i] = new SquareTile*[getysize()];//creating space for rows

            for (int j = 0; j<getysize();j++){
                get2dArray()[i][j] = new SquareTile();//filling up the 2d array with square tiles
                get2dArray()[i][j]->setCoord(j+1,i+1);//just helping us remember the cords
                get2dArray()[i][j]->setNeighbors();
            }
        }
    }

    void displayalltiles(){ // Called when the user stops the game.
        SquareTile* t;
        for (int i = 0;i<getxsize();i++){
            for (int j = 0; j<getysize();j++){
                t = this->GetTileAtPoint(i+1,j+1);
                t->changeDisplay(t->getNumber());
            }
        }
    }

    void GenerateAllNeighbors(){
        SquareTile* t;
        for (int i = 0; i<getxsize();i++){//goes through each file in array
            for (int j = 0;j<getysize();j++){
                t = this->GetTileAtPoint(i+1,j+1);//gets the current tile
                for(int k = 0;k<8;k++){//fills in the Neighbors array with all neighboring tiles.
                    //makes sure the Neighbor is even within the bounds of the board
                    if(WithenBounds(t->getrowNeighbors(k))==true && WithenBounds(t->getcolNeighbors(k))== true){
                        t->getNeighbors()[k]=this->GetTileAtPoint(t->getcolNeighbors(k),t->getrowNeighbors(k));
                    }
                    else{
                        t->getNeighbors()[k] = NULL;
                    }
                }
            }
        }
    }
};

//----------Game_Generate classes-----------------//
class Generate {
    Board* gameBoard; // All game generations need to access the finished board to appropriately set the mines. A pointer to the board is sent here by
                    // calling the setBoard(Board*b) method in the Game class after the board is created in GameEngineer with all safe tiles.
public:
    Generate() {}
    virtual ~Generate() {
        delete gameBoard;
    }

    void setBoard(Board* b) {gameBoard = b;};
    Board* getBoard() {return gameBoard;};
    virtual void setBombs()=0; // Every game generation needs to set bombs in the game board.
};

class RandomSquareGeneration : public Generate { // This class is called "RandomSquareGeneration" because it only applies to Square Boards.
                                                 // If the user wants to randomly generate a triangular board, they might write a class that
                                                 // inherits Generate called "RandomTriangleGeneration".
public:
    RandomSquareGeneration()
            :Generate(){}
    ~RandomSquareGeneration(){}

    int * shuffle(int upperBound) { // Used to shuffle the coordinates of the rows and columns. Only for use in RandomGeneration.
        srand(time(0));

        //declare an array with a number of elements, elements, 0 to upperBound-1
        int *a = new int[upperBound];
        for(int i=0; i<upperBound; i++)
            a[i] = i;
        random_shuffle(a, a + upperBound);

        return a;
    }

    void setBombs() { // Sets the appropriate tiles to bombs by changing their status, number, etc.
        int *shuffledRows = this->shuffle(this->getBoard()->getSize()); // shuffle the rows
        int *shuffledCols = this->shuffle(this->getBoard()->getSize()); // shuffle the columns
        Tile *t;
        int j = getBoard()->getSize()-1;
        for (int i=0; i<this->getBoard()->getnummines(); i++) {
            t = this->getBoard()->GetTileAtPoint(shuffledRows[i]+1,shuffledCols[j]+1);
            t->setMine();
            j--;
        }
    }
};

class PlannedSquareGeneration : public Generate { // This class is called "PlannedSquareGeneration" because it only applies to Square Boards.
                                                 // If the user wants to generate a planned triangular board, they might write a class that
                                                 // inherits Generate called "PlannedTrangleGeneration".
public:
    PlannedSquareGeneration()
            : Generate(){}
    ~PlannedSquareGeneration(){}

    void setBombs() { // There are three cases when it comes to Square boards. 5, 9, and 12, which corresponds to the number of bombs each game has.
        int PNumMines = this ->getBoard()->getnummines();
        switch (PNumMines){
            case 5:
                setBombshelper(1,1);
                setBombshelper(7,7);
                setBombshelper(3,3);
                setBombshelper(2,3);
                setBombshelper(5,5);
                break;
            case 9:
                setBombshelper(1,1);
                setBombshelper(10,10);
                setBombshelper(2,1);
                setBombshelper(5,5);
                setBombshelper(3,3);
                setBombshelper(9,4);
                setBombshelper(3,5);
                setBombshelper(4,1);
                setBombshelper(6,1);
                break;
            case 12:
                setBombshelper(1,1);
                setBombshelper(10,10);
                setBombshelper(2,1);
                setBombshelper(5,5);
                setBombshelper(3,3);
                setBombshelper(9,4);
                setBombshelper(3,5);
                setBombshelper(4,1);
                setBombshelper(6,1);
                setBombshelper(13,13);
                setBombshelper(12,1);
                setBombshelper(2,10);
                break;
        }
    }

    void setBombshelper(int x,int y) {
        Tile *t;
        t = this->getBoard()->GetTileAtPoint(x,y);
        t->setMine();
    }
};

//------------Rules classes----------------------//
class Rules {
    Board* gameBoard; // Every Rules class is sent a pointer to the created Board to access and edit.
public:
    Rules() {}
    virtual ~Rules() {
        delete gameBoard;
    }
    void setBoard(Board* b){gameBoard = b;}
    Board* getBoard(){return gameBoard;}

    virtual void flipTile()=0;
    virtual void printRules()=0;
    virtual int playGame()=0;
};

class SquareRules : public Rules {
    int row; // SquareRules ackowledge that a SquareBoard has rows and columns.
    int col;

    int flipTileNoInput(Tile *t) {
        if (t->getBombTracker() != 0) { // if the bombTracker is 1, 2, 3, etc:
            t->changeDisplay(t->getNumber()); // flip the tile, that's all.
            t->setStatus("flipped");
            getBoard()->decrementUnflippedTracker(); // unflippedTracker--
            return 0;
        } else { // if the bombTracker is 0, flip the tile and the tile's neighbors.
            t->changeDisplay(t->getNumber()); // flip the tile
            t->setStatus("flipped");
            getBoard()->decrementUnflippedTracker(); // unflippedTracker--

            Tile *n;
            for (int j = 0; j < 8; j++) { // looking at each of the tile's 8 neighbors
                n = t->getNeighbors()[j];
                if ((n != NULL) && !n->IsMine() && (n->getStatus() ==
                                                    "unflipped")) { // if the neighbor is a valid tile, is not a mine, and is unflipped
                    n->changeDisplay(n->getNumber()); // flip the neighbor tile // flip the tile
                    n->setStatus("flipped");
                    flipTileNoInput(n); // send this tile in to get its neighbors checked as well.
                }
            }
            return 0;
        }
    }

public:
    SquareRules()
    : Rules() {}
    ~SquareRules(){}

    void setRow(int r) { row = r; }
    int getRow(){return row;}

    int getCol(){return col;}
    void setCol(int c) {col = c;}

    void rows_and_columns() { // Handles user input for rows and columns. Called for every command.
        int gameRow = 0;
        int gameCol = 0;

        bool keepGoing = true;
        while (keepGoing) {
            cout << "What row would you like? Enter a number between 1 and " << getBoard()->getSize() << ":" << endl;
            cin >> gameRow;
            if ((gameRow < 1) || (gameRow > getBoard()->getSize())) {
                cout << "Please enter a number in the correct range." << endl;
            } else {
                break;
            }
        }
        while (keepGoing) {
            cout << "What column would you like? enter a number between 1 and and " << getBoard()->getSize() << ":"
                 << endl;
            cin >> gameCol;
            if ((gameCol < 1) || (gameCol > getBoard()->getSize())) {
                cout << "Please enter a number in the correct range." << endl;
            } else {
                break;
            }
        }
        this->setRow(gameRow);
        this->setCol(gameCol);
    }

    void flipTile() {
        this->rows_and_columns(); // asks for user input

        Tile *t = this->getBoard()->GetTileAtPoint(this->getCol(), this->getRow()); // gets the tile based on user input

        if (t->IsMine() &&
            (t->getStatus() == "unflipped")) { // If you hit a mine, it exits the program and prints out the board.
            cout << endl << endl;
            cout << "Game over. You hit a mine." << endl;
            t->changeDisplay(t->getNumber()); // flip the tile
            this->getBoard()->printBoard();//prints the board with all of the tiles flipped to revel bombs
            exit(0);
        }

        if (t->getStatus() == "unflipped") {
            if (t->getBombTracker() != 0) { // Tile is safe, has a number other than 0.
                t->changeDisplay(t->getNumber()); // flip the tile and change the status.
                t->setStatus("flipped");
                getBoard()->decrementUnflippedTracker(); // unflippedTracker--
            } else { // If the tile is safe and has 0 bombs in its neighborhood:
                flipTileNoInput(t); // see above
            }
            this->getBoard()->printBoard();
        } else {
            cout << "Tile cannot be flipped." << endl;
        }
    }

    void printRules() { // All Square games must have these three commands:
        cout << "-  flip -- Type the word 'flip' to flip a tile of your choosing." << endl;
        cout << "-  rules -- Type the word 'rules' to re-print the rules." << endl;
        cout << "-  stop -- Type the word 'stop' to stop the game" << endl;
    }
};

class SimpleSquareRules : public SquareRules { // SimpleSquareRules has the option to flag and unflag a tile.
public:
    SimpleSquareRules()
            :SquareRules(){}
    ~SimpleSquareRules(){}

    void flagTile() {
        this->rows_and_columns();
        Tile *t = this->getBoard()->GetTileAtPoint(this->getCol(), this->getRow());
        if (t->getStatus() == "unflipped") {
            t->changeDisplay("f"); // change the tile display to indicate that it's flagged
            t->setStatus("flagged"); // update the status
            this->getBoard()->printBoard();
        } else {
            cout << "Tile cannot be flagged." << endl;
        }
    }

    void unflagTile() {
        this->rows_and_columns();
        Tile *t = this->getBoard()->GetTileAtPoint(this->getCol(), this->getRow());
        if (t->getStatus() == "flagged") {
            t->changeDisplay(" "); // changes the display back to a blank tile
            t->setStatus("unflipped"); // updates the status back to unflipped
            this->getBoard()->printBoard();
        } else {
            cout << "Tile cannot be unflagged." << endl;
        }
    }

    void printRules(){
        cout<<"Valid commands for a Simple Square game include: "<<endl;
        SquareRules::printRules();
        cout << "-  flag -- Type the word 'flag' to flag a tile of your choosing." << endl;
        cout << "-  unflag -- Type the word 'unflag' to unflag a tile of your choosing." << endl;
        cout<<"\n";
    }

    int playGame(){
        string command = "placeholder";
        bool keepGoing = true;
        while (keepGoing) {
            if(getBoard()->getUnflippedTracker() == 0) { // Checks to see if the user won the game
                cout<<endl<<endl;
                cout<<"Congratulations! You win."<<endl;
                this->getBoard()->displayalltiles();
                this->getBoard()->printBoard();//prints the board with all of the tiles flipped to revel bombs
                exit(0);
            }
            cout<<"Enter a command: ";
            cin >> command;
            if (command == "flip") {
                this->flipTile();
            }
            else if (command == "flag") {
                this->flagTile();
            }
            else if (command == "unflag") {
                this->unflagTile();
            }
            else if (command == "rules") {
                this->printRules();
            }
            else if (command == "stop") {
                cout<<endl<<endl;
                cout<<"Thank You For Playing our Simple Square Game"<<endl<<"Here is the SquareBoard with all the tiles flipped"<<endl;
                this->getBoard()->displayalltiles();
                this->getBoard()->printBoard();//prints the board with all of the tiles flipped to revel bombs
                break;
            }
            else {
                cout<<"Please enter a correct command."<<endl;
            }
        }
        return 0;
    }
};

class MediumSquareRules : public SquareRules { // MediumSquareRules has the option to flag and unflag a tile.
public:
    MediumSquareRules()
    :SquareRules(){}
    ~MediumSquareRules(){}

    void flagTile() {
        this->rows_and_columns();
        Tile *t = this->getBoard()->GetTileAtPoint(this->getCol(), this->getRow());
        if (t->getStatus() == "unflipped") {
            t->changeDisplay("f"); // change the tile display to indicate that it's flagged
            t->setStatus("flagged"); // update the status
            this->getBoard()->printBoard();
        } else {
            cout << "Tile cannot be flagged." << endl;
        }
    }

    void unflagTile() {
        this->rows_and_columns();
        Tile *t = this->getBoard()->GetTileAtPoint(this->getCol(), this->getRow());
        if (t->getStatus() == "flagged") {
            t->changeDisplay(" "); // changes the display back to a blank tile
            t->setStatus("unflipped"); // updates the status back to unflipped
            this->getBoard()->printBoard();
        } else {
            cout << "Tile cannot be unflagged." << endl;
        }
    }

    void printRules(){
        cout<<"Valid commands for a Medium Square game include: "<<endl;
        SquareRules::printRules();
        cout << "-  flag -- Type the word 'flag' to flag a tile of your choosing." << endl;
        cout << "-  unflag -- Type the word 'unflag' to unflag a tile of your choosing." << endl;
        cout<<"\n";
    }

    int playGame(){
        string command = "placeholder";
        bool keepGoing = true;
        while (keepGoing) {
            if(getBoard()->getUnflippedTracker() == 0) { // Checks to see if the user won the game
                cout<<endl<<endl;
                cout<<"Congratulations! You win."<<endl;
                this->getBoard()->displayalltiles();
                this->getBoard()->printBoard();//prints the board with all of the tiles flipped to revel bombs
                exit(0);
            }
            cout<<"Enter a command: ";
            cin >> command;
            if (command == "flip") {
                this->flipTile();
            }
            else if (command == "flag") {
                this->flagTile();
            }
            else if (command == "unflag") {
                this->unflagTile();
            }
            else if (command == "rules") {
                this->printRules();
            }
            else if (command == "stop") {
                cout<<endl<<endl;
                cout<<"Thank You For Playing our Medium Square Game"<<endl<<"Here is the SquareBoard with all the tiles flipped"<<endl;
                this->getBoard()->displayalltiles();
                this->getBoard()->printBoard();//prints the board with all of the tiles flipped to revel bombs
                break;
            }
            else {
                cout<<"Please enter a correct command."<<endl;
            }
        }
        return 0;
    }
};

class AdvSquareRules : public SquareRules { // AdvancedSquareRules does *not* have the option to flag and unflag a tile. This increases the
                                            // difficulty and demonstrates the flexibility of the Rules class implementation.
public:
    AdvSquareRules()
    :SquareRules(){}
    ~AdvSquareRules(){}

    void printRules(){
        cout<<"Valid commands for a Advanced Square game include: "<<endl;
        SquareRules::printRules();
        cout<<"\n";
        cout<<("****NOTE**** 'flag' and 'unflag' are not valid commands for Advanced Square Games.")<<endl;
        cout<<"\n";
    }

    int playGame() {
        string command = "placeholder";
        bool keepGoing = true;
        while (keepGoing) {
            if (getBoard()->getUnflippedTracker() == 0) { // Checks to see if the user won the game
                cout << endl << endl;
                cout << "Congratulations! You win." << endl;
                this->getBoard()->displayalltiles();
                this->getBoard()->printBoard();//prints the board with all of the tiles flipped to revel bombs
                exit(0);
            }
            cout << "Enter a command: ";
            cin >> command;
            if (command == "flip") {
                this->flipTile();
            } else if (command == "rules") {
                this->printRules();
            } else if (command == "stop") {
                cout << "Thank You For Playing our Advanced Square Game" << endl
                     << "Here is the SquareBoard with all the tiles flipped" << endl;
                this->getBoard()->displayalltiles();
                this->getBoard()->printBoard();//prints the board with all of the tiles flipped to revel bombs
                break;
            } else {
                cout << "Please enter a correct command." << endl;
            }
        }
        return 0;
    }
};

//------------------------Game class-----------------------------------//
class Game {
private:
    Rules* gameRules;
    Board* gameBoard;
    Tile* gameTile;
    Generate* gameGeneration;
public:
    Game() {}
    ~Game() {
        delete gameRules;
        delete gameBoard;
        delete gameTile;
        delete gameGeneration;
    }

// Setters and getters //
    void setRules(Rules* rules){gameRules = rules;}
    void getRules(){return gameRules->printRules();}

    void setBoard(Board* board){gameBoard = board;}
    void getBoard(){gameBoard->printBoard();} // prints the board

    void setTile(Tile* tile){gameTile = tile;}

    void setGeneration(Generate* generation) {gameGeneration = generation;}

    Board* rboard(){return this->gameBoard;} // Actually returns a pointer to the board.

    int playGame(){
        cout<<endl<<endl;
        cout<<"Game built."<<endl;

        this->getRules(); // prints the rules
        this->getBoard(); // prints the board

        gameGeneration->setBoard(this->rboard()); // Sends a pointer to the board (at this point, with all safe tiles) to generation to set the bombs.
        gameGeneration->setBombs(); //Sets the bombs with the appropriate generation.
        cout<<"--------------------------------------------------------------------------------"<<endl;
        gameRules->setBoard(gameGeneration->getBoard()); // Sends a pointer to the board, after it's been generated, to the Rules class.
        gameRules->playGame(); // The Rules class handles user input and handles things like flip, flag, and unflag.
        return 0;
    }
};

//-------------GameBuilder classes------------------------------------//
class GameBuilder {
public:
    GameBuilder(){}
    virtual ~GameBuilder(){}

    virtual void buildRules()=0;
    virtual void buildBoard()=0;
    virtual void buildTile()=0;
    virtual void buildGeneration()=0;

    virtual Game* getGame()=0;
};

class SimpleSquareBuilder : public GameBuilder {
    Game* game;
public:
    SimpleSquareBuilder() {
        this->game = new Game();
    }
    ~SimpleSquareBuilder() {
        delete game;
    }

    void buildRules() {
        Rules* simpleSquareRules = new SimpleSquareRules();
        game->setRules(simpleSquareRules);
        // send the square board to the Rules class
    }

    void buildBoard() {
        SquareBoard* simpleBoard = new SquareBoard(7,7,5); //Initializes a SquareBoard with Simple parameters
        simpleBoard->FillBoardWithTiles();//fills board with square tiles
        simpleBoard->GenerateAllNeighbors();//generates the neighbors for each tile
        game->setBoard(simpleBoard);
    }

    void buildTile() {
        Tile* squareTile = new SquareTile();
        game->setTile(squareTile);
    }

    void buildGeneration() {
        cout<<"Do you want the generation to be Random or Planned?"<<endl;
        cout<<"1: Random Generation "<<endl<<"2: Planned Generation"<<endl;
        string usera;
        cin>> usera;
        while(usera != "1" && usera != "2"){
            cout<<"The value that you entered was incompatible try again. "<<endl;
            cin >> usera;
        }
        stringstream degree(usera);
        int useri = 0;
        degree >> useri;
        if(useri == 1) {
            Generate *randomGeneration = new RandomSquareGeneration();
            game->setGeneration(randomGeneration);
        }
        if(useri == 2){
            cout<<endl<<endl;
            cout<<"The mines are located in:"<<endl;
            cout<<"(1,1)"<<endl;
            cout<<"(7,7)"<<endl;
            cout<<"(3,3)"<<endl;
            cout<<"(3,2)"<<endl;
            cout<<"(5,5)"<<endl;
            Generate *plannedGeneration = new PlannedSquareGeneration();
            game->setGeneration(plannedGeneration);
        }
    }

    Game* getGame() {
        return this->game;
    }
};

class MediumSquareBuilder : public GameBuilder {
    Game* game;
public:
    MediumSquareBuilder() {
        this->game = new Game();
    }
    ~MediumSquareBuilder() {
        delete game;
    }

    void buildRules() {
        Rules* mediumsquarerules = new MediumSquareRules();
        game->setRules(mediumsquarerules);
    }

    void buildBoard() {
        SquareBoard* mediumB = new SquareBoard(10,10,9); //Initializes a SquareBoard with Medium parameters
        mediumB->FillBoardWithTiles();//builds the board with square tiles
        mediumB->GenerateAllNeighbors();
        game->setBoard(mediumB);
    }

    void buildTile() {
        Tile* squareTile = new SquareTile();
        game->setTile(squareTile);
    }

    void buildGeneration() {
        cout<<"Do you want the generation to be Random or Planned?"<<endl;
        cout<<"1: Random Generation "<<endl<<"2: Planned Generation"<<endl;
        string usera;
        cin>> usera;
        while(usera != "1" && usera != "2"){
            cout<<"The value that you entered was incompatible try again. "<<endl;
            cin >> usera;
        }
        stringstream degree(usera);
        int useri = 0;
        degree >> useri;
        if(useri == 1) {
            Generate *randomGeneration = new RandomSquareGeneration();
            game->setGeneration(randomGeneration);
        }
        if(useri == 2){
            cout<<endl<<endl;
            cout<<"The mines are located in:"<<endl;
            cout<<"(1,1)"<<endl;
            cout<<"(10,10)"<<endl;
            cout<<"(1,2)"<<endl;
            cout<<"(5,5)"<<endl;
            cout<<"(3,3)"<<endl;
            cout<<"(4,9)"<<endl;
            cout<<"(5,3)"<<endl;
            cout<<"(1,4)"<<endl;
            cout<<"(1,6)"<<endl;
            Generate *plannedGeneration = new PlannedSquareGeneration();
            game->setGeneration(plannedGeneration);
        }
    }

    Game* getGame() {
        return this->game;
    }
};

class AdvSquareBuilder : public GameBuilder {
    Game* game;
public:
    AdvSquareBuilder() {
        this->game = new Game();
    }
    ~AdvSquareBuilder() {
        delete game;
    }

    void buildRules() {
        Rules* advsqrules = new AdvSquareRules();
        game->setRules(advsqrules);
    }

    void buildTile() {
        Tile* squareTile = new SquareTile();
        game->setTile(squareTile);
    }
    void buildBoard() {
        SquareBoard* advBoard = new SquareBoard(13,13,12); //Initializes a SquareBoard with Advanced parameters
        advBoard->FillBoardWithTiles();//fills board with square tiles
        advBoard->GenerateAllNeighbors();//generates neighbors for each tile
        game->setBoard(advBoard);
    }

    void buildGeneration() {
        cout<<"Do you want the generation to be Random or Planned?"<<endl;
        cout<<"1: Random Generation "<<endl<<"2: Planned Generation"<<endl;
        string usera;
        cin>> usera;
        while(usera != "1" && usera != "2"){
            cout<<"The value that you entered was incompatible try again. "<<endl;
            cin >> usera;
        }
        stringstream degree(usera);
        int useri = 0;
        degree >> useri;
        if(useri == 1) {
            Generate *randomGeneration = new RandomSquareGeneration();
            game->setGeneration(randomGeneration);
        }
        if(useri == 2){
            cout<<endl<<endl;
            cout<<"The mines are located in:"<<endl;
            cout<<"(1,1)"<<endl;
            cout<<"(10,10)"<<endl;
            cout<<"(1,2)"<<endl;
            cout<<"(5,5)"<<endl;
            cout<<"(3,3)"<<endl;
            cout<<"(4,9)"<<endl;
            cout<<"(5,3)"<<endl;
            cout<<"(1,4)"<<endl;
            cout<<"(1,6)"<<endl;
            cout<<"(13,13)"<<endl;
            cout<<"(1,12)"<<endl;
            cout<<"(10,2)"<<endl;
            Generate *plannedGeneration = new PlannedSquareGeneration();
            game->setGeneration(plannedGeneration);
        }
    }

    Game* getGame() {
        return this->game;
    }
};

//----------------GameEngineer class------------------------//
class GameEngineer {
    GameBuilder* gameBuilder; // Has a GameBuilder pointer to actually call the GameBuilder methods on it.
public:
    // Builder specification is sent to the engineer
    GameEngineer(GameBuilder *gameBuilder) {
        this->gameBuilder = gameBuilder;
    }
    ~GameEngineer() {
        delete gameBuilder;
    }

    // Return the Game made from the builder spec
    Game* getGame() {
        return this->gameBuilder->getGame();
    }

    // Execute the methods specific to the builder that inherits GameBuilder
    void makeGame() {
        this->gameBuilder->buildRules();
        this->gameBuilder->buildBoard();
        this->gameBuilder->buildTile();
        this->gameBuilder->buildGeneration();
    }
};

int userhandler(); // handles user input in initGame()
Game* initGame(); // The user can call this to initialize a game.

int main() {
    Game* firstGame;
    firstGame = initGame();
    firstGame->playGame();
    return 0;
}

//------------------------------------------------------------------------------------------------------------------------//

int userhandler(){
    string usera = "testcode";
    cout << "Welcome to Minesweeper!" << endl <<endl;
    cout << "Select from the following choices:" << endl <<endl;
    while(usera != "1" && usera != "2" && usera != "3") {
        if (usera != "testcode"){
            cout<<"You entered in an incompatible option please select from these options"<<endl;
        }
        cout << "1: Simple Square Game (7 x 7 board with 5 mines)" << endl;
        cout << "2: Medium Square Game (10 x 10 board with 9 mines)" << endl;
        cout << "3: Advanced Square Game (13 x 13 board with 12 mines)" << endl;
        cin>>usera;

        cout<<endl;
    }
    stringstream degree(usera);
    int numusera = 0;
    degree >> numusera;
    return numusera;
}

Game* initGame() {
    int usera = userhandler();
    GameBuilder* SquareGame;
    if (usera == 1){
        SquareGame = new SimpleSquareBuilder;
    }
    else if(usera ==2){
        SquareGame = new MediumSquareBuilder;
    }
    else{
        SquareGame = new AdvSquareBuilder;
    }
    // Pass the SimpleSquareBuilder specification to the engineer
    GameEngineer* gameEngineer = new GameEngineer(SquareGame);

    // Tell the engineer to make the Game using the specifications of the
    // SimpleSquareBuilder class
    gameEngineer->makeGame();

    // The engineer returns the right game based off of the spec sent to it.
    Game* firstGame = gameEngineer->getGame();

    return firstGame;
}

