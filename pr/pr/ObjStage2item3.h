#pragma once
//使用するヘッダー
#include "GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;
#define HITEM23 17

class CObjStage2item3 :public CObj
{
public:
	CObjStage2item3() {};
	~CObjStage2item3() {};
	void Init();
	void Action();
	void Draw();
private:
	int map[HITEM23][HITEM23];
};