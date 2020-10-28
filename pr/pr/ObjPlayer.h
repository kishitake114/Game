 #pragma once
//使用するヘッダー
#include "GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;
#include "ObjRoad.h"

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

		float p_x;	  //操作　横（試し）
		float p_y;	  //操作　縦（試し）
		float p_vx;
		float p_vy;

		float cs_x;   //画像切り取り用変数
		float cs_y;

		bool s_p;

};