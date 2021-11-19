#pragma once
#include "Base.h"
class Coin : public Base {
private:
	int type;
	int nLives;
public:
	Coin();
	Coin(int x, int y, int type);
	void move(Graphics^ g);
	void decreaseLives();
	int getNLives();
	int getType();
	~Coin();


};

