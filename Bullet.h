#pragma once
#include"Vector2.h"
class Bullet
{
private:
	Vector2 pos_;
	float size_;
	int count_;
	float speed;
	bool isDead_;
public:
	Bullet(Vector2 pos);
	void Update();
	void Draw();
	bool IsDead() { return isDead_; }
	void OnCollision() { isDead_ = true; }
	Vector2 GetPos() { return  pos_; }
	float Getsize() { return size_; }
};

