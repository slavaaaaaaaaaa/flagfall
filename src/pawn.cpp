#include "pawn.h"

std::vector<std::string> Pawn::getLegalMoves(Board b) {
    legalMoves.clear();

    std::string moves [4] = {
        this->posx + std::to_string(this->posy + 1), // up one
        this->posx + std::to_string(this->posy + 2), // up two
        static_cast<char>(this->posx - 1) + std::to_string(this->posy + 1), // diag left
        static_cast<char>(this->posx + 1) + std::to_string(this->posy + 1) // diag right
    };

    if (!b.at(moves[0]))
        legalMoves.push_back(moves[0]); // up one
    if (!b.at(moves[1]) && this->moveCounter == 0)
        legalMoves.push_back(moves[1]); // up two
    if (b.at(moves[2]))
        legalMoves.push_back(moves[2]); // diagonal to the left
    if (b.at(moves[3]))
        legalMoves.push_back(moves[3]); // diagonal to the right

    return legalMoves;
}
