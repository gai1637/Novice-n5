#include "Enemy.h"
#include"Novice.h"
Enemy::Enemy() {
	pos_ = { 1280 / 2,100 };
	size_ = 10;
	speed = 2;
	isLeft =1;
	isDead = false;
}
void Enemy::Update() {
	pos_.x += isLeft*speed;
	if (pos_.x <= size_ || pos_.x >= 1280 - size_) {
		isLeft *= -1;
	}
	
}
void Enemy::Draw() {
	Novice::DrawEllipse((int)pos_.x, (int)pos_.y, (int)size_, (int)size_, 0.0f, BLACK, kFillModeSolid);
}