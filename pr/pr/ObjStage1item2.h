#pragma once
//使用するヘッダー
#include "GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;
#define HITEM12 14

class CObjStage1item2 :public CObj
{
public:
	CObjStage1item2() {};
	~CObjStage1item2() {};
	void Init();
	void Action();
	void Draw();
private:
	int map[HITEM12][HITEM12];
};