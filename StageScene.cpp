#include "StageScene.h"
#include"Novice.h"
#include"Player.h"
#include"Enemy.h"
#include"Vector2.h"
#include"Bullet.h"
void StageScene::Init() {
	player = std::make_unique<Player>(keys_,preKeys_);
	enemy = std::make_unique<Enemy>();
}

void StageScene::Update() {
	player->Update();
	enemy->Update();
	ChackAllCollisions();
	if (enemy->GetDead()) {
		sceneNo = CLEAR;
	}
}
void StageScene::Draw() {
	player->Draw();
	enemy->Draw();
}
void StageScene::ChackAllCollisions() {
	Vector2 posA, posB;
	const std::list<Bullet*>& bullets = player->Getbullets();
	posA = enemy->GetPos();
	for (Bullet* bullet : bullets) {
		posB = bullet->GetPos();
		float X = posA.x - posB.x;
		float Y = posA.y - posB.y;
		float Dist = sqrtf(X * X + Y * Y);
		if (Dist <= enemy->Getsize() + bullet->Getsize()) {
			enemy->OnCollision();
			bullet->OnCollision();

		}
	}
}