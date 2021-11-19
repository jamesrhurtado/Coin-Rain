#include "Coin.h"

Coin::Coin(){}

Coin::Coin(int x, int y, int type) : Base(x,y, 5, 3, 0, 0){
	this->type = type;
	//silver coin
	if (type == 1) {
		this->nLives = 1;
		this->idy = 2;
	}

	//gold without icon
	if (type == 2) {
		this->nLives = 2;
		this->idy = 4;
	}
	//gold with icon
	if (type == 3) {
		this->nLives = 2;
		this->idy =0;
	}
	this-> dy = 5;
}

void Coin::move(Graphics^ g){
	if (this->y + this->dy + this->h > g->VisibleClipBounds.Height) {
		this->dy = 0;
		setRemove(true);
	}
	this->y += this->dy;
	idx++;
	if (idx > maxidx) {
		idx = 0;
	}
}

void Coin::decreaseLives() {
	this->nLives--;
}

int Coin::getNLives() {
	return this->nLives;
}

int Coin::getType() {
	return this->type;
}

Coin::~Coin(){}
