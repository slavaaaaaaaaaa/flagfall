#ifndef PIECE_HPP
#define PIECE_HPP

#include <string>
#include <vector>
#include <iostream>
#include <boost/lexical_cast.hpp>

using namespace std;

class Piece {
private:
    char posx;
    int posy;
    string pos;

    char color;
    int moveCounter;
    vector<string> legalMoves;

    void calculatePosition();
    void calculateCoords();

    friend ostream& operator<<(ostream&, const Piece&);
public:
    Piece();
    Piece(char newPosx, int newPosy, char newColor);
    Piece(string newPos, char newColor);

    char getPosx();
    int getPosy();
    string getPos();
    char getColor();

    void setPosx(char newPosx);
    void setPosy(int newPosy);
    void setPos(string newPos);
    void setColor(char newColor);
};
#endif
