//�g�p����w�b�_�[
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "ObjPlayer.h"
#include "ObjRoad.h"
#include "GameHead.h" 
#include "GameL/WinInputs.h" 


using namespace GameL;

//�C�j�V�����C�Y
void CObjPlayer::Init()
{
	p_x = 0.0f;
	p_y = 0.0f;
}

//�A�N�V����
void CObjPlayer::Action()
{
	

}

//�h���[
void CObjPlayer::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	


	//�\���F�v���C���[
	RECT_F src;
	RECT_F dst;

	src.m_top     = 0.0f;
	src.m_left    = 0.0f;
	src.m_right   = 45.0f;
	src.m_bottom  = 45.0f;

	dst.m_top	 = 320.0f;
	dst.m_left   =   0.0f;
	dst.m_right  =  40.0f;
	dst.m_bottom = 360.0f;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}
