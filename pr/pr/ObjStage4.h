#pragma once
//使用するヘッダー
#include "GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：背景
class CObjStage4 :public CObj
{
public:
	CObjStage4() {};
	~CObjStage4() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー

	bool s_r;	//ロードのプログラム中止->プレイヤーへ
	bool sei;
private:
	int map[26][26];
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
};

