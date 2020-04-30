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

    // The engineer returns the right robot based off of the spec sent to it.
    Game* firstGame = gameEngineer->getGame();

    cout<<"Game built."<<endl;
    firstGame->getRules();
    firstGame->getBoard();
    firstGame->getTile();
    firstGame->getGeneration();
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
    cout<<"Welcome to Minesweeper"<<endl;
    cout<<"select from the following choices"<<endl;
    cout<<"1: Simple Square Game"<<endl;
    cout<<"2: Medium Square Game"<<endl;
    cout<<"3: Advanced Square Game"<<endl;
    int usera = 0;
    cin >> usera;
    cout<<endl;
    return usera;
}
