#pragma once
#include "Base.h"

class Bullet : public Base
{
private:
	int direction;
public:
	Bullet();
	Bullet(int x, int y, int direction);
	void move(Graphics^ g);
	~Bullet();
};

