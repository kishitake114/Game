#pragma once
//使用するヘッダー
#include "GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェク：プレイヤー
class CObjEnemy :public CObj
{
public:
	CObjEnemy() {};
	~CObjEnemy() {};
	void Init();
	void Action();
	void Draw();
private:
	int HP;
	float p_x;
	float p_y;

	float atr_x;
	float atr_y;

	int plx;
	int ply;

	int ran;

	int memx;
	int memy;

	bool se;

};