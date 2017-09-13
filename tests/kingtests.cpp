#include <iostream>
#include "../src/piece.cpp"
#include "../src/king.cpp"
#include "../src/board.cpp"

using namespace std;

int main()
{
    cout << "time to test some kinggs" << endl;
    King kong;
    kong.printMe();
    Board board;
    cout << "the board has " << board.getMoves() << " moves" << endl;

    kong.getLegalMoves(board);

    kong.printMe();

    kong.setPos("e2");
    kong.printMe();
    kong.getLegalMoves(board);
    kong.printMe();
    return 0;
}
