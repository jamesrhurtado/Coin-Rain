#include "Soldier.h"


Soldier::Soldier(){}
Soldier::Soldier(int x, int y): Base(x, y, 4, 4, 0,0){
	this->dx = dy = 10;
}

void Soldier::move(Graphics^ g, char i){
	switch (i){
	case 'A':
		if (this->x > 0) {
			this->x -= this->dx;
			this->idy = 3;
		}
		break;

	case 'D':
		if (this->x + this->w * 1.0 < g->VisibleClipBounds.Width) {
			this->x += this->dx;
			this->idy = 2;
		}
		break;

	case 'W':
		if (this->y > 0) {
			this->y -= this->dy;
			this->idy = 1;
		}
		break;

	case 'S':
		if (this->y + this->h * 1.0 < g->VisibleClipBounds.Height) {
			this->y += this->dy;
			this->idy = 0;
		}
		break;
	}
	idx++;
	if (idx >= maxidx) {
		idx = 0;
	}
}

Soldier::~Soldier(){}
