#pragma once
//使用するヘッダー
#include "GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

class CObjItem :public CObj
{
public:
	CObjItem(float x, float y) ;
	~CObjItem() {};
	void Init();
	void Action();
	void Draw();
	float m_x;
	float m_y;


private:
	float mou_x;  //マウスカーソル：横
	float mou_y;  //マウスカーソル：縦
	bool  mou_r;  //マウスボタン：右
	bool  mou_l;  //マウスボタン：左

	int map[14][14];
	
};
