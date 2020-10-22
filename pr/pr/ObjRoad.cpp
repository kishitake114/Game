#include "ObjRoad.h"
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "GameHead.h" 


//イニシャライズ
void CObjRoad::Init()
{

}

//アクション
void CObjRoad::Action()
{

}

//ドロー
void CObjRoad::Draw()
{
	//表示：通行不可

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	src.m_top = 90.0f;
	src.m_left = 45.0f;
	src.m_right = 90.0f;
	src.m_bottom = 125.0f;

	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 135.0f;
	dst.m_bottom = 45.0f;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}
