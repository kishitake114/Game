//�g�p����w�b�_�[
#include "GameL/DrawTexture.h"
#include "ObjPlayer.h"
#include "GameHead.h" 

using namespace GameL;

//�C�j�V�����C�Y
void CObjPlayer::Init()
{
}

//�A�N�V����
void CObjPlayer::Action()
{
}

//�h���[
void CObjPlayer::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	src.m_top     = 0.0f;
	src.m_left    = 0.0f;
	src.m_right   = 45.0f;
	src.m_bottom   = 45.0f;

	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 45.0f;
	dst.m_bottom = 45.0f;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}
