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
	int mapdata[32][32] =
	{
		{0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0},
	    {0,1,1,1,1,2,1,1,2,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
		{2,2,2,2,2,2,2,1,2,2,2,2,1,2,2,2,2,2,2,2,2,2,2,2,2,1,2,2,2,2,1,2},
		{0,1,1,1,1,2,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,2,1,0},
	    {0,1,1,1,1,2,1,1,1,1,1,2,1,1,1,1,1,2,1,1,1,1,1,2,1,1,1,1,1,2,1,0},
	    {2,2,2,2,1,2,2,2,2,2,1,2,1,1,2,2,2,2,1,2,2,1,1,2,2,2,2,2,1,2,2,2},
	    {0,1,1,1,1,1,1,1,1,1,1,2,1,1,2,1,1,2,1,1,2,1,1,2,1,1,2,1,1,2,1,0},
	    {0,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,2,1,1,2,1,1,1,1,1,2,1,1,2,1,0},
	    {2,2,2,1,1,2,2,1,2,1,2,2,2,2,2,2,1,2,1,1,2,2,1,2,2,2,2,2,1,2,1,2},
	    {0,1,2,1,1,2,1,1,2,1,1,1,1,1,2,1,1,2,1,1,1,1,1,2,1,1,1,1,1,2,1,0},
	    {0,1,2,1,1,2,1,1,2,1,1,2,1,1,2,1,1,2,1,1,2,1,1,2,1,1,2,1,1,1,1,0},
	    {2,2,2,2,1,2,1,2,2,1,2,2,2,1,2,2,2,2,1,1,2,1,2,2,2,1,2,1,2,2,2,2},
	    {0,1,1,1,1,2,1,1,2,1,1,1,1,1,1,1,1,1,1,1,2,1,1,2,1,1,2,1,1,1,1,0},
	    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,2,1,1,1,1,1,2,1,1,2,1,1,1,1,0},
	    {2,2,2,2,2,2,1,1,2,2,2,2,2,1,2,1,2,2,1,2,2,1,2,2,1,1,2,2,1,2,2,2},
	    {0,1,2,1,1,2,1,1,2,1,1,1,1,1,2,1,1,2,1,1,2,1,1,1,1,1,1,1,1,2,1,0},
	    {0,1,1,1,1,2,1,1,2,1,1,1,1,1,2,1,1,2,1,1,2,1,1,2,1,1,1,1,1,2,1,0},
	    {2,2,2,2,1,2,2,1,2,2,1,2,2,2,2,2,1,2,2,2,2,1,2,2,1,2,2,2,1,2,1,2},
	    {0,1,1,1,1,2,1,1,1,1,1,2,1,1,2,1,1,2,1,1,1,1,1,1,1,1,1,1,1,2,1,0},
	    {0,1,2,1,1,1,1,1,2,1,1,2,1,1,2,1,1,2,1,1,2,1,1,1,1,1,2,1,1,1,1,0},
	    {2,1,2,2,2,2,2,1,2,1,2,2,2,2,2,1,1,2,1,1,2,2,2,2,2,1,2,2,2,2,1,2},
	    {0,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,2,1,1,2,1,0},
	    {0,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,2,1,1,2,1,0},
	    {2,1,2,2,2,2,2,2,2,2,2,2,1,2,2,2,2,2,1,2,2,2,2,2,1,2,2,1,1,2,1,2},
	    {0,1,2,1,1,2,1,1,2,1,1,2,1,1,2,1,1,1,1,1,1,1,1,2,1,1,1,1,1,2,1,0},
	    {0,1,2,1,1,1,1,1,2,1,1,1,1,1,2,1,1,2,1,1,2,1,1,2,1,1,2,1,1,2,1,0},
	    {2,2,2,1,2,2,2,1,2,2,1,2,2,2,2,1,1,2,1,2,2,1,2,2,2,2,2,1,1,2,1,2},
	    {0,1,2,1,1,1,1,1,1,1,1,2,1,1,2,1,1,2,1,1,1,1,1,2,1,1,2,1,1,2,1,0},
	    {0,1,1,1,1,1,1,1,1,1,1,2,1,1,2,1,1,2,1,1,2,1,1,2,1,1,2,1,0,0,0,0},
	    {2,2,2,2,2,2,1,2,2,2,1,2,2,2,2,2,2,2,1,1,2,2,1,2,1,2,2,1,0,0,0,2},
	    {0,1,1,1,1,2,1,1,2,1,1,2,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,0,0,0,0},
	    {0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0},
	};

	memcpy(map, mapdata, sizeof(int) * (32 * 32));
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
		if (mou_x > 20.0f && mou_x < 80.0f && mou_y>20.0f && mou_y < 80.0f)
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
							pv_x = 60.0f;
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
							pv_y = -60.f;
						}
					}
				}
			}
		}




		//1列目２マス目 
		if (mou_x > 80.0f && mou_x < 140.0f && mou_y>.0f && mou_y < 80.0f)
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
						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][4 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][4 + j] = mem[i][j];
							pv_y = -60.0f;
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
							pv_x = -60.0f;
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
						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][4 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][7 + j] = mem[i][j];
							pv_x = -60.0f;
						}
					}

				}
			}
		}


		//1列目（3マス目）
		if (mou_x > 140.0f && mou_x < 200.0f && mou_y>20.0f && mou_y < 80.0f)
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
						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][7 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][7 + j] = mem[i][j];
							pv_y = -60.0f;
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
						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][7 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][4 + j] = mem[i][j];
							pv_x = 60.0f;
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
						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][7 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][10 + j] = mem[i][j];
							pv_x = -60.0f;
						}
					}

				}
			}
		}

		//1列目４マス目
		if (mou_x > 200.0f && mou_x < 260.0f && mou_y>20.0f && mou_y < 80.0f)
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
						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][10 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][10 + j] = mem[i][j];
							pv_x = 60.0f;
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
						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][10 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][7 + j] = mem[i][j];
							pv_x = 60.0f;
						}
					}
				}
				//１列目(4マス目）→（右）1マス移動
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
							pv_x = -60.0f;
						}
					}
				}
			}
		}

		//2列目
		if (mou_x > 20.0f && mou_x < 80.0f && mou_y>80.0f && mou_y < 140.0f)
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
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][1 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][1 + j] = mem[i][j];
							pv_y += 60;
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
							pv_x = 60;
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
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][1 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][1 + j] = mem[i][j];
							pv_x = 60;
						}
					}
				}
			}
		}

		//2列目（2マス目）
		if (mou_x > 80.0f && mou_x < 140.0f && mou_y>140.0f && mou_y < 200.0f)
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
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][4 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][1 + j] = mem[i][j];
							pv_x = -60;
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
							pv_y = 60;
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
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][4 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][4 + j] = mem[i][j];
							pv_y = 60;
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
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][4 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][7 + j] = mem[i][j];
							pv_y = 60;
						}
					}
				}
			}
		}


		//2列目（3マス目）
		if (mou_x > 140.0f && mou_x < 200.0f && mou_y>80.0f && mou_y < 140.0f)
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
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][7 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][4 + j] = mem[i][j];
							pv_x = -60;
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
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][7 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][7 + j] = mem[i][j];
							pv_y = 60;
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
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][7 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][10 + j] = mem[i][j];
							pv_y = 60;
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
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][7 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][7 + j] = mem[i][j];
							pv_y = 60;
						}
					}
				}
			}
		}

		//2列目（4マス目）
		if (mou_x > 200.0f && mou_x < 260.0f && mou_y>80.0f && mou_y < 140.0f)
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
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][10 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][7 + j] = mem[i][j];
							pv_x = -60;
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
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][10 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][10 + j] = mem[i][j];
							pv_y = 60;
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
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][10 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][10 + j] = mem[i][j];
							pv_y = 60;
						}
					}
				}
				//2列目（4マス目）→（右）1マス移動
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
							pv_y = 60;
						}
					}
				}
			}
		}

		//3列目
		if (mou_x > 20.0f && mou_x < 80.0f && mou_y>140.0f && mou_y < 200.0f)
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
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][1 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][1 + j] = mem[i][j];
							pv_y += 60;
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
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][1 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][4 + j] = mem[i][j];
							pv_x = 60;
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
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][1 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][1 + j] = mem[i][j];
							pv_x = 60;
						}
					}
				}
			}
		}

		//3列目（2マス目）
		if (mou_x > 80.0f && mou_x < 140.0f && mou_y>274.0f && mou_y < 394.0f)
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
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][4 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][1 + j] = mem[i][j];
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
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][4 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][4 + j] = mem[i][j];
							pv_y = 120;
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
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][4 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][7 + j] = mem[i][j];
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
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][4 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][4 + j] = mem[i][j];
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
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][7 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][4 + j] = mem[i][j];
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
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][7 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][7 + j] = mem[i][j];
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
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][7 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][10 + j] = mem[i][j];
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
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][7 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][7 + j] = mem[i][j];
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
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][10 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][7 + j] = mem[i][j];
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
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][10 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][10 + j] = mem[i][j];
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
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][10 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][10 + j] = mem[i][j];
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
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][1 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][1 + j] = mem[i][j];
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
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][1 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][4 + j] = mem[i][j];
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
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][4 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][1 + j] = mem[i][j];
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
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][4 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][4 + j] = mem[i][j];
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
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][4 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][7 + j] = mem[i][j];
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
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][7 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][4 + j] = mem[i][j];
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
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][7 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][7 + j] = mem[i][j];
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
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][7 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][10 + j] = mem[i][j];
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
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][10 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][7 + j] = mem[i][j];
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
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][10 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][10 + j] = mem[i][j];
							pv_y = 120;
						}
					}
				}
			}
		}

		//5列目の1行目
		if (mou_l=true)
		{

			//上に１マス
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
			//右に１マス
			if (map[13][4]==0)
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
			//下に１マス
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

		}
	    //5列目の2行目
		if (mou_l = true)
		{
			//上に1マス
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
			//右に1マス
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
			//左に1マス
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
			//下に1マス
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
		}
		//5行目の3列目
		if (mou_l = true)
		{
			//上に1マス
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
			//右に1マス
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
			//左に1マス
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
			//下に1マス
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
		//5行目の4列目
		if (mou_l = true)
		{
			//上に1マス
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
			//右に1マス
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
			//左に1マス
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
			//下に1マス
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
		//5行目の5列目
		if (mou_l = true)
		{
			//上に1マス
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
			//右に1マス
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
			//左に1マス
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
			//下に1マス
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
		//5行目の6列目

		CHitBox* hit = Hits::GetHitBox(this);
		hit->SetPos(pv_x, pv_y);
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

	//表示：通行可

	src.m_top = 90.0f;
	src.m_left = 45.0f;
	src.m_right = 85.0f;
	src.m_bottom = 125.0f;

	for (int i = 0; i < 32; i++)
	{
		for (int j = 0; j < 32; j++)
		{

			if (map[i][j] == 2)
			{
				dst.m_top = i * 18.0f;
				dst.m_left = j * 18.0f;
				dst.m_right = dst.m_left + 18.0f;
				dst.m_bottom = dst.m_top + 18.0f;

				Draw::Draw(0, &src, &dst, c, 0.0f);
			}

		}
	}

	//表示：通行不可

	src.m_top = 90.0f;
	src.m_left = 0.0f;
	src.m_right = 45.0f;
	src.m_bottom = 125.0f;

	for (int i = 0; i < 32; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			if (map[i][j] == 1)
			{
				dst.m_top = i * 18.0f;
				dst.m_left = j * 18.0f;
				dst.m_right = dst.m_left + 18.0f;
				dst.m_bottom = dst.m_top + 18.0f;

				Draw::Draw(0, &src, &dst, c, 0.0f);

			}
		}
	}
}