#pragma once
//使用するヘッダー
#include "GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェク：プレイヤー
class CObjHardEnemy :public CObj
{
public:
	CObjHardEnemy() {};
	~CObjHardEnemy() {};
	void Init();
	void Action();
	void Draw();
	int HP;



private:

	float p_x;
	float p_y;

	float atr_x;
	float atr_y;
	float cs_xe;

	int plx;
	int ply;

	int ran;

	int memx;
	int memy;

	bool se;

	int e_time;

};