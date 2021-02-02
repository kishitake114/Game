#pragma once
//使用するヘッダー
#include "GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

class CObjBackGround04 :public CObj
{
public:
	CObjBackGround04() {};
	~CObjBackGround04() {};
	void Init();
	void Action();
	void Draw();
private:

};
