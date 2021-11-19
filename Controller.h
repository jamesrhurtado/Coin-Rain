#pragma once
#include "Bullet.h"
#include "Coin.h"
#include "Soldier.h"
class Controller
{
private:
	vector<Bullet*> arrBullets;
	Soldier* _soldier;
	vector<Coin*> arrCoins;
	time_t timeCoin;
	time_t timeStarts;
	bool soldierLose;

public:
	Controller();
	//void drawSoldier(Graphics^ g, Bitmap^ bmp);
	//void drawCoins(Graphics^ g, Bitmap^ bmp);
	//void drawBullets(Graphics^ g, Bitmap^ bmp);
	void drawEverything(Graphics^ g, Bitmap^ bmpSoldier, Bitmap^ bmpCoins, Bitmap^ bmpBullets);
	void shootBullet();
	void addCoin();
	void moveSoldier(Graphics^ g, char i);
	void moveBullet(Graphics^ g);
	void moveCoin(Graphics^ g);
	void collision();
	bool getSoldierLose();

	~Controller();





};

