#pragma once
#include <vector>
#include <iostream>
using namespace std;
using namespace System::Drawing;

class Base
{
protected:
	int x, y, w, h, dx, dy;

	bool remove;

	int idx, idy, maxidx, maxidy;
public:
	Base();
	Base(int x, int y, int maxidy, int maxidx, int idy, int idx);
	~Base();
	void setX(int v);
	void setY(int v);
	void setH(int v);
	void setW(int v);
	void setDx(int v);
	void setDy(int v);
	void setIdx(int v);
	void setIdy(int v);
	void setMaxidy(int v);
	void setMaxidx(int v);
	void setRemove(bool v);
	int getX();
	int getY();
	int getW();
	int getH();
	int getDx();
	int getDy();
	int getIdx();
	int getIdy();
	int getMaxidy();
	int getMaxidx();
	bool getRemove();
	Rectangle getRectangle();
	virtual void move(Graphics^ g);
	void drawFromImage(Graphics^ g, Bitmap^ bmp);
};
