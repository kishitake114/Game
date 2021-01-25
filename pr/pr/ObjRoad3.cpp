//�g�p����w�b�_�[�t�@�C��
#include "ObjRoad3.h"
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

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjRoad3::Init()
{
	CObjPlayer* obj = (CObjPlayer*)Objs::GetObj(OBJ_PLAYER);

	((UserData*)Save::GetData())->stage = 3;
	obj->num = 3;
	obj->p_x = 0.0f;
	obj->p_y = 200.0f;

	reset = 0;

	s_time = 240;
	second = 4;
	set = false;


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
		{2,1,2,1,1,2,2,2,4,2,2,3,2,2,3,1,2,6,1,2},
		{0,1,2,1,1,1,1,1,1,1,1,2,1,1,2,1,1,1,1,0},
		{0,1,1,1,1,2,1,1,2,1,1,2,1,1,1,1,1,2,1,0},
		{2,2,3,2,1,5,1,2,3,2,1,3,1,1,2,2,2,3,2,2},
		{0,1,2,1,1,2,1,1,2,1,1,2,1,1,2,1,1,1,1,0},
		{0,1,1,1,1,2,1,1,2,1,1,1,1,1,2,1,1,2,1,0},
		{2,2,6,2,2,3,1,2,2,1,2,5,2,1,4,2,1,6,1,2},
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

	pxc = 0.0f;		//�L���p�ϐ��ix�j
	pyc = 0.0f;		//�L���p�ϐ��iy�j

	test = false;	//�m�F�p
	testx = 0;		//�ʒu�m�F�p�i���j
	testy = 0;		//�ʒu�m�F�p�i�c�j

	s_r = false;
}
//�A�N�V����
void CObjRoad3::Action()
{

	CObjTime* time = (CObjTime*)Objs::GetObj(OBJ_TIME);
	CObjRP* RP = (CObjRP*)Objs::GetObj(OBJ_SWITCH);

	CObjPlayer* player = (CObjPlayer*)Objs::GetObj(OBJ_PLAYER);
	CObjEnemy3* Enemy3 = (CObjEnemy3*)Objs::GetObj(OBJ_ENEMY3);
	float px = player->GetX();
	float py = player->GetY();


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
			RP->sc = false;
		}

	}

	//map�ɃA�N�Z�X

	mou_x = (float)Input::GetPosX();
	mou_y = (float)Input::GetPosY();
	mou_r = Input::GetMouButtonR();
	mou_l = Input::GetMouButtonL();

	//�J�[�\���ʒu�L���p
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
			player->s_p = true;
			Enemy3->atk = false;
		}


		if (mou_x > 25.0f && mou_x < 467.0f && mou_y>25.0f && mou_y < 467.0f)
		{
			test = true;
			
			//1�i��
			
			//1�i��1�s��
			if (mou_x > 25.0f && mou_x < 97.0f && mou_y>25.0f && mou_y < 97.0f)
			{
				testx = 1;
				testy = 1;


				if (mou_l == true)
				{
					//1�i��1�s��->1�i��2�s��
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

					//1�i��1�s��->2�i��1�s��
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
			//1�i��2�s��
			if (mou_x > 98.0f && mou_x < 173.0f && mou_y>25.0f && mou_y < 97.0f)
			{
				testx = 2;
				testy = 1;


				if (mou_l == true)
				{
					//1�i��2�s��->1�i��3�s��
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

					//1�i��2�s��->1�i��1�s��
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

					//1�i��2�s��->2�i��2�s��
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
			//1�i��3�s��
			if (mou_x > 173.0f && mou_x < 246.0f && mou_y>25.0f && mou_y < 97.0f)
			{
				testx = 3;
				testy = 1;


				if (mou_l == true)
				{
					//1�i��3�s��->1�i��4�s��
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

					//1�i��3�s��->1�i��2�s��
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

					//1�i��3�s��->2�i��3�s��
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
			//1�i��4�s��
			if (mou_x > 246.0f && mou_x < 321.0f && mou_y>25.0f && mou_y < 97.0f)
			{
				testx = 4;
				testy = 1;


				if (mou_l == true)
				{
					//1�i��4�s��->1�i��5�s��
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

					//1�i��4�s��->1�i��3�s��
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

					//1�i��4�s��->2�i��4�s��
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
			//1�i��5�s��
			if (mou_x > 321.0f && mou_x < 394.0f && mou_y>25.0f && mou_y < 97.0f)
			{
				testx = 5;
				testy = 1;


				if (mou_l == true)
				{
					//1�i��5�s��->1�i��4�s��
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

					//1�i��5�s��->1�i��6�s��
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

					//1�i��5�s��->2�i��5�s��
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
			//1�i��6�s��
			if (mou_x > 394.0f && mou_x < 467.0f && mou_y>25.0f && mou_y < 97.0f)
			{
				testx = 6;
				testy = 1;


				if (mou_l == true)
				{
					//1�i��6�s��->1�i��5�s��
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

					//1�i��6�s��->2�i��6�s��
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


			//2�i��

			//2�i��1�s��
			if (mou_x > 25.0f && mou_x < 97.0f && mou_y>97.0f && mou_y < 173.0f)
			{
				testx = 1;
				testy = 2;


				if (mou_l == true)
				{
					//2�i��1�s��->1�i��1�s��
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

					//2�i��1�s��->3�i��1�s��
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

					//2�i��1�s��->2�i��2�s��
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
			//2�i��2�s��
			if (mou_x > 98.0f && mou_x < 173.0f && mou_y>97.0f && mou_y < 173.0f)
			{
				testx = 2;
				testy = 2;


				if (mou_l == true)
				{
					//2�i��2�s��->2�i��3�s��
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

					//2�i��2�s��->2�i��1�s��
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

					//2�i��2�s��->1�i��2�s��
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

					//2�i��2�s��->1�i��2�s��
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
			//2�i��3�s��
			if (mou_x > 173.0f && mou_x < 246.0f && mou_y>97.0f && mou_y < 173.0f)
			{
				testx = 3;
				testy = 2;


				if (mou_l == true)
				{
					//2�i��3�s��->2�i��4�s��
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

					//2�i��3�s��->2�i��2�s��
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

					//2�i��3�s��->1�i��3�s��
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

					//2�i��3�s��->3�i��3�s��
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
			//2�i��4�s��
			if (mou_x > 246.0f && mou_x < 321.0f && mou_y>97.0f && mou_y < 173.0f)
			{
				testx = 4;
				testy = 2;


				if (mou_l == true)
				{
					//2�i��4�s��->2�i��3�s��
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

					//2�i��4�s��->2�i��5�s��
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

					//2�i��4�s��->1�i��4�s��
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

					//2�i��4�s��->3�i��4�s��
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
			//2�i��5�s��
			if (mou_x > 321.0f && mou_x < 394.0f && mou_y>97.0f && mou_y < 173.0f)
			{
				testx = 5;
				testy = 2;


				if (mou_l == true)
				{
					//2�i��5�s��->2�i��6�s��
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

					//2�i��5�s��->2�i��4�s��
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

					//2�i��5�s��->1�i��5�s��
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

					//2�i��5�s��->3�i��5�s��
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
			//2�i��6�s��
			if (mou_x > 394.0f && mou_x < 467.0f && mou_y>97.0f && mou_y < 173.0f)
			{
				testx = 6;
				testy = 2;


				if (mou_l == true)
				{
					//2�i��6�s��->1�i��6�s��
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

					//2�i��6�s��->3�i��6�s��
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

					//2�i��6�s��->2�i��5�s��
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

			//3�i��


			//3�i��1�s��
			if (mou_x > 25.0f && mou_x < 97.0f && mou_y>173.0f && mou_y < 246.0f)
			{
				testx = 1;
				testy = 3;


				if (mou_l == true)
				{
					//3�i��1�s��->2�i��1�s��
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

					//3�i��6�s��->4�i��6�s��
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

					//3�i��1�s��->3�i��2�s��
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
			//3�i��2�s��
			if (mou_x > 98.0f && mou_x < 173.0f && mou_y>173.0f && mou_y < 246.0f)
			{
				testx = 2;
				testy = 3;


				if (mou_l == true)
				{
					//3�i��2�s��->3�i��1�s��
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

					//3�i��2�s��->3�i��3�s��
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

					//3�i��2�s��->4�i��2�s��
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

					//3�i��2�s��->2�i��2�s��
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
			//3�i��3�s��
			if (mou_x > 173.0f && mou_x < 246.0f && mou_y>173.0f && mou_y < 246.0f)
			{
				testx = 3;
				testy = 3;


				if (mou_l == true)
				{
					//3�i��3�s��->3�i��4�s��
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

					//3�i��3�s��->3�i��2�s��
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

					//3�i��3�s��->4�i��3�s��
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

					//3�i��3�s��->2�i��3�s��
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
			//3�i��4�s��
			if (mou_x > 246.0f && mou_x < 321.0f && mou_y>173.0f && mou_y < 246.0f)
			{
				testx = 4;
				testy = 3;


				if (mou_l == true)
				{
					//3�i��4�s��->3�i��5�s��
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

					//3�i��4�s��->3�i��3�s��
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

					//3�i��4�s��->4�i��4�s��
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

					//3�i��4�s��->2�i��4�s��
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
			//3�i��5�s��
			if (mou_x > 321.0f && mou_x < 394.0f && mou_y>173.0f && mou_y < 246.0f)
			{
				testx = 5;
				testy = 3;

				if (mou_l == true)
				{
					//3�i��5�s��->3�i��6�s��
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

					//3�i��5�s��->3�i��4�s��
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

					//3�i��5�s��->4�i��5�s��
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

					//3�i��5�s��->2�i��5�s��
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
			//3�i��6�s��
			if (mou_x > 394.0f && mou_x < 467.0f && mou_y>173.0f && mou_y < 246.0f)
			{
				testx = 6;
				testy = 3;

				if (mou_l == true)
				{
					//3�i��6�s��->4�i��6�s��
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

					//3�i��6�s��->2�i��6�s��
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

					//3�i��6�s��->3�i��5�s��
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


			//4�i��


			//4�i��1�s��
			if (mou_x > 25.0f && mou_x < 97.0f && mou_y>246.0f && mou_y < 321.0f)
			{
				testx = 1;
				testy = 4;

				if (mou_l == true)
				{
					//4�i��1�s��->4�i��2�s��
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

					//4�i��1�s��->3�i��1�s��
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

					//4�i��1�s��->5�i��1�s��
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
			//4�i��2�s��
			if (mou_x > 98.0f && mou_x < 173.0f && mou_y>246.0f && mou_y < 321.0f)
			{
				testx = 2;
				testy = 4;

				if (mou_l == true)
				{
					//4�i��2�s��->4�i��3�s��
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

					//4�i��2�s��->4�i��1�s��
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

					//4�i��2�s��->5�i��2�s��
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

					//4�i��2�s��->3�i��2�s��
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
			//4�i��3�s��
			if (mou_x > 173.0f && mou_x < 246.0f && mou_y>246.0f && mou_y < 321.0f)
			{
				testx = 3;
				testy = 4;

				if (mou_l == true)
				{
					//4�i��3�s��->4�i��4�s��
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

					//4�i��3�s��->4�i��2�s��
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

					//4�i��3�s��->5�i��3�s��
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

					//4�i��3�s��->3�i��3�s��
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
			//4�i��4�s��
			if (mou_x > 246.0f && mou_x < 321.0f && mou_y>246.0f && mou_y < 321.0f)
			{
				testx = 4;
				testy = 4;

				if (mou_l == true)
				{
					//4�i��4�s��->4�i��5�s��
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

					//4�i��4�s��->4�i��3�s��
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

					//4�i��4�s��->5�i��4�s��
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

					//4�i��4�s��->3�i��4�s��
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
			//4�i��5�s��
			if (mou_x > 321.0f && mou_x < 394.0f && mou_y>246.0f && mou_y < 321.0f)
			{
				testx = 5;
				testy = 4;

				if (mou_l == true)
				{
					//4�i��5�s��->4�i��6�s��
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

					//4�i��5�s��->4�i��4�s��
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

					//4�i��5�s��->5�i��5�s��
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

					//4�i��5�s��->3�i��5�s��
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
			//4�i��6�s��
			if (mou_x > 394.0f && mou_x < 467.0f && mou_y>246.0f && mou_y < 321.0f)
			{
				testx = 6;
				testy = 4;

				if (mou_l == true)
				{
					//4�i��6�s��->5�i��6�s��
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

					//4�i��6�s��->3�i��6�s��
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

					//4�i��6�s��->4�i��5�s��
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


			//5�i��


			//5�i��1�s��
			if (mou_x > 25.0f && mou_x < 97.0f && mou_y>321.0f && mou_y < 394.0f)
			{
				testx = 1;
				testy = 5;

				if (mou_l == true)
				{
					//5�i��1�s��->5�i��2�s��
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

					//5�i��1�s��->6�i��1�s��
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

					//5�i��1�s��->4�i��1�s��
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
			//5�i��2�s��
			if (mou_x > 98.0f && mou_x < 173.0f && mou_y>321.0f && mou_y < 394.0f)
			{
				testx = 2;
				testy = 5;

				if (mou_l == true)
				{
					//5�i��2�s��->5�i��3�s��
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

					//5�i��2�s��->5�i��1�s��
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

					//5�i��2�s��->6�i��2�s��
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

					//5�i��2�s��->4�i��2�s��
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
			//5�i��3�s��
			if (mou_x > 173.0f && mou_x < 246.0f && mou_y>321.0f && mou_y < 394.0f)
			{
				testx = 3;
				testy = 5;

				if (mou_l == true)
				{
					//5�i��3�s��->5�i��4�s��
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

					//5�i��3�s��->5�i��2�s��
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

					//5�i��3�s��->4�i��3�s��
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

					//5�i��3�s��->6�i��3�s��
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
			//5�i��4�s��
			if (mou_x > 246.0f && mou_x < 321.0f && mou_y>321.0f && mou_y < 394.0f)
			{
				testx = 4;
				testy = 5;

				if (mou_l == true)
				{
					//5�i��4�s��->5�i��5�s��
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

					//5�i��4�s��->5�i��3�s��
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

					//5�i��4�s��->4�i��4�s��
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

					//5�i��4�s��->6�i��4�s��
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
			//5�i��5�s��
			if (mou_x > 321.0f && mou_x < 394.0f && mou_y>321.0f && mou_y < 394.0f)
			{
				testx = 5;
				testy = 5;

				if (mou_l == true)
				{
					//5�i��5�s��->5�i��6�s��
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

					//5�i��5�s��->5�i��4�s��
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

					//5�i��5�s��->4�i��5�s��
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

					//5�i��5�s��->6�i��5�s��
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
			//5�i��6�s��
			if (mou_x > 394.0f && mou_x < 467.0f && mou_y>321.0f && mou_y < 394.0f)
			{
				testx = 6;
				testy = 5;

				if (mou_l == true)
				{
					//5�i��6�s��->6�i��6�s��
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

					//5�i��6�s��->4�i��5�s��
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

					//5�i��6�s��->4�i��6�s��
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


			//6�i��


			//6�i��1�s��
			if (mou_x > 25.0f && mou_x < 97.0f && mou_y>394.0f && mou_y < 467.0f)
			{
				testx = 1;
				testy = 6;

				if (mou_l == true)
				{

					//6�i��1�s��->6�i��2�s��
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

					//6�i��1�s��->5�i��1�s��
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
			//6�i��2�s��
			if (mou_x > 98.0f && mou_x < 173.0f && mou_y>394.0f && mou_y < 467.0f)
			{
				testx = 2;
				testy = 6;

				if (mou_l == true)
				{

					//6�i��2�s��->6�i��3�s��
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

					//6�i��2�s��->6�i��1�s��
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

					//6�i��2�s��->5�i��2�s��
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
			//6�i��3�s��
			if (mou_x > 173.0f && mou_x < 246.0f && mou_y>394.0f && mou_y < 467.0f)
			{
				testx = 3;
				testy = 6;

				if (mou_l == true)
				{
					//6�i��3�s��->6�i��4�s��
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

					//6�i��3�s��->6�i��2�s��
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

					//6�i��3�s��->5�i��3�s��
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
			//6�i��4�s��
			if (mou_x > 246.0f && mou_x < 321.0f && mou_y>394.0f && mou_y < 467.0f)
			{
				testx = 4;
				testy = 6;

				if (mou_l == true)
				{
					//6�i��4�s��->6�i��5�s��
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

					//6�i��4�s��->6�i��3�s��
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

					//6�i��4�s��->5�i��4�s��
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
			//6�i��5�s��
			if (mou_x > 321.0f && mou_x < 394.0f && mou_y>394.0f && mou_y < 467.0f)
			{
				testx = 5;
				testy = 6;

				if (mou_l == true)
				{
					//6�i��5�s��->6�i��6�s��
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

					//6�i��5�s��->6�i��4�s��
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

					//6�i��5�s��->5�i��5�s��
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
			//6�i��6�s��
			if (mou_x > 394.0f && mou_x < 467.0f && mou_y>394.0f && mou_y < 467.0f)
			{
				testx = 6;
				testy = 6;

				if (mou_l == true)
				{
					//6�i��6�s��->6�i��5�s��
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

					//6�i��6�s��->5�i��6�s��
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

	//���Z�b�g�{�^���̃v���O����
	if (s_r == false&&set==true)
	{
		if (mou_x > 622.0f && mou_x < 765.0f && mou_y>450.0f && mou_y < 555.0f)
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
		if (mou_l == true)
		{
			player->battle = false;
			Scene::SetScene(new CSceneStage4);

			if (player->HP == 5 && reset == 0)
			{
				((UserData*)Save::GetData())->Hperfect++;
			}
		}



		s_r = false;
	}
}
//�h���[
void CObjRoad3::Draw()
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

	//�\���F�}�E�X�J�[�\���ƃ{�^��
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


	if (player->battle == true)
	{
		if (player->HP == 5 && reset == 0)
		{
			Font::StrDraw(L"PERFECT", 600, 250, 30, y);
		}

		else
		{
			Font::StrDraw(L"YOU WIN", 600, 250, 30, c);

			swprintf_s(str, L"�󂯂��_���[�W: %d", 5 - player->HP);
			Font::StrDraw(str, 580, 350, 20, c);

			swprintf_s(str, L"���Z�b�g��: %d", reset);
			Font::StrDraw(str, 580, 375, 20, c);
		}


		Font::StrDraw(L"���̃X�e�[�W��", 600, 300, 25, c);
	}
	//�\���F�ʍs��

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


	//�y��
	src.m_top = 45.0f;
	src.m_left = 8.0f;
	src.m_right = 201.0f;
	src.m_bottom = 157.0f;

	dst.m_top = 500.0f;
	dst.m_left = 600.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	Draw::Draw(2, &src, &dst, c, 0.0f);

	//���Z�b�g�{�^��
	src.m_top = 172.0f;
	src.m_left = 8.0f;
	src.m_right = 201.0f;
	src.m_bottom = 291.0f;

	if (s_r == false && set == true)
	{
		//�����ꂽ���ɂ�����
		if (mou_x > 622.0f && mou_x < 765.0f && mou_y>450.0f && mou_y < 555.0f)
		{
			dst.m_top = 475.0f;
			dst.m_left = 622.0f;
			dst.m_right = 765.0f;
			dst.m_bottom = 555.0f;

			Draw::Draw(2, &src, &dst, c, 0.0f);
		}

		//����ȊO
		else
		{
			dst.m_top = 450.0f;
			dst.m_left = 622.0f;
			dst.m_right = 765.0f;
			dst.m_bottom = 555.0f;

			Draw::Draw(2, &src, &dst, c, 0.0f);
		}
	}

	//�s�[�X���쎞�̃{�^��
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