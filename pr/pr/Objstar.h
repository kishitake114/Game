#pragma once
//使用するヘッダー
#include "GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：背景
class CObjStar :public CObj
{
public:
	CObjStar() {};
	~CObjStar() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー

private:
	
};