//�g�p����w�b�_�[�t�@�C��
#include "ObjStage5.h"
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
//�A�N�V����
void CObjStage5::Action()
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

		//1���1�}�X��
		if (mou_x > 20.0f && mou_x < 80.0f && mou_y>20.0f && mou_y < 80.0f)
		{

			if (mou_l == true)
			{
				//�P��ځi�P�}�X�ځj���i�E�j1�}�X�ړ��@
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

				//�P��ځi�P�}�X�ځj���i���j1�}�X�ړ��@
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




		//1��ڂQ�}�X�� 
		if (mou_x > 80.0f && mou_x < 140.0f && mou_y>.0f && mou_y < 80.0f)
		{
			if (mou_l == true)
			{
				//�P��ځi2�}�X�ځj���i���j1�}�X�ړ��@
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

				//�P��ځi2�}�X�ځj���i���j1�}�X�ړ��@
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

				//�P��ځi2�}�X�ځj���i�E�j1�}�X�ړ��@
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


		//1��ځi3�}�X�ځj
		if (mou_x > 140.0f && mou_x < 200.0f && mou_y>20.0f && mou_y < 80.0f)
		{
			if (mou_l == true)
			{

				//�i�R�}�X�ځj���i���j1�}�X�ړ�
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
				//�P��ځi�R�}�X�ځj���i���j1�}�X�ړ�
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
				//�P��ځi�R�}�X�ځj���i�E�j1�}�X�ړ�
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

		//1��ڂS�}�X��
		if (mou_x > 200.0f && mou_x < 260.0f && mou_y>20.0f && mou_y < 80.0f)
		{
			if (mou_l == true)
			{

				//�P��ځi�S�}�X�ځj���i���j1�}�X�ړ�
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
				//�P��ځi�S�}�X�ځj���i���j1�}�X�ړ�
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
				//�P���(4�}�X�ځj���i�E�j1�}�X�ړ�
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

		//2���
		if (mou_x > 20.0f && mou_x < 80.0f && mou_y>80.0f && mou_y < 140.0f)
		{
			if (mou_l == true)
			{
				//2��ځi�P�}�X�ځj���i��j1�}�X�ړ�
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

				//2��ځi�P�}�X�ځj���i�E�j1�}�X�ړ�
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

				//2��ځi�P�}�X�ځj���i���j1�}�X�ړ�
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

		//2��ځi2�}�X�ځj
		if (mou_x > 80.0f && mou_x < 140.0f && mou_y>140.0f && mou_y < 200.0f)
		{
			if (mou_l == true)
			{
				//2��ځi2�}�X�ځj���i���j1�}�X�ړ�
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

				//2��ځi2�}�X�ځj���i��j1�}�X�ړ�
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

				//2��ځi2�}�X�ځj���i�E�j1�}�X�ړ�
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

				//2��ځi2�}�X�ځj���i���j1�}�X�ړ�
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


		//2��ځi3�}�X�ځj
		if (mou_x > 140.0f && mou_x < 200.0f && mou_y>80.0f && mou_y < 140.0f)
		{
			if (mou_l == true)
			{
				//2��ځi3�}�X�ځj���i���j1�}�X�ړ�
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

				//2��ځi3�}�X�ځj���i��j1�}�X�ړ�
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

				//2��ځi3�}�X�ځj���i�E�j1�}�X�ړ�
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

				//2��ځi3�}�X�ځj���i���j1�}�X�ړ�
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

		//2��ځi4�}�X�ځj
		if (mou_x > 200.0f && mou_x < 260.0f && mou_y>80.0f && mou_y < 140.0f)
		{
			if (mou_l == true)
			{
				//2��ځi4�}�X�ځj���i���j1�}�X�ړ�
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

				//2��ځi4�}�X�ځj���i��j1�}�X�ړ�
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

				//2��ځi4�}�X�ځj���i���j1�}�X�ړ�
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
				//2��ځi4�}�X�ځj���i�E�j1�}�X�ړ�
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

		//3���
		if (mou_x > 20.0f && mou_x < 80.0f && mou_y>140.0f && mou_y < 200.0f)
		{
			if (mou_l == true)
			{
				//3��ځi�P�}�X�ځj���i��j1�}�X�ړ�
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

				//3��ځi�P�}�X�ځj���i�E�j1�}�X�ړ�
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

				//3��ځi�P�}�X�ځj���i���j1�}�X�ړ�
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

		//3��ځi2�}�X�ځj
		if (mou_x > 80.0f && mou_x < 140.0f && mou_y>274.0f && mou_y < 394.0f)
		{
			if (mou_l == true)
			{
				//3��ځi2�}�X�ځj���i���j1�}�X�ړ�
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

				//3��ځi2�}�X�ځj���i��j1�}�X�ړ�
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

				//3��ځi2�}�X�ځj���i�E�j1�}�X�ړ�
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

				//3��ځi2�}�X�ځj���i���j1�}�X�ړ�
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

		//3��ځi3�}�X�ځj
		if (mou_x > 274.0f && mou_x < 393.0f && mou_y>274.0f && mou_y < 394.0f)
		{
			if (mou_l == true)
			{
				//3��ځi3�}�X�ځj���i���j1�}�X�ړ�
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

				//3��ځi3�}�X�ځj���i��j1�}�X�ړ�
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

				//3��ځi3�}�X�ځj���i�E�j1�}�X�ړ�
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

				//3��ځi3�}�X�ځj���i���j1�}�X�ړ�
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

		//3��ځi4�}�X�ځj
		if (mou_x > 394.0f && mou_x < 520.0f && mou_y>274.0f && mou_y < 394.0f)
		{
			if (mou_l == true)
			{
				//3��ځi4�}�X�ځj���i���j1�}�X�ړ�
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

				//3��ځi4�}�X�ځj���i��j1�}�X�ړ�
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

				//3��ځi4�}�X�ځj���i���j1�}�X�ړ�
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

		//4���
		if (mou_x > 40.0f && mou_x < 155.0f && mou_y>394.0f && mou_y < 520.0f)
		{
			if (mou_l == true)
			{
				//4��ځi�P�}�X�ځj���i��j1�}�X�ړ�
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

				//4��ځi�P�}�X�ځj���i�E�j1�}�X�ړ�
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

		//4��ځi2�}�X�ځj
		if (mou_x > 156.0f && mou_x < 273.0f && mou_y>394.0f && mou_y < 520.0f)
		{
			if (mou_l == true)
			{
				//4��ځi2�}�X�ځj���i���j1�}�X�ړ�
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

				//4��ځi2�}�X�ځj���i��j1�}�X�ړ�
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

				//4��ځi2�}�X�ځj���i�E�j1�}�X�ړ�
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


		//4��ځi3�}�X�ځj
		if (mou_x > 274.0f && mou_x < 393.0f && mou_y> 394.0f && mou_y < 520.0f)
		{
			if (mou_l == true)
			{
				//4��ځi3�}�X�ځj���i���j1�}�X�ړ�
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


				//4��ځi3�}�X�ځj���i��j1�}�X�ړ�
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

				//4��ځi3�}�X�ځj���i�E�j1�}�X�ړ�
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

		//4��ځi4�}�X�ځj
		if (mou_x > 394.0f && mou_x < 520.0f && mou_y>394.0f && mou_y < 520.0f)
		{
			if (mou_l == true)
			{
				//4��ځi4�}�X�ځj���i���j1�}�X�ړ�
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

				//4��ځi4�}�X�ځj���i��j1�}�X�ړ�
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

		//5��ڂ�1�s��
		if (mou_l=true)
		{

			//��ɂP�}�X
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
			//�E�ɂP�}�X
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
			//���ɂP�}�X
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
	    //5��ڂ�2�s��
		if (mou_l = true)
		{
			//���1�}�X
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
			//�E��1�}�X
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
			//����1�}�X
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
			//����1�}�X
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
		//5�s�ڂ�3���
		if (mou_l = true)
		{
			//���1�}�X
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
			//�E��1�}�X
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
			//����1�}�X
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
			//����1�}�X
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
		//5�s�ڂ�4���
		if (mou_l = true)
		{
			//���1�}�X
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
			//�E��1�}�X
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
			//����1�}�X
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
			//����1�}�X
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
		//5�s�ڂ�5���
		if (mou_l = true)
		{
			//���1�}�X
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
			//�E��1�}�X
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
			//����1�}�X
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
			//����1�}�X
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
		//5�s�ڂ�6���

		CHitBox* hit = Hits::GetHitBox(this);
		hit->SetPos(pv_x, pv_y);
	}	
}
//�h���[
void CObjStage5::Draw()
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

	//�\���F�ʍs�s��

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