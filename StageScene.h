#pragma once
#include "IScene.h"
#include<memory>
#include"Enemy.h"
#include"Player.h"
class Enemy;
class Player;
class StageScene :public IScene
{
	public:
    void Init()override;
    void Update()override;
    void Draw()override;
    void ChackAllCollisions();
private:
    std::unique_ptr<Player> player;
    std::unique_ptr<Enemy> enemy;
};

