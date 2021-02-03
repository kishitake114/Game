#pragma once
//使用するヘッダー
#include "GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;
#define HNOROAD1 14

class CObjNoRoad1 :public CObj
{
public:
	CObjNoRoad1() {};
	~CObjNoRoad1() {};
	void Init();
	void Action();
	void Draw();
private:
	int map[HNOROAD1][HNOROAD1];
};