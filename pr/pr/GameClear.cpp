//使用するヘッダーファイル
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "GameClear.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObGameClear::Init()
{

}
//アクション
void CObGameClear::Action()
{

}
//ドロー
void CObGameClear::Draw()
{
	//描画カラー情報 R=RED B=Biue A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

	//切り取り位置の設定
	src.m_top;
	//表示位置の設定
	dst.m_top;

	//0番目に登録したグラフィックをsrc・dst・cの情報を元に描画
	Draw::Draw(1, &src, &dst, c, 0.0f);
}
