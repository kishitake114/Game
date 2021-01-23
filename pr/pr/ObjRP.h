#pragma once
//使用するヘッダー
#include "GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

class ObjRP :public Objs
{
	ObjRP() {};
	~ObjRP() {};
	void Init();
	void Action();
	void Draw();
};