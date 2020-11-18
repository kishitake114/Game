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

	//�P�i��
	if (mou_x > 22 && mou_x < 550 && mou_y>22 && mou_y < 88)
	{
		//�P�s��[1][1]
		if (mou_x > 22 && mou_x < 88 && mou_y>22 && mou_y < 88)
		{
			if (mou_l == true)
			{
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
			
		//�Q�s��[1][4]
		if (mou_x > 88.0f && mou_x < 154.0f && mou_y>22.0f && mou_y < 88.0f)
		{
			if (mou_l == true)
			{
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

		//�R�s��[1][7]
		if (mou_x > 154.0f && mou_x < 220.0f && mou_y>22.0f && mou_y < 88.0f)
		{
			if (mou_l == true)
			{
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
		//1�i��4�s��
		if (mou_x > 246.0f && mou_x < 321.0f && mou_y>25.0f && mou_y < 97.0f)
		{
			if (mou_l == true)
			{



			}
		}
		//1�i��5�s��
		if (mou_x > 321.0f && mou_x < 394.0f && mou_y>25.0f && mou_y < 97.0f)
		{
			if (mou_l == true)
			{



			}
		}
		//1�i��6�s��
		if (mou_x > 394.0f && mou_x < 467.0f && mou_y>25.0f && mou_y < 97.0f)
		{
			if (mou_l == true)
			{



			}
		}


		//2�i��

		//2�i��1�s��
		if (mou_x > 25.0f && mou_x < 97.0f && mou_y>97.0f && mou_y < 173.0f)
		{
			if (mou_l == true)
			{



			}
		}
		//2�i��2�s��
		if (mou_x > 98.0f && mou_x < 173.0f && mou_y>97.0f && mou_y < 173.0f)
		{
			if (mou_l == true)
			{



			}
		}
		//2�i��3�s��
		if (mou_x > 173.0f && mou_x < 246.0f && mou_y>97.0f && mou_y < 173.0f)
		{
			if (mou_l == true)
			{



			}
		}
		//2�i��4�s��
		if (mou_x > 246.0f && mou_x < 321.0f && mou_y>97.0f && mou_y < 173.0f)
		{
			if (mou_l == true)
			{



			}
		}
		//2�i��5�s��
		if (mou_x > 321.0f && mou_x < 394.0f && mou_y>97.0f && mou_y < 173.0f)
		{
			if (mou_l == true)
			{



			}
		}
		//2�i��6�s��
		if (mou_x > 394.0f && mou_x < 467.0f && mou_y>97.0f && mou_y < 173.0f)
		{
			if (mou_l == true)
			{



			}
		}

		//3�i��


		//3�i��1�s��
		if (mou_x > 25.0f && mou_x < 97.0f && mou_y>173.0f && mou_y < 246.0f)
		{
			if (mou_l == true)
			{



			}
		}
		//3�i��2�s��
		if (mou_x > 98.0f && mou_x < 173.0f && mou_y>173.0f && mou_y < 246.0f)
		{
			if (mou_l == true)
			{



			}
		}
		//3�i��3�s��
		if (mou_x > 173.0f && mou_x < 246.0f && mou_y>173.0f && mou_y < 246.0f)
		{
			if (mou_l == true)
			{



			}
		}
		//3�i��4�s��
		if (mou_x > 246.0f && mou_x < 321.0f && mou_y>173.0f && mou_y < 246.0f)
		{
			if (mou_l == true)
			{



			}
		}
		//3�i��5�s��
		if (mou_x > 321.0f && mou_x < 394.0f && mou_y>173.0f && mou_y < 246.0f)
		{
			if (mou_l == true)
			{



			}
		}
		//3�i��6�s��
		if (mou_x > 394.0f && mou_x < 467.0f && mou_y>173.0f && mou_y < 246.0f)
		{
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
			}
		}


		//4�i��


		//4�i��1�s��
		if (mou_x > 25.0f && mou_x < 97.0f && mou_y>246.0f && mou_y < 321.0f)
		{
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
			}
		}
		//4�i��2�s��
		if (mou_x > 98.0f && mou_x < 173.0f && mou_y>246.0f && mou_y < 321.0f)
		{
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
			}
		}
		//4�i��3�s��
		if (mou_x > 173.0f && mou_x < 246.0f && mou_y>246.0f && mou_y < 321.0f)
		{
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
			}
		}
		//4�i��4�s��
		if (mou_x > 246.0f && mou_x < 321.0f && mou_y>246.0f && mou_y < 321.0f)
		{
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
			}
		}
		//4�i��5�s��
		if (mou_x > 321.0f && mou_x < 394.0f && mou_y>246.0f && mou_y < 321.0f)
		{
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
			}
		}
		//4�i��6�s��
		if (mou_x > 394.0f && mou_x < 467.0f && mou_y>246.0f && mou_y < 321.0f)
		{
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
			}
		}
		//5�i��2�s��
		if (mou_x > 98.0f && mou_x < 173.0f && mou_y>321.0f && mou_y < 394.0f)
		{
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
			}
		}
		//5�i��3�s��
		if (mou_x > 173.0f && mou_x < 246.0f && mou_y>321.0f && mou_y < 394.0f)
		{
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
			}
		}
		//5�i��4�s��
		if (mou_x > 246.0f && mou_x < 321.0f && mou_y>321.0f && mou_y < 394.0f)
		{
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
			}
		}
		//5�i��5�s��
		if (mou_x > 321.0f && mou_x < 394.0f && mou_y>321.0f && mou_y < 394.0f)
		{
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

			}
		}
		//5�i��6�s��
		if (mou_x > 394.0f && mou_x < 467.0f && mou_y>321.0f && mou_y < 394.0f)
		{
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
			}
		}
		//6�i��2�s��
		if (mou_x > 98.0f && mou_x < 173.0f && mou_y>394.0f && mou_y < 467.0f)
		{
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
			}
		}
		//6�i��3�s��
		if (mou_x > 173.0f && mou_x < 246.0f && mou_y>394.0f && mou_y < 467.0f)
		{
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
			}
		}
		//6�i��4�s��
		if (mou_x > 246.0f && mou_x < 321.0f && mou_y>394.0f && mou_y < 467.0f)
		{
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
			}
		}
		//6�i��5�s��
		if (mou_x > 321.0f && mou_x < 394.0f && mou_y>394.0f && mou_y < 467.0f)
		{
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
			}
		}
		//6�i��6�s��
		if (mou_x > 394.0f && mou_x < 467.0f && mou_y>394.0f && mou_y < 467.0f)
		{
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