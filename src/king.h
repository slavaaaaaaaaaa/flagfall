#ifndef KING_H
#define KING_H

#include "piece.h"

class King: public Piece {
public:
    vector<string> getLegalMoves(Board b);
};

#endif
