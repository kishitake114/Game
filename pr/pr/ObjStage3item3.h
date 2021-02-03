#pragma once
//使用するヘッダー
#include "GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;
#define HITEM33 20

class CObjStage3item3 :public CObj
{
public:
	CObjStage3item3() {};
	~CObjStage3item3() {};
	void Init();
	void Action();
	void Draw();
private:
	int map[HITEM33][HITEM33];
};