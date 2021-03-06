#pragma once
//使用するヘッダー
#include "GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

#define HROAD3 20

//オブジェクト：背景
class CObjRoad3 :public CObj
{
public:
	CObjRoad3() {};
	~CObjRoad3() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー

	bool s_r;	//ロードのプログラム中止->プレイヤーへ
	int map[HROAD3][HROAD3];
	int memmap[HROAD3][HROAD3];

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

	bool f_p;	  //クリック操作制御
	bool test;

	int testx;
	int testy;

	int num;  //デバッグ用：y移動

	bool s_count;	//サウンド用カウント

	int reset;
	int s_time;
	int second;

	bool set;
};

