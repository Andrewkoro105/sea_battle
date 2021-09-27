#include"fiend.h"
#include <iostream>
#include <cmath>

using namespace std;

void fiend::get2Fiend(fiend Player2)
{
	system("cls");
	cout << "SEA BATTLE\n";
	if (player == 1)
		cout << "   Player-1 <- shoot              Player-2\n";
	else
		cout << "   Player-1                       Player-2 <- shoot\n";
	cout << "   A B C D E F G H I J    |       A B C D E F G H I J\n";

	for (int x = 0; x < 10; x++)
	{
		char litter = x + 49;

		if (x == 9)// равнение боковых цифр по правой стороне
			cout << 10;
		else
			cout << ' ' << litter;

		if (player == 1)//какое поле рисовать первым (всегда 1)
			getStr(x);
		else
			Player2.getStr(x);
		cout << "    |    ";

		if (x == 9)// равнение боковых цифр по правой стороне
			cout << 10;
		else
			cout << ' ' << litter;

		if (player == 2)//какое поле рисовать вторым (всегда 2)
			getStr(x);
		else
			Player2.getStr(x);
		cout << endl;
	}
}


void fiend::getStr(int str)
{
	for (int y = 0; y < 10; y++)
	{
		cout << ' ' << b[y][str];
	}
}

fiend::fiend(int player, bool avto)
{
	this->player = player;
	gener();

	if (avto)
	{
		int ships[10][4] = {
			{0, 0, 0, 3},
			{2, 0, 2, 2},
			{4, 0, 4, 2},
			{6, 0, 6, 1},
			{8, 0, 8, 1},
			{0, 8, 0, 9},
			{2, 9, 2, 9},
			{4, 9, 4, 9},
			{6, 9, 6, 9},
			{8, 9, 8, 9},
		};
		for (int i = 0; i < 10; i++)
		{
			for (int x = ships[i][0]; x <= ships[i][2]; x++)
			{
				for (int y = ships[i][1]; y <= ships[i][3]; y++)
				{
					a[x][y] = 'O';
				}
			}
		}
	}
	else
	{
		get();
		set();
	}
}

void fiend::gener()
{
	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			a[x][y] = '~';
			b[x][y] = '~';
		}
	}
}

void fiend::get()//ВЫВОД ПОЛЯ
{
	system("cls");
	cout << "SEA BATTLE\nplayer - " << player << endl;
	cout << "   A B C D E F G H I J\n";

	for (int x = 0; x < 10; x++)
	{
		char litter = x + 49;
		
		if (x == 9)
			cout << 10;
		else
			cout << ' ' << litter;

		for (int y = 0; y < 10; y++)
		{
			cout << ' ' << a[y][x];
		}
		cout << '\n';
	}
}

void fiend::set()
{
	int ships[4] = { 0, 0, 0, 0 };

	for (int i = 0; i < 10; i++)
	{
		cout << "\nenter the coordinates of the ships" << endl;

		cout << "[first point] [space] [second point] (Caps Lock)" << endl;

		char ship[100];


		int x, y, x1, y1, distans;
		bool horizontal, ok = true;

		do
		{
			if (!ok)
			{
				ships[distans - 1]--;
				cout << "try again\n";
			}

			gets_s(ship);

			x = ship[0]; x -= 65;

			int _i = 0;//смещение для чтения вторых координат
			
			if (ship[2] == ' ')
			{
				y = ship[1]; y -= 49;
			}
			else
			{
				y = 9;
				_i++;
			}

			x1 = ship[3 + _i]; x1 -= 65;

			if (ship[_i + 5] == '0')
			{
				y1 = 9;
			}
			else
			{
				y1 = ship[4 + _i]; y1 -= 49;
			}

			horizontal = (y == y1);
			distans = (horizontal ? abs(x - x1) : abs(y - y1)) + 1;
			ships[distans - 1]++;
			ok = ((y == y1 || x == x1) && distans < 5) && ships[0] <= 4 && ships[1] <= 3 && ships[2] <= 2 && ships[3] <= 1;// проверка на количество короблей и возмодночть такого корабля

			int 
				_x1 = (x < x1 ? x : x1) - 1,
				_x2 = (x > x1 ? x : x1) + 1,
				_y1 = (y < y1 ? y : y1) - 1,
				_y2 = (y > y1 ? y : y1) + 1;

			for (int _x = _x1; _x <= _x2 && ok; _x++) //проверка на наличие караблей вокруг
				if (_x == -1 || _x == 10) continue;
				else
					for (int _y = _y1; _y <= _y2 && ok; _y++)
						if (_y == -1 || _y == 10) continue;
						else
							ok = (a[_x][_y] != 'O');

		} while (!ok);

		pointShip = 20;

		for (int _x = x < x1 ? x : x1; _x <= (x > x1 ? x : x1); _x++)//ВЫСТОВЛЕНИЕ КОРАБЛЯ
		{
			for (int _y = y < y1 ? y : y1; _y <= (y > y1 ? y : y1); _y++)
			{
				a[_x][_y] = 'O';
			}
		}
		system("cls");
		cout << "delivered" << distans << endl;
		get();
	}
}

bool fiend::Shot(fiend &enemy)
{
	get2Fiend(enemy);

	cout << "\nenter the coordinates of the shoot\n";

	char shotСoord[100];

	int x, y;
	bool unOk = false;

	do
	{
		gets_s(shotСoord);


		x = shotСoord[0]; x -= 65;

		if (shotСoord[2] == '0')
			y = 9;
		else 
		{
			y = shotСoord[1]; y -= 49;
		}

		unOk = x < 0 || x > 9 || y < 0 || y > 9;

		if (unOk)
			cout << "try again\n";

	} while (unOk);
	
	if (enemy.a[x][y] == 'O')
	{
		enemy.b[x][y] = 'X';
		pointShip--;
		return true;
	}
	else
	{
		enemy.b[x][y] = '0';
		return false;
	}
}