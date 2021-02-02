//使用するヘッダーファイル
#include "ObjStage5.h"
#include "ObjPlayer.h"
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "GameHead.h" 
#include "GameL/WinInputs.h"
#include "GameL/HitBoxManager.h"
#include "GameL/SceneObjManager.h"
#include "ObjRP.h"
#include "GameL/Audio.h"

//使用するネームスペース
using namespace GameL;



//イニシャライズ
void CObjStage5::Init()
{
	CObjPlayer* player = (CObjPlayer*)Objs::GetObj(OBJ_PLAYER);
	CObjRP* RP = (CObjRP*)Objs::GetObj(OBJ_SWITCH);
	player->num = 0;
	player->p_x = 0.0f;
	player->p_y = 200.0f;

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

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			memmap[i][j] = map[i][j];
		}
	}

	int mem[3][3] =
	{
		{0,0,0},
		{0,0,0},
		{0,0,0},
	};

	testx = 0;
	testy = 0;

	s_r = true;

	ht = false;
	f_p = true;

}
//アクション
void CObjStage5::Action()
{
	CObjPlayer* player = (CObjPlayer*)Objs::GetObj(OBJ_PLAYER);
	float px = player->GetX();
	float py = player->GetY();

	CObjRP* RP = (CObjRP*)Objs::GetObj(OBJ_SWITCH);
	RP->sc = false;

	mou_x = (float)Input::GetPosX();
	mou_y = (float)Input::GetPosY();
	mou_r = Input::GetMouButtonR();
	mou_l = Input::GetMouButtonL();

	//ロード内のプログラム
		//右クリックで操作中止

		if (s_r == true)
		{
			if (mou_r == true)
			{
				s_r = false;
				player->s_p = true;
				Audio::Start(3);
			}

			//1列目1マス目
			if (mou_x > 40.0f && mou_x < 155.0f && mou_y>40.0f && mou_y < 155.0f)
			{

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
							}
						}
						Audio::Start(2);
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
							Audio::Start(2);
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
							Audio::Start(2);
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
							Audio::Start(2);
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
							Audio::Start(2);
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
							Audio::Start(2);
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
							Audio::Start(2);
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
							Audio::Start(2);
						}
					}
				}
			}

		}
	

	//リセットボタンのプログラム
	if (s_r == false)
	{
		if (mou_x > 622.0f && mou_x < 765.0f && mou_y>450.0f && mou_y < 555.0f)
		{
			if (mou_l == true)
			{
				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < 8; j++)
					{
						map[i][j] = memmap[i][j];
					}
				}

				s_r = true;

				player->s_p = false;

				player->p_x = player->memp_x;
				player->p_y = player->memp_y;

				player->atk = 0;

				Audio::Start(4);

			}
		}
	}

	if (player->battle == true)
	{
		if (mou_l == true)
		{
			player->battle = false;
			Scene::SetScene(new CSceneStage1);
		}
	}

}
//ドロー
void CObjStage5::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float r[4] = { 1.0f,0.0f,0.0f,1.0f };
	float g[4] = { 0.0f,1.0f,0.0f,1.0f };
	float b[4] = { 0.0f,0.0f,1.0f,1.0f };
	float gl[4] = { 0.3f,0.3f,0.3f,1.0f };

	RECT_F src;
	RECT_F dst;

	//表示：マウスカーソルとボタン
	wchar_t str[256];

	CObjPlayer* player = (CObjPlayer*)Objs::GetObj(OBJ_PLAYER);

	if (player->battle == true)
	{
		Font::StrDraw(L"Clear!!", 500, 250, 50, c);
		Font::StrDraw(L"次から本番だ！", 500, 300, 25, c);
	}

	//表示：通行可

	src.m_top = 90.0f;
	src.m_left = 50.0f;
	src.m_right = 81.0f;
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

	//土台
	src.m_top = 45.0f;
	src.m_left = 8.0f;
	src.m_right = 201.0f;
	src.m_bottom = 157.0f;

	dst.m_top = 500.0f;
	dst.m_left = 600.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	Draw::Draw(2, &src, &dst, c, 0.0f);

	//リセットボタン
	src.m_top = 172.0f;
	src.m_left = 8.0f;
	src.m_right = 201.0f;
	src.m_bottom = 291.0f;

	if (s_r == false)
	{
		//押された時にしずむ
		if (mou_x > 622.0f && mou_x < 765.0f && mou_y>450.0f && mou_y < 555.0f)
		{
			dst.m_top = 475.0f;
			dst.m_left = 622.0f;
			dst.m_right = 765.0f;
			dst.m_bottom = 555.0f;

			Draw::Draw(2, &src, &dst, c, 0.0f);
		}

		//それ以外
		else
		{
			dst.m_top = 450.0f;
			dst.m_left = 622.0f;
			dst.m_right = 765.0f;
			dst.m_bottom = 555.0f;

			Draw::Draw(2, &src, &dst, c, 0.0f);
		}
	}

	//ピース操作時のボタン
	else
	{
		src.m_top = 300.0f;
		src.m_left = 8.0f;
		src.m_right = 201.0f;
		src.m_bottom = 417.0f;

		dst.m_top = 450.0f;
		dst.m_left = 622.0f;
		dst.m_right = 765.0f;
		dst.m_bottom = 555.0f;

		Draw::Draw(2, &src, &dst, c, 0.0f);
	}

}