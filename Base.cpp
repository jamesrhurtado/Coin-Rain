#include "Base.h"
Base::Base() {
	this->remove = false;
	this->dx = 0;
	this->dy = 0;
}

Base::Base(int x, int y, int maxidy, int maxidx, int idy, int idx) {
	this->x = x;
	this->y = y;
	this->remove = false;
	this->dx = dy = 0;
	this->maxidx = maxidx;
	this->maxidy = maxidy;
	this->idx = idx;
	this->idy = idy;
}

Base::~Base() {}

void Base::setX(int nuevo) {
	this->x = nuevo;
}

void Base::setY(int nuevo) {
	this->y = nuevo;
}

void Base::setH(int nuevo) {
	this->h = nuevo;
}

void Base::setW(int nuevo) {
	this->w = nuevo;
}

void Base::setDx(int nuevo) {
	this->dx = nuevo;
}

void Base::setDy(int nuevo) {
	this->dy = nuevo;
}

void Base::setIdx(int nuevo) {
	this->idx = nuevo;
}

void Base::setIdy(int nuevo) {
	this->idy = nuevo;
}

void Base::setMaxidy(int nuevo) {
	this->maxidy = nuevo;
}

void Base::setMaxidx(int nuevo) {
	this->maxidx = nuevo;
}

void Base::setRemove(bool nuevo) {
	this->remove = nuevo;
}

int Base::getX() {
	return this->x;
}

int Base::getY() {
	return this->y;
}

int Base::getW() {
	return this->w;
}

int Base::getH() {
	return this->h;
}

int Base::getDx() {
	return this->dx;
}

int Base::getDy() {
	return this->dy;
}

int Base::getIdx() {
	return this->idx;
}

int Base::getIdy() {
	return this->idy;
}

int Base::getMaxidy() {
	return this->maxidy;
}

int Base::getMaxidx() {
	return this->maxidx;
}

bool Base::getRemove() {
	return this->remove;
}

Rectangle Base::getRectangle() {
	return Rectangle(x, y, w * 1.0, h * 1.0);
}

void Base::move(Graphics^ g) {
	//this move method bounces back. For keeping it still when reaches a border
	//dx must be 0, but that'd be on other method
	if (this->x + this->dx<1 || this->x + this->dx + this->w > g->VisibleClipBounds.Width)
		this->dx = this->dx * -1;

	if (this->y + this->dy<1 || this->y + this->dy + this->h > g->VisibleClipBounds.Height)
		this->dy = this->dy * -1;
	this->y += this->dy;
	this->x += this->dx;
	//assumes the sprite has just one column
}

void Base::drawFromImage(Graphics^ g, Bitmap^ bmp) {
	this->w = bmp->Width / this->maxidx;
	this->h = bmp->Height / this->maxidy;

	//portion of the sprite that will be shown
	Rectangle sectionShown = Rectangle(idx * w, idy * h, w, h);
	//zoom in or out and location of the image
	Rectangle zoom = Rectangle(x, y, w * 1.0, h * 1.0);

	g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);


}



