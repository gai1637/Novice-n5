#pragma once
#include"Novice.h"
enum SCENE{TITLE,STAGE,CLEAR,SceneMax};
class IScene
{
protected:
	static int sceneNo;
	char* keys_;
	char* preKeys_;
public:
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	virtual ~IScene();

	int GetSceneNo();
	void SetKeys(char* keys, char* preKeys);
};

