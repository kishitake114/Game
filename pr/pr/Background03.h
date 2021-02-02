#pragma once
//使用するヘッダー
#include "GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

class CObjBackGround03 :public CObj
{
public:
	CObjBackGround03() {};
	~CObjBackGround03() {};
	void Init();
	void Action();
	void Draw();
private:

};
