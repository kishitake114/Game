#pragma once
//使用するヘッダー
#include "GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;
#define HITEM21 17

class CObjStage2item1 :public CObj
{
public:
	CObjStage2item1() {};
	~CObjStage2item1() {};
	void Init();
	void Action();
	void Draw();
private:
	int map[HITEM21][HITEM21];
};