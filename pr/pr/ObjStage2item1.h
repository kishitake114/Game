#pragma once
//使用するヘッダー
#include "GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;
#define NO 17

class CObjStage2item1 :public CObj
{
public:
	CObjStage2item1() {};
	~CObjStage2item1() {};
	void Init();
	void Action();
	void Draw();
private:
	int map[NO][NO];
};