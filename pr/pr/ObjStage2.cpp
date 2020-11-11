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

	for (int i = 0; i < 17; i++)
	{
		for (int j = 0; j < 17; j++)
		{
			if (map[i][j] == 1)
				Hits::SetHitBox(this, i * 40, j * 40, 40, 40, ELEMENT_GREEN, OBJ_NO_ROAD, 1);
		}
	}
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


		//��A��
		if (mou_x > 40.0f && mou_x < 155.0f && mou_y>40.0f && mou_y < 155.0f)
		{
			if (mou_l == true)
			{
				//��A��->��A�E
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
							pv_x = 120;
						}
					}

				}

				//��A��->���A��
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
							pv_y = -120;
						}
					}

				}
			}

			//��A�E
			if (mou_x > 156.0f && mou_x < 273.0f && mou_y>40.0f && mou_y < 155.0f)
			{
				if (mou_l == true)
				{
					//��A�E->���A�E
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
								pv_y = -120.0f;
							}
						}

					}

					//��A�E->��A��
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
								pv_x = -120.0f;
							}
						}

					}



				}
			}
			//���ォ�牺�ɓ��
			if (mou_x > 40.0f && mou_x < 155.0f && mou_y>80.0f && mou_y < 195.0f)
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
						pv_y = -240;
					}
				}
			}



			//�E����2
			if (mou_x > 480.0f && mou_x < 600.0f && mou_y>480.0f && mou_y < 600.0f)
			{
				if (mou_l == true)
				{
					//�E����2���E��
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
								pv_y = -480;
							}
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