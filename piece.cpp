#include "piece.hpp"

//TODO: destructors
Piece::Piece() {
    cout << "making a peace" << endl;
    this->posx = 'a';
    this->posy = 1;
    this->calculatePosition();
    this->color = 'w';
    this->moveCounter = 0;
}

Piece::Piece(char newPosx, int newPosy, char newColor) {
    cout << "making a peace" << endl;
    this->posx = newPosx;
    this->posy = newPosy;
    this->calculatePosition();
    this->color = newColor;
    this->moveCounter = 0;
}

Piece::Piece(string newPos, char newColor) {
    cout << "making a peace" << endl;
    this->pos = newPos;
    this->calculateCoords();
    this->color = newColor;
    this->moveCounter = 0;
}

void Piece::calculatePosition() {
    this->pos = posx + boost::lexical_cast<std::string>(posy);
}

void Piece::calculateCoords() {
    this->posx = this->pos[0];
    this->posy = this->pos[1] - '0';
}

char Piece::getPosx() {
    return this->posx;
}

int Piece::getPosy() {
    return this->posy;
}

string Piece::getPos() {
    return this->pos;
}

char Piece::getColor() {
    return this->color;
}

void Piece::setPosx(char newPosx) {
    this->posx = newPosx;
    calculatePosition();
}

void Piece::setPosy(int newPosy) {
    this->posy = newPosy;
    calculatePosition();
}

void Piece::setPos(string newPos) {
    this->pos = newPos;
    calculateCoords();
}

void Piece::setColor(char newColor) {
    this->color = newColor;
}

ostream& operator<< (ostream &strm, const Piece &p) {
    return strm <<  "I'm a generic piece: " << "\n"
                    "\tpos x: \t" << p.posx << "\n"
                    "\tpos y: \t" << p.posy << "\n"
                    "\tpos: \t" << p.pos << "\n"
                    "\tcolor: \t" << p.color << "\n"
                    "\tmoves: \t" << p.moveCounter << endl;
                    //TODO: legalMoves as well
}

