#pragma once
//使用するヘッダー
#include "GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

class CObjRP :public CObj
{
	public:
		CObjRP() {};
		~CObjRP() {};
		void Init();
		void Action();
		void Draw();
		bool sc;	//スタート時とクリア時のもの

	private:
		bool sw;	//ROADとPLAYERの表示欄
};