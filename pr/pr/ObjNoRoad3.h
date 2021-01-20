#pragma once
//使用するヘッダー
#include "GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;
#define NO  20

class CObjNoRoad3 :public CObj
{
public:
	CObjNoRoad3() {};
	~CObjNoRoad3() {};
	void Init();
	void Action();
	void Draw();
private:
	int map[NO][NO];
};