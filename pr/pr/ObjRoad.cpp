#include "ObjRoad.h"
#include "ObjPlayer.h"
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "GameHead.h" 
#include "GameL/WinInputs.h"
#include "GameL/HitBoxManager.h"
#include "GameL/SceneObjManager.h"


//�C�j�V�����C�Y
void CObjRoad::Init()
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


//
//		int mapdata[14][14] =
//	{
//{0,0,2,0,0,2,0,0,2,0,0,2,0,0},
//{0,1,2,1,1,2,1,1,1,1,1,1,1,0},
//{2,2,2,2,1,2,1,2,2,1,2,2,2,2},
//{0,1,2,1,1,2,1,1,2,1,1,1,1,0},
//{0,1,2,1,1,2,1,1,1,1,1,1,1,0},
//{2,1,2,1,2,2,2,2,2,1,1,2,2,2},
//{0,1,2,1,1,2,1,1,2,1,1,2,1,0},
//{0,1,1,1,1,2,1,1,2,1,1,2,1,0},
//{2,2,2,2,1,2,2,2,2,2,2,2,1,2},
//{0,1,1,1,1,1,1,1,2,1,1,1,1,0},
//{0,1,1,1,0,0,0,1,2,1,1,1,1,0},
//{2,2,2,2,0,0,0,1,2,1,2,2,2,2},
//{0,1,1,1,0,0,0,1,2,1,1,1,1,0},
//{0,0,2,0,0,2,0,0,2,0,0,2,0,0},
//	};
//
//	memcpy(map, mapdata, sizeof(int) * (14 * 14));

	int alfhamap[8][8] =
	{
		{0,0,2,0,0,2,0,0,},
		{0,1,2,1,1,2,1,0,},
		{2,2,2,2,1,2,1,2,},
		{0,1,2,1,1,2,1,0,},
		{0,1,1,1,0,0,0,0,},
		{2,2,2,2,0,0,0,2,},
		{0,1,1,1,0,0,0,0,},
		{0,0,2,0,0,2,0,0,},
	};

	memcpy(map, alfhamap, sizeof(int) * (8 * 8));

		int mem[3][3] =
		{
			{0,0,0},
			{0,0,0},
			{0,0,0},
		};

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if(map[i][j]==1)
				Hits::SetHitBox(this, i * 40, j * 40, 40, 40, ELEMENT_GREEN, OBJ_NO_ROAD, 1);
			}
		}

}

//�A�N�V����
void CObjRoad::Action()
{
	CObjPlayer* player = (CObjPlayer*)Objs::GetObj(OBJ_PLAYER);

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





		//���A��
		if (mou_x > 40.0f && mou_x < 155.0f && mou_y>156.0f && mou_y < 273.0f)
		{
			if (mou_l == true)
			{
				//���A��->��A��
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
							pv_y += 120;
						}
					}
				}

				//���A��->���A�E
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
							pv_x = 120;
						}
					}
				}
			}
		}

		//���A�E
		if (mou_x > 156.0f && mou_x < 273.0f && mou_y>156.0f && mou_y < 273.0f)
		{
			if (mou_l == true)
			{
				//���A�E>���A��
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
							pv_x = -120;
						}
					}

				}
				//���A�E->��A�E
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
							pv_y = 120;
						}
					}
				}
			}

					CHitBox* hit = Hits::GetHitBox(this);
					hit->SetPos(pv_x,pv_y);

		}

	}

			if (mou_l == true)
			{
				s_r = true;
				sei = false;
			}
	
}



//�h���[
void CObjRoad::Draw()
{

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float r[4] = { 1.0f,0.0f,0.0f,1.0f };
	float g[4] = { 0.0f,1.0f,0.0f,1.0f };
	float b[4] = { 0.0f,0.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	//�\���F�}�E�X�J�[�\���ƃ{�^��
	wchar_t str[256];

	swprintf_s(str, L"x=%f,y=%f", pxc, pyc);
	Font::StrDraw(str, 600, 20, 15, c);

	swprintf_s(str, L"x=%f,y=%f", mou_x, mou_y);
	Font::StrDraw(str, 600, 10, 15, c);

	if (s_r == true)
	{
		Font::StrDraw(L"�E�N���b�N�ŃL�[�{�[�h����", 500, 60, 20, r);
	}
	else
	{
		Font::StrDraw(L"OFF", 500, 60, 20, c);
	}


	//�E�N���b�N
	if (s_r == true)
	{
		Font::StrDraw(L"Road", 600, 40, 20, r);
		Font::StrDraw(L"����\n �}�E�X", 550, 300, 20, r);
	}

	//�\���F�ʍs��


	src.m_top = 90.0f;
	src.m_left = 45.0f;
	src.m_right = 85.0f;
	src.m_bottom = 125.0f;
	
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{

			if (map[i][j] == 2)
			{
				dst.m_top = i * 40.0f;
				dst.m_left = j * 40.0f;
				dst.m_right = dst.m_left + 40.0f;
				dst.m_bottom = dst.m_top + 40.0f;

				Draw::Draw(0, &src, &dst, c, 0.0f);
			}

		}
	}

	//�\���F�ʍs�s��

	src.m_top = 90.0f;
	src.m_left = 0.0f;
	src.m_right = 45.0f;
	src.m_bottom = 125.0f;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (map[i][j] == 1)
			{
				dst.m_top = i * 40.0f;
				dst.m_left = j * 40.0f;
				dst.m_right = dst.m_left + 40.0f;
				dst.m_bottom = dst.m_top + 40.0f;

				Draw::Draw(0, &src, &dst, c, 0.0f);

			}
		}
	}

}
