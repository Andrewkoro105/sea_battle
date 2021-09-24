#pragma once

class fiend
{
private:
	void gener();
	char a[10][10];
	char b[10][10];
public:
	int player;

	fiend(int player);
	fiend(int player, bool avto);

	void get();
	void set();
	void Shot(fiend enemu);
	void get2Fiend(fiend Player2);
};