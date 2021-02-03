#pragma once
//使用するヘッダー
#include "GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

class CObjBackGround01 :public CObj
{
public:
	CObjBackGround01() {};
		~CObjBackGround01() {};
		void Init();
		void Action();
		void Draw();
	private:
		int stage;

};
