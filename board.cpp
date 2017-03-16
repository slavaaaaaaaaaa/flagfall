#include "board.h"

Board::Board() {
    cout << "making a bored" << endl;
    this->moves = 0;
}

int Board::getMoves() {
    return this->moves;
}

Piece* Board::at(string pos) {
    cout << "checking at " << pos << endl;
    int x = pos[0] - 97;
    int y = pos[1] - 1;
    if (!this->matrix[pos[0]-97][pos[1]-1])
        return NULL;
    else if (x < 0 || x > 7 || y < 0 || y > 7)
        return NULL;
    else
        return this->matrix[pos[0]-97][pos[1]-1];
}
