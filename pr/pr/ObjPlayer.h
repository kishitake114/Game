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
		float mou_x;  //マウスカーソル：横
		float mou_y;  //マウスカーソル：縦
		bool  mou_r;  //マウスボタン：右
		bool  mou_l;  //マウスボタン：左
};