#pragma once
//使用するヘッダー
#include "GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェク：プレイヤー
class CObjPlayer :public CObj
{
	public:
		CObjPlayer() {};
		~CObjPlayer() {};
		void Init();
		void Action();
		void Draw();
	private:

};