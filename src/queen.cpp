#include "queen.h"

vector<string> Queen::getLegalMoves(Board b) {
    legalMoves.clear();

    string moves [] = {
    };

    for(unsigned int i = 0; i < sizeof(moves)/sizeof(moves[0]); i++) {
        if (b.inBounds(moves[i]))
            legalMoves.push_back(moves[i]);
    }

    return legalMoves;
}
