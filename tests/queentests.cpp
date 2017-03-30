#include <iostream>
#include "../src/piece.cpp"
#include "../src/queen.cpp"
#include "../src/board.cpp"

using namespace std;

int main()
{
    cout << "time to test some queen bees" << endl;
    Queen bee;
    bee.printMe();
    Board board;
    cout << "the board has " << board.getMoves() << " moves" << endl;

    bee.getLegalMoves(board);

    bee.printMe();

    bee.setPos("e2");
    bee.printMe();
    bee.getLegalMoves(board);
    bee.printMe();
    return 0;
}
