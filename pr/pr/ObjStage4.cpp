//�g�p����w�b�_�[�t�@�C��
#include "ObjStage4.h"
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
void CObjStage4::Init()
{

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

	int mapdata[26][26] =
	{
		{0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0},
	    {0,1,2,1,0,0,0,1,2,1,1,1,1,1,2,1,1,1,1,1,2,1,1,2,1,0},
	    {2,1,2,2,0,0,0,1,2,1,1,2,2,2,2,1,2,2,1,1,2,2,2,2,2,2},
	    {0,1,1,1,0,0,0,1,2,1,1,2,1,1,1,1,1,2,1,1,2,1,1,2,1,0},
	    {0,1,1,1,1,1,1,1,2,1,1,2,1,1,1,1,1,2,1,1,2,1,1,1,1,0},
	    {2,2,2,2,2,2,1,1,2,2,1,2,1,1,2,2,2,2,2,2,2,1,2,2,2,2},
	    {0,1,2,1,1,2,1,1,1,1,1,2,1,1,2,1,1,1,1,1,2,1,1,2,1,0},
	    {0,1,1,1,1,2,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,2,1,0},
	    {2,2,2,2,2,2,2,2,2,1,2,2,2,2,2,1,2,2,2,1,2,2,1,2,1,2},
	    {0,1,1,1,1,2,1,1,2,1,1,2,1,1,2,1,1,1,1,1,2,1,1,2,1,0},
	    {0,1,2,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,2,1,0},
	    {2,1,2,2,1,2,1,2,2,2,2,2,1,2,2,2,2,2,2,2,2,1,1,2,1,2},
	    {0,1,1,1,1,2,1,1,1,1,1,2,1,1,2,1,1,1,1,1,1,1,1,2,1,0},
	    {0,1,2,1,1,2,1,1,2,1,1,2,1,1,2,1,1,1,1,1,1,1,1,2,1,0},
	    {2,2,2,2,2,2,1,1,2,2,2,2,1,1,2,1,2,2,2,2,2,1,2,2,2,2},
	    {0,1,2,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,2,1,1,1,1,0},
	    {0,1,2,1,1,1,1,1,2,1,1,2,1,1,1,1,1,2,1,1,2,1,1,1,1,0},
	    {2,1,2,1,2,2,2,2,2,1,2,2,2,1,2,2,2,2,1,1,2,2,2,2,1,2},
	    {0,1,2,1,1,1,1,1,1,1,1,1,1,1,2,1,1,2,1,1,2,1,1,2,1,0},
	    {0,1,1,1,1,2,1,1,2,1,1,2,1,1,1,1,1,1,1,1,2,1,1,2,1,0},
	    {2,2,2,1,1,2,2,2,2,1,2,2,2,1,2,2,2,2,2,1,2,1,2,2,2,2},
	    {0,1,2,1,1,2,1,1,1,1,1,2,1,1,2,1,1,1,1,1,2,1,1,1,1,0},
	    {0,1,2,1,1,1,1,1,2,1,1,2,1,1,2,1,1,1,1,1,2,1,1,1,1,0},
	    {2,1,2,1,2,2,1,2,2,2,1,2,2,1,2,1,2,2,2,2,2,2,2,2,2,2},
	    {0,1,2,1,1,2,1,1,2,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,0},
	    {0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0},

	};

	memcpy(map, mapdata, sizeof(int) * (26 * 26));

	int mem[3][3] =
	{
		{0,0,0},
		{0,0,0},
		{0,0,0},
	};
}
//�A�N�V����
void CObjStage4::Action()
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
							map[10 + i][17 + j] = mem[i][j];
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
	
}


//�h���[
void CObjStage4::Draw()
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

	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < 26; j++)
		{

			if (map[i][j] == 2)
			{
				dst.m_top = i * 22.0f;
				dst.m_left = j * 22.0f;
				dst.m_right = dst.m_left + 22.0f;
				dst.m_bottom = dst.m_top + 22.0f;

				Draw::Draw(0, &src, &dst, c, 0.0f);
			}

		}
	}

	//�\���F�ʍs�s��

	src.m_top = 90.0f;
	src.m_left = 0.0f;
	src.m_right = 45.0f;
	src.m_bottom = 125.0f;

	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (map[i][j] == 1)
			{
				dst.m_top = i * 22.0f;
				dst.m_left = j * 22.0f;
				dst.m_right = dst.m_left + 22.0f;
				dst.m_bottom = dst.m_top + 22.0f;

				Draw::Draw(0, &src, &dst, c, 0.0f);

			}
		}
	}
}