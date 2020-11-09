//�g�p����w�b�_�[�t�@�C��
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "GameL/WinInputs.h"
#include "GameL/SceneManager.h"
#include "GameHead.h"
#include "GameL\Audio.h"
#include "ObjRule2.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjRule2::Init()
{
	mou_x = 0.0f;
	mou_y = 0.0f;
	mou_r = false;
	mou_l = false;
}
//�A�N�V����
void CObjRule2::Action()
{

	mou_x = (float)Input::GetPosX();
	mou_y = (float)Input::GetPosY();
	mou_r = Input::GetMouButtonR();
	mou_l = Input::GetMouButtonL();

	if (mou_x > 165 && mou_x < 585 && mou_y > 520 && mou_y < 580)
	{
		if (mou_l == true)
		{
			Scene::SetScene(new CSceneMain());
		}
	}



}
//�h���[
void CObjRule2::Draw()
{
	//�`��J���[��� R=RED B=Biue A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	//�\���F�^�C�g�����
	RECT_F src;
	RECT_F dst;

	src.m_top = 260.0f;
	src.m_left = 170.0f;
	src.m_right = 845.0f;
	src.m_bottom = 765.0f;

	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	Draw::Draw(0, &src, &dst, c, 0.0f);

}