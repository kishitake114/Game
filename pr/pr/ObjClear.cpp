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
	m_x = 170;
	m_y = 100;

	mou_x = 0.0f;
	mou_y = 0.0f;
	mou_r = false;
	mou_l = false;

	m_time = 0;
}

//�A�N�V����
void CObjClear::Action()
{
	mou_x = (float)Input::GetPosX();
	mou_y = (float)Input::GetPosY();
	mou_r = Input::GetMouButtonR();
	mou_l = Input::GetMouButtonL();

	if (m_y > -1300.0f)
	{
		m_y -= 3;
	}


	m_time++;



	if (m_time>=800)
	{
		if (mou_l == true)
		{
			Scene::SetScene(new CSceneTitle());
		}
	}
}

//�h���[
void CObjClear::Draw()
{

	//�`��J���[��� R=RED B=Biue A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	/*Font::StrDraw(L"GAME CLEAR!", 300, 200, 32, c);
	Font::StrDraw(L"���N���b�N�Ń^�C�g����ʂ�", 200, 400, 32, c);*/

	if (m_time >= 5)
	{
		Font::StrDraw(L"�����f�B���N�^�[�@�@�@�@�@�@�ݖ{�@��", 100, 600+m_y, 30, c);
	}

	if (m_time >= 15)
	{
		Font::StrDraw(L"�T�E���h�f�B���N�^�[�@�@�@�@��@����", 100, 645+ m_y, 30, c);
	}

	if (m_time >= 25)
	{
		Font::StrDraw(L"�f�U�C���f�B���N�^�[�@�@�@�@�с@�Y��", 100, 690 + m_y, 30, c);
	}

	if (m_time >= 35)
	{
		Font::StrDraw(L"�v�����i�[�f�B���N�^�[�@�|�V���@���n", 100, 735 + m_y, 30, c);
	}

	if (m_time >= 45)
	{
		Font::StrDraw(L"�v���O���}�f�B���N�^�[�@���ҁ@�Փl��", 100, 780 + m_y, 30, c);
	}

	if (m_time >= 500 && m_time<=700)
	{
		Font::StrDraw(L"�h���S���͓|���ꂽ�B", 100, 350, 20, c);
	}

	if(	((UserData*)Save::GetData())->Hperfect>=2)
	{
		if (m_time >= 700 )
		{
			Font::StrDraw(L"��ʂ̒[�������Ɖ������N����", 100, 350, 20, c);
		}
	}

	else
	{
		if (m_time >= 700)
		{
			Font::StrDraw(L"PERFECT�@��_���̂��I�I", 100, 350, 20, c);
		}
	}

	if (m_time >= 800)
	{
		Font::StrDraw(L"���N���b�N�Ń^�C�g���ɖ߂�", 100, 450, 30, c);
	}


	wchar_t str[256];

	swprintf_s(str, L"%d", m_time);
	Font::StrDraw(str, 0, 0, 30, c);

	swprintf_s(str, L"%f", m_y);
	Font::StrDraw(str, 0, 570, 30, c);


	//�\���F�^�C�g�����
	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 460.0f;
	src.m_bottom = 265.0f;

	dst.m_top = 1450.0f+m_y;
	dst.m_left = 100.0f;
	dst.m_right = 700.0f;
	dst.m_bottom = 1650.0f+m_y;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}
