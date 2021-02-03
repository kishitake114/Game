#pragma once
//使用するヘッダー
#include "GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;
#define HITEM31 20

class CObjStage3item1 :public CObj
{
public:
	CObjStage3item1() {};
	~CObjStage3item1() {};
	void Init();
	void Action();
	void Draw();
private:
	int map[HITEM31][HITEM31];
};