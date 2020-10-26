#pragma once
//使用するヘッダー
#include "GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェク：プレイヤー
class CObjRoad :public CObj
{
public:
	CObjRoad() {};
	~CObjRoad() {};
	void Init();
	void Action();
	void Draw();
private:
	int map[14][14];


};