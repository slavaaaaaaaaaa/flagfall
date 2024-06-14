#include "board.h"


Board::Board() {
    std::cout << "making a bored" << std::endl;
    this->moves = 0;
}

int Board::getMoves() {
    return this->moves;
}

Piece* Board::at(std::string pos) {
    std::cout << "checking for duders at " << pos << "\n";
    int x = pos[0];
    //int y = boost::lexical_cast<int>(pos[1]);
    int y = pos[1] - '0'; // subtracting the ASCII value of '0' to get the integer
    if (!this->matrix[pos[0]-97][pos[1]-1])
        return nullptr;
    else if (x < 'a' || x > 'h' || y < 1 || y > 8)
        return nullptr;
    else
        return this->matrix[pos[0]-97][pos[1]-1];
}

bool Board::inBounds(std::string pos) {
    std::cout << "checking for bounds at " << pos << "\n";
    int x = pos[0];
    //int y = boost::lexical_cast<int>(pos[1]);
    int y = pos[1] - '0'; // subtracting the ASCII value of '0' to get the integer
    if (x < 'a' || x > 'h' || y < 1 || y > 8)
        return false;
    else
        return true;
}
