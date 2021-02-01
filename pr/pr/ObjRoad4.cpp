//�g�p����w�b�_�[�t�@�C��
#include "ObjRoad4.h"
#include "ObjPlayer.h"
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "GameHead.h" 
#include "GameL/WinInputs.h"
#include "GameL/HitBoxManager.h"
#include "GameL/SceneObjManager.h"
#include "GameL/UserData.h"
#include "GameL/Audio.h"

#define PIECE 26
#define SIZE 22.0f

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjRoad4::Init()
{
	CObjPlayer* obj = (CObjPlayer*)Objs::GetObj(OBJ_PLAYER);
	((UserData*)Save::GetData())->stage = 4;
	obj->num = 4;
	obj->p_x = 0.0f;
	obj->p_y = 242.0f;

	reset = 0;

	s_count = false;

	mou_x = 0.0f;
	mou_y = 0.0f;
	mou_r = false;
	mou_l = false;

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

	int mapdata[PIECE][PIECE] =
	{
		{0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0},
	    {0,1,2,1,1,2,1,1,1,1,1,2,1,1,1,1,1,1,1,1,2,1,1,1,1,0},
		{2,2,3,2,1,6,2,2,5,2,2,4,1,2,6,2,2,5,2,1,2,1,2,6,1,2},
		{0,1,2,1,1,1,1,1,1,1,1,2,1,1,2,1,1,1,1,1,2,1,1,2,1,0},
	    {0,1,2,1,1,1,1,1,1,1,1,2,1,1,2,1,1,1,1,1,2,1,1,2,1,0},
		{2,2,2,1,2,3,2,2,4,1,1,2,1,1,2,2,1,3,2,2,5,2,2,2,1,2},
		{0,1,2,1,1,1,1,1,2,1,1,2,1,1,1,1,1,2,1,1,2,1,1,2,1,0},
	    {0,1,2,1,1,2,1,1,2,1,1,2,1,1,2,1,1,2,1,1,1,1,1,1,1,0},
		{2,1,4,2,1,2,1,2,2,2,2,2,1,1,2,2,1,5,1,2,2,2,2,4,1,2},
		{0,1,1,1,1,2,1,1,2,1,1,2,1,1,1,1,1,2,1,1,2,1,1,2,1,0},
		{0,1,1,1,1,1,1,1,2,1,1,2,1,1,2,1,1,2,1,1,1,1,1,1,1,0},
		{2,2,2,1,2,2,2,2,4,1,2,2,2,1,6,2,1,2,1,2,2,2,1,2,2,2},
		{0,1,2,1,1,1,1,1,1,1,1,1,1,1,2,1,1,2,1,1,1,1,1,2,1,0},
		{0,1,2,1,1,2,1,1,1,1,0,0,0,1,2,1,1,2,1,1,1,1,1,2,1,0},
		{2,2,2,2,1,3,1,2,3,2,0,0,0,2,3,2,2,3,2,2,3,1,1,2,2,2},
		{0,1,2,1,1,2,1,1,2,1,0,0,0,1,2,1,1,2,1,1,2,1,1,2,1,0},
	    {0,1,2,1,1,2,1,1,2,1,1,1,1,1,1,1,1,2,1,1,2,1,1,2,1,0},
		{2,1,3,1,2,3,1,1,5,1,1,3,2,2,2,2,2,2,1,2,2,2,1,2,1,2},
		{0,1,2,1,1,1,1,1,2,1,1,2,1,1,1,1,1,1,1,1,1,1,1,2,1,0},
	    {0,1,1,1,1,1,1,1,2,1,1,2,1,1,2,1,1,1,1,1,1,1,1,2,1,0},
		{2,2,2,2,2,2,2,1,2,2,2,4,2,1,2,2,1,2,2,2,2,2,2,4,2,2},
		{0,1,1,1,1,2,1,1,1,1,1,2,1,1,2,1,1,2,1,1,1,1,1,2,1,0},
	    {0,1,1,1,1,1,1,1,2,1,1,2,1,1,1,1,1,2,1,1,2,1,1,2,1,0},
		{2,1,3,2,2,6,2,2,3,2,1,2,1,2,2,2,2,3,1,2,4,2,1,6,2,2},
		{0,1,2,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,2,1,0},
	    {0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0},

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
//�A�N�V����
void CObjRoad4::Action()
{
	CObjTime* time = (CObjTime*)Objs::GetObj(OBJ_TIME);
	CObjRP* RP = (CObjRP*)Objs::GetObj(OBJ_SWITCH);
	CObjPlayer* player = (CObjPlayer*)Objs::GetObj(OBJ_PLAYER);
	CObjEnemy4* Enemy4 = (CObjEnemy4*)Objs::GetObj(OBJ_ENEMY4);
	float px = player->GetX();
	float py = player->GetY();

	if (set == false)
	{
		if (s_time % 60 == 0 && s_time >= 120)
			Audio::Start(9);
		if (s_time == 60)
			Audio::Start(10);

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

			Audio::Start(0);
		}

	}

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

	if(s_r==true)
	{
		if (mou_r == true)
		{
			s_r = false;
			player->s_p = true;
			Enemy4->atk = false;
			Audio::Start(5);
		}
	
		//1�i��
		
		//1�s��[1][1] 
		if (mou_x > 22.0f && mou_x < 88.0f && mou_y>22.0f && mou_y < 88.0f)
			{
				if (mou_l == true)
				{
					//�E
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

					//��
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

		//2�s��[1][4]
		if (mou_x > 88.0f && mou_x < 154.0f && mou_y>22.0f && mou_y < 88.0f)
			{
				if (mou_l == true)
				{
					//��
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

					//�E
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

					//��
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

		//2�s��[1][7]
		if (mou_x > 154.0f && mou_x < 220.0f && mou_y>22.0f && mou_y < 88.0f)
			{
				if (mou_l == true)
				{
					//��
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

					//�E
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

					//��
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

		//4�s��[1][10]
		if (mou_x > 220.0f && mou_x < 286.0f && mou_y>22.0f && mou_y < 88.0f)
			{
				if (mou_l == true)
				{
					//��
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

					//�E
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

					//��
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

		//5�s��[1][13]
		if (mou_x > 286.0f && mou_x < 352.0f && mou_y>22.0f && mou_y < 88.0f)
			{
				if (mou_l == true)
				{
					//��
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

					//�E
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

					//��
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

		//6�s��[1][16]
		if (mou_x > 352.0f && mou_x < 418.0f && mou_y>22.0f && mou_y < 88.0f)
			{
				if (mou_l == true)
				{
					//��
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

					//�E
					if (map[1][19] == 0)
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
								map[1 + i][19 + j] = mem[i][j];
							}
						}
					}

					//��
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

		//7�s��[1][19]
		if (mou_x > 418.0f && mou_x < 484.0f && mou_y>22.0f && mou_y < 88.0f)
			{
				if (mou_l == true)
				{
					//��
					if (map[1][16] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[1 + i][19 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[1 + i][19 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[1 + i][16 + j] = mem[i][j];
							}
						}
					}

					//�E
					if (map[1][22] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[1 + i][19 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[1 + i][19 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[1 + i][22 + j] = mem[i][j];
							}
						}
					}

					//��
					if (map[4][19] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[1 + i][19 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[1 + i][19 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[4 + i][19 + j] = mem[i][j];
							}
						}
					}
				}
			}

		//8�s��[1][22]
		if (mou_x > 484.0f && mou_x < 550.0f && mou_y>22.0f && mou_y < 88.0f)
			{
				if (mou_l == true)
				{
					//��
					if (map[1][19] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[1 + i][22 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[1 + i][22 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[1 + i][19 + j] = mem[i][j];
							}
						}
					}

					//��
					if (map[4][22] == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								mem[i][j] = map[1 + i][22 + j];
							}

							for (int j = 0; j < 3; j++)
							{
								map[1 + i][22 + j] = 0;
							}

							for (int j = 0; j < 3; j++)
							{
								map[4 + i][22 + j] = mem[i][j];
							}
						}
					}
				}
			}

		//2�i��

		//1�s��[4][1]
		if (mou_x > 22.0f && mou_x < 88.0f && mou_y > 88.0f && mou_y < 154.0f)
		{
			if (mou_l == true)
			{
				//�E
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

				//��
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

				//��
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

		//2�s��[4][4]
		if (mou_x > 88.0f && mou_x < 154.0f && mou_y > 88.0f && mou_y < 154.0f)
		{
			if (mou_l == true)
			{
				//�E
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

				//��
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

				//��
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

				//��
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
			}
		}

		//3�s��[4][7]
		if (mou_x > 154.0f && mou_x < 220.0f && mou_y > 88.0f && mou_y < 154.0f)
		{
			if (mou_l == true)
			{
				//�E
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

				//��
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

				//��
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

				//��
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
			}
		}

		//4�s��[4][10]
		if (mou_x > 220.0f && mou_x < 286.0f && mou_y > 88.0f && mou_y < 154.0f)
		{
			if (mou_l == true)
			{
				//�E
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

				//��
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

				//��
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

				//��
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
			}
		}

		//5�s��[4][13]
		if (mou_x > 286.0f && mou_x < 352.0f && mou_y > 88.0f && mou_y < 154.0f)
		{
			if (mou_l == true)
			{
				//�E
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

				//��
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

				//��
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

				//��
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
			}
		}

		//6�s��[4][16]
		if (mou_x > 352.0f && mou_x < 418.0f && mou_y > 88.0f && mou_y < 154.0f)
		{
			if (mou_l == true)
			{
				//�E
				if (map[4][19] == 0)
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
							map[4 + i][19 + j] = mem[i][j];
						}
					}
				}

				//��
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

				//��
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

				//��
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

		//7�s��[4][19]
		if (mou_x > 418.0f && mou_x < 484.0f && mou_y > 88.0f && mou_y < 154.0f)
		{
			if (mou_l == true)
			{
				//�E
				if (map[4][22] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[4 + i][19 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][19 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][22 + j] = mem[i][j];
						}
					}
				}

				//��
				if (map[7][19] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[4 + i][19 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][19 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][19 + j] = mem[i][j];
						}
					}
				}

				//��
				if (map[1][19] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[4 + i][19 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][19 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][19 + j] = mem[i][j];
						}
					}
				}

				//��
				if (map[4][16] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[4 + i][19 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][19 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][16 + j] = mem[i][j];
						}
					}
				}
			}
		}

		//8�s��[4][22]
		if (mou_x > 484.0f && mou_x < 550.0f && mou_y > 88.0f && mou_y < 154.0f)
		{
			if (mou_l == true)
			{
				//��
				if (map[7][22] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[4 + i][22 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][22 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][22 + j] = mem[i][j];
						}
					}
				}

				//��
				if (map[1][22] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[4 + i][22 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][22 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][22 + j] = mem[i][j];
						}
					}
				}

				//��
				if (map[4][19] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[4 + i][22 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][22 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][19 + j] = mem[i][j];
						}
					}
				}
			}
		}

		//3�i��

		//1�s��[7][1]
		if (mou_x > 22.0f && mou_x < 88.0f && mou_y>154.0f && mou_y < 220.0f)
		{
			if (mou_l == true)
			{
				//�E
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

				//��
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

				//��
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

		//2�s��[7][4]
		if (mou_x > 88.0f && mou_x < 154.0f && mou_y>154.0f && mou_y < 220.0f)
		{
			if (mou_l == true)
			{
				//�E
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

				//��
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

				//��
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

				//��
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

		//3�s��[7][7]
		if (mou_x > 154.0f && mou_x < 220.0f && mou_y>154.0f && mou_y < 220.0f)
		{
			if (mou_l == true)
			{
				//�E
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

				//��
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

				//��
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

				//��
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

		//4�s��[7][10]
		if (mou_x > 220.0f && mou_x < 286.0f && mou_y>154.0f && mou_y < 220.0f)
		{
			if (mou_l == true)
			{
				//�E
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

				//��
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

				//��
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

				//��
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

		//5�s��[7][13]
		if (mou_x > 286.0f && mou_x < 352.0f && mou_y>154.0f && mou_y < 220.0f)
		{
			if (mou_l == true)
			{
				//��
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

				//��
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

				//��
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

				//�E
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
			}


		}

		//6�s��[7][16]
		if (mou_x > 352.0f && mou_x < 418.0f && mou_y>154.0f && mou_y < 220.0f)
		{
			if (mou_l == true)
			{
				//��
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

				//��
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

				//��
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

				//�E
				if (map[7][19] == 0)
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
							map[7 + i][19 + j] = mem[i][j];
						}
					}
				}
			}


		}

		//7�s��[7][19]
		if (mou_x > 418.0f && mou_x < 484.0f && mou_y>154.0f && mou_y < 220.0f)
		{
			if (mou_l == true)
			{
				//��
				if (map[10][19] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[7 + i][19 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][19 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][19 + j] = mem[i][j];
						}
					}
				}

				//��
				if (map[7][16] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[7 + i][19 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][19 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][16 + j] = mem[i][j];
						}
					}
				}

				//��
				if (map[4][19] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[7 + i][19 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][19 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][19 + j] = mem[i][j];
						}
					}
				}

				//�E
				if (map[7][22] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[7 + i][19 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][19 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][22 + j] = mem[i][j];
						}
					}
				}
			}


		}

		//8�s��[7][22]
		if (mou_x > 484.0f && mou_x < 550.0f && mou_y>154.0f && mou_y < 220.0f)
		{
			if (mou_l == true)
			{
				//��
				if (map[10][22] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[7 + i][22 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][22 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][22 + j] = mem[i][j];
						}
					}
				}

				//��
				if (map[7][19] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[7 + i][22 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][22 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][19 + j] = mem[i][j];
						}
					}
				}

				//��
				if (map[4][22] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[7 + i][22 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][22 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][22 + j] = mem[i][j];
						}
					}
				}
			}
		}

		//4�i��

		//1�s��[10][1]
		if (mou_x > 22.0f && mou_x < 88.0f && mou_y>220.0f && mou_y < 286.0f)
		{
			if (mou_l == true)
			{
				//�E
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

				//��
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

				//��
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

		//2�s��[10][4]
		if (mou_x > 88.0f && mou_x < 154.0f && mou_y>220.0f && mou_y < 286.0f)
		{
			if (mou_l == true)
			{
				//�E
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

				//��
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

				//��
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

				//��
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

		//3�s��[10][7]
		if (mou_x > 154.0f && mou_x < 220.0f && mou_y>220.0f && mou_y < 286.0f)
		{
			if (mou_l == true)
			{
				//�E
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

				//��
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

				//��
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

				//��
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

		//4�s��[10][10]
		if (mou_x > 220.0f && mou_x < 286.0f && mou_y>220.0f && mou_y < 286.0f)
		{
			if (mou_l == true)
			{
				//�E
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

				//��
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

				//��
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

				//��
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

		//5�s��[10][13]
		if (mou_x > 286.0f && mou_x < 352.0f && mou_y>220.0f && mou_y < 286.0f)
		{
			if (mou_l == true)
			{
				//��
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

				//��
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

				//��
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

				//�E
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
			}
		}

		//6�s��[10][16]
		if (mou_x > 352.0f && mou_x < 418.0f && mou_y>220.0f && mou_y < 286.0f)
		{
			if (mou_l == true)
			{
				//��
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

				//��
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

				//��
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

				//�E
				if (map[10][19] == 0)
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
							map[10 + i][19 + j] = mem[i][j];
						}
					}
				}
			}
		}

		//7�s��[10][19]
		if (mou_x > 418.0f && mou_x < 484.0f && mou_y>220.0f && mou_y < 286.0f)
		{
			if (mou_l == true)
			{
				//��
				if (map[13][19] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[10 + i][19 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][19 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[13 + i][19 + j] = mem[i][j];
						}
					}
				}

				//��
				if (map[10][16] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[10 + i][19 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][19 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][16 + j] = mem[i][j];
						}
					}
				}

				//��
				if (map[7][19] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[10 + i][19 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][19 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][19 + j] = mem[i][j];
						}
					}
				}

				//�E
				if (map[10][22] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[10 + i][19 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][19 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][22 + j] = mem[i][j];
						}
					}
				}
			}
		}

		//8�s��[10][22]
		if (mou_x > 484.0f && mou_x < 550.0f && mou_y>220.0f && mou_y < 286.0f)
		{
			if (mou_l == true)
			{
				//��
				if (map[13][22] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[10 + i][22 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][22 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[13 + i][22 + j] = mem[i][j];
						}
					}
				}

				//��
				if (map[10][19] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[10 + i][22 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][22 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][19 + j] = mem[i][j];
						}
					}
				}

				//��
				if (map[7][22] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[10 + i][22 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][22 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][22 + j] = mem[i][j];
						}
					}
				}
			}
		}

		//5�i��

		//1�s��[13][1]
		if (mou_x > 22.0f && mou_x < 88.0f && mou_y>286.0f && mou_y < 352.0f)
		{

			if (mou_l == true)
			{
				//�E
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

				//��
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

				//��
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
		}

		//2�s��[13][4]
		if (mou_x > 88.0f && mou_x < 154.0f && mou_y>286.0f && mou_y < 352.0f)
		{

			if (mou_l == true)
			{
				//�E
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

				//��
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

				//��
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

				//��
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
			}
		}

		//3�s��[13][7]
		if (mou_x > 154.0f && mou_x < 220.0f && mou_y>286.0f && mou_y < 352.0f)
		{

			if (mou_l == true)
			{
				//�E
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

				//��
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

				//��
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

				//��
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

		//4�s��[13][10]
		if (mou_x > 220.0f && mou_x < 286.0f && mou_y>286.0f && mou_y < 352.0f)
		{

			if (mou_l == true)
			{
				//�E
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

				//��
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

				//��
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

				//��
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

		//5�s��[13][13]
		if (mou_x > 286.0f && mou_x < 352.0f && mou_y>286.0f && mou_y < 352.0f)
		{
			if (mou_l == true)
			{
				//��
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

				//��
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

				//��
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

				//�E
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
			}
		}

		//6�s��[13][16]
		if (mou_x > 352.0f && mou_x < 418.0f && mou_y>286.0f && mou_y < 352.0f)
		{
			if (mou_l == true)
			{
				//��
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

				//��
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

				//��
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

				//�E
				if (map[13][19] == 0)
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
							map[13 + i][19 + j] = mem[i][j];
						}
					}
				}
			}
		}

		//7�s��[13][19]
		if (mou_x > 418.0f && mou_x < 484.0f && mou_y>286.0f && mou_y < 352.0f)
		{
			if (mou_l == true)
			{
				//��
				if (map[13][16] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[13 + i][19 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[13 + i][19 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[13 + i][16 + j] = mem[i][j];
						}
					}
				}

				//��
				if (map[10][19] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[13 + i][19 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[13 + i][19 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][19 + j] = mem[i][j];
						}
					}
				}

				//��
				if (map[16][19] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[13 + i][19 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[13 + i][19 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[16 + i][19 + j] = mem[i][j];
						}
					}
				}

				//�E
				if (map[13][22] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[13 + i][19 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[13 + i][19 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[13 + i][22 + j] = mem[i][j];
						}
					}
				}
			}
		}

		//8�s��[13][22]
		if (mou_x > 484.0f && mou_x < 550.0f && mou_y>286.0f && mou_y < 352.0f)
		{
			if (mou_l == true)
			{
				//��
				if (map[13][19] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[13 + i][22 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[13 + i][22 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[13 + i][19 + j] = mem[i][j];
						}
					}
				}

				//��
				if (map[10][22] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[13 + i][22 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[13 + i][22 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][22 + j] = mem[i][j];
						}
					}
				}

				//��
				if (map[16][22] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[13 + i][22 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[13 + i][22 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[16 + i][22 + j] = mem[i][j];
						}
					}
				}
			}
		}

		//6�i��

		//6�i�ڂ�1��(������)
		if (mou_x > 22.0f && mou_x < 86.0f && mou_y>346.0f && mou_y < 410.0f)
		{
			if (mou_l == true)
			{
				//�E�ֈړ�
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
				//���ֈړ�
				if (map[19][1] == 0)
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
							map[19 + i][1 + j] = mem[i][j];
						}

					}
				}

				//��ֈړ�
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

		//6�i�ڂ�2��(������)
		if (mou_x > 86.0f && mou_x < 150.0f && mou_y>346.0f && mou_y < 410.0f)
		{
			if (mou_l == true)
			{
				//�E�ֈړ�
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
				//���ֈړ�
				if (map[19][4] == 0)
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
							map[19 + i][4 + j] = mem[i][j];
						}

					}
				}

				//���ֈړ�
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

				//��ֈړ�
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

		//6�i�ڂ�3��(������)
		if (mou_x > 150.0f && mou_x < 216.0f && mou_y>346.0f && mou_y < 410.0f)
		{
			if (mou_l == true)
			{
				//�E�ֈړ�
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
				//���ֈړ�
				if (map[19][7] == 0)
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
							map[19 + i][7 + j] = mem[i][j];
						}

					}
				}

				//���ֈړ�
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

				//��ֈړ�
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

		//6�i�ڂ�4��(������)
		if (mou_x > 216.0f && mou_x < 282.0f && mou_y>346.0f && mou_y < 410.0f)
		{
			if (mou_l == true)
			{
				//�E�ֈړ�
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
				//���ֈړ�
				if (map[19][10] == 0)
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
							map[19 + i][10 + j] = mem[i][j];
						}

					}
				}

				//���ֈړ�
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

				//��ֈړ�
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

		//6�i�ڂ�5��(������)
		if (mou_x > 282.0f && mou_x < 346.0f && mou_y>346.0f && mou_y < 410.0f)
		{
			if (mou_l == true)
			{
				//�E�ֈړ�
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
				//���ֈړ�
				if (map[19][13] == 0)
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
							map[19 + i][13 + j] = mem[i][j];
						}

					}
				}

				//���ֈړ�
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

				//��ֈړ�
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

		//6�i�ڂ�6��(������)
		if (mou_x > 346.0f && mou_x < 410.0f && mou_y>346.0f && mou_y < 410.0f)
		{
			if (mou_l == true)
			{
				//�E�ֈړ�
				if (map[16][19] == 0)
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
							map[16 + i][19 + j] = mem[i][j];
						}

					}
				}
				//���ֈړ�
				if (map[19][16] == 0)
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
							map[19 + i][16 + j] = mem[i][j];
						}

					}
				}

				//���ֈړ�
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

				//��ֈړ�
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

		//6�i�ڂ�7��(������)
		if (mou_x > 410.0f && mou_x < 478.0f && mou_y>346.0f && mou_y < 410.0f)
		{
			if (mou_l == true)
			{
				//�E�ֈړ�
				if (map[16][22] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[16 + i][19 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[16 + i][19 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[16 + i][22 + j] = mem[i][j];
						}

					}
				}
				//���ֈړ�
				if (map[19][19] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[16 + i][19 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[16 + i][19 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[19 + i][19 + j] = mem[i][j];
						}

					}
				}

				//���ֈړ�
				if (map[16][16] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[16 + i][19 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[16 + i][19 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[16 + i][16 + j] = mem[i][j];
						}

					}
				}

				//��ֈړ�
				if (map[13][19] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[16 + i][19 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[16 + i][19 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[13 + i][19 + j] = mem[i][j];
						}

					}
				}
			}
		}

		//6�i�ڂ�8��(������)
		if (mou_x > 478.0f && mou_x < 542.0f && mou_y>346.0f && mou_y < 410.0f)
		{
			if (mou_l == true)
			{
				//���ֈړ�
				if (map[19][22] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[16 + i][22 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[16 + i][22 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[19 + i][22 + j] = mem[i][j];
						}

					}
				}

				//���ֈړ�
				if (map[16][19] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[16 + i][22 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[16 + i][22 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[16 + i][19 + j] = mem[i][j];
						}

					}
				}

				//��ֈړ�
				if (map[13][22] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[16 + i][22 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[16 + i][22 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[13 + i][22 + j] = mem[i][j];
						}

					}
				}
			}
		}

		//7�i��
		
		//7�i�ڂ�1��(������)
		if (mou_x > 22.0f && mou_x < 86.0f && mou_y>412.0f && mou_y < 478.0f)
		{
			if (mou_l == true)
			{
				//�E�ֈړ�
				if (map[19][4] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[19 + i][1 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[19 + i][1 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[19 + i][4 + j] = mem[i][j];
						}

					}
				}
				//���ֈړ�
				if (map[22][1] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[19 + i][1 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[19 + i][1 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[22 + i][1 + j] = mem[i][j];
						}

					}
				}

				//��ֈړ�
				if (map[16][1] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[19 + i][1 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[19 + i][1 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[16 + i][1 + j] = mem[i][j];
						}

					}
				}
			}
		}

		//7�i�ڂ�2��(������)
		if (mou_x > 86.0f && mou_x < 150.0f && mou_y>412.0f && mou_y < 478.0f)
		{
			if (mou_l == true)
			{
				//�E�ֈړ�
				if (map[19][7] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[19 + i][4 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[19 + i][4 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[19 + i][7 + j] = mem[i][j];
						}

					}
				}
				//���ֈړ�
				if (map[22][4] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[19 + i][4 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[19 + i][4 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[22 + i][4 + j] = mem[i][j];
						}

					}
				}

				//���ֈړ�
				if (map[19][1] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[19 + i][4 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[19 + i][4 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[19 + i][1 + j] = mem[i][j];
						}

					}
				}

				//��ֈړ�
				if (map[16][4] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[19 + i][4 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[19 + i][4 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[16 + i][4 + j] = mem[i][j];
						}

					}
				}
			}
		}

		//7�i�ڂ�3��(������)
		if (mou_x > 150.0f && mou_x < 216.0f && mou_y>412.0f && mou_y < 478.0f)
		{
			if (mou_l == true)
			{
				//�E�ֈړ�
				if (map[19][10] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[19 + i][7 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[19 + i][7 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[19 + i][10 + j] = mem[i][j];
						}

					}
				}
				//���ֈړ�
				if (map[22][7] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[19 + i][7 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[19 + i][7 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[22 + i][7 + j] = mem[i][j];
						}

					}
				}

				//���ֈړ�
				if (map[19][4] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[19 + i][7 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[19 + i][7 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[19 + i][4 + j] = mem[i][j];
						}

					}
				}

				//��ֈړ�
				if (map[16][7] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[19 + i][7 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[19 + i][7 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[16 + i][7 + j] = mem[i][j];
						}

					}
				}
			}
		}

		//7�i�ڂ�4��(������)
		if (mou_x > 216.0f && mou_x < 284.0f && mou_y>412.0f && mou_y < 478.0f)
		{
			if (mou_l == true)
			{
				//�E�ֈړ�
				if (map[19][13] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[19 + i][10 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[19 + i][10 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[19 + i][13 + j] = mem[i][j];
						}

					}
				}
				//���ֈړ�
				if (map[22][10] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[19 + i][10 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[19 + i][10 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[22 + i][10 + j] = mem[i][j];
						}

					}
				}

				//���ֈړ�
				if (map[19][7] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[19 + i][10 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[19 + i][10 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[19 + i][7 + j] = mem[i][j];
						}

					}
				}

				//��ֈړ�
				if (map[16][10] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[19 + i][10 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[19 + i][10 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[16 + i][10 + j] = mem[i][j];
						}

					}
				}
			}
		}

		//7�i�ڂ�5��(������)
		if (mou_x > 284.0f && mou_x < 348.0f && mou_y>412.0f && mou_y < 478.0f)
		{
			if (mou_l == true)
			{
				//�E�ֈړ�
				if (map[19][16] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[19 + i][13 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[19 + i][13 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[19 + i][16 + j] = mem[i][j];
						}

					}
				}
				//���ֈړ�
				if (map[22][13] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[19 + i][13 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[19 + i][13 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[22 + i][13 + j] = mem[i][j];
						}

					}
				}

				//���ֈړ�
				if (map[19][10] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[19 + i][13 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[19 + i][13 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[19 + i][10 + j] = mem[i][j];
						}

					}
				}

				//��ֈړ�
				if (map[16][13] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[19 + i][13 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[19 + i][13 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[16 + i][13 + j] = mem[i][j];
						}

					}
				}
			}
		}

		//7�i�ڂ�6��(������)
		if (mou_x > 348.0f && mou_x < 412.0f && mou_y>412.0f && mou_y < 478.0f)
		{
			if (mou_l == true)
			{
				//�E�ֈړ�
				if (map[19][19] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[19 + i][16 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[19 + i][16 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[19 + i][19 + j] = mem[i][j];
						}

					}
				}
				//���ֈړ�
				if (map[22][16] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[19 + i][16 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[19 + i][16 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[22 + i][16 + j] = mem[i][j];
						}

					}
				}

				//���ֈړ�
				if (map[19][13] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[19 + i][16 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[19 + i][16 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[19 + i][13 + j] = mem[i][j];
						}

					}
				}

				//��ֈړ�
				if (map[16][16] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[19 + i][16 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[19 + i][16 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[16 + i][16 + j] = mem[i][j];
						}

					}
				}
			}
		}

		//7�i�ڂ�7��(������)
		if (mou_x > 412.0f && mou_x < 478.0f && mou_y>412.0f && mou_y < 478.0f)
		{
			if (mou_l == true)
			{
				//�E�ֈړ�
				if (map[19][22] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[19 + i][19 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[19 + i][19 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[19 + i][22 + j] = mem[i][j];
						}

					}
				}
				//���ֈړ�
				if (map[22][19] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[19 + i][19 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[19 + i][19 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[22 + i][19 + j] = mem[i][j];
						}

					}
				}

				//���ֈړ�
				if (map[19][16] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[19 + i][19 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[19 + i][19 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[19 + i][16 + j] = mem[i][j];
						}

					}
				}

				//��ֈړ�
				if (map[16][19] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[19 + i][19 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[19 + i][19 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[16 + i][19 + j] = mem[i][j];
						}

					}
				}
			}
		}

		//7�i�ڂ�8��(������)
		if (mou_x > 478.0f && mou_x < 544.0f && mou_y>412.0f && mou_y < 478.0f)
		{
			if (mou_l == true)
			{
				//���ֈړ�
				if (map[22][22] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[19 + i][22 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[19 + i][22 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[22 + i][22 + j] = mem[i][j];
						}

					}
				}

				//���ֈړ�
				if (map[19][19] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[19 + i][22 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[19 + i][22 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[19 + i][19 + j] = mem[i][j];
						}

					}
				}

				//��ֈړ�
				if (map[16][22] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[19 + i][22 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[19 + i][22 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[16 + i][22 + j] = mem[i][j];
						}

					}
				}
			}
		}

		//8�i��

		//8�i�ڂ�1��(������)
		if (mou_x > 20.0f && mou_x < 88.0f && mou_y>474.0f && mou_y < 540.0f)
		{
			if (mou_l == true)
			{
				//�E�ֈړ�
				if (map[22][4] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[22 + i][1 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[22 + i][1 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[22 + i][4 + j] = mem[i][j];
						}

					}
				}

				//��ֈړ�
				if (map[19][1] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[22 + i][1 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[22 + i][1 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[19 + i][1 + j] = mem[i][j];
						}

					}
				}
			}


		}

		//8�i�ڂ�2��(������)
		if (mou_x > 86.0f && mou_x < 148.0f && mou_y>474.0f && mou_y < 540.0f)
		{
			if (mou_l == true)
			{
				//�E�ֈړ�
				if (map[22][7] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[22 + i][4 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[22 + i][4 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[22 + i][7 + j] = mem[i][j];
						}

					}
				}

				//���ֈړ�
				if (map[22][1] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[22 + i][4 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[22 + i][4 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[22 + i][1 + j] = mem[i][j];
						}

					}
				}

				//��ֈړ�
				if (map[19][4] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[22 + i][4 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[22 + i][4 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[19 + i][4 + j] = mem[i][j];
						}

					}
				}
			}


		}

		//8�i�ڂ�3��(������)
		if (mou_x > 150.0f && mou_x < 218.0f && mou_y>474.0f && mou_y < 540.0f)
		{
			if (mou_l == true)
			{
				//�E�ֈړ�
				if (map[22][10] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[22 + i][7 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[22 + i][7 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[22 + i][10 + j] = mem[i][j];
						}

					}
				}

				//���ֈړ�
				if (map[22][4] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[22 + i][7 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[22 + i][7 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[22 + i][4 + j] = mem[i][j];
						}

					}
				}

				//��ֈړ�
				if (map[19][7] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[22 + i][7 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[22 + i][7 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[19 + i][7 + j] = mem[i][j];
						}

					}
				}
			}


		}

		//8�i�ڂ�4��(������)
		if (mou_x > 216.0f && mou_x < 282.0f && mou_y>474.0f && mou_y < 540.0f)
		{
			if (mou_l == true)
			{
				//�E�ֈړ�
				if (map[22][13] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[22 + i][10 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[22 + i][10 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[22 + i][13 + j] = mem[i][j];
						}

					}
				}

				//���ֈړ�
				if (map[22][7] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[22 + i][10 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[22 + i][10 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[22 + i][7 + j] = mem[i][j];
						}

					}
				}

				//��ֈړ�
				if (map[19][10] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[22 + i][10 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[22 + i][10 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[19 + i][10 + j] = mem[i][j];
						}

					}
				}
			}


		}

		//8�i�ڂ�5��(������)
		if (mou_x > 280.0f && mou_x < 350.0f && mou_y>474.0f && mou_y < 540.0f)
		{
			if (mou_l == true)
			{
				//�E�ֈړ�
				if (map[22][16] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[22 + i][13 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[22 + i][13 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[22 + i][16 + j] = mem[i][j];
						}

					}
				}

				//���ֈړ�
				if (map[22][10] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[22 + i][13 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[22 + i][13 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[22 + i][10 + j] = mem[i][j];
						}

					}
				}

				//��ֈړ�
				if (map[19][13] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[22 + i][13 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[22 + i][13 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[19 + i][13 + j] = mem[i][j];
						}

					}
				}
			}


		}

		// 8�i�ڂ�6��(������)
		if (mou_x > 346.0f && mou_x < 414.0f && mou_y>474.0f && mou_y < 540.0f)
		{
			if (mou_l == true)
			{
				//�E�ֈړ�
				if (map[22][19] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[22 + i][16 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[22 + i][16 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[22 + i][19 + j] = mem[i][j];
						}

					}
				}

				//���ֈړ�
				if (map[22][13] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[22 + i][16 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[22 + i][16 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[22 + i][13 + j] = mem[i][j];
						}

					}
				}

				//��ֈړ�
				if (map[19][16] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[22 + i][16 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[22 + i][16 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[19 + i][16 + j] = mem[i][j];
						}

					}
				}
			}


		}

		// 8�i�ڂ�7��(������)
		if (mou_x > 410.0f && mou_x < 480.0f && mou_y>474.0f && mou_y < 540.0f)
		{
			if (mou_l == true)
			{
				//�E�ֈړ�
				if (map[22][22] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[22 + i][19 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[22 + i][19 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[22 + i][22 + j] = mem[i][j];
						}

					}
				}

				//���ֈړ�
				if (map[22][16] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[22 + i][19 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[22 + i][19 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[22 + i][16 + j] = mem[i][j];
						}

					}
				}

				//��ֈړ�
				if (map[19][19] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[22 + i][19 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[22 + i][19 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[19 + i][19 + j] = mem[i][j];
						}

					}
				}
			}


		}

		// 8�i�ڂ�8��(������)
		if (mou_x > 476.0f && mou_x < 544.0f && mou_y>474.0f && mou_y < 540.0f)
		{
			if (mou_l == true)
			{

				//���ֈړ�
				if (map[22][19] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[22 + i][22 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[22 + i][22 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[22 + i][19 + j] = mem[i][j];
						}

					}
				}

				//��ֈړ�
				if (map[19][22] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[22 + i][22 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[22 + i][22 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[19 + i][22 + j] = mem[i][j];
						}
					}
				}
			}
		}

		if (mou_l == true)
		{
			if (s_count == true)
			{
				Audio::Start(2);
				s_count = false;
			}
		}
		else
		{
			s_count = true;
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


					reset++;

					time->m_time = 7200;
					time->m_flag_time = true;

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
		Audio::Stop(0);
		s_r = false;
		if (mou_l == true)
		{
			player->battle = false;
			Scene::SetScene(new CSceneClear);

			if (player->HP ==5 && reset == 0)
			{
				((UserData*)Save::GetData())->Hperfect++;
			}
		}
	}

}


//�h���[
void CObjRoad4::Draw()
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

	if(player->battle==true)
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


		Font::StrDraw(L"����", 600, 300, 25, y);
	}
	//�\���F�ʍs��

	src.m_top = 90.0f;
	src.m_left = 331.0f;
	src.m_right = 377.0f;
	src.m_bottom = 125.0f;

	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < 26; j++)
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