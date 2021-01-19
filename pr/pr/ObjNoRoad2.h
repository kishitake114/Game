#pragma once
//使用するヘッダー
#include "GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;
#define NO 17

class CObjNoRoad2 :public CObj
{
public:
	CObjNoRoad2() {};
	~CObjNoRoad2() {};
	void Init();
	void Action();
	void Draw();
private:
	int map[NO][NO];
};