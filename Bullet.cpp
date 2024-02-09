#include "Bullet.h"
#include"Novice.h"
Bullet::Bullet(Vector2 pos) {
	pos_ = pos;
	size_ = 5;
	count_ = 600;
	speed = 2.f;
	isDead_ = false;
}
void Bullet::Update() {
	pos_.y -= speed;
	count_--;
	if (--count_ <= 0) {
		isDead_ = true;
	}
}
void Bullet::Draw() {
	Novice::DrawEllipse((int)pos_.x,(int)pos_.y, (int)size_, (int)size_, 0.0f, RED, kFillModeSolid);
}