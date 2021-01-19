#pragma once
//使用するヘッダー
#include "GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;
#define NO 14

class CObjStage1Lifeitem :public CObj
{
public:
	CObjStage1Lifeitem() {};
	~CObjStage1Lifeitem() {};
	void Init();
	void Action();
	void Draw();
private:
	int map[NO][NO];
};