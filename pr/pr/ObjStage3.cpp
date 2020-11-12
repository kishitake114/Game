//使用するヘッダーファイル
#include "ObjStage3.h"
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
void CObjStage3::Init()
{
	int mapdata[20][20] =
	{
		{0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0},
		{0,1,2,1,1,1,1,1,2,1,1,1,1,1,2,1,1,1,1,0},
		{2,1,2,2,2,2,2,1,2,1,1,2,2,2,2,1,2,2,1,2},
		{0,1,1,1,1,1,1,1,2,1,1,2,1,1,1,1,1,2,1,0},
		{0,1,1,1,1,1,1,1,2,1,1,2,1,1,1,1,1,2,1,0},
		{2,2,2,2,2,2,1,1,2,2,1,2,1,1,2,2,2,2,2,2},
		{0,1,2,1,1,2,1,1,1,1,1,2,1,1,2,1,1,1,1,0},
		{0,1,1,1,1,2,1,1,1,1,1,1,1,1,2,1,1,1,1,0},
		{2,2,2,2,2,2,2,2,2,1,2,2,2,2,2,1,2,2,2,2},
		{0,1,1,1,1,2,1,1,2,1,1,2,1,1,2,1,1,1,1,0},
		{0,1,2,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
		{2,1,2,2,1,2,1,2,2,2,2,2,1,2,2,2,2,2,2,2},
		{0,1,1,1,1,2,1,1,1,1,1,2,1,1,2,1,1,1,1,0},
		{0,1,2,1,1,2,1,1,2,1,1,2,1,1,2,1,1,1,1,0},
		{2,2,2,2,2,2,1,1,2,2,2,2,1,1,2,1,2,2,2,2},
		{0,1,2,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,0},
		{0,1,2,1,1,1,1,1,2,1,1,2,1,1,1,1,0,0,0,0},
		{2,1,2,1,2,2,2,2,2,1,2,2,2,1,2,2,0,0,0,2},
		{0,1,2,1,1,1,1,1,1,1,1,1,1,1,2,1,0,0,0,0},
		{0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0},

	};

	memcpy(map, mapdata, sizeof(int) * (20 * 20));

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

		//if (map[][] == 0)
	//{
	//	for (int i = 0; i < 3; i++)
	//	{
	//		for (int j = 0; j < 3; j++)
	//		{
	//			mem[i][j] = map[ + i][ + j];
	//		}

	//		for (int j = 0; j < 3; j++)
	//		{
	//			map[ + i][ + j] = 0;
	//		}

	//		for (int j = 0; j < 3; j++)
	//		{
	//			map[ + i][ + j] = mem[i][j];
	//		}
	//	}
	//}

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



				}
			}
			//1段目2行目
			if (mou_x > 98.0f && mou_x < 173.0f && mou_y>25.0f && mou_y < 97.0f)
			{
				testx = 2;
				testy = 1;


				if (mou_l == true)
				{



				}
			}
			//1段目3行目
			if (mou_x > 173.0f && mou_x < 246.0f && mou_y>25.0f && mou_y < 97.0f)
			{
				testx = 3;
				testy = 1;


				if (mou_l == true)
				{



				}
			}
			//1段目4行目
			if (mou_x > 246.0f && mou_x < 321.0f && mou_y>25.0f && mou_y < 97.0f)
			{
				testx = 4;
				testy = 1;


				if (mou_l == true)
				{



				}
			}
			//1段目5行目
			if (mou_x > 321.0f && mou_x < 394.0f && mou_y>25.0f && mou_y < 97.0f)
			{
				testx = 5;
				testy = 1;


				if (mou_l == true)
				{



				}
			}
			//1段目6行目
			if (mou_x > 394.0f && mou_x < 467.0f && mou_y>25.0f && mou_y < 97.0f)
			{
				testx = 6;
				testy = 1;


				if (mou_l == true)
				{



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



				}
			}
			//2段目2行目
			if (mou_x > 98.0f && mou_x < 173.0f && mou_y>97.0f && mou_y < 173.0f)
			{
				testx = 2;
				testy = 2;


				if (mou_l == true)
				{



				}
			}
			//2段目3行目
			if (mou_x > 173.0f && mou_x < 246.0f && mou_y>97.0f && mou_y < 173.0f)
			{
				testx = 3;
				testy = 2;


				if (mou_l == true)
				{



				}
			}
			//2段目4行目
			if (mou_x > 246.0f && mou_x < 321.0f && mou_y>97.0f && mou_y < 173.0f)
			{
				testx = 4;
				testy = 2;


				if (mou_l == true)
				{



				}
			}
			//2段目5行目
			if (mou_x > 321.0f && mou_x < 394.0f && mou_y>97.0f && mou_y < 173.0f)
			{
				testx = 5;
				testy = 2;


				if (mou_l == true)
				{



				}
			}
			//2段目6行目
			if (mou_x > 394.0f && mou_x < 467.0f && mou_y>97.0f && mou_y < 173.0f)
			{
				testx = 6;
				testy = 2;


				if (mou_l == true)
				{



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



				}
			}
			//3段目2行目
			if (mou_x > 98.0f && mou_x < 173.0f && mou_y>173.0f && mou_y < 246.0f)
			{
				testx = 2;
				testy = 3;


				if (mou_l == true)
				{



				}
			}
			//3段目3行目
			if (mou_x > 173.0f && mou_x < 246.0f && mou_y>173.0f && mou_y < 246.0f)
			{
				testx = 3;
				testy = 3;


				if (mou_l == true)
				{



				}
			}
			//3段目4行目
			if (mou_x > 246.0f && mou_x < 321.0f && mou_y>173.0f && mou_y < 246.0f)
			{
				testx = 4;
				testy = 3;


				if (mou_l == true)
				{



				}
			}
			//3段目5行目
			if (mou_x > 321.0f && mou_x < 394.0f && mou_y>173.0f && mou_y < 246.0f)
			{
				testx = 5;
				testy = 3;

				if (mou_l == true)
				{



				}
			}
			//3段目6行目
			if (mou_x > 394.0f && mou_x < 467.0f && mou_y>173.0f && mou_y < 246.0f)
			{
				testx = 6;
				testy = 3;

				if (mou_l == true)
				{



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

				}
			}
			//4段目6行目
			if (mou_x > 394.0f && mou_x < 467.0f && mou_y>246.0f && mou_y < 321.0f)
			{
				testx = 6;
				testy = 4;

				if (mou_l == true)
				{
					//4段目6行目->5段目5行目
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

	//if (map[][] == 0)
	//{
	//	for (int i = 0; i < 3; i++)
	//	{
	//		for (int j = 0; j < 3; j++)
	//		{
	//			mem[i][j] = map[ + i][ + j];
	//		}

	//		for (int j = 0; j < 3; j++)
	//		{
	//			map[ + i][ + j] = 0;
	//		}

	//		for (int j = 0; j < 3; j++)
	//		{
	//			map[ + i][ + j] = mem[i][j];
	//		}
	//	}
	//}

		else
		{
			test = false;
		}


	}
}

	
//ドロー
void CObjStage3::Draw()
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

	swprintf_s(str, L"横=%d", testx);
	Font::StrDraw(str, 600, 200, 25, c);
	swprintf_s(str, L"縦=%d", testy);
	Font::StrDraw(str, 600, 226, 25, c);

	////右クリック
	//if (s_r == true)
	//{
	//	Font::StrDraw(L"Road", 600, 40, 20, c);
	//	Font::StrDraw(L"操作\n マウス", 550, 300, 20, c);
	//}

	//左クリック
	if (mou_l == true)
		Font::StrDraw(L"左=押してる", 600, 60, 20, c);
	else
		Font::StrDraw(L"左=押してない", 600, 60, 20, c);

	//左クリック
	if (test == true)
		Font::StrDraw(L"OK!!", 600, 300, 20, c);
	else
		Font::StrDraw(L"NOK", 600, 300, 20, c);

	//表示：通行可


	src.m_top = 90.0f;
	src.m_left = 45.0f;
	src.m_right = 85.0f;
	src.m_bottom = 125.0f;

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{

			if (map[i][j] == 2)
			{
				dst.m_top = i * 25.0f;
				dst.m_left = j * 25.0f;
				dst.m_right = dst.m_left + 25.0f;
				dst.m_bottom = dst.m_top + 25.0f;

				Draw::Draw(0, &src, &dst, c, 0.0f);
			}

		}
	}

	//表示：通行不可

	src.m_top = 90.0f;
	src.m_left = 0.0f;
	src.m_right = 45.0f;
	src.m_bottom = 125.0f;

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (map[i][j] == 1)
			{
				dst.m_top = i * 25.0f;
				dst.m_left = j * 25.0f;
				dst.m_right = dst.m_left + 25.0f;
				dst.m_bottom = dst.m_top + 25.0f;

				Draw::Draw(0, &src, &dst, c, 0.0f);

			}
		}
	}
}