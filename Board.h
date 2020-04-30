
#ifndef MINESWEEPERBUILDER_BOARD_H
#define MINESWEEPERBUILDER_BOARD_H

// An interface that defines what all kinds of Boards need.
class Board {
    private:
    int xsize;
    int ysize;
    int mines;
    
public:
    virtual void printBoard()=0;
    Board(int xsize,int ysize,int mines);
    // might consider making the destructors in base classes virtual to avoid memory leaks in derived classes.
    int getxsize();
    int getysize();
    int getnummines();
    
};

#endif //MINESWEEPERBUILDER_BOARD_H
