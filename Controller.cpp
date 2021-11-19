#include "Controller.h"

Controller::Controller(){
	this->_soldier = new Soldier(10, 10);
	this->timeCoin = time(0);
	this->timeStarts = time(0);
	this->soldierLose = false;
} 

void Controller::drawEverything(Graphics^ g, Bitmap^ bmpSoldier, Bitmap^ bmpCoins, Bitmap^ bmpBullets) {
	_soldier->drawFromImage(g, bmpSoldier);

	for each (Bullet * b in arrBullets) {
		b->drawFromImage(g, bmpBullets);
	}

	for each (Coin * c in arrCoins) {
		c->drawFromImage(g, bmpCoins);
	}

	for (int i = 0;i <arrBullets.size(); i++) {
		if (arrBullets.at(i)->getRemove()) {
			arrBullets.erase(arrBullets.begin()+ i);
		}
	}

}
void Controller::moveSoldier(Graphics^ g, char i) {
	_soldier->move(g, i);
}

void Controller::shootBullet() {
	arrBullets.push_back(new Bullet(_soldier->getX(), _soldier->getY(), _soldier->getIdy()));
}

void Controller::addCoin(){
	if (difftime(time(0), timeCoin) > rand() % 20 + 1) {
		arrCoins.push_back(new Coin(rand() % 600 + 10, rand() % 100 + 30, rand() % 4 + 1));
		timeCoin = time(0);
	}

	for (int i = 0; i < arrCoins.size(); i++) {
		if (arrCoins.at(i)->getRemove()) {
			arrCoins.erase(arrCoins.begin() + i);
		}
	}

}

void Controller::moveBullet(Graphics^ g) {
	for each (Bullet* b in arrBullets) {
		b->move(g);
	}

}

void Controller::moveCoin(Graphics^ g) {
	for each (Coin* c in arrCoins) {
		c->move(g);
	}
}

void Controller::collision() {
	for (int i = 0; i < arrBullets.size(); i++) {
		for (int j = 0; j < arrCoins.size(); j++) {
			if (arrBullets.at(i)->getRectangle().IntersectsWith(arrCoins.at(j)->getRectangle()) && difftime(time(0), timeStarts) > 1) {
				if (arrCoins.at(j)->getType() == 1) {
					this->soldierLose = true;
				}
				if (arrCoins.at(j)->getType() == 2 || arrCoins.at(j)->getType() == 3) {
					arrCoins.at(j)->decreaseLives();
				}
				if (arrCoins.at(j)->getNLives() <= 0) {
					arrCoins.at(j)->setRemove(true);
				}
				arrBullets.at(i)->setRemove(true);
				this->timeStarts = time(0);
			}
		}
	}
}

bool Controller::getSoldierLose() {
	return this->soldierLose;

}

Controller::~Controller() {}
