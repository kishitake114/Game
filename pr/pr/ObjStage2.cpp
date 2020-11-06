//使用するヘッダーファイル
#include "ObjStage2.h"
#include "ObjPlayer.h"
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "GameHead.h" 
#include "GameL/WinInputs.h"
#include "GameL/HitBoxManager.h"
#include "GameL/SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjStage2::Init()
{
	int mapdata[17][17] =
	{
		{0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0},
		{0,1,2,1,1,1,1,1,2,1,1,1,1,1,2,1,0},
		{2,1,2,2,2,2,2,1,2,1,1,2,2,2,2,1,2},
		{0,1,1,1,1,1,1,1,2,1,1,2,1,1,1,1,0},
		{0,1,1,1,1,1,1,1,2,1,1,2,1,1,1,1,0},
		{2,2,2,2,2,2,1,1,2,2,1,2,1,1,2,2,2},
		{0,1,2,1,1,2,1,1,1,1,1,2,1,1,2,1,0},
		{0,1,1,1,1,2,1,1,1,1,1,1,1,1,2,1,0},
		{2,2,2,2,2,2,2,2,2,1,2,2,2,2,2,1,2},
		{0,1,1,1,1,2,1,1,2,1,1,2,1,1,2,1,0},
		{0,1,2,1,1,2,1,1,1,1,1,1,1,1,1,1,0},
		{2,1,2,2,1,2,1,2,2,2,2,2,1,2,2,2,2},
		{0,1,1,1,1,2,1,1,1,1,1,2,1,1,2,1,0},
		{0,1,2,1,1,2,1,1,2,1,1,2,1,0,0,0,0},
		{2,2,2,2,2,2,1,1,2,2,2,2,1,0,0,0,2},
		{0,1,2,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
		{0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0},

	};

	memcpy(map, mapdata, sizeof(int) * (17 * 17));
}
//アクション
void CObjStage2::Action()
{

}
//ドロー
void CObjStage2::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	//表示：マウスカーソルとボタン
	wchar_t str[256];

	swprintf_s(str, L"x=%f,y=%f", pxc, pyc);
	Font::StrDraw(str, 600, 20, 15, c);

	swprintf_s(str, L"x=%f,y=%f", mou_x, mou_y);
	Font::StrDraw(str, 600, 10, 15, c);



	//右クリック
	if (s_r == true)
	{
		Font::StrDraw(L"Road", 600, 40, 20, c);
		Font::StrDraw(L"操作\n マウス", 550, 300, 20, c);
	}

	//左クリック
	if (mou_l == true)
		Font::StrDraw(L"左=押してる", 600, 60, 20, c);
	else
		Font::StrDraw(L"左=押してない", 600, 60, 20, c);

	//表示：通行可


	src.m_top = 90.0f;
	src.m_left = 45.0f;
	src.m_right = 85.0f;
	src.m_bottom = 125.0f;

	for (int i = 0; i < 17; i++)
	{
		for (int j = 0; j < 17; j++)
		{

			if (map[i][j] == 2)
			{
				dst.m_top = i * 30.0f;
				dst.m_left = j * 30.0f;
				dst.m_right = dst.m_left + 30.0f;
				dst.m_bottom = dst.m_top + 30.0f;

				Draw::Draw(0, &src, &dst, c, 0.0f);
			}

		}
	}

	//表示：通行不可

	src.m_top = 90.0f;
	src.m_left = 0.0f;
	src.m_right = 45.0f;
	src.m_bottom = 125.0f;

	for (int i = 0; i < 17; i++)
	{
		for (int j = 0; j < 17; j++)
		{
			if (map[i][j] == 1)
			{
				dst.m_top = i * 30.0f;
				dst.m_left = j * 30.0f;
				dst.m_right = dst.m_left + 30.0f;
				dst.m_bottom = dst.m_top + 30.0f;

				Draw::Draw(0, &src, &dst, c, 0.0f);

			}
		}
	}
}