//�g�p����w�b�_�[�t�@�C��
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "GameL/WinInputs.h"
#include "GameL/SceneManager.h"
#include "GameHead.h"
#include "GameL/Audio.h"
#include "ObjRule.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjRule::Init()
{
	mou_x = 0.0f;
	mou_y = 0.0f;
	mou_r = false;
	mou_l = false;
	Image = 0;
	s_r = true;
}
//�A�N�V����
void CObjRule::Action()
{
	mou_x = (float)Input::GetPosX();
	mou_y = (float)Input::GetPosY();
	mou_r = Input::GetMouButtonR();
	mou_l = Input::GetMouButtonL();

	if (mou_x > 0 && mou_x < 800 && mou_y > 0 && mou_y < 600)
	{
			if(mou_l==true)
			{
				if (s_r == true) 
				{
					if (Image < 3)
					{
						Image++;
						s_r = false;
					}
					else if (Image == 3)
					{
						Scene::SetScene(new CSceneStage5());
					}
				}
			}
			else if (mou_r == true)
			{
				if (s_r == true)
				{
					if (Image > 0)
					{
						Image--;
						s_r = false;
					}
				}
			}
			else
			{
				s_r = true;
			}
	}
}
//�h���[
void CObjRule::Draw()
{
	//�`��J���[��� R=RED B=Biue A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	//�\���F�^�C�g�����
	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 800.0f;
	src.m_bottom = 600.0f;

	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	Draw::Draw(Image, &src, &dst, c, 0.0f);

}