//�g�p����w�b�_�[�t�@�C��
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "GameL/WinInputs.h"
#include "GameL/SceneManager.h"
#include "GameHead.h"
#include "ObjTitle.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjTitle::Init()
{
	m_x = 170;
	m_y = 100;

	mou_x = 0.0f;
	mou_y = 0.0f;
	mou_r = false;
	mou_l = false;
}
//�A�N�V����
void CObjTitle::Action()
{
	
	mou_x = (float)Input::GetPosX();
	mou_y = (float)Input::GetPosY();
	mou_r = Input::GetMouButtonR();
	mou_l = Input::GetMouButtonL();

	if (mou_x > 161 && mou_x < 629 && mou_y > 391 && mou_y < 423)
	{
		if (mou_l == true)
		{
			Scene::SetScene(new CSceneRule());
		}
	}

	

}
//�h���[
void CObjTitle::Draw()
{
	//�`��J���[��� R=RED B=Biue A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"���N���b�N�ő���E���[��������", 160, 400, 32, c);

	//�\���F�}�E�X�J�[�\���ƃ{�^��
	wchar_t str[256];
	swprintf_s(str, L"x=%f,y=%f", mou_x, mou_y);
	Font::StrDraw(str, 50, 20, 15, c);

	//�E�N���b�N
	if (mou_r == true)
		Font::StrDraw(L"�E=�����Ă�", 50, 40, 20, c);
	else
		Font::StrDraw(L"�E=�����ĂȂ�", 50, 40, 20, c);

	//���N���b�N
	if (mou_l == true)
		Font::StrDraw(L"��=�����Ă�", 50, 60, 20, c);
	else
		Font::StrDraw(L"��=�����ĂȂ�", 50, 60, 20, c);

	//�\���F�^�C�g�����
	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 460.0f;
	src.m_bottom = 265.0f;

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 450.0f + m_x;
	dst.m_bottom = 200.0f + m_y;

	Draw::Draw(0, &src, &dst, c, 0.0f);

}