#pragma once
//使用するヘッダー
#include "GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;
#include "ObjRoad.h"

//オブジェク：プレイヤー
class CObjStar :public CObj
{
public:
	CObjStar(){};
	~CObjStar(){};
	void Init();
	void Action();
	void Draw();

private:
	int HardSter;

};