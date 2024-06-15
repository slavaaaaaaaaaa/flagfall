#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn: public Piece {
public:
    std::vector<std::string> getLegalMoves(Board b);
};

#endif
