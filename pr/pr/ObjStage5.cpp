//使用するヘッダーファイル
#include "ObjStage5.h"
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
void CObjStage5::Init()
{
	CObjPlayer* obj = (CObjPlayer*)Objs::GetObj(OBJ_PLAYER);
	obj->num = 5;

	int alfhamap[8][8] =
	{
		{0,0,2,0,0,2,0,0,},
		{0,1,2,1,1,2,1,0,},
		{2,2,2,2,1,2,1,2,},
		{0,1,2,1,1,2,1,0,},
		{0,1,1,1,0,0,0,0,},
		{2,2,2,2,0,0,0,2,},
		{0,1,1,1,0,0,0,0,},
		{0,0,2,0,0,2,0,0,},
	};

	memcpy(map, alfhamap, sizeof(int) * (8 * 8));

	int mem[3][3] =
	{
		{0,0,0},
		{0,0,0},
		{0,0,0},
	};

	testx = 0;
	testy = 0;

	s_r = true;

}
//アクション
void CObjStage5::Action()
{

	mou_x = (float)Input::GetPosX();
	mou_y = (float)Input::GetPosY();
	mou_r = Input::GetMouButtonR();
	mou_l = Input::GetMouButtonL();

	//左クリックで座標を記録
	if (mou_l == true)
	{
		if (f_p == true)
		{
			pxc = mou_x;
			pyc = mou_y;

			f_p = false;
		}
	}
	else
	{
		f_p = true;

	}


	//ロード内のプログラム
	if (s_r == true)
	{
		//右クリックで操作中止
		if (mou_r == true)
		{
			s_r = false;
		}

		//1列目1マス目
		if (mou_x > 40.0f && mou_x < 155.0f && mou_y>40.0f && mou_y < 155.0f)
		{
			testx = 1;
			testy = 1;

			if (mou_l == true)
			{
				//１列目（１マス目）→（右）1マス移動　
				if (map[1][4] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[1 + i][1 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][1 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][4 + j] = mem[i][j];
							pv_x = 120;
						}
					}

				}

				//１列目（１マス目）↓（下）1マス移動　
				if (map[4][1] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[1 + i][1 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][1 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][1 + j] = mem[i][j];
							pv_y = -120;
						}
					}
				}
			}
		}

		//1列目２マス目 
		if (mou_x > 155.0f && mou_x < 273.0f && mou_y>40.0f && mou_y < 155.0f)
		{
			testx = 1;
			testy = 2;
			if (mou_l == true)
			{
				//１列目（2マス目）↓（下）1マス移動　
				if (map[4][4] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[1 + i][4 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][4 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][4 + j] = mem[i][j];
							pv_y = -120.0f;
						}
					}

				}

				//１列目（2マス目）←（左）1マス移動　
				if (map[1][1] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[1 + i][4 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][4 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][1 + j] = mem[i][j];
							pv_x = -120.0f;
						}
					}
				}
			}
		}


		//2列目
		if (mou_x > 40.0f && mou_x < 155.0f && mou_y>155.0f && mou_y < 273.0f)
		{
			testx = 2;
			testy = 1;
			if (mou_l == true)
			{
				//2列目（１マス目）↑（上）1マス移動
				if (map[1][1] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[4 + i][1 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][1 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][1 + j] = mem[i][j];
							pv_y += 120;
						}
					}
				}

				//2列目（１マス目）→（右）1マス移動
				if (map[4][4] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[4 + i][1 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][1 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][4 + j] = mem[i][j];
							pv_x = 120;
						}
					}
				}
			}
		}

		//2列目（2マス目）
		if (mou_x > 156.0f && mou_x < 273.0f && mou_y>156.0f && mou_y < 273.0f)
		{
			testx = 2;
			testy = 2;
			if (mou_l == true)
			{
				//2列目（2マス目）←（左）1マス移動
				if (map[4][1] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[4 + i][4 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][4 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][1 + j] = mem[i][j];
							pv_x = -120;
						}
					}

				}

				//2列目（2マス目）↑（上）1マス移動
				if (map[1][4] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[4 + i][4 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][4 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][4 + j] = mem[i][j];
							pv_y = 120;
						}
					}
				}
			}
		}

	}
}
//ドロー
void CObjStage5::Draw()
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

	swprintf_s(str, L"横=%d", testx);
	Font::StrDraw(str, 600, 200, 25, c);
	swprintf_s(str, L"縦=%d", testy);
	Font::StrDraw(str, 600, 226, 25, c);

	//表示：通行可

	src.m_top = 90.0f;
	src.m_left = 45.0f;
	src.m_right = 85.0f;
	src.m_bottom = 125.0f;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
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

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
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