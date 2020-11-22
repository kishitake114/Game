#pragma once
//使用するヘッダー
#include "GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：背景
class CObjTime :public CObj
{
public:
	CObjTime() {};
	~CObjTime() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー

	bool m_flag_time;//時間計測スタートフラグ
	
	int m_time;      //時間

	void SetTimeFlag(bool b) { m_flag_time = b; }
private:

	float mou_r;
	float mou_l;

	int plas;
};