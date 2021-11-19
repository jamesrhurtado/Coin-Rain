#include "Bullet.h"

Bullet::Bullet(){}
Bullet::Bullet(int x, int y, int direction) : Base(x, y, 4, 4, 0, 0){
	this->direction = direction;
	this->dy = dx = 10;
}

void Bullet::move(Graphics^ g) {
	if (direction == 0 && y + h * 1.0 <= g->VisibleClipBounds.Height) {
		y += dy;
	}

	if (direction == 1 && y >= 0) {
		y -= dy;
	}

	if (direction == 2 && x + w * 1.0 <= g->VisibleClipBounds.Width) {
		x += dx;
	}

	if (direction == 3 && x >= 0) {
		x -= dx;
	}

	if (this->y + this->dy + this->h > g->VisibleClipBounds.Height || this->y + this->dy <= 0) {
		this->dy = 0;
		setRemove(true);
	}

	if (this->x + this->dx + this->w > g->VisibleClipBounds.Width || this->x + this->dx <= 0) {
		this->dx = 0;
		setRemove(true);
	}

	idx++;
	if (idx > maxidx) {
		idx = 0;
	}
}

Bullet::~Bullet() {}
