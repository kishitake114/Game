#pragma once
//使用するヘッダー
#include "GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;
#define MAP 17
#define MEM 3

//オブジェク：プレイヤー
class CObjHardStage2 :public CObj
{
public:
	CObjHardStage2() {};
	~CObjHardStage2() {};
	void Init();
	void Action();
	void Draw();

	bool s_r;	//ロードのプログラム中止->プレイヤーへ
	bool sei;
	bool swi;

	int map[MAP][MAP];
	int memmap[MAP][MAP];

	int Hmap[MAP][MAP];
	int Hmemmap[MAP][MAP];

	int reset;

private:
	int mem[MEM][MEM];//操作ピースの保存
	int Hmem[MEM][MEM];//操作ピースの保存

	float mou_x;  //マウスカーソル：横
	float mou_y;  //マウスカーソル：縦
	bool  mou_r;  //マウスボタン：右
	bool  mou_l;  //マウスボタン：左

	float pxc;	  //左クリックでその座標xの追加
	float pyc;	  //左クリックでその座標yの追加

	float pv_x;
	float pv_y;

	bool f_p;	  //クリック操作制御

	float itemc;

	bool piece;

	int RESETcount;


};