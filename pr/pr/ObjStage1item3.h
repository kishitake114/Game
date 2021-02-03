#pragma once
//使用するヘッダー
#include "GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;
#define HITEM13 14

class CObjStage1item3 :public CObj
{
public:
	CObjStage1item3() {};
	~CObjStage1item3() {};
	void Init();
	void Action();
	void Draw();
private:
	int map[HITEM13][HITEM13];
};