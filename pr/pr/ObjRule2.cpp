//使用するヘッダーファイル
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "GameL/WinInputs.h"
#include "GameL/SceneManager.h"
#include "GameHead.h"
#include "GameL\Audio.h"
#include "ObjRule2.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjRule2::Init()
{
	mou_x = 0.0f;
	mou_y = 0.0f;
	mou_r = false;
	mou_l = false;

	Image = 0;
	s_r = true;
}
//アクション
void CObjRule2::Action()
{

	mou_x = (float)Input::GetPosX();
	mou_y = (float)Input::GetPosY();
	mou_r = Input::GetMouButtonR();
	mou_l = Input::GetMouButtonL();

	if (mou_x > 0 && mou_x < 800 && mou_y > 0 && mou_y < 600)
	{
		if (mou_l == true)
		{
			if (s_r == true)
			{
				if (Image < 1)
				{
					Image++;
					s_r = false;
				}
				else if (Image == 1)
				{
					Scene::SetScene(new CSceneHardstage1());
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
//ドロー
void CObjRule2::Draw()
{
	//描画カラー情報 R=RED B=Biue A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	//表示：タイトル画面
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

	Draw::Draw(Image, &src, &dst, c, 0.0f);

}