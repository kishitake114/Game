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

	m_x = 100;
	m_y = 100;

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
	
	
	if (ed == true && m_time >= 210&&m_y>-10000.0F)
	{
			m_y -= 2.5f;
			m_x -= 2.5f;
	}

	if (ed == true && m_time <= 320)
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
		if(m_time>=60)
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

	//-------------------チーム　ジャンケン弱者------------------
		Font::StrDraw(L"TEAM", 200, 1150 + m_y, 20, c);
		Font::StrDraw(L"JYANKEN JYAKUSYA", 250, 1200 + m_y, 32, c);

		Font::StrDraw(L"GENERAL DIRECTOR", 200, 1350 + m_y, 20, c);
		Font::StrDraw(L"TAKERU KISHIMOTO", 250, 1400 + m_y, 32, c);

		Font::StrDraw(L"PLANNING DIRECTOR", 200, 1550 + m_y, 20, c);
		Font::StrDraw(L"RYOMA TAKENOSHITA", 250, 1600 + m_y, 32, c);

		Font::StrDraw(L"DESIGN DIRECTOR", 200, 1750 + m_y, 20, c);
		Font::StrDraw(L"YUDAI HAYASHI", 250, 1800 + m_y, 32, c);

		Font::StrDraw(L"SOUND DIRECTOR", 200, 1950 + m_y, 20, c);
		Font::StrDraw(L"RIKU MINAMI", 250, 2000 + m_y, 32, c);

		Font::StrDraw(L"PROGRAMU DIRECTOR", 200, 2150 + m_y, 20, c);
		Font::StrDraw(L"MATSURI NAKATSUJI", 250, 2200 + m_y, 32, c);
	//-------------------------内部の担当---------------------------
		Font::StrDraw(L"_____________________________", 150, 2300 + m_y, 32, c);

		Font::StrDraw(L"GAME PLANNING", 200, 2400 + m_y, 20, c);
		Font::StrDraw(L"RYOMA TAKENOSHITA", 250, 2450 + m_y, 32, c);

		Font::StrDraw(L"CHARACTER DESIGN", 200, 2600 + m_y, 20, c);
		Font::StrDraw(L"YUDAI HAYASHI", 250, 2650+ m_y, 32, c);

		Font::StrDraw(L"TITLE DESIGN", 200, 2800 + m_y, 20, c);
		Font::StrDraw(L"RYOMA TAKENOSHITA", 250, 2850 + m_y, 32, c);

		Font::StrDraw(L"TITLE STAR DESIGN", 200, 3000 + m_y, 20, c);
		Font::StrDraw(L"TAKERU KISHIMOTO", 250, 3050 + m_y, 32, c);

		Font::StrDraw(L"TUTORIAL STAGE PROGRAM", 200, 3200 + m_y, 20, c);
		Font::StrDraw(L"YUDAI HAYASHI", 250, 3250 + m_y, 32, c);
		Font::StrDraw(L"RIKU MINAMI", 250, 3300 + m_y, 32, c);
		Font::StrDraw(L"TAKERU KISHIMOTO", 250, 3350 + m_y, 32, c);

		Font::StrDraw(L"STAGE 1F PROGRAM", 200, 3500 + m_y, 20, c);
		Font::StrDraw(L"YUDAI HAYASHI", 250, 3550 + m_y, 32, c);

		Font::StrDraw(L"STAGE 2F PROGRAM", 200, 3700 + m_y, 20, c);
		Font::StrDraw(L"MATSURI NAKATSUJI", 250, 3750 + m_y, 32, c);

		Font::StrDraw(L"STAGE 3F PROGRAM", 200, 3900 + m_y, 20, c);
		Font::StrDraw(L"TAKERU KISHIMOTO", 250, 3950 + m_y, 32, c);

		Font::StrDraw(L"STAGE 4F PROGRAM", 200, 4100 + m_y, 20, c);
		Font::StrDraw(L"RYOMA TAKENOSHITA", 250, 4150 + m_y, 32, c);

		Font::StrDraw(L"TITLE CLEAR GAMEOVER PROGRAM", 200, 4300 + m_y, 20, c);
		Font::StrDraw(L"TAKERU KISHIMOTO", 250, 4350 + m_y, 32, c);

		Font::StrDraw(L"SOUND SELECT", 200, 4500 + m_y, 20, c);
		Font::StrDraw(L"RIKU MINAMI", 250, 4550 + m_y, 32, c);

		Font::StrDraw(L"RULE DESCRIPTION", 200, 4700 + m_y, 20, c);
		Font::StrDraw(L"RYOMA TAKENOSHITA", 250, 4750 + m_y, 32, c);
	//-------------------------------------------------------------

	//----------------------マスター資料---------------------------
		Font::StrDraw(L"_____________________________", 150, 4850 + m_y, 32, c);
		Font::StrDraw(L"A PROPOSAL", 200, 5000 + m_y, 20, c);
		Font::StrDraw(L"RYOMA TAKENOSHITA", 250, 5050 + m_y, 32, c);
		Font::StrDraw(L"MATSURI NAKATSUJI", 250, 5100 + m_y, 32, c);

		Font::StrDraw(L"VIDEO EDITING", 200, 5250 + m_y, 20, c);
		Font::StrDraw(L"RIKU MINAMI", 250, 5300 + m_y, 32, c);

	//-------------------------------------------------------------
	//----------------------製作ソフト-----------------------------
		Font::StrDraw(L"_____________________________", 150, 5400 + m_y, 32, c);
		Font::StrDraw(L"SOFT WARE", 200, 5550 + m_y, 20, c);
		Font::StrDraw(L"Visual Studio 2019", 250, 5600 + m_y, 32, c);
		Font::StrDraw(L"GitHub", 250, 5650 + m_y, 32, c);
		Font::StrDraw(L"Power Point", 250, 5700 + m_y, 32, c);
		Font::StrDraw(L"Word", 250, 5750 + m_y, 32, c);
		Font::StrDraw(L"Excel", 250, 5800 + m_y, 32, c);
		Font::StrDraw(L"Trello", 250, 5850 + m_y, 32, c);
		Font::StrDraw(L"Avitil", 250, 5900 + m_y, 32, c);

		Font::StrDraw(L"MUSIC", 200, 6050 + m_y, 20, c);
		Font::StrDraw(L"魔王魂", 250, 6100 + m_y, 32, c);

	//-------------------------------------------------------------
	//----------------------スペシャルサンクス---------------------
		Font::StrDraw(L"_____________________________", 150, 6200 + m_y, 32, c);
		Font::StrDraw(L"SPECIAL THANKS", 250, 6300 + m_y, 32, c);

		Font::StrDraw(L"ADVICE", 200, 6450 + m_y, 20, c);
		Font::StrDraw(L"KIMURA TEACHER", 250, 6500 + m_y, 32, c);
		
		Font::StrDraw(L"SUPPORT", 200, 6650 + m_y, 20, c);
		Font::StrDraw(L"TANAKA TEACHER", 250, 6700 + m_y, 32, c);

		Font::StrDraw(L"TEST PLAY", 200, 6850 + m_y, 20, c);

		Font::StrDraw(L"YUICHI SUGISHITA", 250, 6900 + m_y, 32, c);
		Font::StrDraw(L"TAKATO YAMADA", 250, 6950 + m_y, 32, c);
		Font::StrDraw(L"HAYATO NAGAHARA", 250, 7000 + m_y, 32, c);
		Font::StrDraw(L"TAKERU IWANAGA", 250, 7050 + m_y, 32, c);

	//-------------------------------------------------------------	
		Font::StrDraw(L"_____________________________", 150, 7500+ m_y, 32, c);
		Font::StrDraw(L"CAST", 350, 7750+ m_y, 32, c);
		Font::StrDraw(L"____", 350, 7751+ m_y, 32, c);

		Font::StrDraw(L"HERO", 200, 7900 + m_y, 20, c);
		Font::StrDraw(L"YUSYA", 250, 7950 + m_y, 32, c);

		Font::StrDraw(L"STAGE1", 200, 8100 + m_y, 20, c);
		Font::StrDraw(L"SLIME", 250, 8150 + m_y, 32, c);

		Font::StrDraw(L"STAGE2", 200, 8300 + m_y, 20, c);
		Font::StrDraw(L"GOBLIN", 250, 8350 + m_y, 32, c);

		Font::StrDraw(L"STAGE3", 200, 8500 + m_y, 20, c);
		Font::StrDraw(L"GOLEM", 250, 8550 + m_y, 32, c);

		Font::StrDraw(L"STAGE4", 200, 8700 + m_y, 20, c);
		Font::StrDraw(L"DRAGON", 250, 8750 + m_y, 32, c);


		if (skip == true)
		{
				Font::StrDraw(L"左クリックでタイトルへ戻る ", 530, 0, 18, c);	
		}

	wchar_t str[256];

	swprintf_s(str, L"%d", m_time);
	Font::StrDraw(str, 0, 0, 30, c);

	swprintf_s(str, L"%d", sigo);
	Font::StrDraw(str, 0, 33, 30, c);

	swprintf_s(str, L"%f", m_y);
	Font::StrDraw(str, 0, 570, 30, c);

	swprintf_s(str, L"%f", m_x);
	Font::StrDraw(str, 0, 530, 30, c);


	//表示：タイトル画面
	RECT_F src;
	RECT_F dst;

	src.m_top = 128.0f;
	src.m_left = 0.0f;
	src.m_right = 512.0f;
	src.m_bottom = 380.0f;
	if (ed==true&&m_time >= 120)
	{
		dst.m_top = 100.0f + m_y;
		dst.m_left = 200.0f;
		dst.m_right = 600.0f;
		dst.m_bottom = 300.0f + m_y;

		Draw::Draw(0, &src, &dst, c, 0.0f);
	}

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 45.0f;
	src.m_bottom = 45.0f;

	dst.m_top = 7950.0f+m_x;
	dst.m_left = 400.0f - pf;
	dst.m_right = 432.0f - pf;
	dst.m_bottom = 7982.0f + m_x;

	Draw::Draw(1, &src, &dst, c, 0.0f);

	src.m_top = 50.0f;
	src.m_left = 0.0f;
	src.m_right = 45.0f;
	src.m_bottom = 80.0f;

	dst.m_top = 8150.0f + m_x;
	dst.m_left = 400.0f - (pf * 2) - P;
	dst.m_right = 432.0f - (pf * 2) - P;
	dst.m_bottom = 8182.0f + m_x;

	Draw::Draw(1, &src, &dst, c, 0.0f);

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 45.0f;
	src.m_bottom = 50.0f;

	dst.m_top = 8350.0f + m_x;
	dst.m_left = 400.0f + (pf * 2) + P;
	dst.m_right = 432.0f + (pf * 2) + P;
	dst.m_bottom = 8382.0f + m_x;

	Draw::Draw(3, &src, &dst, c, 0.0f);

	src.m_top = 64.0f;
	src.m_left = 10.0f;
	src.m_right = 40.0f;
	src.m_bottom = 84.0f;

	dst.m_top = 8550.0f + m_x;
	dst.m_left = 400.0f-(pf*3)-P;
	dst.m_right = 432.0f - (pf * 3) - P;
	dst.m_bottom = 8582.0f + m_x;

	Draw::Draw(2, &src, &dst, c, 0.0f);

	src.m_top = 10.0f;
	src.m_left = 160.0f;
	src.m_right = 190.0f;
	src.m_bottom = 35.0f;

	dst.m_top = 8750.0f + m_x;
	dst.m_left = 400.0f + (pf * 3) + P;
	dst.m_right = 432.0f + (pf * 3) + P;
	dst.m_bottom = 8782.0f + m_x;

	Draw::Draw(2, &src, &dst, c, 0.0f);

	if (((UserData*)Save::GetData())->Hperfect == 4&&m_y<-10000.0f)
	{
		Font::StrDraw(L"THANK YOU!", 280, 200, 50, c);

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
	}
	else if(m_y<-10000.0f)
	{
		Font::StrDraw(L"END", 325, 275, 50, c);
	}
}
	
