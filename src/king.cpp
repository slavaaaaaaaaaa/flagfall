#include "king.h"

vector<string> King::getLegalMoves(Board b) {
    legalMoves.clear();

    string moves [] = {
        this->posx + boost::lexical_cast<std::string>(this->posy + 1), // up one
        this->posx + boost::lexical_cast<std::string>(this->posy - 1), // down one
        static_cast<char>(this->posx - 1) + boost::lexical_cast<std::string>(this->posy), // left one
        static_cast<char>(this->posx + 1) + boost::lexical_cast<std::string>(this->posy), // right one
        static_cast<char>(this->posx - 1) + boost::lexical_cast<std::string>(this->posy + 1), // left up
        static_cast<char>(this->posx + 1) + boost::lexical_cast<std::string>(this->posy + 1), // right up
        static_cast<char>(this->posx + 1) + boost::lexical_cast<std::string>(this->posy - 1), // right down
        static_cast<char>(this->posx - 1) + boost::lexical_cast<std::string>(this->posy - 1) // left down
        //TODO: castling
    };

    for(unsigned int i = 0; i < sizeof(moves)/sizeof(moves[0]); i++) {
        if (b.inBounds(moves[i]))
            legalMoves.push_back(moves[i]);
    }

    return legalMoves;
}
