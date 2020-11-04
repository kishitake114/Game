//�g�p����w�b�_�[�t�@�C��
#include "ObjStage3.h"
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
}
//�A�N�V����
void CObjStage3::Action()
{

}
//�h���[
void CObjStage3::Draw()
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

	//�\���F�ʍs�s��

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