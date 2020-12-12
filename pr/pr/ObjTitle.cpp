//使用するヘッダーファイル
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "GameL/WinInputs.h"
#include "GameL/SceneManager.h"
#include "GameHead.h"
#include "ObjTitle.h"
#include "GameL/UserData.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjTitle::Init()
{
	mou_x = 0.0f;
	mou_y = 0.0f;
	mou_r = false;
	mou_l = false;

	lup = false;
	rup = false;
	ldown = false;
	rdown = false;

	m_time = 0;

	slide = 0.0f;

	P = 0;

	hard = false;
	story = false;

	static bool init_point = false;
	if (init_point == false)
	{
		((UserData*)Save::GetData())->Hperfect = 0;
		((UserData*)Save::GetData())->EXperfect = 0;
		init_point = true;
	}

	Hcount=((UserData*)Save::GetData())->Hperfect;

}
//アクション
void CObjTitle::Action()
{
	mou_x = (float)Input::GetPosX();
	mou_y = (float)Input::GetPosY();
	mou_r = Input::GetMouButtonR();
	mou_l = Input::GetMouButtonL();

	m_time++;

	if (story == false)
	{
		if (m_time == 240)
			story = true;

		//if(((UserData*)Save::GetData())->Hperfect >= 2)
		//{
		//	if (mou_x > 0 && mou_x < 50 && mou_y > 0 && mou_y < 50)
		//	{
		//		if (mou_l == true)
		//		{
		//			lup = true;
		//		}
		//	}

		//	if (mou_x > 750 && mou_x < 800 && mou_y > 0 && mou_y < 50)
		//	{
		//		if (mou_l == true)
		//		{
		//			rup = true;
		//		}
		//	}

		//	if (mou_x > 0 && mou_x < 50 && mou_y > 550 && mou_y < 600)
		//	{
		//		if (mou_l == true)
		//		{
		//			ldown = true;
		//		}
		//	}

		//	if (mou_x > 750 && mou_x < 800 && mou_y > 550 && mou_y < 600)
		//	{
		//		if (mou_l == true)
		//		{
		//			rdown = true;
		//		}
		//	}

		//	if (lup == true && rup == true && ldown == true && rdown == true)
		//	{
		//		hard = true;
		//		title = 1;
		//	}
		//}


		if (mou_x > 161 && mou_x < 629 && mou_y > 391 && mou_y < 423)
		{

			if (mou_l == true)
			{
				Scene::SetScene(new CSceneRule());
				((UserData*)Save::GetData())->Hperfect = 0;
			}

			else if (mou_r == true)
			{
				Scene::SetScene(new CSceneMain());
				((UserData*)Save::GetData())->Hperfect = 0;
			}
		}

		if (slide < 0.0f)
		{
			if (slide > -100.0f)
			{
				slide += 4.0f;
			}
			else if (slide > -50.0f)
			{
				slide += 2.0f;
			}
			else
			{
				slide += 8.0f;
			}

			
		}

		//if (mou_x > 161 && mou_x < 629 && mou_y > 441 && mou_y < 473)
		//{
		//	if (hard == true)
		//	{
		//		if (mou_l == true)
		//		{
		//			Scene::SetScene(new CSceneRule2());
		//		}
		//	}
		//}
	}
	else
	{
		if (slide > -800.0f)
		{


			if (slide < -700.0f)
			{
				slide -= 4.0f;
			}

			else if (slide < -750.0f)
			{
				slide -= 2.0f;
			}

			else
			{
				slide -= 8.0f;
			}
		}

		if (mou_l == true)
		{
			story = false;
		}

		if (m_time == 1200)
		{
			story = false;
			m_time = -500;
		}
	}
}
//ドロー
void CObjTitle::Draw()
{
	
	//描画カラー情報 R=RED B=Biue A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float r[4] = { 0.3f,0.3f,0.3f,0.3f };

	//表示：マウスカーソルとボタン
	wchar_t str[256];
	if (story == true && m_time >= 420)
	{
		Font::StrDraw(L"あらすじ", 325, 75, 30, c);
	}

	if (story == true && m_time >= 480)
		Font::StrDraw(L"ある日、村のはずれの家で平和に過ごしている勇者がいました。", 50, 125, 25, c);
	if (story == true && m_time >= 540)
		Font::StrDraw(L"平和すぎて退屈していた勇者に一本の電話が来ました。", 100, 200, 25, c);
	if (story == true && m_time >= 600)
		Font::StrDraw(L"モンスター達が村の道を滅茶苦茶にしてしまい、", 125, 275, 25, c);
	if (story == true && m_time >= 660)
		Font::StrDraw(L"村の住民達は非常に困っていて、何とかして欲しいとのことです。", 25, 355, 25, c);
	if (story == true && m_time >= 720)
		Font::StrDraw(L"勇者は、久々の冒険でワクワクしながら家を後にしました。", 75, 430, 25, c);



	//表示：タイトル画面
	RECT_F src;
	RECT_F dst;

		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 512.0f;
		src.m_bottom = 512.0f;

		dst.m_top = 0.0f;
		dst.m_left = 0.0f+slide;
		dst.m_right = 800.0f+slide;
		dst.m_bottom = 600.0f;

		Draw::Draw(0, &src, &dst,c , 0.0f);
	

}