#include "Player.h"
#include"Novice.h"
Player::Player(char* keys, char* preKeys) {
	pos_ = { 1280 / 2,500 };
	size_ = 10;
	speed_ = 3;
	keys_ = keys;
	preKeys_ = preKeys;
}

Player::~Player() {
	for (Bullet* bullet : bullets_) {
		delete bullet;
	}
}
void Player::Update() {
	if (keys_[DIK_A]&& pos_.x >= size_) {
		pos_.x -= speed_;
	}
	if (keys_[DIK_D] && pos_.x <= 1280-size_) {
		pos_.x += speed_;
	}
	
	if (keys_[DIK_SPACE] && !preKeys_[DIK_SPACE]) {
		Bullet* newbullet = new Bullet(pos_);
		bullets_.push_back(newbullet);
	}
	for(Bullet* bullet : bullets_) {
		bullet->Update();
	}
	bullets_.remove_if([](Bullet* bullet) {
		if (bullet->IsDead()) {
			delete bullet;
			return true;
		}
		return false;
		});

}
void Player::Draw() {
	Novice::DrawEllipse((int)pos_.x,(int) pos_.y,(int) size_,(int) size_, 0.f, WHITE, kFillModeSolid);
	for (Bullet* bullet : bullets_) {
		bullet->Draw();
	}

}