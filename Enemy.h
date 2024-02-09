#pragma once
#include"Vector2.h"
class Enemy
{
public:
	Enemy();
	void Update();
	void Draw();
	void OnCollision() { isDead = true; }
	bool GetDead() { return isDead; }
	Vector2 GetPos() { return  pos_; }
	float Getsize() { return size_; }
private:
	Vector2 pos_;
	float size_;
	float speed;
	int isLeft;
	bool isDead;
};

