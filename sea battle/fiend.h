#pragma once

class fiend
{
private:
	void gener();
	void getStr(int str);
public:
	char a[10][10];
	char b[10][10];
	int player;
	int pointShip;
	bool win;

	fiend(int player, bool avto);

	void get();
	void set();
	void getStr_A(int str);
	bool Shot(fiend &enemu);
	void get2Fiend(fiend Player2);
};