//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL/DrawTexture.h"
#include "GameL/WinInputs.h"

#include "GameHead.h"
#include "ObjGameOver.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjGameOver::Init()
{
	mou_l = false; //�}�E�X���N���b�N
}

//�A�N�V����
void CObjGameOver::Action()
{
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (mou_l == true)
		{
			Scene::SetScene(new CSceneTitle());
			mou_l == false;
		}
	}
	else
	{
		mou_l = true;
	}
}

//�h���[
void CObjGameOver::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
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

	Draw::Draw(0, &src, &dst, c, 0.0f);
}