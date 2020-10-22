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
}
//�A�N�V����
void CObjTitle::Action()
{
	if (Input::GetVKey(VK_RETURN) == true)
	{
		Scene::SetScene(new CSceneMain());
	}
}
//�h���[
void CObjTitle::Draw()
{
	//�`��J���[��� R=RED B=Biue A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"Enter�L�[�ő���E���[��������", 160, 400, 32, c);

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