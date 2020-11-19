//�g�p����w�b�_�[�t�@�C��
#include "ObjStage2.h"
#include "ObjPlayer.h"
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "GameHead.h" 
#include "GameL/WinInputs.h"
#include "GameL/HitBoxManager.h"
#include "GameL/SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjStage2::Init()
{
	CObjPlayer* obj = (CObjPlayer*)Objs::GetObj(OBJ_PLAYER);
	obj->num = 2;

	mou_x = 0.0f;
	mou_y = 0.0f;
	mou_r = false;
	mou_l = false;

	pxc = 0.0f;
	pyc = 0.0f;

	pv_x = 0.0f;
	pv_y = 0.0f;

	f_p = false;

	s_r = true;
	sei = false;




	int mapdata[17][17] =
	{                     //11.12.13.14.15.16
		{0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0},//0
		{0,1,2,1,1,1,1,1,2,1,1,1,1,1,2,1,0},//1
		{2,1,2,2,2,2,2,1,2,1,1,2,2,2,2,1,2},//2
		{0,1,1,1,1,1,1,1,2,1,1,2,1,1,1,1,0},//3
		{0,1,1,1,1,1,1,1,2,1,1,2,1,1,1,1,0},//4
		{2,2,2,2,2,2,1,1,2,2,1,2,1,1,2,2,2},//5
		{0,1,2,1,1,2,1,1,1,1,1,2,1,1,2,1,0},//6
		{0,1,1,1,1,2,1,1,1,1,1,1,1,1,2,1,0},//7
		{2,2,2,2,2,2,2,2,2,1,2,2,2,2,2,1,2},//8
		{0,1,1,1,1,2,1,1,2,1,1,2,1,1,2,1,0},//9
		{0,1,2,1,1,2,1,1,1,1,1,1,1,1,1,1,0},//10
		{2,1,2,2,1,2,1,2,2,2,2,2,1,2,2,2,2},//11
		{0,1,1,1,1,2,1,1,1,1,1,2,1,1,2,1,0},//12
		{0,1,2,1,1,2,1,1,2,1,1,2,1,0,0,0,0},//13
		{2,2,2,2,2,2,1,1,2,2,2,2,1,0,0,0,2},//14
		{0,1,2,1,1,1,1,1,1,1,1,1,1,0,0,0,0},//15
		{0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0},//16
	   //0,1,2,3,4,5,6,7,8,9,10
	};

	memcpy(map, mapdata, sizeof(int) * (17 * 17));

	int mem[3][3] =
	{
		{0,0,0},
		{0,0,0},
		{0,0,0},
	};

}
//�A�N�V����
void CObjStage2::Action()
{
	mou_x = (float)Input::GetPosX();
	mou_y = (float)Input::GetPosY();
	mou_r = Input::GetMouButtonR();
	mou_l = Input::GetMouButtonL();

	//���N���b�N�ō��W���L�^
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


	//���[�h���̃v���O����
	if (s_r == true)
	{
		//�E�N���b�N�ő��쒆�~
		if (mou_r == true)
		{
			s_r = false;
		}
		
		//1�i�ڂ�1��(������)
		if (mou_x > 28.0f && mou_x < 118.0f && mou_y>28.0f && mou_y < 118.0f)
		{
			if (mou_l == true)
			{
				//�E�ֈړ�
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
				//���ֈړ�
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

		//1�i�ڂ�2��(������)
		if (mou_x > 117.0f && mou_x < 207.0f && mou_y>28.0f && mou_y < 118.0f)
		{
			if (mou_l == true)
			{
				//�E�ֈړ�
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
				//���ֈړ�
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

				//���ֈړ�
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

		//1�i�ڂ�3��(������)
		if (mou_x > 205.0f && mou_x < 297.0f && mou_y>28.0f && mou_y < 118.0f)
		{
			if (mou_l == true)
			{
				//�E�ֈړ�
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
				//���ֈړ�
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

				//���ֈړ�
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

		//1�i�ڂ�4��(������)
		if (mou_x > 294.0f && mou_x < 386.0f && mou_y>28.0f && mou_y < 118.0f)
		{
			if (mou_l == true)
			{
				//�E�ֈړ�
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
				//���ֈړ�
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

				//���ֈړ�
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

		//1�i�ڂ�5��(������)
		if (mou_x > 383.0f && mou_x < 474.0f && mou_y>27.0f && mou_y < 118.0f)
		{
			if (mou_l == true)
			{
				//���ֈړ�
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

				//���ֈړ�
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

		//2�i�ڂ�1��(������)
		if (mou_x > 28.0f && mou_x < 120.0f && mou_y>115.0f && mou_y < 210.0f)
		{
			if (mou_l == true)
			{
				//�E�ֈړ�
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
				//���ֈړ�
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

				//��ֈړ�
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

		//2�i�ڂ�2��(������)
		if (mou_x > 117.0f && mou_x < 206.0f && mou_y>117.0f && mou_y < 206.0f)
		{
			if (mou_l == true)
			{
				//�E�ֈړ�
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
				//���ֈړ�
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

				//���ֈړ�
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

				//��ֈړ�
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
		//2�i�ڂ�3��(������)
		if (mou_x > 205.0f && mou_x < 297.0f && mou_y>115.0f && mou_y < 205.0f)
		{
			if (mou_l == true)
			{
				//�E�ֈړ�
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
				//���ֈړ�
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

				//���ֈړ�
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

				//��ֈړ�
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

		//2�i�ڂ�4��(������)
		if (mou_x > 294.0f && mou_x < 385.0f && mou_y>115.0f && mou_y < 207.0f)
		{
			if (mou_l == true)
			{
				//�E�ֈړ�
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
				//���ֈړ�
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

				//���ֈړ�
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

				//��ֈړ�
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

		//2�i�ڂ�5��(������)
		if (mou_x > 384.0f && mou_x < 472.0f && mou_y>116.0f && mou_y < 204.0f)
		{
			if (mou_l == true)
			{
				//���ֈړ�
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

				//���ֈړ�
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

				//��ֈړ�
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

		//3�i�ڂ�1��(������)
		if (mou_x > 28.0f && mou_x < 119.0f && mou_y>205.0f && mou_y < 296.0f)
		{
			if (mou_l == true)
			{
				//�E�ֈړ�
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
				//���ֈړ�
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

				//��ֈړ�
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

		//3�i�ڂ�2��(������)
		if (mou_x > 116.0f && mou_x < 207.0f && mou_y>206.0f && mou_y < 296.0f)
		{
			if (mou_l == true)
			{
				//�E�ֈړ�
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
				//���ֈړ�
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

				//���ֈړ�
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

				//��ֈړ�
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

		//3�i�ڂ�3��(������)
		if (mou_x > 206.0f && mou_x < 296.0f && mou_y>206.0f && mou_y < 296.0f)
		{
			if (mou_l == true)
			{
				//�E�ֈړ�
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
				//���ֈړ�
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

				//���ֈړ�
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

				//��ֈړ�
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

		//3�i�ڂ�4��(������)
		if (mou_x > 295.0f && mou_x < 387.0f && mou_y>206.0f && mou_y < 296.0f)
		{
			if (mou_l == true)
			{
				//�E�ֈړ�
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
				//���ֈړ�
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

				//���ֈړ�
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

				//��ֈړ�
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

		//3�i�ڂ�5��(������)
		if (mou_x > 382.0f && mou_x < 473.0f && mou_y>205.0f && mou_y < 295.0f)
		{
			if (mou_l == true)
			{
				
				//���ֈړ�
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

				//���ֈړ�
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

				//��ֈړ�
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

		//4�i�ڂ�1��(������)
		if (mou_x > 29.0f && mou_x < 120.0f && mou_y>293.0f && mou_y < 384.0f)
		{

			if (mou_l == true)
			{
				//�E�ֈړ�
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
				//���ֈړ�
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

				//��ֈړ�
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

		//4�i�ڂ�2��(������)
		if (mou_x > 117.0f && mou_x < 209.0f && mou_y>292.0f && mou_y < 383.0f)
		{
			if (mou_l == true)
			{
				//�E�ֈړ�
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
				//���ֈړ�
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

				//���ֈړ�
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

				//��ֈړ�
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

		//4�i�ڂ�3��(������)
		if (mou_x > 206.0f && mou_x < 297.0f && mou_y>293.0f && mou_y < 385.0f)
		{
			if (mou_l == true)
			{
				//�E�ֈړ�
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
				//���ֈړ�
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

				//���ֈړ�
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

				//��ֈړ�
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


		//4�i�ڂ�4��(������)
		if (mou_x > 293.0f && mou_x < 386.0f && mou_y>293.0f && mou_y < 386.0f)
		{
			if (mou_l == true)
			{
				//�E�ֈړ�
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
				//���ֈړ�
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

				//���ֈړ�
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

				//��ֈړ�
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

		//4�i�ڂ�5��(������)
		if (mou_x > 384.0f && mou_x < 473.0f && mou_y>291.0f && mou_y < 382.0f)
		{
			if (mou_l == true)
			{
				//���ֈړ�
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
				//���ֈړ�
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

				//��ֈړ�
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

		

		//5�i�ڂ�1��(������)
		if (mou_x > 28.0f && mou_x < 120.0f && mou_y>382.0f && mou_y < 471.0f)
		{

			if (mou_l == true)
			{
				//�E�ֈړ�
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

				//��ֈړ�
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
		//5�i�ڂ�2��(������)
		if (mou_x > 119.0f && mou_x < 207.0f && mou_y>382.0f && mou_y < 473.0f)
		{

			if (mou_l == true)
			{
				//�E�ֈړ�
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

				//���ֈړ�
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

				//��ֈړ�
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
		//5�i�ڂ�3��(������)
		if (mou_x > 206.0f && mou_x < 296.0f && mou_y>381.0f && mou_y < 472.0f)
		{

			if (mou_l == true)
			{
				//�E�ֈړ�
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

				//���ֈړ�
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

				//��ֈړ�
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
		//5�i�ڂ�4��(������)
		if (mou_x > 295.0f && mou_x < 384.0f && mou_y>381.0f && mou_y < 472.0f)
		{

			if (mou_l == true)
			{
				//�E�ֈړ�
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

				//���ֈړ�
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

				//��ֈړ�
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

		//5�i�ڂ�5��(������)
		if (mou_x > 383.0f && mou_x < 473.0f && mou_y>383.0f && mou_y < 473.0f)
		{
			if (mou_l == true)
			{
				//���ֈړ�
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
				//��ֈړ�
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
}
//�h���[
void CObjStage2::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	//�\���F�}�E�X�J�[�\���ƃ{�^��
	wchar_t str[256];

	swprintf_s(str, L"x=%f,y=%f", pxc, pyc);
	Font::StrDraw(str, 600, 20, 15, c);

	swprintf_s(str, L"x=%f,y=%f", mou_x, mou_y);
	Font::StrDraw(str, 600, 10, 15, c);



	//�E�N���b�N
	if (s_r == true)
	{
		Font::StrDraw(L"Road", 600, 40, 20, c);
		Font::StrDraw(L"����\n �}�E�X", 550, 300, 20, c);
	}

	//���N���b�N
	if (mou_l == true)
		Font::StrDraw(L"��=�����Ă�", 600, 60, 20, c);
	else
		Font::StrDraw(L"��=�����ĂȂ�", 600, 60, 20, c);

	//�\���F�ʍs��


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

	//�\���F�ʍs�s��

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


////6�i�ڂ�1��(������)
//if (mou_x > 22.0f && mou_x < 86.0f && mou_y>346.0f && mou_y < 410.0f)
//{
//	if (mou_l == true)
//	{
//		//�E�ֈړ�
//		if (map[16][4] == 0)
//		{
//			for (int i = 0; i < 3; i++)
//			{
//				for (int j = 0; j < 3; j++)
//				{
//					mem[i][j] = map[16 + i][1 + j];
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[16 + i][1 + j] = 0;
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[16 + i][4 + j] = mem[i][j];
//				}
//
//			}
//		}
//		//���ֈړ�
//		if (map[19][1] == 0)
//		{
//			for (int i = 0; i < 3; i++)
//			{
//				for (int j = 0; j < 3; j++)
//				{
//					mem[i][j] = map[16 + i][1 + j];
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[16 + i][1 + j] = 0;
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[19 + i][1 + j] = mem[i][j];
//				}
//
//			}
//		}
//
//		//��ֈړ�
//		if (map[13][1] == 0)
//		{
//			for (int i = 0; i < 3; i++)
//			{
//				for (int j = 0; j < 3; j++)
//				{
//					mem[i][j] = map[16 + i][1 + j];
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[16 + i][1 + j] = 0;
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[13 + i][1 + j] = mem[i][j];
//				}
//
//			}
//		}
//	}
//}
//
////6�i�ڂ�2��(������)
//if (mou_x > 86.0f && mou_x < 150.0f && mou_y>346.0f && mou_y < 410.0f)
//{
//	if (mou_l == true)
//	{
//		//�E�ֈړ�
//		if (map[16][7] == 0)
//		{
//			for (int i = 0; i < 3; i++)
//			{
//				for (int j = 0; j < 3; j++)
//				{
//					mem[i][j] = map[16 + i][4 + j];
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[16 + i][4 + j] = 0;
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[16 + i][7 + j] = mem[i][j];
//				}
//
//			}
//		}
//		//���ֈړ�
//		if (map[19][4] == 0)
//		{
//			for (int i = 0; i < 3; i++)
//			{
//				for (int j = 0; j < 3; j++)
//				{
//					mem[i][j] = map[16 + i][4 + j];
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[16 + i][4 + j] = 0;
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[19 + i][4 + j] = mem[i][j];
//				}
//
//			}
//		}
//
//		//���ֈړ�
//		if (map[16][1] == 0)
//		{
//			for (int i = 0; i < 3; i++)
//			{
//				for (int j = 0; j < 3; j++)
//				{
//					mem[i][j] = map[16 + i][4 + j];
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[16 + i][4 + j] = 0;
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[16 + i][1 + j] = mem[i][j];
//				}
//
//			}
//		}
//
//		//��ֈړ�
//		if (map[13][4] == 0)
//		{
//			for (int i = 0; i < 3; i++)
//			{
//				for (int j = 0; j < 3; j++)
//				{
//					mem[i][j] = map[16 + i][4 + j];
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[16 + i][4 + j] = 0;
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[13 + i][4 + j] = mem[i][j];
//				}
//
//			}
//		}
//	}
//}
//
////6�i�ڂ�3��(������)
//if (mou_x > 150.0f && mou_x < 216.0f && mou_y>346.0f && mou_y < 410.0f)
//{
//	if (mou_l == true)
//	{
//		//�E�ֈړ�
//		if (map[16][10] == 0)
//		{
//			for (int i = 0; i < 3; i++)
//			{
//				for (int j = 0; j < 3; j++)
//				{
//					mem[i][j] = map[16 + i][7 + j];
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[16 + i][7 + j] = 0;
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[16 + i][10 + j] = mem[i][j];
//				}
//
//			}
//		}
//		//���ֈړ�
//		if (map[19][7] == 0)
//		{
//			for (int i = 0; i < 3; i++)
//			{
//				for (int j = 0; j < 3; j++)
//				{
//					mem[i][j] = map[16 + i][7 + j];
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[16 + i][7 + j] = 0;
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[19 + i][7 + j] = mem[i][j];
//				}
//
//			}
//		}
//
//		//���ֈړ�
//		if (map[16][4] == 0)
//		{
//			for (int i = 0; i < 3; i++)
//			{
//				for (int j = 0; j < 3; j++)
//				{
//					mem[i][j] = map[16 + i][7 + j];
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[16 + i][7 + j] = 0;
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[16 + i][4 + j] = mem[i][j];
//				}
//
//			}
//		}
//
//		//��ֈړ�
//		if (map[13][7] == 0)
//		{
//			for (int i = 0; i < 3; i++)
//			{
//				for (int j = 0; j < 3; j++)
//				{
//					mem[i][j] = map[16 + i][7 + j];
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[16 + i][7 + j] = 0;
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[13 + i][7 + j] = mem[i][j];
//				}
//
//			}
//		}
//	}
//}
//
////6�i�ڂ�4��(������)
//if (mou_x > 216.0f && mou_x < 282.0f && mou_y>346.0f && mou_y < 410.0f)
//{
//	if (mou_l == true)
//	{
//		//�E�ֈړ�
//		if (map[16][13] == 0)
//		{
//			for (int i = 0; i < 3; i++)
//			{
//				for (int j = 0; j < 3; j++)
//				{
//					mem[i][j] = map[16 + i][10 + j];
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[16 + i][10 + j] = 0;
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[16 + i][13 + j] = mem[i][j];
//				}
//
//			}
//		}
//		//���ֈړ�
//		if (map[19][10] == 0)
//		{
//			for (int i = 0; i < 3; i++)
//			{
//				for (int j = 0; j < 3; j++)
//				{
//					mem[i][j] = map[16 + i][10 + j];
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[16 + i][10 + j] = 0;
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[19 + i][10 + j] = mem[i][j];
//				}
//
//			}
//		}
//
//		//���ֈړ�
//		if (map[16][7] == 0)
//		{
//			for (int i = 0; i < 3; i++)
//			{
//				for (int j = 0; j < 3; j++)
//				{
//					mem[i][j] = map[16 + i][10 + j];
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[16 + i][10 + j] = 0;
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[16 + i][7 + j] = mem[i][j];
//				}
//
//			}
//		}
//
//		//��ֈړ�
//		if (map[13][10] == 0)
//		{
//			for (int i = 0; i < 3; i++)
//			{
//				for (int j = 0; j < 3; j++)
//				{
//					mem[i][j] = map[16 + i][10 + j];
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[16 + i][10 + j] = 0;
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[13 + i][10 + j] = mem[i][j];
//				}
//
//			}
//		}
//	}
//}
//
////6�i�ڂ�5��(������)
//if (mou_x > 282.0f && mou_x < 346.0f && mou_y>346.0f && mou_y < 410.0f)
//{
//	if (mou_l == true)
//	{
//		//�E�ֈړ�
//		if (map[16][16] == 0)
//		{
//			for (int i = 0; i < 3; i++)
//			{
//				for (int j = 0; j < 3; j++)
//				{
//					mem[i][j] = map[16 + i][13 + j];
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[16 + i][13 + j] = 0;
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[16 + i][16 + j] = mem[i][j];
//				}
//
//			}
//		}
//		//���ֈړ�
//		if (map[19][13] == 0)
//		{
//			for (int i = 0; i < 3; i++)
//			{
//				for (int j = 0; j < 3; j++)
//				{
//					mem[i][j] = map[16 + i][13 + j];
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[16 + i][13 + j] = 0;
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[19 + i][13 + j] = mem[i][j];
//				}
//
//			}
//		}
//
//		//���ֈړ�
//		if (map[16][10] == 0)
//		{
//			for (int i = 0; i < 3; i++)
//			{
//				for (int j = 0; j < 3; j++)
//				{
//					mem[i][j] = map[16 + i][13 + j];
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[16 + i][13 + j] = 0;
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[16 + i][10 + j] = mem[i][j];
//				}
//
//			}
//		}
//
//		//��ֈړ�
//		if (map[13][13] == 0)
//		{
//			for (int i = 0; i < 3; i++)
//			{
//				for (int j = 0; j < 3; j++)
//				{
//					mem[i][j] = map[16 + i][13 + j];
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[16 + i][13 + j] = 0;
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[13 + i][13 + j] = mem[i][j];
//				}
//
//			}
//		}
//	}
//}
//
////6�i�ڂ�6��(������)
//if (mou_x > 346.0f && mou_x < 410.0f && mou_y>346.0f && mou_y < 410.0f)
//{
//	if (mou_l == true)
//	{
//		//�E�ֈړ�
//		if (map[16][19] == 0)
//		{
//			for (int i = 0; i < 3; i++)
//			{
//				for (int j = 0; j < 3; j++)
//				{
//					mem[i][j] = map[16 + i][16 + j];
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[16 + i][16 + j] = 0;
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[16 + i][19 + j] = mem[i][j];
//				}
//
//			}
//		}
//		//���ֈړ�
//		if (map[19][16] == 0)
//		{
//			for (int i = 0; i < 3; i++)
//			{
//				for (int j = 0; j < 3; j++)
//				{
//					mem[i][j] = map[16 + i][16 + j];
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[16 + i][16 + j] = 0;
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[19 + i][16 + j] = mem[i][j];
//				}
//
//			}
//		}
//
//		//���ֈړ�
//		if (map[16][13] == 0)
//		{
//			for (int i = 0; i < 3; i++)
//			{
//				for (int j = 0; j < 3; j++)
//				{
//					mem[i][j] = map[16 + i][16 + j];
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[16 + i][16 + j] = 0;
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[16 + i][13 + j] = mem[i][j];
//				}
//
//			}
//		}
//
//		//��ֈړ�
//		if (map[13][16] == 0)
//		{
//			for (int i = 0; i < 3; i++)
//			{
//				for (int j = 0; j < 3; j++)
//				{
//					mem[i][j] = map[16 + i][16 + j];
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[16 + i][16 + j] = 0;
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[13 + i][16 + j] = mem[i][j];
//				}
//
//			}
//		}
//	}
//}
//
////6�i�ڂ�7��(������)
//if (mou_x > 410.0f && mou_x < 478.0f && mou_y>346.0f && mou_y < 410.0f)
//{
//	if (mou_l == true)
//	{
//		//�E�ֈړ�
//		if (map[16][22] == 0)
//		{
//			for (int i = 0; i < 3; i++)
//			{
//				for (int j = 0; j < 3; j++)
//				{
//					mem[i][j] = map[16 + i][19 + j];
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[16 + i][19 + j] = 0;
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[16 + i][22 + j] = mem[i][j];
//				}
//
//			}
//		}
//		//���ֈړ�
//		if (map[19][19] == 0)
//		{
//			for (int i = 0; i < 3; i++)
//			{
//				for (int j = 0; j < 3; j++)
//				{
//					mem[i][j] = map[16 + i][19 + j];
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[16 + i][19 + j] = 0;
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[19 + i][19 + j] = mem[i][j];
//				}
//
//			}
//		}
//
//		//���ֈړ�
//		if (map[16][16] == 0)
//		{
//			for (int i = 0; i < 3; i++)
//			{
//				for (int j = 0; j < 3; j++)
//				{
//					mem[i][j] = map[16 + i][19 + j];
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[16 + i][19 + j] = 0;
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[16 + i][16 + j] = mem[i][j];
//				}
//
//			}
//		}
//
//		//��ֈړ�
//		if (map[13][19] == 0)
//		{
//			for (int i = 0; i < 3; i++)
//			{
//				for (int j = 0; j < 3; j++)
//				{
//					mem[i][j] = map[16 + i][19 + j];
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[16 + i][19 + j] = 0;
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[13 + i][19 + j] = mem[i][j];
//				}
//
//			}
//		}
//	}
//}
//
////6�i�ڂ�8��(������)
//if (mou_x > 478.0f && mou_x < 542.0f && mou_y>346.0f && mou_y < 410.0f)
//{
//	if (mou_l == true)
//	{
//		//���ֈړ�
//		if (map[19][22] == 0)
//		{
//			for (int i = 0; i < 3; i++)
//			{
//				for (int j = 0; j < 3; j++)
//				{
//					mem[i][j] = map[16 + i][22 + j];
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[16 + i][22 + j] = 0;
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[19 + i][22 + j] = mem[i][j];
//				}
//
//			}
//		}
//
//		//���ֈړ�
//		if (map[16][19] == 0)
//		{
//			for (int i = 0; i < 3; i++)
//			{
//				for (int j = 0; j < 3; j++)
//				{
//					mem[i][j] = map[16 + i][22 + j];
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[16 + i][22 + j] = 0;
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[16 + i][19 + j] = mem[i][j];
//				}
//
//			}
//		}
//
//		//��ֈړ�
//		if (map[13][22] == 0)
//		{
//			for (int i = 0; i < 3; i++)
//			{
//				for (int j = 0; j < 3; j++)
//				{
//					mem[i][j] = map[16 + i][22 + j];
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[16 + i][22 + j] = 0;
//				}
//
//				for (int j = 0; j < 3; j++)
//				{
//					map[13 + i][22 + j] = mem[i][j];
//				}
//
//			}
//		}
//	}
//}