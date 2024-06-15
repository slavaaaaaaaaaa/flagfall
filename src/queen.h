#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

class Queen: public Piece {
public:
    std::vector<std::string> getLegalMoves(Board b);
};

#endif
