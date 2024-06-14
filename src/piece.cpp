#include "piece.h"

//TODO: objectize the position
Piece::Piece() {
    std::cout << "making a peace" << "\n";
    this->posx = 'a';
    this->posy = 1;
    this->calculatePosition();
    this->color = 'w';
    this->moveCounter = 0;
//    this->legalMoves = {};
}

Piece::Piece(char newPosx, int newPosy, char newColor) {
    std::cout << "making a peace" << "\n";
    this->posx = newPosx;
    this->posy = newPosy;
    this->calculatePosition();
    this->color = newColor;
    this->moveCounter = 0;
//    this->legalMoves = {};
}

Piece::Piece(std::string newPos, char newColor) {
    std::cout << "making a peace" << "\n";
    this->pos = newPos;
    this->calculateCoords();
    this->color = newColor;
    this->moveCounter = 0;
//    this->legalMoves = {};
}

void Piece::calculatePosition() {
    this->pos = posx + std::to_string(posy);  // Getting rid of boost dependency
    this->legalMoves.clear();
}

void Piece::calculateCoords() {
    this->posx = this->pos[0];
    this->posy = this->pos[1] - '0';
    this->legalMoves.clear();
}

char Piece::getPosx() {
    return this->posx;
}

int Piece::getPosy() {
    return this->posy;
}

std::string Piece::getPos() {
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

void Piece::setPos(std::string newPos) {
    this->pos = newPos;
    calculateCoords();
}

void Piece::setColor(char newColor) {
    this->color = newColor;
    this->legalMoves.clear();
}

void Piece::printMe() {
    std::cout << "I'm a piece: " << "\n"
            "\tpos x: \t" << this->posx << "\n"
            "\tpos y: \t" << this->posy << "\n"
            "\tpos: \t" << this->pos << "\n"
            "\tcolor: \t" << this->color << "\n"
            "\tmoves: \t" << this->moveCounter << "\n"
            "\tlegalMoves: \t";

    for (std::vector<std::string>::const_iterator m = this->legalMoves.begin(); m != this->legalMoves.end(); ++m)
        std::cout << *m << ' ';

    std::cout << "\n";
}

std::vector<std::string> Piece::getLegalMoves(Board b) {
    return legalMoves;
}
