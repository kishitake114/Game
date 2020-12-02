//使用するヘッダーファイル
#include "ObjStage3.h"
#include "ObjPlayer.h"
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "GameHead.h" 
#include "GameL/WinInputs.h"
#include "GameL/HitBoxManager.h"
#include "GameL/SceneObjManager.h"
#include "GameL/UserData.h"

#define PIECE 20
#define SIZE 25.0f

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjStage3::Init()
{
	CObjPlayer* obj = (CObjPlayer*)Objs::GetObj(OBJ_PLAYER);
	obj->num = 3;
	obj->p_x = 0.0f;
	obj->p_y = 200.0f;

	reset = 0;

	int mapdata[PIECE][PIECE] =
	{
		{0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0},
		{0,1,2,1,1,2,1,1,1,1,1,2,1,1,2,1,1,2,1,0},
		{2,2,4,1,2,3,2,2,2,2,2,3,1,1,5,1,1,4,2,2},
		{0,1,2,1,1,2,1,1,1,1,1,1,1,1,2,1,1,1,1,0},
		{0,1,1,1,1,2,1,1,1,1,1,2,1,0,0,0,1,1,1,0},
		{2,2,2,1,1,3,1,1,4,2,1,3,2,0,0,0,2,3,1,2},
		{0,1,2,1,1,2,1,1,2,1,1,2,1,0,0,0,1,2,1,0},
		{0,1,1,1,1,2,1,1,2,1,1,2,1,1,2,1,1,1,1,0},
		{2,1,3,2,2,2,2,1,3,1,1,2,2,2,3,2,2,4,2,2},
		{0,1,2,1,1,1,1,1,2,1,1,1,1,1,2,1,1,1,1,0},
		{0,1,2,1,1,2,1,1,1,1,1,1,1,1,1,1,1,2,1,0},
		{2,1,2,1,1,2,2,2,4,2,2,3,2,2,3,1,2,2,1,2},
		{0,1,2,1,1,1,1,1,1,1,1,2,1,1,2,1,1,1,1,0},
		{0,1,1,1,1,2,1,1,2,1,1,2,1,1,1,1,1,2,1,0},
		{2,2,3,2,1,5,1,2,3,2,1,3,1,1,2,2,2,3,2,2},
		{0,1,2,1,1,2,1,1,2,1,1,2,1,1,2,1,1,1,1,0},
		{0,1,1,1,1,2,1,1,2,1,1,1,1,1,2,1,1,2,1,0},
		{2,2,2,2,2,3,1,2,2,1,2,5,2,1,4,2,1,2,1,2},
		{0,1,1,1,1,1,1,1,2,1,1,1,1,1,2,1,1,2,1,0},
		{0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0},

	};

	memcpy(map, mapdata, sizeof(int) * (PIECE * PIECE));

	for (int i = 0; i < PIECE; i++)
	{
		for (int j = 0; j < PIECE; j++)
		{
			memmap[i][j] = map[i][j];
		}
	}

	mou_x = 0.0f;
	mou_y = 0.0f;
	mou_l = false;
	mou_r = false;

	pxc = 0.0f;		//記憶用変数（x）
	pyc = 0.0f;		//記憶用変数（y）

	test = false;	//確認用
	testx = 0;		//位置確認用（横）
	testy = 0;		//位置確認用（縦）

	s_r = true;
}
//アクション
void CObjStage3::Action()
{
	CObjItem* item = (CObjItem*)Objs::GetObj(OBJ_ITEM);
	CObjTime* time = (CObjTime*)Objs::GetObj(OBJ_TIME);

	CObjnul* nul = (CObjnul*)Objs::GetObj(OBJ_NUL);

	CObjPlayer* player = (CObjPlayer*)Objs::GetObj(OBJ_PLAYER);
	float px = player->GetX();
	float py = player->GetY();

	//mapにアクセス

	//通行不可
	for (int i = 0; i < PIECE; i++)
	{
		for (int j = 0; j < PIECE; j++)
		{
			if (map[i][j] <= 1)
			{
				float x = j * SIZE;
				float y = i * SIZE;

				if ((px + SIZE > x) && (px < x + SIZE) && (py + SIZE > y) && (py < y + SIZE))
				{
					//ベクトル作成
					float vx = px - x;
					float vy = py - y;

					float len = sqrt(vx * vx + vy * vy);

					float r = atan2(vy, vx);
					r = r * 180.0f / 3.14f;

					if (r <= 0.0f)
					{
						r = abs(r);
					}

					else
					{
						r = 360.0f - abs(r);
					}

					//上
					if (r > 45 && r < 135)
					{
						player->SetVY(y - SIZE);
					}

					//左
					else if (r > 135 && r < 225)
					{
						player->SetVX(x - SIZE);
					}

					//下
					else if (r > 225 && r < 315)
					{
						player->SetVY(y + SIZE);
					}

					else
					{
						player->SetVX(x + SIZE);
					}

				}

			}


		}

	}
	//アイテム（１）
	for (int i = 0; i < PIECE; i++)
	{
		for (int j = 0; j < PIECE; j++)
		{
			if (map[i][j] == 3)
			{
				float x = j * SIZE;
				float y = i * SIZE;

				if ((px + SIZE > x) && (px < x + SIZE) && (py + SIZE > y) && (py < y + SIZE))
				{
					//ベクトル作成
					float vx = px - x;
					float vy = py - y;

					float len = sqrt(vx * vx + vy * vy);

					float r = atan2(vy, vx);
					r = r * 180.0f / 3.14f;

					if (r <= 0.0f)
					{
						r = abs(r);
					}

					else
					{
						r = 360.0f - abs(r);
					}

					if (r > 45 && r < 315)
					{
						if (map[i][j] == 3)
						{
							map[i][j] = 2;
						}

						player->atk++;
					}

				}
			}
		}
	}
	//アイテム（２）
	for (int i = 0; i < PIECE; i++)
	{
		for (int j = 0; j < PIECE; j++)
		{
			if (map[i][j] == 4)
			{
				float x = j * SIZE;
				float y = i * SIZE;

				if ((px + SIZE > x) && (px < x + SIZE) && (py + SIZE > y) && (py < y + SIZE))
				{
					//ベクトル作成
					float vx = px - x;
					float vy = py - y;

					float len = sqrt(vx * vx + vy * vy);

					float r = atan2(vy, vx);
					r = r * 180.0f / 3.14f;

					if (r <= 0.0f)
					{
						r = abs(r);
					}

					else
					{
						r = 360.0f - abs(r);
					}

					if (r > 45 && r < 315)
					{
						if (map[i][j] == 4)
						{
							map[i][j] = 2;
						}

						player->atk += 2;
					}

				}
			}
		}
	}
	//アイテム（３）
	for (int i = 0; i < PIECE; i++)
	{
		for (int j = 0; j < PIECE; j++)
		{
			if (map[i][j] == 5)
			{
				float x = j * SIZE;
				float y = i * SIZE;

				if ((px + SIZE > x) && (px < x + SIZE) && (py + SIZE > y) && (py < y + SIZE))
				{
					//ベクトル作成
					float vx = px - x;
					float vy = py - y;

					float len = sqrt(vx * vx + vy * vy);

					float r = atan2(vy, vx);
					r = r * 180.0f / 3.14f;

					if (r <= 0.0f)
					{
						r = abs(r);
					}

					else
					{
						r = 360.0f - abs(r);
					}

					if (r > 45 && r < 315)
					{
						if (map[i][j] == 5)
						{
							map[i][j] = 2;
						}

						player->atk += 3;
					}

				}
			}
		}
	}



	mou_x = (float)Input::GetPosX();
	mou_y = (float)Input::GetPosY();
	mou_r = Input::GetMouButtonR();
	mou_l = Input::GetMouButtonL();

	//カーソル位置記憶用
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


		if (mou_x > 25.0f && mou_x < 467.0f && mou_y>25.0f && mou_y < 467.0f)
		{
			test = true;
			
			//1段目
			
			//1段目1行目
			if (mou_x > 25.0f && mou_x < 97.0f && mou_y>25.0f && mou_y < 97.0f)
			{
				testx = 1;
				testy = 1;


				if (mou_l == true)
				{
					//1段目1行目->1段目2行目
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
					}

					//1段目1行目->2段目1行目
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
							}
						}
					}


				}
			}
			//1段目2行目
			if (mou_x > 98.0f && mou_x < 173.0f && mou_y>25.0f && mou_y < 97.0f)
			{
				testx = 2;
				testy = 1;


				if (mou_l == true)
				{
					//1段目2行目->1段目3行目
					if (map[1][7] == 0)
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
								map[1 + i][7 + j] = mem[i][j];
							}
						}
					}

					//1段目2行目->1段目1行目
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
							}
						}
					}

					//1段目2行目->2段目2行目
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
							}
						}
					}
				}
			}
			//1段目3行目
			if (mou_x > 173.0f && mou_x < 246.0f && mou_y>25.0f && mou_y < 97.0f)
			{
				testx = 3;
				testy = 1;


				if (mou_l == true)
				{
					//1段目3行目->1段目4行目
					if (map[1][10] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[1 + i][7 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[1 + i][7 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[1 + i][10 + j] = mem[i][j];
							}
						}
					}

					//1段目3行目->1段目2行目
					if (map[1][4] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[1 + i][7 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[1 + i][7 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[1 + i][4 + j] = mem[i][j];
							}
						}
					}

					//1段目3行目->2段目3行目
					if (map[4][7] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[1 + i][7 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[1 + i][7 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[4 + i][7 + j] = mem[i][j];
							}
						}
					}
				}
			}
			//1段目4行目
			if (mou_x > 246.0f && mou_x < 321.0f && mou_y>25.0f && mou_y < 97.0f)
			{
				testx = 4;
				testy = 1;


				if (mou_l == true)
				{
					//1段目4行目->1段目5行目
					if (map[1][13] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[1 + i][10 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[1 + i][10 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[1 + i][13 + j] = mem[i][j];
							}
						}
					}

					//1段目4行目->1段目3行目
					if (map[1][7] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[1 + i][10 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[1 + i][10 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[1 + i][7 + j] = mem[i][j];
							}
						}
					}

					//1段目4行目->2段目4行目
					if (map[4][10] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[1 + i][10 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[1 + i][10 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[4 + i][10 + j] = mem[i][j];
							}
						}
					}
				}
			}
			//1段目5行目
			if (mou_x > 321.0f && mou_x < 394.0f && mou_y>25.0f && mou_y < 97.0f)
			{
				testx = 5;
				testy = 1;


				if (mou_l == true)
				{
					//1段目5行目->1段目4行目
					if (map[1][10] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[1 + i][13 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[1 + i][13 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[1 + i][10 + j] = mem[i][j];
							}
						}
					}

					//1段目5行目->1段目6行目
					if (map[1][16] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[1 + i][13 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[1 + i][13 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[1 + i][16 + j] = mem[i][j];
							}
						}
					}

					//1段目5行目->2段目5行目
					if (map[4][13] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[1 + i][13 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[1 + i][13 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[4 + i][13 + j] = mem[i][j];
							}
						}
					}
				}
			}
			//1段目6行目
			if (mou_x > 394.0f && mou_x < 467.0f && mou_y>25.0f && mou_y < 97.0f)
			{
				testx = 6;
				testy = 1;


				if (mou_l == true)
				{
					//1段目6行目->1段目5行目
					if (map[1][13] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[1 + i][16 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[1 + i][16 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[1 + i][13 + j] = mem[i][j];
							}
						}
					}

					//1段目6行目->2段目6行目
					if (map[4][16] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[1 + i][16 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[1 + i][16 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[4 + i][16 + j] = mem[i][j];
							}
						}
					}


				}
			}


			//2段目

			//2段目1行目
			if (mou_x > 25.0f && mou_x < 97.0f && mou_y>97.0f && mou_y < 173.0f)
			{
				testx = 1;
				testy = 2;


				if (mou_l == true)
				{
					//2段目1行目->1段目1行目
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
							}
						}
					}

					//2段目1行目->3段目1行目
					if (map[7][1] == 0)
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
								map[7 + i][1 + j] = mem[i][j];
							}
						}
					}

					//2段目1行目->2段目2行目
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
							}
						}
					}
				}
			}
			//2段目2行目
			if (mou_x > 98.0f && mou_x < 173.0f && mou_y>97.0f && mou_y < 173.0f)
			{
				testx = 2;
				testy = 2;


				if (mou_l == true)
				{
					//2段目2行目->2段目3行目
					if (map[4][7] == 0)
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
								map[4 + i][7 + j] = mem[i][j];
							}
						}
					}

					//2段目2行目->2段目1行目
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
							}
						}
					}

					//2段目2行目->1段目2行目
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
							}
						}
					}

					//2段目2行目->1段目2行目
					if (map[7][4] == 0)
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
								map[7 + i][4 + j] = mem[i][j];
							}
						}
					}
				}
			}
			//2段目3行目
			if (mou_x > 173.0f && mou_x < 246.0f && mou_y>97.0f && mou_y < 173.0f)
			{
				testx = 3;
				testy = 2;


				if (mou_l == true)
				{
					//2段目3行目->2段目4行目
					if (map[4][10] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[4 + i][7 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[4 + i][7 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[4 + i][10 + j] = mem[i][j];
							}
						}
					}

					//2段目3行目->2段目2行目
					if (map[4][4] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[4 + i][7 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[4 + i][7 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[4 + i][4 + j] = mem[i][j];
							}
						}
					}

					//2段目3行目->1段目3行目
					if (map[1][7] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[4 + i][7 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[4 + i][7 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[1 + i][7 + j] = mem[i][j];
							}
						}
					}

					//2段目3行目->3段目3行目
					if (map[7][7] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[4 + i][7 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[4 + i][7 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[7 + i][7 + j] = mem[i][j];
							}
						}
					}
				}
			}
			//2段目4行目
			if (mou_x > 246.0f && mou_x < 321.0f && mou_y>97.0f && mou_y < 173.0f)
			{
				testx = 4;
				testy = 2;


				if (mou_l == true)
				{
					//2段目4行目->2段目3行目
					if (map[4][7] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[4 + i][10 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[4 + i][10 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[4 + i][7 + j] = mem[i][j];
							}
						}
					}

					//2段目4行目->2段目5行目
					if (map[4][13] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[4 + i][10 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[4 + i][10 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[4 + i][13 + j] = mem[i][j];
							}
						}
					}

					//2段目4行目->1段目4行目
					if (map[1][10] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[4 + i][10 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[4 + i][10 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[1 + i][10 + j] = mem[i][j];
							}
						}
					}

					//2段目4行目->3段目4行目
					if (map[7][10] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[4 + i][10 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[4 + i][10 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[7 + i][10 + j] = mem[i][j];
							}
						}
					}
				}
			}
			//2段目5行目
			if (mou_x > 321.0f && mou_x < 394.0f && mou_y>97.0f && mou_y < 173.0f)
			{
				testx = 5;
				testy = 2;


				if (mou_l == true)
				{
					//2段目5行目->2段目6行目
					if (map[4][16] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[4 + i][13 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[4 + i][13 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[4 + i][16 + j] = mem[i][j];
							}
						}
					}

					//2段目5行目->2段目4行目
					if (map[4][10] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[4 + i][13 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[4 + i][13 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[4 + i][10 + j] = mem[i][j];
							}
						}
					}

					//2段目5行目->1段目5行目
					if (map[1][13] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[4 + i][13 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[4 + i][13 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[1 + i][13 + j] = mem[i][j];
							}
						}
					}

					//2段目5行目->3段目5行目
					if (map[7][13] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[4 + i][13 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[4 + i][13 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[7 + i][13 + j] = mem[i][j];
							}
						}
					}
				}
			}
			//2段目6行目
			if (mou_x > 394.0f && mou_x < 467.0f && mou_y>97.0f && mou_y < 173.0f)
			{
				testx = 6;
				testy = 2;


				if (mou_l == true)
				{
					//2段目6行目->1段目6行目
					if (map[1][16] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[4 + i][16 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[4 + i][16 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[1 + i][16 + j] = mem[i][j];
							}
						}
					}

					//2段目6行目->3段目6行目
					if (map[7][16] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[4 + i][16 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[4 + i][16 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[7 + i][16 + j] = mem[i][j];
							}
						}
					}

					//2段目6行目->2段目5行目
					if (map[4][13] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[4 + i][16 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[4 + i][16 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[4 + i][13 + j] = mem[i][j];
							}
						}
					}
				}
			}

			//3段目


			//3段目1行目
			if (mou_x > 25.0f && mou_x < 97.0f && mou_y>173.0f && mou_y < 246.0f)
			{
				testx = 1;
				testy = 3;


				if (mou_l == true)
				{
					//3段目1行目->2段目1行目
					if (map[4][1] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[7 + i][1 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[7 + i][1 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[4 + i][1 + j] = mem[i][j];
							}
						}
					}

					//3段目6行目->4段目6行目
					if (map[10][1] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[7 + i][1 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[7 + i][1 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[10 + i][1 + j] = mem[i][j];
							}
						}
					}

					//3段目1行目->3段目2行目
					if (map[7][4] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[7 + i][1 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[7 + i][1 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[7 + i][4 + j] = mem[i][j];
							}
						}
					}

				}
			}
			//3段目2行目
			if (mou_x > 98.0f && mou_x < 173.0f && mou_y>173.0f && mou_y < 246.0f)
			{
				testx = 2;
				testy = 3;


				if (mou_l == true)
				{
					//3段目2行目->3段目1行目
					if (map[7][1] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[7 + i][4 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[7 + i][4 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[7 + i][1 + j] = mem[i][j];
							}
						}
					}

					//3段目2行目->3段目3行目
					if (map[7][7] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[7 + i][4 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[7 + i][4 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[7 + i][7 + j] = mem[i][j];
							}
						}
					}

					//3段目2行目->4段目2行目
					if (map[10][4] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[7 + i][4 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[7 + i][4 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[10 + i][4 + j] = mem[i][j];
							}
						}
					}

					//3段目2行目->2段目2行目
					if (map[4][4] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[7 + i][4 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[7 + i][4 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[4 + i][4 + j] = mem[i][j];
							}
						}
					}
				}
			}
			//3段目3行目
			if (mou_x > 173.0f && mou_x < 246.0f && mou_y>173.0f && mou_y < 246.0f)
			{
				testx = 3;
				testy = 3;


				if (mou_l == true)
				{
					//3段目3行目->3段目4行目
					if (map[7][10] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[7 + i][7 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[7 + i][7 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[7 + i][10 + j] = mem[i][j];
							}
						}
					}

					//3段目3行目->3段目2行目
					if (map[7][4] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[7 + i][7 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[7 + i][7 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[7 + i][4 + j] = mem[i][j];
							}
						}
					}

					//3段目3行目->4段目3行目
					if (map[10][7] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[7 + i][7 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[7 + i][7 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[10 + i][7 + j] = mem[i][j];
							}
						}
					}

					//3段目3行目->2段目3行目
					if (map[4][7] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[7 + i][7 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[7 + i][7 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[4 + i][7 + j] = mem[i][j];
							}
						}
					}
				}
			}
			//3段目4行目
			if (mou_x > 246.0f && mou_x < 321.0f && mou_y>173.0f && mou_y < 246.0f)
			{
				testx = 4;
				testy = 3;


				if (mou_l == true)
				{
					//3段目4行目->3段目5行目
					if (map[7][13] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[7 + i][10 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[7 + i][10+ j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[7 + i][13 + j] = mem[i][j];
							}
						}
					}

					//3段目4行目->3段目3行目
					if (map[7][7] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[7 + i][10 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[7 + i][10 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[7 + i][7 + j] = mem[i][j];
							}
						}
					}

					//3段目4行目->4段目4行目
					if (map[10][10] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[7 + i][10 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[7 + i][10 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[10 + i][10 + j] = mem[i][j];
							}
						}
					}

					//3段目4行目->2段目4行目
					if (map[4][10] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[7 + i][10 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[7 + i][10 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[4 + i][10 + j] = mem[i][j];
							}
						}
					}
				}
			}
			//3段目5行目
			if (mou_x > 321.0f && mou_x < 394.0f && mou_y>173.0f && mou_y < 246.0f)
			{
				testx = 5;
				testy = 3;

				if (mou_l == true)
				{
					//3段目5行目->3段目6行目
					if (map[7][16] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[7 + i][13 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[7 + i][13 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[7 + i][16 + j] = mem[i][j];
							}
						}
					}

					//3段目5行目->3段目4行目
					if (map[7][10] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[7 + i][13 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[7 + i][13 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[7 + i][10 + j] = mem[i][j];
							}
						}
					}

					//3段目5行目->4段目5行目
					if (map[10][13] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[7 + i][13 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[7 + i][13 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[10 + i][13 + j] = mem[i][j];
							}
						}
					}

					//3段目5行目->2段目5行目
					if (map[4][13] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[7 + i][13 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[7 + i][13 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[4 + i][13 + j] = mem[i][j];
							}
						}
					}
				}
			}
			//3段目6行目
			if (mou_x > 394.0f && mou_x < 467.0f && mou_y>173.0f && mou_y < 246.0f)
			{
				testx = 6;
				testy = 3;

				if (mou_l == true)
				{
					//3段目6行目->4段目6行目
					if (map[10][16] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[7 + i][16 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[7 + i][16 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[10 + i][16 + j] = mem[i][j];
							}
						}
					}

					//3段目6行目->2段目6行目
					if (map[4][16] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[7 + i][16 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[7 + i][16 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[4 + i][16 + j] = mem[i][j];
							}
						}
					}

					//3段目6行目->3段目5行目
					if (map[7][13] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[7 + i][16 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[7 + i][16 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[7 + i][13 + j] = mem[i][j];
							}
						}
					}
				}
			}


			//4段目


			//4段目1行目
			if (mou_x > 25.0f && mou_x < 97.0f && mou_y>246.0f && mou_y < 321.0f)
			{
				testx = 1;
				testy = 4;

				if (mou_l == true)
				{
					//4段目1行目->4段目2行目
					if (map[10][4] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[10 + i][1 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[10 + i][1 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[10 + i][4 + j] = mem[i][j];
							}
						}
					}

					//4段目1行目->3段目1行目
					if (map[7][1] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[10 + i][1 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[10 + i][1 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[7 + i][1 + j] = mem[i][j];
							}
						}
					}

					//4段目1行目->5段目1行目
					if (map[13][1] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[10 + i][1 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[10 + i][1 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[13 + i][1 + j] = mem[i][j];
							}
						}
					}


				}
			}
			//4段目2行目
			if (mou_x > 98.0f && mou_x < 173.0f && mou_y>246.0f && mou_y < 321.0f)
			{
				testx = 2;
				testy = 4;

				if (mou_l == true)
				{
					//4段目2行目->4段目3行目
					if (map[10][7] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[10 + i][4 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[10 + i][4 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[10 + i][7 + j] = mem[i][j];
							}
						}
					}

					//4段目2行目->4段目1行目
					if (map[10][1] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[10 + i][4 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[10 + i][4 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[10 + i][1 + j] = mem[i][j];
							}
						}
					}

					//4段目2行目->5段目2行目
					if (map[13][4] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[10 + i][4 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[10 + i][4 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[13 + i][4 + j] = mem[i][j];
							}
						}
					}

					//4段目2行目->3段目2行目
					if (map[7][4] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[10 + i][4 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[10 + i][4 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[7 + i][4 + j] = mem[i][j];
							}
						}
					}
				}
			}
			//4段目3行目
			if (mou_x > 173.0f && mou_x < 246.0f && mou_y>246.0f && mou_y < 321.0f)
			{
				testx = 3;
				testy = 4;

				if (mou_l == true)
				{
					//4段目3行目->4段目4行目
					if (map[10][10] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[10 + i][7 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[10 + i][7 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[10 + i][10 + j] = mem[i][j];
							}
						}
					}

					//4段目3行目->4段目2行目
					if (map[10][4] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[10 + i][7 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[10 + i][7 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[10 + i][4 + j] = mem[i][j];
							}
						}
					}

					//4段目3行目->5段目3行目
					if (map[13][7] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[10 + i][7 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[10 + i][7 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[13 + i][7 + j] = mem[i][j];
							}
						}
					}

					//4段目3行目->3段目3行目
					if (map[7][7] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[10 + i][7 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[10 + i][7 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[7 + i][7 + j] = mem[i][j];
							}
						}
					}
				}
			}
			//4段目4行目
			if (mou_x > 246.0f && mou_x < 321.0f && mou_y>246.0f && mou_y < 321.0f)
			{
				testx = 4;
				testy = 4;

				if (mou_l == true)
				{
					//4段目4行目->4段目5行目
					if (map[10][13] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[10 + i][10 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[10 + i][10 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[10 + i][13 + j] = mem[i][j];
							}
						}
					}

					//4段目4行目->4段目3行目
					if (map[10][7] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[10 + i][10 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[10 + i][10 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[10 + i][7 + j] = mem[i][j];
							}
						}
					}

					//4段目4行目->5段目4行目
					if (map[13][10] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[10 + i][10 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[10 + i][10 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[13 + i][10 + j] = mem[i][j];
							}
						}
					}

					//4段目4行目->3段目4行目
					if (map[7][10] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[10 + i][10 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[10 + i][10 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[7 + i][10 + j] = mem[i][j];
							}
						}
					}
				}
			}
			//4段目5行目
			if (mou_x > 321.0f && mou_x < 394.0f && mou_y>246.0f && mou_y < 321.0f)
			{
				testx = 5;
				testy = 4;

				if (mou_l == true)
				{
					//4段目5行目->4段目6行目
					if (map[10][16] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[10 + i][13 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[10 + i][13 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[10 + i][16 + j] = mem[i][j];
							}
						}
					}

					//4段目5行目->4段目4行目
					if (map[10][10] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[10 + i][13 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[10 + i][13 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[10 + i][10 + j] = mem[i][j];
							}
						}
					}

					//4段目5行目->5段目5行目
					if (map[13][13] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[10 + i][13 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[10 + i][13 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[13 + i][13 + j] = mem[i][j];
							}
						}
					}

					//4段目5行目->3段目5行目
					if (map[7][13] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[10 + i][13 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[10 + i][13 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[7 + i][13 + j] = mem[i][j];
							}
						}
					}

				}
			}
			//4段目6行目
			if (mou_x > 394.0f && mou_x < 467.0f && mou_y>246.0f && mou_y < 321.0f)
			{
				testx = 6;
				testy = 4;

				if (mou_l == true)
				{
					//4段目6行目->5段目6行目
					if (map[13][16] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[10 + i][16 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[10 + i][16 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[13 + i][16 + j] = mem[i][j];
							}
						}

					
					}

					//4段目6行目->3段目6行目
					if (map[7][16] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[10 + i][16 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[10 + i][16 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[7 + i][16 + j] = mem[i][j];
							}
						}
					}

					//4段目6行目->4段目5行目
					if (map[10][13] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[10 + i][16 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[10 + i][16 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[10 + i][13 + j] = mem[i][j];
							}
						}
					}

				}

			}


			//5段目


			//5段目1行目
			if (mou_x > 25.0f && mou_x < 97.0f && mou_y>321.0f && mou_y < 394.0f)
			{
				testx = 1;
				testy = 5;

				if (mou_l == true)
				{
					//5段目1行目->5段目2行目
					if (map[13][4] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[13 + i][1 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[13 + i][1 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[13 + i][4 + j] = mem[i][j];
							}
						}
					}

					//5段目1行目->6段目1行目
					if (map[16][1] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[13 + i][1 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[13 + i][1 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[16 + i][1 + j] = mem[i][j];
							}
						}
					}

					//5段目1行目->4段目1行目
					if (map[10][1] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[13 + i][1 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[13 + i][1 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[10 + i][1 + j] = mem[i][j];
							}
						}
					}
				}
			}
			//5段目2行目
			if (mou_x > 98.0f && mou_x < 173.0f && mou_y>321.0f && mou_y < 394.0f)
			{
				testx = 2;
				testy = 5;

				if (mou_l == true)
				{
					//5段目2行目->5段目3行目
					if (map[13][7] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[13 + i][4 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[13 + i][4 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[13 + i][7 + j] = mem[i][j];
							}
						}
					}

					//5段目2行目->5段目1行目
					if (map[13][1] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[13 + i][4 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[13 + i][4 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[13 + i][1 + j] = mem[i][j];
							}
						}
					}

					//5段目2行目->6段目2行目
					if (map[16][4] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[13 + i][4 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[13 + i][4 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[16 + i][4 + j] = mem[i][j];
							}
						}
					}

					//5段目2行目->4段目2行目
					if (map[10][4] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[13 + i][4 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[13 + i][4 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[10 + i][4 + j] = mem[i][j];
							}
						}
					}
				}
			}
			//5段目3行目
			if (mou_x > 173.0f && mou_x < 246.0f && mou_y>321.0f && mou_y < 394.0f)
			{
				testx = 3;
				testy = 5;

				if (mou_l == true)
				{
					//5段目3行目->5段目4行目
					if (map[13][10] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[13 + i][7 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[13 + i][7 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[13 + i][10 + j] = mem[i][j];
							}
						}
					}

					//5段目3行目->5段目2行目
					if (map[13][4] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[13 + i][7 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[13 + i][7 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[13 + i][4 + j] = mem[i][j];
							}
						}
					}

					//5段目3行目->4段目3行目
					if (map[10][7] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[13 + i][7 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[13 + i][7 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[10 + i][7 + j] = mem[i][j];
							}
						}
					}

					//5段目3行目->6段目3行目
					if (map[16][7] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[13 + i][7 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[13 + i][7 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[16 + i][7 + j] = mem[i][j];
							}
						}
					}

				}
			}
			//5段目4行目
			if (mou_x > 246.0f && mou_x < 321.0f && mou_y>321.0f && mou_y < 394.0f)
			{
				testx = 4;
				testy = 5;

				if (mou_l == true)
				{
					//5段目4行目->5段目5行目
					if (map[13][13] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[13 + i][10 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[13 + i][10 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[13 + i][13 + j] = mem[i][j];
							}
						}
					}

					//5段目4行目->5段目3行目
					if (map[13][7] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[13 + i][10 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[13 + i][10 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[13 + i][7 + j] = mem[i][j];
							}
						}
					}

					//5段目4行目->4段目4行目
					if (map[10][10] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[13 + i][10 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[13 + i][10 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[10 + i][10 + j] = mem[i][j];
							}
						}
					}

					//5段目4行目->6段目4行目
					if (map[16][10] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[13 + i][10 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[13 + i][10 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[16 + i][10 + j] = mem[i][j];
							}
						}
					}
				}
			}
			//5段目5行目
			if (mou_x > 321.0f && mou_x < 394.0f && mou_y>321.0f && mou_y < 394.0f)
			{
				testx = 5;
				testy = 5;

				if (mou_l == true)
				{
					//5段目5行目->5段目6行目
					if (map[13][16] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[13 + i][13 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[13 + i][13 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[13 + i][16 + j] = mem[i][j];
							}
						}
					}

					//5段目5行目->5段目4行目
					if (map[13][10] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[13 + i][13 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[13 + i][13 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[13 + i][10 + j] = mem[i][j];
							}
						}
					}

					//5段目5行目->4段目5行目
					if (map[10][13] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[13 + i][13 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[13 + i][13 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[10 + i][13 + j] = mem[i][j];
							}
						}
					}

					//5段目5行目->6段目5行目
					if (map[16][13] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[13 + i][13 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[13 + i][13 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[16 + i][13 + j] = mem[i][j];
							}
						}
					}

				}
			}
			//5段目6行目
			if (mou_x > 394.0f && mou_x < 467.0f && mou_y>321.0f && mou_y < 394.0f)
			{
				testx = 6;
				testy = 5;

				if (mou_l == true)
				{
					//5段目6行目->6段目6行目
					if (map[16][16] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[13 + i][16 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[13 + i][16 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[16 + i][16 + j] = mem[i][j];
							}
						}
					}

					//5段目6行目->4段目5行目
					if (map[13][13] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[13 + i][16 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[13 + i][16 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[13 + i][13 + j] = mem[i][j];
							}
						}
					}

					//5段目6行目->4段目6行目
					if (map[10][16] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[13 + i][16 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[13 + i][16 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[10 + i][16 + j] = mem[i][j];
							}
						}
					}
				}
			}


			//6段目


			//6段目1行目
			if (mou_x > 25.0f && mou_x < 97.0f && mou_y>394.0f && mou_y < 467.0f)
			{
				testx = 1;
				testy = 6;

				if (mou_l == true)
				{

					//6段目1行目->6段目2行目
					if (map[16][4] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[16 + i][1 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[16 + i][1 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[16 + i][4 + j] = mem[i][j];
							}
						}
					}

					//6段目1行目->5段目1行目
					if (map[13][1] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[16 + i][1 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[16 + i][1 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[13 + i][1 + j] = mem[i][j];
							}
						}
					}

				}
			}
			//6段目2行目
			if (mou_x > 98.0f && mou_x < 173.0f && mou_y>394.0f && mou_y < 467.0f)
			{
				testx = 2;
				testy = 6;

				if (mou_l == true)
				{

					//6段目2行目->6段目3行目
					if (map[16][7] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[16 + i][4 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[16 + i][4 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[16 + i][7 + j] = mem[i][j];
							}
						}
					}

					//6段目2行目->6段目1行目
					if (map[16][1] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[16 + i][4 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[16 + i][4 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[16 + i][1 + j] = mem[i][j];
							}
						}
					}

					//6段目2行目->5段目2行目
					if (map[13][4] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[16 + i][4 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[16 + i][4 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[13 + i][4 + j] = mem[i][j];
							}
						}
					}
				}
			}
			//6段目3行目
			if (mou_x > 173.0f && mou_x < 246.0f && mou_y>394.0f && mou_y < 467.0f)
			{
				testx = 3;
				testy = 6;

				if (mou_l == true)
				{
					//6段目3行目->6段目4行目
					if (map[16][10] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[16 + i][7 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[16 + i][7 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[16 + i][10 + j] = mem[i][j];
							}
						}
					}

					//6段目3行目->6段目2行目
					if (map[16][4] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[16 + i][7 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[16 + i][7 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[16 + i][4 + j] = mem[i][j];
							}
						}
					}

					//6段目3行目->5段目3行目
					if (map[13][7] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[16 + i][7 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[16 + i][7 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[13 + i][7 + j] = mem[i][j];
							}
						}
					}
				}
			}
			//6段目4行目
			if (mou_x > 246.0f && mou_x < 321.0f && mou_y>394.0f && mou_y < 467.0f)
			{
				testx = 4;
				testy = 6;

				if (mou_l == true)
				{
					//6段目4行目->6段目5行目
					if (map[16][13] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[16 + i][10 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[16 + i][10 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[16 + i][13 + j] = mem[i][j];
							}
						}
					}

					//6段目4行目->6段目3行目
					if (map[16][7] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[16 + i][10 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[16 + i][10 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[16 + i][7 + j] = mem[i][j];
							}
						}
					}

					//6段目4行目->5段目4行目
					if (map[13][10] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[16 + i][10 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[16 + i][10 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[13 + i][10 + j] = mem[i][j];
							}
						}
					}

				}
			}
			//6段目5行目
			if (mou_x > 321.0f && mou_x < 394.0f && mou_y>394.0f && mou_y < 467.0f)
			{
				testx = 5;
				testy = 6;

				if (mou_l == true)
				{
					//6段目5行目->6段目6行目
					if (map[16][16] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[16 + i][13 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[16 + i][13 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[16 + i][16 + j] = mem[i][j];
							}
						}
					}

					//6段目5行目->6段目4行目
					if (map[16][10] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[16 + i][13 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[16 + i][13 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[16 + i][10 + j] = mem[i][j];
							}
						}
					}

					//6段目5行目->5段目5行目
					if (map[13][13] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[16 + i][13 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[16 + i][13 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[13 + i][13 + j] = mem[i][j];
							}
						}
					}

				}
				

			}
			//6段目6行目
			if (mou_x > 394.0f && mou_x < 467.0f && mou_y>394.0f && mou_y < 467.0f)
			{
				testx = 6;
				testy = 6;

				if (mou_l == true)
				{
					//6段目6行目->6段目5行目
					if (map[16][13] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[16 + i][16 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[16 + i][16 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[16 + i][13 + j] = mem[i][j];
							}
						}
					}

					//6段目6行目->5段目6行目
					if (map[13][16] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[16 + i][16 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[16 + i][16 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[13 + i][16 + j] = mem[i][j];
							}
						}
					}


				}
			}
		}

	
		else
		{
			test = false;
		}


	}

	//リセットボタンのプログラム
	if (s_r == false)
	{
		if (mou_x > 645.0f && mou_x < 764.0f && mou_y>497.0f && mou_y < 533.0f)
		{
			if (mou_l == true)
			{
				for (int i = 0; i < PIECE; i++)
				{
					for (int j = 0; j < PIECE; j++)
					{
						map[i][j] = memmap[i][j];
					}
				}

				time->m_time = 5400;
				time->m_flag_time = true;

				s_r = true;

				player->s_p = false;

				player->p_x = player->memp_x;
				player->p_y = player->memp_y;

				player->atk = 0;

				reset++;

			}
		}
	}

	if (player->battle == true)
	{
		if (pxc > 444.0f && pxc < 765.0f && pyc>301 && pyc < 312)
		{
			player->battle = false;
			Scene::SetScene(new CSceneStage4);

			if (player->HP == 10 && reset == 0)
			{
				((UserData*)Save::GetData())->Hperfect++;
			}
		}



		s_r = false;
	}
}
//ドロー
void CObjStage3::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float r[4] = { 1.0f,0.0f,0.0f,1.0f };
	float g[4] = { 0.0f,1.0f,0.0f,1.0f };
	float b[4] = { 0.0f,0.0f,1.0f,1.0f };
	float gl[4] = { 0.3f,0.3f,0.3f,1.0f };
	float y[4] = { 1.0f,1.0f,0.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	//表示：マウスカーソルとボタン
	wchar_t str[256];

	CObjPlayer* player = (CObjPlayer*)Objs::GetObj(OBJ_PLAYER);

	if (s_r == true)
	{
		Font::StrDraw(L"Road", 600, 30, 40, r);
	}

	if (player->battle == false)
	{

		if (s_r == true)
		{
			swprintf_s(str, L"RESET");
			Font::StrDraw(str, 650, 500, 50, gl);
		}

		else
		{
			swprintf_s(str, L"RESET");
			Font::StrDraw(str, 650, 500, 50, b);
		}
	}
	else
	{
		if (player->HP == 10 && reset == 0)
		{
			Font::StrDraw(L"PERFECT", 600, 250, 30, y);
		}

		else
		{
			Font::StrDraw(L"YOU WIN", 600, 250, 30, c);

			swprintf_s(str, L"受けたダメージ: %d", 10 - player->HP);
			Font::StrDraw(str, 580, 350, 20, c);

			swprintf_s(str, L"リセット回数: %d", reset);
			Font::StrDraw(str, 580, 375, 20, c);
		}


		Font::StrDraw(L"Next", 650, 300, 25, c);
	}
	//表示：通行可


	src.m_top = 90.0f;
	src.m_left = 45.0f;
	src.m_right = 85.0f;
	src.m_bottom = 125.0f;

	for (int i = 0; i < PIECE; i++)
	{
		for (int j = 0; j < PIECE; j++)
		{

			if (map[i][j] == 2)
			{
				dst.m_top = i * SIZE;
				dst.m_left = j * SIZE;
				dst.m_right = dst.m_left + SIZE;
				dst.m_bottom = dst.m_top + SIZE;

				Draw::Draw(0, &src, &dst, c, 0.0f);
			}

		}
	}

	//表示：通行不可

	src.m_top = 90.0f;
	src.m_left = 0.0f;
	src.m_right = 45.0f;
	src.m_bottom = 125.0f;

	for (int i = 0; i < PIECE; i++)
	{
		for (int j = 0; j < PIECE; j++)
		{
			if (map[i][j] == 1)
			{
				dst.m_top = i * SIZE;
				dst.m_left = j * SIZE;
				dst.m_right = dst.m_left + SIZE;
				dst.m_bottom = dst.m_top + SIZE;

				Draw::Draw(0, &src, &dst, c, 0.0f);

			}
		}
	}

	//表示：アイテム
	src.m_top = 130.0f;
	src.m_left = 1.0f;
	src.m_right = 51.0f;
	src.m_bottom = 180.0f;

	for (int i = 0; i < PIECE; i++)
	{
		for (int j = 0; j < PIECE; j++)
		{
			if (map[i][j] == 3)
			{
				dst.m_top = i * SIZE;
				dst.m_left = j * SIZE;
				dst.m_right = dst.m_left + SIZE;
				dst.m_bottom = dst.m_top + SIZE;

				Draw::Draw(0, &src, &dst, c, 0.0f);

			}
		}
	}


	//表示：アイテム
	src.m_top = 130.0f;
	src.m_left = 52.0f;
	src.m_right = 101.0f;
	src.m_bottom = 180.0f;

	for (int i = 0; i < PIECE; i++)
	{
		for (int j = 0; j < PIECE; j++)
		{
			if (map[i][j] == 4)
			{
				dst.m_top = i * SIZE;
				dst.m_left = j * SIZE;
				dst.m_right = dst.m_left + SIZE;
				dst.m_bottom = dst.m_top + SIZE;

				Draw::Draw(0, &src, &dst, c, 0.0f);

			}
		}
	}

	//表示：アイテム
	src.m_top = 130.0f;
	src.m_left = 102.0f;
	src.m_right = 151.0f;
	src.m_bottom = 180.0f;

	for (int i = 0; i < PIECE; i++)
	{
		for (int j = 0; j < PIECE; j++)
		{
			if (map[i][j] == 5)
			{
				dst.m_top = i * SIZE;
				dst.m_left = j * SIZE;
				dst.m_right = dst.m_left + SIZE;
				dst.m_bottom = dst.m_top + SIZE;

				Draw::Draw(0, &src, &dst, c, 0.0f);

			}
		}
	}
}