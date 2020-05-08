#include "GameEngineer.cpp"
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

    cout<<"Game built."<<endl;

    firstGame->getRules();
    firstGame->getBoard();
    firstGame->getTile();
    firstGame->getGeneration();

/*
    //This is where I am testing to make sure the neighbors work;
    cout<<"which tile would you like to see neighbors"<<endl;
    int a;
    int b;
    cout<<"X: ";
    cin >> a;
    cout << endl <<"Y: ";
    cin >> b;
    cout <<endl;
    Tile* testtile = firstGame->rboard()->GetTileAtPoint(a,b);
    for(int i = 0;i<8;i++){
        
        cout<< "Col: " << testtile->getcolNeighbors(i)<<"   ";
        if(testtile->getNeighbors()[i] != NULL){
            cout<< "Col: " << testtile->getNeighbors()[i]->getXCoord()<<endl;
        }
        else{
            cout<<"Col or Row was out of bounds" <<endl;
        }
        
        
        cout<< "Row: " << testtile->getrowNeighbors(i)<<"   ";
        if(testtile->getNeighbors()[i] != NULL){
            cout<< "Row: " << testtile->getNeighbors()[i]->getYCoord()<<endl<<endl;
        }
        else{
            cout<< "Col or Row was out of bouds"<<endl<<endl;
        }
    }
    //changing display of all of the neighbors
    for(int j = 0;j<8;j++){
        Tile* changedisplaytest = testtile->getNeighbors()[j];
        if(changedisplaytest != NULL){
            changedisplaytest->changeDisplay("1");
        }
    }

    firstGame->getBoard();
*/
    firstGame->playGame();
    /*
    Tile* t = firstGame->rboard()->GetTileAtPoint(1,2);
    t->ChangeDisplay("x ");
    firstGame->getBoard();
    cout<<"X: "<<t->getxcord()<<endl;
    cout<<"Y: "<<t->getycord()<<endl;
    return 0;
    */
}
int userhandler(){
    int usera = NULL;
    cout << "Welcome to Minesweeper" << endl;
    cout << "select from the following choices" << endl;
    while(usera < 1 || usera > 3) {
        if (usera != NULL){
            cout<<"You entered in an incompatable option please select from these options"<<endl;
        }
        cout << "1: Simple Square Game" << endl;
        cout << "2: Medium Square Game" << endl;
        cout << "3: Advanced Square Game" << endl;
        cin>>usera;
        cout<<endl;
    }
    return usera;
}
