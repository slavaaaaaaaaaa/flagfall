#ifndef BOARD_HPP
#define BOARD_HPP

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
};

#endif
