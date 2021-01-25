#pragma once
//使用するヘッダー
#include "GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;
#define NO 26

class CObjStage4item1 :public CObj
{
public:
	CObjStage4item1() {};
	~CObjStage4item1() {};
	void Init();
	void Action();
	void Draw();
private:
	int map[NO][NO];
};