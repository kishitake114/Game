#pragma once
//使用するヘッダー
#include "GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：背景
class CObjnul :public CObj
{
public:
	CObjnul() {};
	~CObjnul() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー

	int count;

private:
	
};