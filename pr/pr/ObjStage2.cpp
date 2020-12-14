//使用するヘッダーファイル
#include "ObjStage2.h"
#include "ObjPlayer.h"
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "GameHead.h" 
#include "GameL/WinInputs.h"
#include "GameL/HitBoxManager.h"
#include "GameL/SceneObjManager.h"
#include "GameL/UserData.h"
#include "GameL/Audio.h"

#define PIECE 17
#define SIZE 30.0f

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjStage2::Init()
{
	((UserData*)Save::GetData())->stage = 2;



	mou_x = 0.0f;
	mou_y = 0.0f;
	mou_r = false;
	mou_l = false;

	reset = 0;

	pxc = 0.0f;
	pyc = 0.0f;

	pv_x = 0.0f;
	pv_y = 0.0f;

	f_p = false;

	s_r = false;
	sei = false;

	s_time = 240;
	second = 4;
	set = false;


	CObjPlayer* player = (CObjPlayer*)Objs::GetObj(OBJ_PLAYER);
	CObjItem* item = (CObjItem*)Objs::GetObj(OBJ_ITEM);
	

	player->num = 2;

	player->p_x = 0.0f;
	player->p_y = 240.0f;

	int mapdata[PIECE][PIECE] =
	{                     //11.12.13.14.15.16
		{0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0},//0
		{0,1,2,1,1,1,1,1,2,1,1,1,1,1,2,1,0},//1
		{2,1,3,2,2,2,2,1,5,1,1,2,2,2,3,1,2},//2
		{0,1,1,1,1,1,1,1,2,1,1,2,1,1,1,1,0},//3
		{0,1,1,1,1,1,1,1,2,1,1,2,1,1,1,1,0},//4
		{2,2,3,2,2,2,1,1,2,2,1,4,1,1,3,2,2},//5
		{0,1,2,1,1,2,1,1,1,1,1,2,1,1,2,1,0},//6
		{0,1,1,1,1,2,1,1,1,1,1,1,1,1,2,1,0},//7
		{2,2,2,2,2,4,2,2,2,1,2,3,2,2,2,1,2},//8
		{0,1,1,1,1,2,1,1,2,1,1,2,1,1,2,1,0},//9
		{0,1,2,1,1,2,1,1,1,1,1,1,1,1,1,1,0},//10
		{2,1,6,2,1,2,1,2,3,2,2,2,1,2,5,2,2},//11
		{0,1,1,1,1,2,1,1,1,1,1,2,1,1,2,1,0},//12
		{0,1,2,1,1,2,1,1,2,1,1,2,1,0,0,0,0},//13
		{2,2,5,2,2,2,1,1,3,2,2,4,1,0,0,0,2},//14
		{0,1,2,1,1,1,1,1,1,1,1,1,1,0,0,0,0},//15
		{0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0},//16
	   //0,1,2,3,4,5,6,7,8,9,10
	};



	memcpy(map, mapdata, sizeof(int) * (PIECE * PIECE));

	for (int i = 0; i < PIECE; i++)
	{
		for (int j = 0; j < PIECE; j++)
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

}
//アクション
void CObjStage2::Action()
{
	CObjItem* item = (CObjItem*)Objs::GetObj(OBJ_ITEM);
	CObjTime* time = (CObjTime*)Objs::GetObj(OBJ_TIME);

	CObjEnemy2* Enemy2 = (CObjEnemy2*)Objs::GetObj(OBJ_ENEMY2);
	CObjPlayer* player = (CObjPlayer*)Objs::GetObj(OBJ_PLAYER);
	float px = player->GetX();
	float py = player->GetY();

	//mapにアクセス


	if (set == false)
	{
		s_time--;
		if (s_time % 60 == 0)
		{
			second--;
		}
		if (second == 0)
		{
			s_r = true;
			set = true;
			time->m_flag_time = true;
		}

	}


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
	//回復アイテム
	for (int i = 0; i < PIECE; i++)
	{
		for (int j = 0; j < PIECE; j++)
		{
			if (map[i][j] == 6)
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
						if (map[i][j] == 6)
						{
							map[i][j] = 2;
						}

						if (player->HP < 5)
						{
							player->HP++;
						}
					}

				}
			}
		}
	}


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
			player->s_p = true;
			Enemy2->atk = false;
		}
		
		//1段目の1個目(左から)
		if (mou_x > 28.0f && mou_x < 118.0f && mou_y>28.0f && mou_y < 118.0f)
		{
			if (mou_l == true)
			{
				//右へ移動
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
				//下へ移動
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

		//1段目の2個目(左から)
		if (mou_x > 117.0f && mou_x < 207.0f && mou_y>28.0f && mou_y < 118.0f)
		{
			if (mou_l == true)
			{
				//右へ移動
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
				//下へ移動
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

				//左へ移動
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

		
			}


		}

		//1段目の3個目(左から)
		if (mou_x > 205.0f && mou_x < 297.0f && mou_y>28.0f && mou_y < 118.0f)
		{
			if (mou_l == true)
			{
				//右へ移動
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
				//下へ移動
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

				//左へ移動
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

			}


		}

		//1段目の4個目(左から)
		if (mou_x > 294.0f && mou_x < 386.0f && mou_y>28.0f && mou_y < 118.0f)
		{
			if (mou_l == true)
			{
				//右へ移動
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
				//下へ移動
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

				//左へ移動
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

			}

		}

		//1段目の5個目(左から)
		if (mou_x > 383.0f && mou_x < 474.0f && mou_y>27.0f && mou_y < 118.0f)
		{
			if (mou_l == true)
			{
				//下へ移動
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

				//左へ移動
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

			}
		}

		//2段目の1個目(左から)
		if (mou_x > 28.0f && mou_x < 120.0f && mou_y>115.0f && mou_y < 210.0f)
		{
			if (mou_l == true)
			{
				//右へ移動
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
				//下へ移動
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

				//上へ移動
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
			}


		}

		//2段目の2個目(左から)
		if (mou_x > 117.0f && mou_x < 206.0f && mou_y>117.0f && mou_y < 206.0f)
		{
			if (mou_l == true)
			{
				//右へ移動
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
				//下へ移動
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

				//左へ移動
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

				//上へ移動
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
			}


		}

		//2段目の3個目(左から)
		if (mou_x > 205.0f && mou_x < 297.0f && mou_y>115.0f && mou_y < 205.0f)
		{
			if (mou_l == true)
			{
				//右へ移動
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
				//下へ移動
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

				//左へ移動
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

				//上へ移動
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
			}


		}

		//2段目の4個目(左から)
		if (mou_x > 294.0f && mou_x < 385.0f && mou_y>115.0f && mou_y < 207.0f)
		{
			if (mou_l == true)
			{
				//右へ移動
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
				//下へ移動
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

				//左へ移動
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

				//上へ移動
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
			}


		}

		//2段目の5個目(左から)
		if (mou_x > 384.0f && mou_x < 472.0f && mou_y>116.0f && mou_y < 204.0f)
		{
			if (mou_l == true)
			{
				//下へ移動
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

				//左へ移動
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

				//上へ移動
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
			}


		}

		//3段目の1個目(左から)
		if (mou_x > 28.0f && mou_x < 119.0f && mou_y>205.0f && mou_y < 296.0f)
		{
			if (mou_l == true)
			{
				//右へ移動
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
				//下へ移動
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

				//上へ移動
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
			}


		}

		//3段目の2個目(左から)
		if (mou_x > 116.0f && mou_x < 207.0f && mou_y>206.0f && mou_y < 296.0f)
		{
			if (mou_l == true)
			{
				//右へ移動
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
				//下へ移動
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

				//左へ移動
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

				//上へ移動
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

		//3段目の3個目(左から)
		if (mou_x > 206.0f && mou_x < 296.0f && mou_y>206.0f && mou_y < 296.0f)
		{
			if (mou_l == true)
			{
				//右へ移動
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
				//下へ移動
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

				//左へ移動
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

				//上へ移動
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

		//3段目の4個目(左から)
		if (mou_x > 295.0f && mou_x < 387.0f && mou_y>206.0f && mou_y < 296.0f)
		{
			if (mou_l == true)
			{
				//右へ移動
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
							map[7 + i][10 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][13 + j] = mem[i][j];
						}

					}
				}
				//下へ移動
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

				//左へ移動
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

				//上へ移動
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

		//3段目の5個目(左から)
		if (mou_x > 382.0f && mou_x < 473.0f && mou_y>205.0f && mou_y < 295.0f)
		{
			if (mou_l == true)
			{
				
				//下へ移動
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

				//左へ移動
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

				//上へ移動
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

		//4段目の1個目(左から)
		if (mou_x > 29.0f && mou_x < 120.0f && mou_y>293.0f && mou_y < 384.0f)
		{

			if (mou_l == true)
			{
				//右へ移動
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
				//下へ移動
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

				//上へ移動
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
			}

		}

		//4段目の2個目(左から)
		if (mou_x > 117.0f && mou_x < 209.0f && mou_y>292.0f && mou_y < 383.0f)
		{
			if (mou_l == true)
			{
				//右へ移動
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
				//下へ移動
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

				//左へ移動
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

				//上へ移動
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

		//4段目の3個目(左から)
		if (mou_x > 206.0f && mou_x < 297.0f && mou_y>293.0f && mou_y < 385.0f)
		{
			if (mou_l == true)
			{
				//右へ移動
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
				//下へ移動
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

				//左へ移動
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

				//上へ移動
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

		//4段目の4個目(左から)
		if (mou_x > 293.0f && mou_x < 386.0f && mou_y>293.0f && mou_y < 386.0f)
		{
			if (mou_l == true)
			{
				//右へ移動
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
				//下へ移動
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

				//左へ移動
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

				//上へ移動
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

		//4段目の5個目(左から)
		if (mou_x > 384.0f && mou_x < 473.0f && mou_y>291.0f && mou_y < 382.0f)
		{
			if (mou_l == true)
			{
				//下へ移動
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
				//左へ移動
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

				//上へ移動
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

		//5段目の1個目(左から)
		if (mou_x > 28.0f && mou_x < 120.0f && mou_y>382.0f && mou_y < 471.0f)
		{

			if (mou_l == true)
			{
				//右へ移動
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

				//上へ移動
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

		//5段目の2個目(左から)
		if (mou_x > 119.0f && mou_x < 207.0f && mou_y>382.0f && mou_y < 473.0f)
		{

			if (mou_l == true)
			{
				//右へ移動
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

				//左へ移動
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

				//上へ移動
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

		//5段目の3個目(左から)
		if (mou_x > 206.0f && mou_x < 296.0f && mou_y>381.0f && mou_y < 472.0f)
		{

			if (mou_l == true)
			{
				//右へ移動
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

				//左へ移動
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

				//上へ移動
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

			}
		}

		//5段目の4個目(左から)
		if (mou_x > 295.0f && mou_x < 384.0f && mou_y>381.0f && mou_y < 472.0f)
		{

			if (mou_l == true)
			{
				//右へ移動
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

				//左へ移動
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

				//上へ移動
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


			}
		}

		//5段目の5個目(左から)
		if (mou_x > 383.0f && mou_x < 473.0f && mou_y>383.0f && mou_y < 473.0f)
		{
			if (mou_l == true)
			{
				//左へ移動
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
				//上へ移動
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
			}
		}
	}

	//リセットボタンのプログラム
	if (s_r == false&&set==true)
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

				reset++;

				time->m_time = 5400;
				time->m_flag_time = true;

				s_r = true;

				player->s_p = false;

				player->p_x = player->memp_x;
				player->p_y = player->memp_y;

				player->atk = 0;

			}
		}
	}

	if (player->battle == true)
	{
		if (mou_l == true)
		{


			player->battle = false;
			Scene::SetScene(new CSceneStage3);

			if (player->HP == 5 && reset == 0)
			{
				((UserData*)Save::GetData())->Hperfect++;
			}

		}



		s_r = false;
	}
}
//ドロー
void CObjStage2::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float r[4] = { 1.0f,0.0f,0.0f,1.0f };
	float g[4] = { 0.0f,1.0f,0.0f,1.0f };
	float b[4] = { 0.0f,0.0f,1.0f,1.0f };
	float gl[4] = { 0.3f,0.3f,0.3f,1.0f };
	float y[4] = { 1.0f,1.0f,0.0f,1.0f };
	float p[4] = { 1.0f,0.5f,0.5f,1.0f };

	RECT_F src;
	RECT_F dst;

	//表示：マウスカーソルとボタン
	wchar_t str[256];

	if (set == false)
	{
		if (second > 1)
		{
			swprintf_s(str, L"%d", second - 1);
			Font::StrDraw(str, 642, 350, 100, c);
		}
		else
		{
			Font::StrDraw(L"GO!", 642, 350, 100, r);
		}
	}

	CObjPlayer* player = (CObjPlayer*)Objs::GetObj(OBJ_PLAYER);

	if (s_r == true)
	{
		Font::StrDraw(L"Road", 600, 30, 40, r);
	}

	if (player->battle == false)
	{

		if (s_r == true||set==true)
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
		if (player->HP == 5 && reset == 0)
		{
			Font::StrDraw(L"PERFECT", 600, 250, 30, y);
		}

		else
		{
			Font::StrDraw(L"YOU WIN", 600, 250, 30, c);

			swprintf_s(str, L"受けたダメージ: %d", 5 - player->HP);
			Font::StrDraw(str, 580, 350, 20, c);

			swprintf_s(str, L"リセット回数: %d", reset);
			Font::StrDraw(str, 580, 375, 20, c);
		}


		Font::StrDraw(L"次のステージへ", 600, 300, 25, c);
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

	//表示：アイテム1
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


	src.m_top = 130.0f;
	src.m_left = 152.0f;
	src.m_right = 203.0f;
	src.m_bottom = 180.0f;

	//表示：回復アイテム
	for (int i = 0; i < PIECE; i++)
	{
		for (int j = 0; j < PIECE; j++)
		{
			if (map[i][j] == 6)
			{
				dst.m_top = i * SIZE;
				dst.m_left = j * SIZE;
				dst.m_right = dst.m_left + SIZE;
				dst.m_bottom = dst.m_top + SIZE;

				Draw::Draw(0, &src, &dst, c, 0.0f);

			}
		}
	}

	//表示：アイテム2
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

	//表示：アイテム3
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
