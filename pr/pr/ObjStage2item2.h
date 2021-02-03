#pragma once
//使用するヘッダー
#include "GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;
#define HITEM22 17

class CObjStage2item2 :public CObj
{
public:
	CObjStage2item2() {};
	~CObjStage2item2() {};
	void Init();
	void Action();
	void Draw();
private:
	int map[HITEM22][HITEM22];
};