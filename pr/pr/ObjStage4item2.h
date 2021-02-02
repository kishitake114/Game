#pragma once
//使用するヘッダー
#include "GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;
#define NO 26

class CObjStage4item2 :public CObj
{
public:
	CObjStage4item2() {};
	~CObjStage4item2() {};
	void Init();
	void Action();
	void Draw();
private:
	int map[NO][NO];
};