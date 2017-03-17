#include "board.h"

Board::Board() {
    cout << "making a bored" << endl;
    this->moves = 0;
}

int Board::getMoves() {
    return this->moves;
}

Piece* Board::at(string pos) {
    cout << "checking for duders at " << pos << endl;
    int x = pos[0];
    int y = boost::lexical_cast<int>(pos[1]);
    if (!this->matrix[pos[0]-97][pos[1]-1])
        return NULL;
    else if (x < 'a' || x > 'h' || y < 1 || y > 8)
        return NULL;
    else
        return this->matrix[pos[0]-97][pos[1]-1];
}

bool Board::inBounds(string pos) {
    cout << "checking for bounds at " << pos << endl;
    int x = pos[0];
    int y = boost::lexical_cast<int>(pos[1]);
    if (x < 'a' || x > 'h' || y < 1 || y > 8)
        return false;
    else
        return true;
}
