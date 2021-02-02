//�g�p����w�b�_�[
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "GameL/SceneManager.h"
#include "ObjClear.h"
#include "GameHead.h" 
#include "GameL/WinInputs.h" 
#include "GameL/UserData.h"

using namespace GameL;

//�C�j�V�����C�Y
void CObjClear::Init()
{
	mou_x = 0.0f;
	mou_y = 0.0f;
	mou_r = false;
	mou_l = false;

	skip = false;
	cont = false;

	P = 0;

	pf = 0.0f;

	m_time = 0;
	sigo = 0;

	ed = false;

	((UserData*)Save::GetData())->Hperfect = 4;
}

//�A�N�V����
void CObjClear::Action()
{
	mou_x = (float)Input::GetPosX();
	mou_y = (float)Input::GetPosY();
	mou_r = Input::GetMouButtonR();
	mou_l = Input::GetMouButtonL();

	if (mou_r==true)
	{
		if (cont == false)
		{
			if (skip == false)
			{
				skip = true;
				cont = true;
			}
			else
			{
				Scene::SetScene(new CSceneTitle());
			}
		}
	
	}
	else
	{
		cont = false;
	}
	
	if(ed==false)
		m_time++;	

	if (ed == true)
	{
		m_time++;
	}

	if (m_time % 30 == 0)
		sigo++;

	if (ed==false&&m_time>480)
	{
		ed = true;
		m_time = 0;
	}
}

//�h���[
void CObjClear::Draw()
{
	RECT_F src;
	RECT_F dst;

	//�`��J���[��� R=RED B=Biue A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float r[4] = { 1.0f,0.0f,0.0f,1.0f };
	float g[4] = { 0.0f,1.0f,0.0f,1.0f };
	float b[4] = { 0.0f,0.0f,1.0f,1.0f };
	float y[4] = { 1.0f,1.0f,0.0f,1.0f };

	wchar_t str[256];

	if (ed == false)
	{
		if (m_time >= 60)
			Font::StrDraw(L"�������Ė��������X�^�[�𒦂炵�߁A���̏C�����I�����E�҂́A", 50, 125, 25, c);

		if (m_time >= 120)
			Font::StrDraw(L"�@�@�@�@�@���̏Z���݂̂�Ȃ��犴�ӂ���܂����B�@�@�@�@�@�@", 50, 200, 25, c);

		if (m_time >= 180)
			Font::StrDraw(L"�@�@�@�@�@�@�@�������čĂё��ɕ��a���K��,�@�@�@�@�@�@�@�@�@", 50, 275, 25, c);

		if (m_time >= 240)
			Font::StrDraw(L"�@�@�@�E�҂͉ƂɋA��Ƃ����Ȃ薰��ɂ����Ƃ�...�@�@�@ ", 50, 350, 25, c);

		if (m_time >= 300)
			Font::StrDraw(L"�@�@�@�@�@�@�@�@�@�@�@�����܂��I�@�@�@�@�@�@�@�@�@�@�@�@�@", 50, 425, 25, c);

	}
	else
	{
		if(m_time>=120&&m_time<=240)
		Font::StrDraw(L"STAFF CREDIT", 250, 310, 40, c);

		//�X�^�b�t�N���W�b�g�@�`�[��
		if (m_time >= 250 && m_time <= 470)
		{
			Font::StrDraw(L"�`�[��", 280, 80, 15, c);
			Font::StrDraw(L"�W�����P�����", 300, 100, 30, c);

			Font::StrDraw(L"�����f�B���N�^�[", 250, 150, 15, c);
			Font::StrDraw(L"�ݖ{�@��", 300, 170, 30, c);

			Font::StrDraw(L"�v�����i�[�f�B���N�^�[", 250, 220, 15, c);
			Font::StrDraw(L"�|�V���@���n", 300, 240, 30, c);

			Font::StrDraw(L"�v���O�����f�B���N�^�[", 250, 290, 15, c);
			Font::StrDraw(L"���ҁ@�Փl�j", 300, 310, 30, c);

			Font::StrDraw(L"�f�U�C���f�B���N�^�[", 250, 360, 15, c);
			Font::StrDraw(L"�с@�Y��", 300, 380, 30, c);

			Font::StrDraw(L"�T�E���h�f�B���N�^�[", 250, 430, 15, c);
			Font::StrDraw(L"��@����", 300, 450, 30, c);


		}

		//�X�^�b�t�N���W�b�g�@�\�t�g
		if (m_time >= 480 && m_time <= 700)
		{
			Font::StrDraw(L"�\�t�g", 325, 100, 30, c);

			Font::StrDraw(L"Visual Studio 2019", 250, 150, 30, c);

			Font::StrDraw(L"Git Hub", 250, 200, 30, c);

			Font::StrDraw(L"Power Point", 250, 250, 30, c);

			Font::StrDraw(L"Ward", 250, 300, 30, c);

			Font::StrDraw(L"Excel", 250, 350, 30, c);

			Font::StrDraw(L"Trello", 250, 400, 30, c);


		}

		//�X�^�b�t�N���W�b�g�@�X�y�V�����T���N�X����1
		if (m_time >= 710 && m_time <= 930)
		{
			Font::StrDraw(L"�X�y�V�����T���N�X", 250, 100, 30, c);

			Font::StrDraw(L"�T�|�[�g", 250, 200, 15, c);
			Font::StrDraw(L"�c���@��l", 300, 220, 30, c);
			Font::StrDraw(L"�搶", 450, 240, 20, c);

			Font::StrDraw(L"�A�h�o�C�X", 250, 290, 15, c);
			Font::StrDraw(L"�ؑ��@�s�u", 300, 310, 30, c);
			Font::StrDraw(L"�搶", 450, 330, 20, c);
		}

		//�X�^�b�t�N���W�b�g�@�X�y�V�����T���N�X����2
		if (m_time >= 940 && m_time <= 1160)
		{
			Font::StrDraw(L"�X�y�V�����T���N�X", 250, 100, 30, c);
			Font::StrDraw(L"�@ �e�X�g�v���C", 250, 140, 30, c);

			Font::StrDraw(L"��i�@��", 200, 200, 25, c);

			Font::StrDraw(L"��{�@�I��", 500, 200, 25, c);

			Font::StrDraw(L"��c�@�Ύ�", 200, 240, 25, c);

			Font::StrDraw(L"���J�@����", 500, 240, 25, c);

			Font::StrDraw(L"�����@�F��", 200, 280, 25, c);

			Font::StrDraw(L"�c���@���", 500, 280, 25, c);

			Font::StrDraw(L"�x�i�@���l", 200, 320, 25, c);

			Font::StrDraw(L"���@���@�D��", 500, 320, 25, c);

			Font::StrDraw(L"�i���@�D�l", 200, 360, 25, c);

			Font::StrDraw(L"���c�@����", 500, 360, 25, c);

			Font::StrDraw(L"�{�R�@�C��", 200, 400, 25, c);

			Font::StrDraw(L"�R���@�^�D", 500, 400, 25, c);

			Font::StrDraw(L"�R�c�@�ːl", 200, 440, 25, c);
		}
		if (m_time >= 1170)
		{
			if (((UserData*)Save::GetData())->Hperfect == 4)
			{
				


			}
			
			else
			{
				Font::StrDraw(L"END", 350, 235, 50, c);
			}
		}

	}
	
	Font::StrDraw(L"PERFECT!!", 275, 185, 50, y);

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 45.0f;
	src.m_bottom = 45.0f;

	dst.m_top = 230.0f;
	dst.m_left = 350.0f;
	dst.m_right = 400.0f;
	dst.m_bottom = 280.0f;

	Draw::Draw(1, &src, &dst, c, 0.0f);

	Font::StrDraw(L"YOU ARE SUPER PLAYER!!", 100, 285, 50, y);

	if (skip == true)
	{
		if(sigo%2==0)
		Font::StrDraw(L"�E�N���b�N�Ń^�C�g���֖߂� ", 530, 0, 18, c);
	}

	//�\���F�^�C�g�����


	src.m_top = 128.0f;
	src.m_left = 0.0f;
	src.m_right = 512.0f;
	src.m_bottom = 380.0f;
	if (ed == true && m_time >= 120 && m_time < 240)
	{
		dst.m_top = 100.0f;
		dst.m_left = 200.0f;
		dst.m_right = 600.0f;
		dst.m_bottom = 300.0f;

		Draw::Draw(0, &src, &dst, c, 0.0f);

	}
}
	
