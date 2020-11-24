//�g�p����w�b�_�[
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "GameL/SceneManager.h"
#include "ObjClear.h"
#include "GameHead.h" 
#include "GameL/WinInputs.h" 

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

	m_y -= 3;

	m_time++;

	//if (mou_x > 200 && mou_x < 629 && mou_y > 391 && mou_y < 423)
	//{
	//	if (mou_l == true)
	//	{
	//		Scene::SetScene(new CSceneTitle());
	//	}
	//}
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




	//�\���F�^�C�g�����
	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 460.0f;
	src.m_bottom = 265.0f;

	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 450.0f;
	dst.m_bottom = 200.0f;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}
