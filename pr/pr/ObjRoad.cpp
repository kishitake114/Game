#include "ObjRoad.h"
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "GameHead.h" 
#include "GameL/WinInputs.h"
#include "GameL/HitBoxManager.h"


//�C�j�V�����C�Y
void CObjRoad::Init()
{
	mou_x = 0.0f;
	mou_y = 0.0f;
	mou_r = false;
	mou_l = false;

	p_x = 40;
	p_y = 40;
	p = 1;

	pxc = 0.0f;
	pyc = 0.0f;

	f_p = false;

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

}

//�A�N�V����
void CObjRoad::Action()
{
	mou_x = (float)Input::GetPosX();
	mou_y = (float)Input::GetPosY();
	mou_r = Input::GetMouButtonR();
	mou_l = Input::GetMouButtonL();

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

	//��A��
	if (pxc > 40.0f || pxc < 155.0f && pyc>40.0f || pyc < 155.0f)
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
				f_p = false;
				}

			}

		}

	}

	//��A�E
	if (pxc > 40.0f || pxc < 155.0f && pyc>156.0f || pyc < 273.0f)
	{
		if (mou_l == true)
		{
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
					f_p = false;
			}

			

		}
	}




		
	//���A��
	if (pxc > 156.0f || pxc < 273.0f && pyc>40.0f || pyc < 155.0f)
	{

	}

	//���A�E
	if (pxc > 156.0f || pxc < 273.0f && pyc>156.0f || pyc < 273.0f)
	{

	}


	
	if (mou_x > 600 && mou_x < 660 && mou_y > 40 && mou_y < 55)
	{
		if (mou_r == true)
		{
			Scene::SetScene(new CSceneClear());
		}
	}

}



//�h���[
void CObjRoad::Draw()
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

	swprintf_s(str, L"%d", p);
	Font::StrDraw(str, 600, 160, 20, c);

	//�E�N���b�N
	Font::StrDraw(L"�E=����", 600, 40, 20, c);

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
