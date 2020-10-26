#include "ObjRoad.h"
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "GameHead.h" 
#include "GameL/WinInputs.h"


//イニシャライズ
void CObjRoad::Init()
{
	mou_x = 0.0f;
	mou_y = 0.0f;
	mou_r = false;
	mou_l = false;

	p_x = 40;
	p_y = 40;
	p = 1;

		int mapdata[14][14] =
	{
{0,0,2,0,0,2,0,0,2,0,0,2,0,0},
{0,1,2,1,1,2,1,1,1,1,1,1,1,0},
{2,2,2,2,1,2,1,2,2,1,2,2,2,2},
{0,1,2,1,1,2,1,1,2,1,1,1,1,0},
{0,1,2,1,1,2,1,1,1,1,1,1,1,0},
{2,1,2,1,2,2,2,2,2,1,1,2,2,2},
{0,1,2,1,1,2,1,1,2,1,1,2,1,0},
{0,1,1,1,1,2,1,1,2,1,1,2,1,0},
{2,2,2,2,1,2,2,2,2,2,2,2,1,2},
{0,1,1,1,1,1,1,1,2,1,1,1,1,0},
{0,1,1,1,0,0,0,1,2,1,1,1,1,0},
{2,2,2,2,0,0,0,1,2,1,2,2,2,2},
{0,1,1,1,0,0,0,1,2,1,1,1,1,0},
{0,0,2,0,0,2,0,0,2,0,0,2,0,0},
	};

	memcpy(map, mapdata, sizeof(int) * (14 * 14));

}

//アクション
void CObjRoad::Action()
{
	mou_x = (float)Input::GetPosX();
	mou_y = (float)Input::GetPosY();
	mou_r = Input::GetMouButtonR();
	mou_l = Input::GetMouButtonL();

	//while (p)
	//{


	//	if (mou_x > 37 || mou_x < 510 && mou_y > 41 || mou_y < 509)
	//	{
	//		if (mou_l == true)
	//		{

	//			for (int i = 1; i < 12; i++)
	//			{
	//				for (int j = 1; j < 12; j++)
	//				{
	//					for (int a = 0; a < 3; a++)
	//					{
	//						if (map[i + a][j] == 0)
	//						{
	//							for (int b = 0; b < 3; b++)
	//							{
	//								map[i + a][j] = map[i][j];
	//								map[i][j] = 0;

	//							}
	//						}
	//					}

	//				}
	//			}

	//		}

	//	}
	//}
}

//ドロー
void CObjRoad::Draw()
{

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

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

	//表示：通行可


	src.m_top = 90.0f;
	src.m_left = 45.0f;
	src.m_right = 85.0f;
	src.m_bottom = 125.0f;
	
	for (int i = 0; i < 14; i++)
	{
		for (int j = 0; j < 14; j++)
		{

			if (map[i][j] == 2)
			{
				dst.m_top = i * 40.0f;
				dst.m_left = j * 40.0f;
				dst.m_right = dst.m_left + 40.0f;
				dst.m_bottom = dst.m_top + 40.0f;

				Draw::Draw(0, &src, &dst, c, 0.0f);
			}

		}
	}

	//表示：通行不可

	src.m_top = 90.0f;
	src.m_left = 0.0f;
	src.m_right = 45.0f;
	src.m_bottom = 125.0f;

	for (int i = 0; i < 14; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			if (map[i][j] == 1)
			{
				dst.m_top = i * 40.0f;
				dst.m_left = j * 40.0f;
				dst.m_right = dst.m_left + 40.0f;
				dst.m_bottom = dst.m_top + 40.0f;

				Draw::Draw(0, &src, &dst, c, 0.0f);

			}
		}
	}

}
