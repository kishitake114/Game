#include "hardstage1.h"
#include "ObjPlayer.h"
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "GameHead.h" 
#include "GameL/WinInputs.h"
#include "GameL/HitBoxManager.h"
#include "GameL/SceneObjManager.h"
#include "GameL/UserData.h"

#define PIECE 14
#define SIZE 40.0f


//イニシャライズ
void CObjHardStage1::Init()
{
	CObjPlayer* player = (CObjPlayer*)Objs::GetObj(OBJ_PLAYER);
	CObjTime* time = (CObjTime*)Objs::GetObj(OBJ_TIME);

	player->num = 1;

	reset = 0;

	mou_x = 0.0f;
	mou_y = 0.0f;
	mou_r = false;
	mou_l = false;

	piece = true;

	pxc = 0.0f;
	pyc = 0.0f;

	pv_x = 0.0f;
	pv_y = 0.0f;

	f_p = false;

	s_r = true;
	sei = false;
	swi = false;

	CObjPlayer* obj = (CObjPlayer*)Objs::GetObj(OBJ_PLAYER);
	obj->p_x = 0.0f;
	obj->p_y = 200.0f;

	int mapdata[PIECE][PIECE] =
	{
	{0,0,7,0,0,7,0,0,7,0,0,7,0,0},
	{0,1,2,1,1,2,1,1,1,1,1,2,1,0},
	{7,2,2,2,1,4,1,2,2,2,1,6,2,7},
	{0,1,2,1,1,2,1,1,2,1,1,1,1,0},
	{0,1,2,1,1,1,1,1,1,1,1,2,1,0},
	{7,1,4,1,2,2,2,2,5,2,1,2,2,7},
	{0,1,2,1,1,2,1,1,1,1,1,2,1,0},
	{0,1,1,1,1,1,1,1,2,1,1,2,1,0},
	{7,2,3,2,1,2,2,2,3,2,2,2,2,7},
	{0,1,1,1,1,2,1,1,1,1,1,2,1,0},
	{0,1,2,1,0,0,0,1,2,1,1,1,1,0},
	{7,2,6,1,0,0,0,1,2,1,2,4,2,7},
	{0,1,1,1,0,0,0,1,2,1,1,1,1,0},
	{0,0,7,0,0,7,0,0,7,0,0,7,0,0},
	};

	memcpy(map, mapdata, sizeof(int) * (PIECE * PIECE));


	for (int i = 0; i < PIECE; i++)
	{
		for (int j = 0; j < PIECE; j++)
		{

			Hmap[i][j] = 0;

		}
	}

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
void CObjHardStage1::Action()
{
	CObjTime* time = (CObjTime*)Objs::GetObj(OBJ_TIME);

	if (s_r == true && mou_l == true)
	{
		time->m_flag_time = true;
	}

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
	//通行可
	for (int i = 0; i < PIECE; i++)
	{
		for (int j = 0; j < PIECE; j++)
		{
			if (map[i][j] == 2)
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
							if (map[i][j] == 2)
							{
								Hmap[i][j] = 1;
							}
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

						if (player->HP < 10)
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
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				Hmem[i][j] = 0;
			}
		}

		//右クリックで操作中止
		if (mou_r == true)
		{
			s_r = false;
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
							Hmem[i][j] = Hmap[1 + i][1 + j];
						}


						for (int j = 0; j < 3; j++)
						{
							map[1 + i][1 + j] = 0;

						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][4 + j] = mem[i][j];
							Hmap[1 + i][4 + j] = Hmem[i][j];

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
							Hmem[i][j] = Hmap[1 + i][1 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][1 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][1 + j] = mem[i][j];
							Hmap[4 + i][1 + j] = Hmem[i][j];
						
						}
					}
				}
			}
		}

		//1列目２マス目 
		if (mou_x > 155.0f && mou_x < 273.0f && mou_y>40.0f && mou_y < 155.0f)
		{
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
							Hmem[i][j] = Hmap[1 + i][4 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][4 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][4 + j] = mem[i][j];
							Hmap[4 + i][4 + j] = Hmem[i][j];
							
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
							Hmap[1 + i][1 + j] = Hmem[i][j];
							
						}
					}

				}

				//１列目（2マス目）→（右）1マス移動　
				if (map[1][7] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[1 + i][4 + j];
							Hmem[i][j] = Hmap[1 + i][4 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][4 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][7 + j] = mem[i][j];
							Hmap[1 + i][7 + j] = Hmem[i][j];
							
						}
					}

				}
			}
		}

		//1列目（3マス目）
		if (mou_x > 274.0f && mou_x < 394.0f && mou_y>40.0f && mou_y < 155.0f)
		{
			if (mou_l == true)
			{

				//（３マス目）↓（下）1マス移動
				if (map[4][7] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[1 + i][7 + j];
							Hmem[i][j] = Hmap[1 + i][7 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][7 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][7 + j] = mem[i][j];
							Hmap[4 + i][7 + j] = Hmem[i][j];
							
						}
					}
				}
				//１列目（３マス目）←（左）1マス移動
				if (map[1][4] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[1 + i][7 + j];
							Hmem[i][j] = Hmap[1 + i][7 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][7 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							Hmap[1 + i][4 + j] = Hmem[i][j];
							map[1 + i][4 + j] = mem[i][j];

						}
					}
				}
				//１列目（３マス目）→（右）1マス移動
				if (map[1][10] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[1 + i][7 + j];
							Hmem[i][j] = Hmap[1 + i][7 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][7 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][10 + j] = mem[i][j];
							Hmap[1 + i][10 + j] = Hmem[i][j];
							
						}
					}

				}
			}
		}

		//1列目４マス目
		if (mou_x > 395.0f && mou_x < 520.0f && mou_y>40.0f && mou_y < 155.0f)
		{
			if (mou_l == true)
			{

				//１列目（４マス目）↓（下）1マス移動
				if (map[4][10] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[1 + i][10 + j];
							Hmem[i][j] = Hmap[1 + i][10 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][10 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][10 + j] = mem[i][j];
							Hmap[4 + i][10 + j] = Hmem[i][j];

							
						}
					}
				}
				//１列目（４マス目）←（左）1マス移動
				if (map[1][7] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[1 + i][10 + j];
							Hmem[i][j] = Hmap[1 + i][10 + j];

						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][10 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][7 + j] = mem[i][j];
							Hmap[1 + i][7 + j] = Hmem[i][j];
							
						}
					}
				}
			}
		}

		//2列目
		if (mou_x > 40.0f && mou_x < 155.0f && mou_y>156.0f && mou_y < 273.0f)
		{
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
							Hmem[i][j] = Hmap[4 + i][1 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][1 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][1 + j] = mem[i][j];
							Hmap[1 + i][1 + j] = Hmem[i][j];
							
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
							Hmem[i][j] = Hmap[4 + i][1 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][1 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][4 + j] = mem[i][j];
							Hmap[4 + i][4 + j] = Hmem[i][j];

						}
					}
				}

				//2列目（１マス目）↓（下）1マス移動
				if (map[7][1] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[4 + i][1 + j];
							Hmem[i][j] = Hmap[4 + i][1 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][1 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][1 + j] = mem[i][j];
							Hmap[7 + i][1 + j] = Hmem[i][j];
							
						}
					}
				}
			}
		}

		//2列目（2マス目）
		if (mou_x > 156.0f && mou_x < 273.0f && mou_y>156.0f && mou_y < 273.0f)
		{
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
							Hmem[i][j] = Hmap[4 + i][4 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][4 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][1 + j] = mem[i][j];
							Hmap[4 + i][1 + j] = Hmem[i][j];
							
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
							Hmem[i][j] = Hmap[4 + i][4 + j];

						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][4 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][4 + j] = mem[i][j];
							Hmap[1 + i][4 + j] = Hmem[i][j];
							
						}
					}
				}

				//2列目（2マス目）→（右）1マス移動
				if (map[7][4] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[4 + i][4 + j];
							Hmem[i][j] = Hmap[4 + i][4 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][4 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][4 + j] = mem[i][j];
							Hmap[7 + i][4 + j] = Hmem[i][j];
							
						}
					}
				}

				//2列目（2マス目）↓（下）1マス移動
				if (map[4][7] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[4 + i][4 + j];
							Hmem[i][j] = Hmap[4 + i][4 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][4 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][7 + j] = mem[i][j];
							Hmap[4 + i][7 + j] = Hmem[i][j];
							
						}
					}
				}
			}
		}

		//2列目（3マス目）
		if (mou_x > 274.0f && mou_x < 394.0f && mou_y>155.0f && mou_y < 274.0f)
		{
			if (mou_l == true)
			{
				//2列目（3マス目）←（左）1マス移動
				if (map[4][4] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[4 + i][7 + j];
							Hmem[i][j] = Hmap[4 + i][7 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][7 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][4 + j] = mem[i][j];
							Hmap[4 + i][4 + j] = Hmem[i][j];
							
						}
					}

				}

				//2列目（3マス目）↑（上）1マス移動
				if (map[1][7] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[4 + i][7 + j];
							Hmem[i][j] = Hmap[4 + i][7 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][7 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][7 + j] = mem[i][j];
							Hmap[1 + i][7 + j] = Hmem[i][j];
							
						}
					}
				}

				//2列目（3マス目）→（右）1マス移動
				if (map[4][10] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[4 + i][7 + j];
							Hmem[i][j] = Hmap[4 + i][7 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][7 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][10 + j] = mem[i][j];
							Hmap[4 + i][10 + j] = Hmem[i][j];
							
						}
					}
				}

				//2列目（3マス目）↓（下）1マス移動
				if (map[7][7] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[4 + i][7 + j];
							Hmem[i][j] = Hmap[4 + i][7 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][7 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][7 + j] = mem[i][j];
							Hmap[7 + i][7 + j] = Hmem[i][j];
							
						}
					}
				}
			}
		}

		//2列目（4マス目）
		if (mou_x > 394.0f && mou_x < 520.0f && mou_y>156.0f && mou_y < 273.0f)
		{
			if (mou_l == true)
			{
				//2列目（4マス目）←（左）1マス移動
				if (map[4][7] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[4 + i][10 + j];
							Hmem[i][j] = Hmap[4 + i][10 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][10 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][7 + j] = mem[i][j];
							Hmap[4 + i][7 + j] = Hmem[i][j];
							
						}
					}

				}

				//2列目（4マス目）↑（上）1マス移動
				if (map[1][10] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[4 + i][10 + j];
							Hmem[i][j] = Hmap[4 + i][10 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][10 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][10 + j] = mem[i][j];
							Hmap[1 + i][10 + j] = Hmem[i][j];
						
						}
					}
				}

				//2列目（4マス目）↓（下）1マス移動
				if (map[7][10] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[4 + i][10 + j];
							Hmem[i][j] = Hmap[4 + i][10 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][10 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][10 + j] = mem[i][j];
							Hmap[7 + i][10 + j] = Hmem[i][j];
							pv_y = 120;
						}
					}
				}
			}
		}

		//3列目
		if (mou_x > 40.0f && mou_x < 155.0f && mou_y>274.0f && mou_y < 394.0f)
		{
			if (mou_l == true)
			{
				//3列目（１マス目）↑（上）1マス移動
				if (map[4][1] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[7 + i][1 + j];
							Hmem[i][j] = Hmap[7 + i][1 + j];

						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][1 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][1 + j] = mem[i][j];
							Hmap[4 + i][1 + j] = Hmem[i][j];
							pv_y += 120;
						}
					}
				}

				//3列目（１マス目）→（右）1マス移動
				if (map[7][4] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[7 + i][1 + j];
							Hmem[i][j] = Hmap[7 + i][1 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][1 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][4 + j] = mem[i][j];
							Hmap[7 + i][4 + j] = Hmem[i][j];
							pv_x = 120;
						}
					}
				}

				//3列目（１マス目）↓（下）1マス移動
				if (map[10][1] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[7 + i][1 + j];
							Hmem[i][j] = Hmap[7 + i][1 + j];

						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][1 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][1 + j] = mem[i][j];
							Hmap[10 + i][1 + j] = Hmem[i][j];
							pv_x = 120;
						}
					}
				}
			}
		}

		//3列目（2マス目）
		if (mou_x > 156.0f && mou_x < 273.0f && mou_y>274.0f && mou_y < 394.0f)
		{
			if (mou_l == true)
			{
				//3列目（2マス目）←（左）1マス移動
				if (map[7][1] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[7 + i][4 + j];
							Hmem[i][j] = Hmap[7 + i][4 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][4 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][1 + j] = mem[i][j];
							Hmap[7 + i][1 + j] = Hmem[i][j];
							pv_x = -120;
						}
					}

				}

				//3列目（2マス目）↑（上）1マス移動
				if (map[4][4] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[7 + i][4 + j];
							Hmem[i][j] = Hmap[7 + i][4 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][4 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][4 + j] = mem[i][j];
							Hmap[4 + i][4 + j] = Hmem[i][j];
						
						}
					}
				}

				//3列目（2マス目）→（右）1マス移動
				if (map[7][7] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[7 + i][4 + j];
							Hmem[i][j] = Hmap[7 + i][4 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][4 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][7 + j] = mem[i][j];
							Hmap[7 + i][7 + j] = Hmem[i][j];
							pv_y = 120;
						}
					}
				}

				//3列目（2マス目）↓（下）1マス移動
				if (map[10][4] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[7 + i][4 + j];
							Hmem[i][j] = Hmap[7 + i][4 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][4 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][4 + j] = mem[i][j];
							Hmap[10 + i][4 + j] = Hmem[i][j];
							pv_y = 120;
						}
					}
				}
			}
		}

		//3列目（3マス目）
		if (mou_x > 274.0f && mou_x < 393.0f && mou_y>274.0f && mou_y < 394.0f)
		{
			if (mou_l == true)
			{
				//3列目（3マス目）←（左）1マス移動
				if (map[7][4] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[7 + i][7 + j];
							Hmem[i][j] = Hmap[7 + i][7 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][7 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][4 + j] = mem[i][j];
							Hmap[7 + i][4 + j] = Hmem[i][j];
							pv_x = -120;
						}
					}

				}

				//3列目（3マス目）↑（上）1マス移動
				if (map[4][7] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[7 + i][7 + j];
							Hmem[i][j] = Hmap[7 + i][7 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][7 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][7 + j] = mem[i][j];
							Hmap[4 + i][7 + j] = Hmem[i][j];
							pv_y = 120;
						}
					}
				}

				//3列目（3マス目）→（右）1マス移動
				if (map[7][10] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[7 + i][7 + j];
							Hmem[i][j] = Hmap[7 + i][7 + j];

						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][7 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][10 + j] = mem[i][j];
							Hmap[7 + i][10 + j] = Hmem[i][j];
							pv_y = 120;
						}
					}
				}

				//3列目（3マス目）↓（下）1マス移動
				if (map[10][7] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[7 + i][7 + j];
							Hmem[i][j] = Hmap[7 + i][7 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][7 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][7 + j] = mem[i][j];
							Hmap[10 + i][7 + j] = Hmem[i][j];
							pv_y = 120;
						}
					}
				}
			}
		}

		//3列目（4マス目）
		if (mou_x > 394.0f && mou_x < 520.0f && mou_y>274.0f && mou_y < 394.0f)
		{
			if (mou_l == true)
			{
				//3列目（4マス目）←（左）1マス移動
				if (map[7][7] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[7 + i][10 + j];
							Hmem[i][j] = Hmap[7 + i][10 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][10 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][7 + j] = mem[i][j];
							Hmap[7 + i][7 + j] = Hmem[i][j];
							pv_x = -120;
						}
					}

				}

				//3列目（4マス目）↑（上）1マス移動
				if (map[4][10] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[7 + i][10 + j];
							Hmem[i][j] = Hmap[7 + i][10 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][10 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][10 + j] = mem[i][j];
							Hmap[4 + i][10 + j] = Hmem[i][j];
							pv_y = 120;
						}
					}
				}

				//3列目（4マス目）↓（下）1マス移動
				if (map[10][10] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[7 + i][10 + j];
							Hmem[i][j] = Hmap[7 + i][10 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][10 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][10 + j] = mem[i][j];
							Hmap[10 + i][10 + j] = Hmem[i][j];
							pv_y = 120;
						}
					}
				}
			}
		}

		//4列目
		if (mou_x > 40.0f && mou_x < 155.0f && mou_y>394.0f && mou_y < 520.0f)
		{
			if (mou_l == true)
			{
				//4列目（１マス目）↑（上）1マス移動
				if (map[7][1] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[10 + i][1 + j];
							Hmem[i][j] = Hmap[10 + i][1 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][1 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][1 + j] = mem[i][j];
							Hmap[7 + i][1 + j] = Hmem[i][j];
							pv_y += 120;
						}
					}
				}

				//4列目（１マス目）→（右）1マス移動
				if (map[10][4] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[10 + i][1 + j];
							Hmem[i][j] = Hmap[10 + i][1 + j];


						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][1 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][4 + j] = mem[i][j];
							Hmap[10 + i][4 + j] = Hmem[i][j];
							pv_x = 120;
						}
					}
				}
			}
		}

		//4列目（2マス目）
		if (mou_x > 156.0f && mou_x < 273.0f && mou_y>394.0f && mou_y < 520.0f)
		{
			if (mou_l == true)
			{
				//4列目（2マス目）←（左）1マス移動
				if (map[10][1] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[10 + i][4 + j];
							Hmem[i][j] = Hmap[10 + i][4 + j];

						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][4 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][1 + j] = mem[i][j];
							Hmap[10 + i][1 + j] = Hmem[i][j];
							pv_x = -120;
						}
					}

				}

				//4列目（2マス目）↑（上）1マス移動
				if (map[7][4] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[10 + i][4 + j];
							Hmem[i][j] = Hmap[10 + i][4 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][4 + j] = 0;
							
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][4 + j] = mem[i][j];
							Hmap[7 + i][4 + j] = Hmem[i][j];
							pv_y = 120;
						}
					}
				}

				//4列目（2マス目）→（右）1マス移動
				if (map[10][7] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[10 + i][4 + j];
							Hmem[i][j] = Hmap[10 + i][4 + j];

						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][4 + j] = 0;
							
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][7 + j] = mem[i][j];
							Hmap[10 + i][7 + j] = Hmem[i][j];
							pv_y = 120;
						}
					}
				}
			}
		}

		//4列目（3マス目）
		if (mou_x > 274.0f && mou_x < 393.0f && mou_y> 394.0f && mou_y < 520.0f)
		{
			if (mou_l == true)
			{
				//4列目（3マス目）←（左）1マス移動
				if (map[10][4] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[10 + i][7 + j];
							Hmem[i][j] = Hmap[10 + i][7 + j];

						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][7 + j] = 0;
						
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][4 + j] = mem[i][j];
							Hmap[10 + i][4 + j] = Hmem[i][j];
							pv_x = -120;
						}
					}

				}

				//4列目（3マス目）↑（上）1マス移動
				if (map[7][7] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[10 + i][7 + j];
							Hmem[i][j] = Hmap[10 + i][7 + j];

						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][7 + j] = 0;
							
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][7 + j] = mem[i][j];
							Hmap[7 + i][7 + j] = Hmem[i][j];
							pv_y = 120;
						}
					}
				}

				//4列目（3マス目）→（右）1マス移動
				if (map[10][10] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[10 + i][7 + j];
							Hmem[i][j] = Hmap[10 + i][7 + j];

						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][7 + j] = 0;
							Hmap[10 + i][7 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][10 + j] = mem[i][j];
							Hmap[10 + i][10 + j] = Hmem[i][j];
							pv_y = 120;
						}
					}
				}
			}
		}

		//4列目（4マス目）
		if (mou_x > 394.0f && mou_x < 520.0f && mou_y>394.0f && mou_y < 520.0f)
		{
			if (mou_l == true)
			{
				//4列目（4マス目）←（左）1マス移動
				if (map[10][7] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[10 + i][10 + j];
							Hmem[i][j] = Hmap[10 + i][10 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][10 + j] = 0;
							
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][7 + j] = mem[i][j];
							Hmap[10 + i][7 + j] = Hmem[i][j];
							pv_x = -120;
						}
					}

				}

				//4列目（4マス目）↑（上）1マス移動
				if (map[7][10] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[10 + i][10 + j];
							Hmem[i][j] = Hmap[10 + i][10 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][10 + j] = 0;
							
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][10 + j] = mem[i][j];
							Hmap[7 + i][10 + j] = Hmem[i][j];
							pv_y = 120;
						}
					}
				}
			}
		}

	}

	if (player->battle == true)
	{
		for (int i = 0; i < PIECE; i++)
		{
			for (int j = 0; j < PIECE; j++)
			{
				if (map[i][j] >= 2&&map[i][j]<7)
				{
					map[i][j] = 0;
				}
			}
		}


		if (pxc > 444.0f && pxc < 765.0f && pyc>301 && pyc < 312)
		{
			player->battle = false;

			if (player->HP == 10 && reset == 0)
			{
				
			}
		}

		s_r = false;
	}

	//リセットボタンのプログラム
	if (s_r == false)
	{
		if (reset < 5)
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

					for (int i = 0; i < PIECE; i++)
					{
						for (int j = 0; j < PIECE; j++)
						{
							Hmap[i][j] = Hmemmap[i][j];
						}
					}

					time->m_time = 3600;
					time->m_flag_time = false;

					s_r = true;

					player->s_p = false;

					player->p_x = player->memp_x;
					player->p_y = player->memp_y;

					player->atk = 0;

					reset++;


				}
			}
		}
	}

}

//ドロー
void CObjHardStage1::Draw()
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

	CObjEnemy* Enemy = (CObjEnemy*)Objs::GetObj(OBJ_ENEMY);
	CObjPlayer* player = (CObjPlayer*)Objs::GetObj(OBJ_PLAYER);

	if (s_r == true)
	{
		Font::StrDraw(L"Road", 600, 30, 40, r);
	}

	if (player->battle == false)
	{

		if (s_r == true||reset>=5)
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

	for (int i = 0; i < PIECE; i++)
	{
		for (int j = 0; j < PIECE; j++)
		{

			if (map[i][j] == 7)
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

				Draw::Draw(0, &src, &dst, p, 0.0f);

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


