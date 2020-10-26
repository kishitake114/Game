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

	pxc = 0.0f;
	pyc = 0.0f;

	time = 0;

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

	if (mou_l == true)
	{
		pxc = mou_x;
		pyc = mou_y;
	}

	if (mou_x > 80 || mou_x < 120 && mou_x>440 || mou_y < 480)
	{
		if (mou_l == true)
		{
			if (pxc <= mou_x)
			{
				for (int i = 1; i < 4; i++)
				{
					for (int j = 1; j < 4; j++)
					{
						map[9 + i][3 + j] = map[9 + i][0 + j];
					}

				}
			}
		}
		
	}



	//	}
	//}

	if (mou_x > 600 && mou_x < 660 && mou_y > 40 && mou_y < 55)
	{
		if (mou_r == true)
		{
			Scene::SetScene(new CSceneClear());
		}
	}
}

//ドロー
void CObjRoad::Draw()
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

	swprintf_s(str, L"%d", p);
	Font::StrDraw(str, 600, 160, 20, c);

	//右クリック
	Font::StrDraw(L"右=決定", 600, 40, 20, c);

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
