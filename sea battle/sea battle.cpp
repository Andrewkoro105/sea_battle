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

void final(fiend Pl1, fiend Pl2)
{
	system("cls");
	cout << "SEA BATTLE\n";
	cout << "   Player-1                       Player-2\n";
	cout << "   A B C D E F G H I J    |       A B C D E F G H I J\n";

	for (int x = 0; x < 10; x++)
	{
		char litter = x + 49;

		if (x == 9)// равнение боковых цифр по правой стороне
			cout << 10;
		else
			cout << ' ' << litter;

		Pl1.getStr_A(x);
		cout << "    |    ";

		if (x == 9)// равнение боковых цифр по правой стороне
			cout << 10;
		else
			cout << ' ' << litter;

		Pl2.getStr_A(x);
		cout << endl;
	}
}