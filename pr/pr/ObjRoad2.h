#pragma once
//使用するヘッダー
#include "GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;
#define HROAD2 17

//オブジェクト：背景
class CObjRoad2 :public CObj
{
public:
	CObjRoad2() {};
	~CObjRoad2() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー

	bool s_r;	//ロードのプログラム中止->プレイヤーへ
	bool sei;

	int map[HROAD2][HROAD2];
	int memmap[HROAD2][HROAD2];

private:
	int mem[3][3];//操作ピースの保存

	float mou_x;  //マウスカーソル：横
	float mou_y;  //マウスカーソル：縦
	bool  mou_r;  //マウスボタン：右
	bool  mou_l;  //マウスボタン：左

	float pxc;	  //左クリックでその座標xの追加
	float pyc;	  //左クリックでその座標yの追加

	float pv_x;
	float pv_y;

	int reset;

	bool f_p;	  //クリック操作制御

	int s_time;
	int second;

	bool s_count;	//サウンド用カウント

	bool set;
};

