#include<iostream>
#include <sstream>
#include <algorithm>    // std::random_shuffle
#include<time.h>
using namespace std;

//------------Tile classes-----------------//
class Tile {
public:
    Tile() {}

    virtual void printTile()=0; // print out the tile on the terminal
    virtual void changeDisplay(string s)=0; // changes what the tile displays
    virtual void setMine()=0; // Make a tile a mine

    virtual bool IsMine()=0; // checks to see if a tile is a mine

    virtual int getBombTracker()=0;
    virtual void setBombTracker(int b)=0;
    virtual void setNumber(string n)=0;
    virtual string getNumber()=0;
    virtual void setStatus(string s)=0;
    virtual string getStatus()=0;
    virtual Tile** getNeighbors()=0;
    virtual void setNeighbors()=0; // set the neighbors of a tile
};

class SquareTile : public Tile {
private:
    string shape;
    string status;
    int xcord;
    int ycord;
    bool isMine;//tells if tile is a mine
    string number; // underlying number (1, 2, 3) or letter (B) that indicates the bombs in the vicinity
    // or a Bomb.
    string display; // what is actually displayed on the tile
    Tile** neighbors = new Tile*[8];

    int rowNeighbors[8];
    int colNeighbors[8];

    int bombTracker;
public:
    SquareTile() {
        status = "unflipped"; // when the board is initialized, all the tiles are unflipped.
        isMine = false; // at first, all the mines are safe.
        number = "0"; // all tiles are marked with a 0 since all of the tiles are currently safe.
        display = " "; // since the tiles are all initially unflipped, there should be no number or letter displayed on the tile.
        bombTracker = 0;
        shape = "[ ]";
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
        cout<<"("<<this->getYCoord()<<", "<<this->getXCoord()<<")"<<endl; //UNCOMMENT IF YOU WANT TO SEE THE BOMBS
        for (int i=0; i<8; i++) {
            t = this->getNeighbors()[i];
            if ((t != NULL) && !t->IsMine()) { // checks if the neighbor is valid AND is not a bomb itself
                //cout<<"("<<t->getYCoord()<<", "<<t->getXCoord()<<")"<<endl; // UNCOMMENT IF YOU WANT TO SEE THE NEIGHBORS
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
    int mines;
    int unflippedTracker; // Checks to see how many tiles are currently unflipped; will be referenced to know if the user won the game
public:
    Board(int mines){this->mines = mines;}
    int getnummines(){return mines;}

    void setUnflippedTracker(int u){unflippedTracker = u;}
    int getUnflippedTracker(){return unflippedTracker;}
    void decrementUnflippedTracker(){unflippedTracker--;}

    virtual int getSize()=0;
    virtual Tile* GetTileAtPoint(int x,int y)=0;
    virtual void printBoard()=0;
    virtual void FillBoardWithTiles()=0;
    virtual void displayalltiles()=0;
    virtual void GenerateAllNeighbors()=0;
};

class SquareBoard : public Board {
private:
    int xsize;
    int ysize;
    SquareTile ***c; //pointer to our 2D array

public:
    SquareBoard(int xsize, int ysize, int mines)
    : Board(mines){
        this->xsize = xsize;
        this->ysize = ysize;
        this->setUnflippedTracker(((xsize * ysize) - mines));
    }

    int getxsize(){return this->xsize;}
    int getysize(){return this->ysize;}

    SquareTile*** get2dArray(){return c;}
    void set2dArray(int size){c = new SquareTile**[size];}

    int getSize(){return getxsize();}

    bool WithenBounds(int p){
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
            cout<<k<<"  ";
        }
        cout<<endl;
        for(int i = 0; i < this->getysize() ;i++){ // printing row numbers
            //this if else statement just fixes the SquareBoard
            if(i+1 >= this->getysize()){
                cout<<i+1<<" ";
            }
            else{
                cout << i + 1 << "  ";
            }
            for (int j = 0;j<this->getysize();j++){
                get2dArray()[i][j]->printTile(); // printing the tile shape, which is, for now, 2 brackets.
            }
            cout<<endl;
        }
    }

    SquareTile* GetTileAtPoint(int x,int y){return get2dArray()[y-1][x-1];}
    void FillBoardWithTiles(){
        set2dArray(getxsize());

        for (int i = 0;i<getxsize();i++){
            get2dArray()[i] = new SquareTile*[getysize()];//creating space for rows

            for (int j = 0; j<getysize();j++){
                get2dArray()[i][j] = new SquareTile();//filling up the 2d array with square tiles;
                get2dArray()[i][j]->setCoord(j+1,i+1);//just helping us remember the cords
                get2dArray()[i][j]->setNeighbors();
            }
        }
    }

    void displayalltiles(){
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

class SimpleBoard : public SquareBoard {
private:
public:
    SimpleBoard() : SquareBoard(7, 7, 5) {}
};

class MediumBoard : public SquareBoard {
private:

public:
    MediumBoard(): SquareBoard(10, 10, 9) {
    }
};

class AdvBoard : public SquareBoard {

public:
    AdvBoard(): SquareBoard(13, 13, 12) {
    }
};

//----------Game_Generate classes-----------------//
class Generate {
    Board* gameBoard;
public:
    void setBoard(Board* b) {gameBoard = b;};
    Board* getBoard() {return gameBoard;};
    virtual void setBombs()=0;
};

class RandomGeneration : public Generate {
public:
    RandomGeneration()
    :Generate(){}

    int * shuffle(int upperBound) {
        srand(time(0)); //srand(time(o)) will set the seed to current time
        //srand(100);    //srand(100) will set the seed to 100;

        //declare an array with a number of elements, elements, 0 to upperBound-1
        int *a = new int[upperBound];
        for(int i=0; i<upperBound; i++)
            a[i] = i;
        random_shuffle(a, a + upperBound);

        return a;
    }

    void setBombs() {
        int *shuffledRows = this->shuffle(this->getBoard()->getSize());
        int *shuffledCols = this->shuffle(this->getBoard()->getSize());
        Tile *t;
        int j = getBoard()->getSize()-1;
        for (int i=0; i<this->getBoard()->getnummines(); i++) {
            t = this->getBoard()->GetTileAtPoint(shuffledRows[i]+1,shuffledCols[j]+1);
            t->setMine();
            j--;
        }
    }
};

class PlannedGeneration : public Generate {
public:
    PlannedGeneration()
    : Generate(){}

    void setBombs() {
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
    Board* gameBoard;
public:
    void setBoard(Board* b){gameBoard = b;}
    Board* getBoard(){return gameBoard;}

    virtual void flipTile()=0;
    virtual void flagTile()=0;
    virtual void unflagTile()=0;
    virtual void printRules()=0;
    virtual int playGame()=0;
};

class SquareRules : public Rules {
    int row;
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

    void setRow(int r) { row = r; }
    int getRow(){return row;}

    int getCol(){return col;}
    void setCol(int c) {col = c;}

    void rows_and_columns() {
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

    void printRules() {
        cout << "(1) flip -- flips a tile of your choosing" << endl;
        cout << "(2) flag -- flags a tile of your choosing" << endl;
        cout << "(3) unflag -- unflags a tile of your choosing" << endl;
        cout << "(4) rules -- prints the rules" << endl;
        cout << "(5) stop -- stops the game" << endl;
    }
};

class SimpleSquareRules : public SquareRules {
public:
    SimpleSquareRules()
    :SquareRules(){}

    void printRules(){
        cout<<"Valid commands for a Simple Square game include: "<<endl;
        SquareRules::printRules();
        cout<<"(6) revealT -- reveals one tile of your choosing"<<endl;
        cout<<"(7) revealB -- reveals 1 bomb of your choosing"<<endl;
        cout<<"\n";
    }

    void revealTile(){
        this->rows_and_columns();
        Tile* t = this->getBoard()->GetTileAtPoint(this->getCol(),this->getRow());
        t->changeDisplay("r");
        this->getBoard()->printBoard();
        cout<<"Tile revealed."<<endl;
    }

    void revealBomb(){
        this->rows_and_columns();
        Tile* t = this->getBoard()->GetTileAtPoint(this->getCol(),this->getRow());
        t->changeDisplay("B");
        this->getBoard()->printBoard();
        cout<<"Bomb revealed."<<endl;
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
            else if (command == "revealT") {
                this->revealTile();
            }
            else if (command == "revealB") {
                this->revealBomb();
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

class MediumSquareRules : public SquareRules {
public:
    MediumSquareRules()
    :SquareRules(){}

    void printRules(){
        cout<<"Valid commands for a Medium Square game include: "<<endl;
        SquareRules::printRules();
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

class AdvSquareRules : public SquareRules {
public:
    AdvSquareRules()
    :SquareRules(){}

    void printRules(){
        cout<<"Valid commands for a Advanced Square game include: "<<endl;
        SquareRules::printRules();
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
            } else if (command == "flag") {
                this->flagTile();
            } else if (command == "unflag") {
                this->unflagTile();
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
// Setters and getters //
    void setRules(Rules* rules){gameRules = rules;}
    void getRules(){return gameRules->printRules();}

    void setBoard(Board* board){gameBoard = board;}
    void getBoard(){gameBoard->printBoard();}

    void setTile(Tile* tile){gameTile = tile;}
    void getTile(){}

    void setGeneration(Generate* generation) {gameGeneration = generation;}

    Board* rboard(){return this->gameBoard;}

    int playGame(){
        cout<<"Game built."<<endl;

        this->getRules();
        this->getBoard();
        this->getTile();

        gameGeneration->setBoard(this->rboard());
        gameGeneration->setBombs();
        cout<<"--------------------------------------------------------------------------------"<<endl;
        gameRules->setBoard(gameGeneration->getBoard());
        gameRules->playGame(); // see SquareRules.cpp for implementation
        return 0;
    }
};

//-------------GameBuilder classes------------------------------------//
class GameBuilder {
public:
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

    void buildRules() {
        Rules* simpleSquareRules = new SimpleSquareRules();
        game->setRules(simpleSquareRules);
        // send the square board to the Rules class
    }

    void buildBoard() {
        SquareBoard* simpleBoard = new SimpleBoard(); //TODO: Simple Square Board
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

class MediumSquareBuilder : public GameBuilder {
    Game* game;
public:
    MediumSquareBuilder() {
        this->game = new Game();
    }

    void buildRules() {
        Rules* mediumsquarerules = new MediumSquareRules();
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

class AdvSquareBuilder : public GameBuilder {
    Game* game;
public:
    AdvSquareBuilder() {
        this->game = new Game();
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
        SquareBoard* advBoard = new AdvBoard();
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

//----------------GameEngineer class------------------------//
class GameEngineer {
    GameBuilder* gameBuilder;
public:
    // SimpleSquareBuilder specification is sent to the engineer
    GameEngineer(GameBuilder *gameBuilder) {
        this->gameBuilder = gameBuilder;
    }

    // Return the Game made from the SimpleSquareBuilder spec
    Game* getGame() {
        return this->gameBuilder->getGame();
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

int userhandler();

int main() {
    // Get a GameBuilder of type SimpleSquareBuilder
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
    firstGame->playGame();
}

int userhandler(){
    int usera = NULL;
    cout << "Welcome to Minesweeper" << endl;
    cout << "select from the following choices" << endl;
    while(usera < 1 || usera > 3) {
        if (usera != NULL){
            cout<<"You entered in an incompatible option please select from these options"<<endl;
        }
        cout << "1: Simple Square Game" << endl;
        cout << "2: Medium Square Game" << endl;
        cout << "3: Advanced Square Game" << endl;
        cin>>usera;
        cout<<endl;
    }
    return usera;
}
