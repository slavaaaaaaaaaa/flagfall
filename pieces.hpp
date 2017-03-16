#ifndef PIECES_HPP
#define PIECES_HPP

#include <string>
#include <vector>
#include <iostream>
#include <boost/lexical_cast.hpp>
#include "board.hpp"

using namespace std;

class Piece {
protected:
    char posx;
    int posy;
    string pos;

    char color;
    int moveCounter;
    vector<string> legalMoves;

    void calculatePosition();
    void calculateCoords();

public:
    Piece();
    Piece(char newPosx, int newPosy, char newColor);
    Piece(string newPos, char newColor);

    char getPosx();
    int getPosy();
    string getPos();
    char getColor();
    vector<string> getLegalMoves(Board &b);

    void setPosx(char newPosx);
    void setPosy(int newPosy);
    void setPos(string newPos);
    void setColor(char newColor);

    void printMe();
};

class Pawn: public Piece {
public:
    vector<string> getLegalMoves(Board &b);
};

#endif
