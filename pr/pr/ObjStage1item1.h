#pragma once
//使用するヘッダー
#include "GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;
#define HITEM11 14

class CObjStage1item1 :public CObj
{
public:
	CObjStage1item1() {};
	~CObjStage1item1() {};
	void Init();
	void Action();
	void Draw();
private:
	int map[HITEM11][HITEM11];
};