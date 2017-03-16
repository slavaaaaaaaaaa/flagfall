#include "pieces.h"

//TODO: destructor
//TODO: objectize the position
Piece::Piece() {
    cout << "making a peace" << endl;
    this->posx = 'a';
    this->posy = 1;
    this->calculatePosition();
    this->color = 'w';
    this->moveCounter = 0;
//    this->legalMoves = {};
}

Piece::Piece(char newPosx, int newPosy, char newColor) {
    cout << "making a peace" << endl;
    this->posx = newPosx;
    this->posy = newPosy;
    this->calculatePosition();
    this->color = newColor;
    this->moveCounter = 0;
//    this->legalMoves = {};
}

Piece::Piece(string newPos, char newColor) {
    cout << "making a peace" << endl;
    this->pos = newPos;
    this->calculateCoords();
    this->color = newColor;
    this->moveCounter = 0;
//    this->legalMoves = {};
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

void Piece::printMe() {
    cout << "I'm a piece: " << "\n"
            "\tpos x: \t" << this->posx << "\n"
            "\tpos y: \t" << this->posy << "\n"
            "\tpos: \t" << this->pos << "\n"
            "\tcolor: \t" << this->color << "\n"
            "\tmoves: \t" << this->moveCounter << "\n"
            "\tlegalMoves: \t";

    for (std::vector<string>::const_iterator m = this->legalMoves.begin(); m != this->legalMoves.end(); ++m)
        cout << *m << ' ';

    cout << endl;
}

vector<string> Piece::getLegalMoves(Board b) {
    return legalMoves;
}

vector<string> Pawn::getLegalMoves(Board b) {
    legalMoves.clear();

    if (!b.at(this->posx + boost::lexical_cast<std::string>(this->posy + 1)))
        legalMoves.push_back(this->posx + boost::lexical_cast<std::string>(this->posy + 1)); // one up
    if (!b.at(this->posx + boost::lexical_cast<std::string>(this->posy + 2)) && this->moveCounter == 0)
        legalMoves.push_back(this->posx + boost::lexical_cast<std::string>(this->posy + 2)); // two up
    if (b.at(static_cast<char>(this->posx + 1) + boost::lexical_cast<std::string>(this->posy + 1)))
        legalMoves.push_back(static_cast<char>(this->posx + 1) + boost::lexical_cast<std::string>(this->posy + 1)); // diagonal to the right
    if (b.at(static_cast<char>(this->posx - 1) + boost::lexical_cast<std::string>(this->posy + 1)))
        legalMoves.push_back(static_cast<char>(this->posx - 1) + boost::lexical_cast<std::string>(this->posy + 1)); // diagonal to the left

    return legalMoves;
}
