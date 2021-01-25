#pragma once
//使用するヘッダー
#include "GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;
#define NO 20

class CObjStage3Lifeitem :public CObj
{
public:
	CObjStage3Lifeitem() {};
	~CObjStage3Lifeitem() {};
	void Init();
	void Action();
	void Draw();
private:
	int map[NO][NO];
};