#include <iostream>
#include "fiend.h"

using namespace std;

int main()
{
    fiend meField(1, false);
    fiend unMeField(2, false);

    bool move1 = 1;

    do
    {
        bool secondMove = false;
        if (move1)
            secondMove = meField.Shot(unMeField);
        else
            secondMove = unMeField.Shot(meField);
        move1 = (secondMove ? move1 : !move1);
    } while (!(meField.pointShip == 0 || unMeField.pointShip == 0));

    cout << "won -> " << (meField.pointShip == 0 ? "player1" : "Player2");
}