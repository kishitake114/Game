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
	int map[8][8];
	int mem[3][3];
	float mou_x;  //マウスカーソル：横
	float mou_y;  //マウスカーソル：縦
	bool  mou_r;  //マウスボタン：右
	bool  mou_l;  //マウスボタン：左

	int p_x;
	int p_y;
	int p;

	float pxc;
	float pyc;
	int time;
};