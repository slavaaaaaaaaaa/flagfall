#include <iostream>
#include "../src/piece.cpp"
#include "../src/pawn.cpp"
#include "../src/board.cpp"

using namespace std;

main()
{
    cout << "twenty pizza a day" << endl;
    Piece pizza;

    pizza.printMe();

    pizza.setPos("e2");
    pizza.printMe();

    pizza.setPosx('e');
    pizza.printMe();
    pizza.setPosy(4);
    pizza.printMe();

    Pawn pasta;
    pasta.printMe();
    Board board;
    cout << board.getMoves() << endl;

    pasta.getLegalMoves(board);

    pasta.printMe();
    //so far so good, wow

    pasta.setPos("e2");
    pasta.printMe();
    pasta.getLegalMoves(board);
    pasta.printMe();
    return 0;
}
