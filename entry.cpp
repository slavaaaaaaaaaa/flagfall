#include <iostream>
#include "piece.cpp"

using namespace std;

main()
{
    cout << "twenty pizza a day" << endl;
    Piece pizza;

    cout << pizza << endl;

    pizza.setPos("e2");
    cout << pizza << endl;

    pizza.setPosx('e');
    cout << pizza << endl;
    pizza.setPosy(4);
    cout << pizza << endl;

    return 0;
}

