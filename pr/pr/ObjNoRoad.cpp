//�g�p����w�b�_�[
#include "ObjNoRoad.h"
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "GameHead.h" 
 

//�C�j�V�����C�Y
void CObjNoRoad::Init()
{

}

//�A�N�V����
void CObjNoRoad::Action()
{

}
//�h���[
void CObjNoRoad::Draw()
{

	//�\���F�ʍs�s��

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	src.m_top = 90.0f;
	src.m_left = 0.0f;
	src.m_right = 45.0f;
	src.m_bottom = 125.0f;

	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 90.0f;
	dst.m_bottom = 45.0f;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}
