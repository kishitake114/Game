#include "GameL/DrawTexture.h"
#include "GameHead.h" 

#include "ObjRoad.h"

//�C�j�V�����C�Y
void CObjRoad::Init()
{

}

//�A�N�V����
void CObjRoad::Action()
{

}

//�h���[
void CObjRoad::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	//�\���F�ʍs�s��
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
