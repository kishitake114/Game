#pragma once
//使用するヘッダー
#include "GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;
#define NO 26

class CObjNoRoad4 :public CObj
{
public:
	CObjNoRoad4() {};
	~CObjNoRoad4() {};
	void Init();
	void Action();
	void Draw();
private:
	int map[NO][NO];
};