#pragma once
//使用するヘッダー
#include "GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：背景
class CObjTitle :public CObj
{
public:
	CObjTitle() {};
	~CObjTitle() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー



private:
	float m_x;
	float m_y;
	float mou_x;  //マウスカーソル：横
	float mou_y;  //マウスカーソル：縦
	bool  mou_r;  //マウスボタン：右
	bool  mou_l;  //マウスボタン：左

	int m_time;
	int Hcount;

	int second;
	bool story;

	bool lup;
	bool rup;
	bool ldown;
	bool rdown;

	float slide;

	bool hard;
};