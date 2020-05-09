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
