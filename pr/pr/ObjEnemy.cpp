#include "ObjEnemy.h"
#include "ObjRoad.h"
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "GameHead.h" 
#include "GameL/WinInputs.h" 

//�C�j�V�����C�Y
void CObjEnemy::Init()
{
	
}

//�A�N�V����
void CObjEnemy::Action()
{

}

//�h���[
void CObjEnemy::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	src.m_top = 50.0f;
	src.m_left = 0.0f;
	src.m_right = 45.0f;
	src.m_bottom = 80.0f;

	dst.m_top	 =   0.0f;
	dst.m_left   = 250.0f;
	dst.m_right  = 300.0f;
	dst.m_bottom =  50.0f;

	Draw::Draw(0, &src, &dst, c, 0.0f);

}
