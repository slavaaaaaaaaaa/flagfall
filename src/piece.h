#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <vector>
#include <iostream>
#include "board.h"

class Piece {
protected:
    char posx;
    int posy;
    std::string pos;

    char color;
    int moveCounter;
    std::vector<std::string> legalMoves;

    void calculatePosition();
    void calculateCoords();

public:
    Piece();
    Piece(char newPosx, int newPosy, char newColor);
    Piece(std::string newPos, char newColor);

    char getPosx();
    int getPosy();
    std::string getPos();
    char getColor();
    std::vector<std::string> getLegalMoves(Board b);

    void setPosx(char newPosx);
    void setPosy(int newPosy);
    void setPos(std::string newPos);
    void setColor(char newColor);

    void printMe();
};

#endif
