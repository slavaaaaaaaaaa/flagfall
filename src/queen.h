#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

class Queen: public Piece {
public:
    vector<string> getLegalMoves(Board b);
};

#endif