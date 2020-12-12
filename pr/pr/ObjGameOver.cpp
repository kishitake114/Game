//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL/DrawTexture.h"
#include "GameL/WinInputs.h"
#include "GameL/UserData.h"

#include "GameHead.h"
#include "ObjGameOver.h"

#include <stdlib.h>
#include <time.h>


//�g�p����l�[���X�y�[�X
using namespace GameL;
//�C�j�V�����C�Y
void CObjGameOver::Init()
{
	hint = 0;
	srand(time(NULL));
	hint = rand() % 7;

	mou_x = 0.0f;
	mou_y = 0.0f;
	mou_r = false;
	mou_l = false;

	f_p = 0.0f;
	pxc = 0.0f;
	pyc = 0.0f;

	Time = 600;
	second = 10;
}

//�A�N�V����
void CObjGameOver::Action()
{
	mou_x = (float)Input::GetPosX();
	mou_y = (float)Input::GetPosY();
	mou_r = Input::GetMouButtonR();
	mou_l = Input::GetMouButtonL();
	Time--;


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

	if (Time % 60 == 0)
	{
		if (second > 0)
		{
			second--;
		}
	}

	if (second < 0)
	{
		((UserData*)Save::GetData())->Hperfect = 0;
		Scene::SetScene(new CSceneTitle());
	}



	//�I���ŃV�[���ړ�
	if (((UserData*)Save::GetData())->stage >= 1)
	{
		if (mou_x > 353.0f && mou_x < 375.0f && mou_y>493.0f && mou_y < 521)
		{
			if (mou_l == true)
			{
				((UserData*)Save::GetData())->Hperfect = 0;
				Scene::SetScene(new CSceneMain());
			}
		}
	}
	if (((UserData*)Save::GetData())->stage >= 2)
	{
		if (mou_x > 394.0f && mou_x < 425.0f && mou_y>493.0f && mou_y < 521)
		{
			if (mou_l == true)
			{
				((UserData*)Save::GetData())->Hperfect = 0;
				Scene::SetScene(new CSceneStage2());
			}
		}
	}
	if (((UserData*)Save::GetData())->stage >= 3)
	{
		if (mou_x > 445.0f && mou_x < 473.0f && mou_y>493.0f && mou_y < 521)
		{
			if (mou_l == true)
			{
				((UserData*)Save::GetData())->Hperfect = 0;
				Scene::SetScene(new CSceneStage3());
			}
		}
	}
	if (((UserData*)Save::GetData())->stage >= 4)
	{
		if (mou_x > 496.0f && mou_x < 521.0f && mou_y>493.0f && mou_y < 521)
		{
			if (mou_l == true)
			{
				((UserData*)Save::GetData())->Hperfect = 0;
				Scene::SetScene(new CSceneStage4());
			}
		}
	}
}

//�h���[
void CObjGameOver::Draw()
{
	//�`��J���[��� R=RED B=Biue A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float r[4] = { 1.0f,0.0f,0.0f,1.0f };
	float y[4] = { 1.0f,1.0f,0.0f,1.0f };
	float g[4] = { 0.3f,0.3f,0.3f,1.0f };

	//�\���F�}�E�X�J�[�\���ƃ{�^��
	wchar_t str[256];

	swprintf_s(str, L"x=%f,y=%f", mou_x, mou_y);
	Font::StrDraw(str, 50, 20, 15, c);

	if (second < 4)
	{
		swprintf_s(str, L"%2d", second);
		Font::StrDraw(str , 650, 200, 100, r);
	}

	else if (second < 6)
	{
		swprintf_s(str, L"%2d", second);
		Font::StrDraw(str, 650, 200, 100, y);
	}

	else
	{
		swprintf_s(str, L"%2d", second);
		Font::StrDraw(str,650 , 200, 100, c);
	}

	
	
	Font::StrDraw(L"GAME OVER", 130, 200, 100, c);

	Font::StrDraw(L"�q���g:", 70, 350, 30, c);

	if (hint==0||hint==3)
	Font::StrDraw(L"�p�Y�����쒆�A�}�E�X���𒷉����Ń}�E�X�𓮂����Ă݂�!", 180, 355, 20, c);

	if (hint == 1||hint==4)
		Font::StrDraw(L"�U������炸�G�ɓ�����ƃ_���[�W�󂯂��!", 180, 355, 25, c);

	if (hint == 2)
		Font::StrDraw(L"�E�E�E�E�E�E���A�Q�Ă��B", 180, 355, 25, c);

	if (hint == 6 || hint == 7)
		Font::StrDraw(L"�Q�[�����n�߂�Ƃ��Ƀ}�E�X�E�������Ƃ����ɃQ�[�����n�߂��!", 180, 355, 20, c);
	

	Font::StrDraw(L"continue...?", 130, 500, 30, c);
	if (((UserData*)Save::GetData())->stage >= 1)
	{
		Font::StrDraw(L"1F", 350, 500, 30, c);
		Font::StrDraw(L"__", 350, 501, 30, c);
	}
	else
	{
		Font::StrDraw(L"1F", 350, 500, 30, g);
		Font::StrDraw(L"__", 350, 501, 30, g);
	}

	if (((UserData*)Save::GetData())->stage >= 2)
	{
		Font::StrDraw(L"2F", 400, 500, 30, c);
		Font::StrDraw(L"__", 400, 501, 30, c);
	}
	else
	{
		Font::StrDraw(L"2F", 400, 500, 30, g);
		Font::StrDraw(L"__", 400, 501, 30, g);
	}

	if (((UserData*)Save::GetData())->stage >= 3)
	{
		Font::StrDraw(L"3F", 450, 500, 30, c);
		Font::StrDraw(L"__", 450, 501, 30, c);
	}
	else
	{
		Font::StrDraw(L"3F", 450, 500, 30, g);
		Font::StrDraw(L"__", 450, 501, 30, g);
	}

	if (((UserData*)Save::GetData())->stage >= 4)
	{
		Font::StrDraw(L"4F", 500, 500, 30, c);
		Font::StrDraw(L"__", 500, 501, 30, c);
	}
	else
	{
		Font::StrDraw(L"4F", 500, 500, 30, g);
		Font::StrDraw(L"__", 500, 501, 30, g);
	}


}