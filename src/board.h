#ifndef BOARD_H
#define BOARD_H

using namespace std;

class Piece;

class Board {
private:
    Piece* matrix [8][8];
    int moves;

public:
    Board(); //TODO: preset positions

    int getMoves();
    Piece* at(string pos);
    bool inBounds(string pos);
};

#endif
