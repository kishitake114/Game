//�g�p����w�b�_�[�t�@�C��
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "GameL/WinInputs.h"
#include "GameL/SceneManager.h"
#include "GameHead.h"
#include "ObjTitle.h"
#include "GameL/UserData.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjTitle::Init()
{
	mou_x = 0.0f;
	mou_y = 0.0f;
	mou_r = false;
	mou_l = false;

	lup = false;
	rup = false;
	ldown = false;
	rdown = false;

	title = 0;

	hard = false;
	story = true;

	static bool init_point = false;
	if (init_point == false)
	{
		((UserData*)Save::GetData())->Hperfect = 0;
		((UserData*)Save::GetData())->EXperfect = 0;
		init_point = true;
	}

	Hcount=((UserData*)Save::GetData())->Hperfect;

}
//�A�N�V����
void CObjTitle::Action()
{
	mou_x = (float)Input::GetPosX();
	mou_y = (float)Input::GetPosY();
	mou_r = Input::GetMouButtonR();
	mou_l = Input::GetMouButtonL();

	if (story == false)
	{



		//if(((UserData*)Save::GetData())->Hperfect >= 2)
		//{
		//	if (mou_x > 0 && mou_x < 50 && mou_y > 0 && mou_y < 50)
		//	{
		//		if (mou_l == true)
		//		{
		//			lup = true;
		//		}
		//	}

		//	if (mou_x > 750 && mou_x < 800 && mou_y > 0 && mou_y < 50)
		//	{
		//		if (mou_l == true)
		//		{
		//			rup = true;
		//		}
		//	}

		//	if (mou_x > 0 && mou_x < 50 && mou_y > 550 && mou_y < 600)
		//	{
		//		if (mou_l == true)
		//		{
		//			ldown = true;
		//		}
		//	}

		//	if (mou_x > 750 && mou_x < 800 && mou_y > 550 && mou_y < 600)
		//	{
		//		if (mou_l == true)
		//		{
		//			rdown = true;
		//		}
		//	}

		//	if (lup == true && rup == true && ldown == true && rdown == true)
		//	{
		//		hard = true;
		//		title = 1;
		//	}
		//}


		if (mou_x > 161 && mou_x < 629 && mou_y > 391 && mou_y < 423)
		{

			if (mou_l == true)
			{
				Scene::SetScene(new CSceneRule());
				((UserData*)Save::GetData())->Hperfect = 0;
			}
		}

		if (mou_x > 161 && mou_x < 629 && mou_y > 441 && mou_y < 473)
		{
			if (hard == true)
			{
				if (mou_l == true)
				{
					Scene::SetScene(new CSceneRule2());
				}
			}
		}
	}
}
//�h���[
void CObjTitle::Draw()
{
	
	//�`��J���[��� R=RED B=Biue A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float r[4] = { 0.3f,0.3f,0.3f,1.0f };

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
		src.m_right = 512.0f;
		src.m_bottom = 512.0f;

		dst.m_top = 0.0f;
		dst.m_left = 0.0f;
		dst.m_right = 800.0f;
		dst.m_bottom = 600.0f;

		Draw::Draw(title, &src, &dst, c, 0.0f);

}