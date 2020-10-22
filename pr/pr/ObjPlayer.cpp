//使用するヘッダー
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "ObjPlayer.h"
#include "GameHead.h" 
#include "GameL/WinInputs.h" 

using namespace GameL;

//イニシャライズ
void CObjPlayer::Init()
{
	mou_x = 0.0f;
	mou_y = 0.0f;
	mou_r = false;
	mou_l = false;
}

//アクション
void CObjPlayer::Action()
{
	mou_x = (float)Input::GetPosX();
	mou_y = (float)Input::GetPosY();
	mou_r = Input::GetMouButtonR();
	mou_l = Input::GetMouButtonL();

}

//ドロー
void CObjPlayer::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	//表示：マウスカーソルとボタン
	wchar_t str[256];
	swprintf_s(str, L"x=%f,y=%f", mou_x, mou_y);
	Font::StrDraw(str, 600, 20, 15, c);

	//右クリック
	if (mou_r == true)
		Font::StrDraw(L"右=押してる", 600, 40, 20, c);
	else
		Font::StrDraw(L"右=押してない", 600, 40, 20, c);

	//左クリック
	if (mou_l == true)
		Font::StrDraw(L"左=押してる", 600, 60, 20, c);
	else
		Font::StrDraw(L"左=押してない", 600, 60, 20, c);



	//表示：プレイヤー
	RECT_F src;
	RECT_F dst;

	src.m_top     = 0.0f;
	src.m_left    = 0.0f;
	src.m_right   = 45.0f;
	src.m_bottom  = 45.0f;

	dst.m_top	  = 0.0f;
	dst.m_left    = 0.0f;
	dst.m_right   = 45.0f;
	dst.m_bottom  = 45.0f;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}
