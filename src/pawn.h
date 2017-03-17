#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn: public Piece {
public:
    vector<string> getLegalMoves(Board b);
};

#endif
