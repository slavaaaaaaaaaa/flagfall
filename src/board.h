#ifndef BOARD_H
#define BOARD_H

#include <iostream>

class Piece;

class Board {
private:
    Piece* matrix [8][8];
    int moves;

public:
    Board(); //TODO: preset positions

    int getMoves();
    Piece* at(std::string pos);
    bool inBounds(std::string pos);
};

#endif
