#pragma once
//使用するヘッダー
#include "GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;
#define HITEML2 17

class CObjStage2Lifeitem :public CObj
{
public:
	CObjStage2Lifeitem() {};
	~CObjStage2Lifeitem() {};
	void Init();
	void Action();
	void Draw();
private:
	int map[HITEML2][HITEML2];
};