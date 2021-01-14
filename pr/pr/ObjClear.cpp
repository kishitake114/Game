//使用するヘッダー
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "GameL/SceneManager.h"
#include "ObjClear.h"
#include "GameHead.h" 
#include "GameL/WinInputs.h" 
#include "GameL/UserData.h"

using namespace GameL;

//イニシャライズ
void CObjClear::Init()
{
	mou_x = 0.0f;
	mou_y = 0.0f;
	mou_r = false;
	mou_l = false;

	skip = false;
	cont = false;

	P = 0;

	pf = 0.0f;

	m_time = 0;
	sigo = 0;

	ed = false;

	((UserData*)Save::GetData())->Hperfect = 4;
}

//アクション
void CObjClear::Action()
{
	mou_x = (float)Input::GetPosX();
	mou_y = (float)Input::GetPosY();
	mou_r = Input::GetMouButtonR();
	mou_l = Input::GetMouButtonL();

	if (mou_l==true)
	{
		if (cont == false)
		{
			if (skip == false)
			{
				skip = true;
				cont = true;
			}
			else
			{
				Scene::SetScene(new CSceneTitle());
			}
		}
	
	}
	else
	{
		cont = false;
	}
	
	if(ed==false)
		m_time++;	

	if (ed == true)
	{
		m_time++;
	}

	if (ed==false&&m_time>480)
	{
		ed = true;
		m_time = 0;
	}
}

//ドロー
void CObjClear::Draw()
{

	//描画カラー情報 R=RED B=Biue A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float r[4] = { 1.0f,0.0f,0.0f,1.0f };
	float g[4] = { 0.0f,1.0f,0.0f,1.0f };
	float b[4] = { 0.0f,0.0f,1.0f,1.0f };
	float y[4] = { 1.0f,1.0f,0.0f,1.0f };

	/*Font::StrDraw(L"GAME CLEAR!", 300, 200, 32, c);*/

	if (ed == false)
	{
		if (m_time >= 60)
			Font::StrDraw(L"こうして無事モンスターを懲らしめ、道の修復を終えた勇者は、", 50, 125, 25, c);

		if (m_time >= 120)
			Font::StrDraw(L"　　　　　村の住民のみんなから感謝されました。　　　　　　", 50, 200, 25, c);

		if (m_time >= 180)
			Font::StrDraw(L"　　　　　　　こうして再び村に平和が訪れ,　　　　　　　　　", 50, 275, 25, c);

		if (m_time >= 240)
			Font::StrDraw(L"　　　勇者は家に帰るといきなり眠りについたとさ...　　　 ", 50, 350, 25, c);

		if (m_time >= 300)
			Font::StrDraw(L"　　　　　　　　　　　おしまい！　　　　　　　　　　　　　", 50, 425, 25, c);

	}

	Font::StrDraw(L"STAFF CREDIT", 250, 1000 + m_y, 40, c);

	if (skip == true)
	{
		Font::StrDraw(L"左クリックでタイトルへ戻る ", 530, 0, 18, c);
	}

	wchar_t str[256];

	swprintf_s(str, L"%d", m_time);
	Font::StrDraw(str, 0, 0, 30, c);

	swprintf_s(str, L"%d", sigo);
	Font::StrDraw(str, 0, 33, 30, c);

	//表示：タイトル画面
	RECT_F src;
	RECT_F dst;

	src.m_top = 128.0f;
	src.m_left = 0.0f;
	src.m_right = 512.0f;
	src.m_bottom = 380.0f;
	if (ed == true && m_time >= 120 && m_time < 240)
	{
		dst.m_top = 100.0f;
		dst.m_left = 200.0f;
		dst.m_right = 600.0f;
		dst.m_bottom = 300.0f;

		Draw::Draw(0, &src, &dst, c, 0.0f);
		//}

		//src.m_top = 0.0f;
		//src.m_left = 0.0f;
		//src.m_right = 45.0f;
		//src.m_bottom = 45.0f;

		//dst.m_top = 7950.0f;
		//dst.m_left = 400.0f ;
		//dst.m_right = 432.0f;
		//dst.m_bottom = 7982.0f;

		//Draw::Draw(1, &src, &dst, c, 0.0f);

		//src.m_top = 50.0f;
		//src.m_left = 0.0f;
		//src.m_right = 45.0f;
		//src.m_bottom = 80.0f;

		//dst.m_top = 8150.0f + m_y;
		//dst.m_left = 400.0f - (pf * 2) - P;
		//dst.m_right = 432.0f - (pf * 2) - P;
		//dst.m_bottom = 8182.0f + m_y;

		//Draw::Draw(1, &src, &dst, c, 0.0f);

		//src.m_top = 0.0f;
		//src.m_left = 0.0f;
		//src.m_right = 45.0f;
		//src.m_bottom = 50.0f;

		//dst.m_top = 8350.0f + m_y;
		//dst.m_left = 400.0f + (pf * 2) + P;
		//dst.m_right = 432.0f + (pf * 2) + P;
		//dst.m_bottom = 8382.0f + m_y;

		//Draw::Draw(3, &src, &dst, c, 0.0f);

		//src.m_top = 64.0f;
		//src.m_left = 10.0f;
		//src.m_right = 40.0f;
		//src.m_bottom = 84.0f;

		//dst.m_top = 8550.0f + m_y;
		//dst.m_left = 400.0f-(pf*3)-P;
		//dst.m_right = 432.0f - (pf * 3) - P;
		//dst.m_bottom = 8582.0f + m_y;

		//Draw::Draw(2, &src, &dst, c, 0.0f);

		//src.m_top = 10.0f;
		//src.m_left = 160.0f;
		//src.m_right = 190.0f;
		//src.m_bottom = 35.0f;

		//dst.m_top = 8750.0f + m_y;
		//dst.m_left = 400.0f + (pf * 3) + P;
		//dst.m_right = 432.0f + (pf * 3) + P;
		//dst.m_bottom = 8782.0f + m_y;

		//Draw::Draw(2, &src, &dst, c, 0.0f);

	/*	if (((UserData*)Save::GetData())->Hperfect == 4&&m_y<-9250.0f)
		{
			Font::StrDraw(L"THANK YOU!", 280, 200, 50, y);

			src.m_top = 0.0f;
			src.m_left = 0.0f;
			src.m_right = 45.0f;
			src.m_bottom = 45.0f;

			dst.m_top = 284.0f;
			dst.m_left = 384.0f;
			dst.m_right = 416.0f;
			dst.m_bottom = 316.0f;

			Draw::Draw(1, &src, &dst, c, 0.0f);

			src.m_top = 50.0f;
			src.m_left = 0.0f;
			src.m_right = 45.0f;
			src.m_bottom = 80.0f;

			dst.m_top = 284.0f;
			dst.m_left = 347.0f;
			dst.m_right = 379.0f;
			dst.m_bottom = 316.0f;

			Draw::Draw(1, &src, &dst, c, 0.0f);

			src.m_top = 0.0f;
			src.m_left = 0.0f;
			src.m_right = 45.0f;
			src.m_bottom = 50.0f;

			dst.m_top = 284.0f;
			dst.m_left = 421.0f;
			dst.m_right = 453.0f;
			dst.m_bottom = 316.0f;

			Draw::Draw(3, &src, &dst, c, 0.0f);

			src.m_top = 64.0f;
			src.m_left = 10.0f;
			src.m_right = 40.0f;
			src.m_bottom = 84.0f;

			dst.m_top = 284.0f;
			dst.m_left = 310.0f;
			dst.m_right = 342.0f;
			dst.m_bottom = 316.0f;

			Draw::Draw(2, &src, &dst, c, 0.0f);

			src.m_top = 10.0f;
			src.m_left = 160.0f;
			src.m_right = 190.0f;
			src.m_bottom = 35.0f;

			dst.m_top = 284.0f;
			dst.m_left = 458.0f;
			dst.m_right = 490.0f;
			dst.m_bottom = 316.0f;

			Draw::Draw(2, &src, &dst, c, 0.0f);
		}*/
		//if(m_y<-9250.0f)
		//{
		//	Font::StrDraw(L"END", 325, 275, 50, c);
		//}
	}
}
	
