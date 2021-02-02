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

	if (mou_r==true)
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

	if (m_time % 30 == 0)
		sigo++;

	if (ed==false&&m_time>480)
	{
		ed = true;
		m_time = 0;
	}
}

//ドロー
void CObjClear::Draw()
{
	RECT_F src;
	RECT_F dst;

	//描画カラー情報 R=RED B=Biue A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float r[4] = { 1.0f,0.0f,0.0f,1.0f };
	float g[4] = { 0.0f,1.0f,0.0f,1.0f };
	float b[4] = { 0.0f,0.0f,1.0f,1.0f };
	float y[4] = { 1.0f,1.0f,0.0f,1.0f };

	wchar_t str[256];

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
	else
	{
		if(m_time>=120&&m_time<=240)
		Font::StrDraw(L"STAFF CREDIT", 250, 310, 40, c);

		//スタッフクレジット　チーム
		if (m_time >= 250 && m_time <= 470)
		{
			Font::StrDraw(L"チーム", 280, 80, 15, c);
			Font::StrDraw(L"ジャンケン弱者", 300, 100, 30, c);

			Font::StrDraw(L"総合ディレクター", 250, 150, 15, c);
			Font::StrDraw(L"岸本　偉", 300, 170, 30, c);

			Font::StrDraw(L"プランナーディレクター", 250, 220, 15, c);
			Font::StrDraw(L"竹之下　涼馬", 300, 240, 30, c);

			Font::StrDraw(L"プログラムディレクター", 250, 290, 15, c);
			Font::StrDraw(L"中辻　祭斗史", 300, 310, 30, c);

			Font::StrDraw(L"デザインディレクター", 250, 360, 15, c);
			Font::StrDraw(L"林　雄大", 300, 380, 30, c);

			Font::StrDraw(L"サウンドディレクター", 250, 430, 15, c);
			Font::StrDraw(L"南　陸玖", 300, 450, 30, c);


		}

		//スタッフクレジット　ソフト
		if (m_time >= 480 && m_time <= 700)
		{
			Font::StrDraw(L"ソフト", 325, 100, 30, c);

			Font::StrDraw(L"Visual Studio 2019", 250, 150, 30, c);

			Font::StrDraw(L"Git Hub", 250, 200, 30, c);

			Font::StrDraw(L"Power Point", 250, 250, 30, c);

			Font::StrDraw(L"Ward", 250, 300, 30, c);

			Font::StrDraw(L"Excel", 250, 350, 30, c);

			Font::StrDraw(L"Trello", 250, 400, 30, c);


		}

		//スタッフクレジット　スペシャルサンクスその1
		if (m_time >= 710 && m_time <= 930)
		{
			Font::StrDraw(L"スペシャルサンクス", 250, 100, 30, c);

			Font::StrDraw(L"サポート", 250, 200, 15, c);
			Font::StrDraw(L"田中　喜人", 300, 220, 30, c);
			Font::StrDraw(L"先生", 450, 240, 20, c);

			Font::StrDraw(L"アドバイス", 250, 290, 15, c);
			Font::StrDraw(L"木村　尽志", 300, 310, 30, c);
			Font::StrDraw(L"先生", 450, 330, 20, c);
		}

		//スタッフクレジット　スペシャルサンクスその2
		if (m_time >= 940 && m_time <= 1160)
		{
			Font::StrDraw(L"スペシャルサンクス", 250, 100, 30, c);
			Font::StrDraw(L"　 テストプレイ", 250, 140, 30, c);

			Font::StrDraw(L"岩永　猛", 200, 200, 25, c);

			Font::StrDraw(L"岩本　悠生", 500, 200, 25, c);

			Font::StrDraw(L"上田　茂樹", 200, 240, 25, c);

			Font::StrDraw(L"桶谷　光城", 500, 240, 25, c);

			Font::StrDraw(L"杉下　友一", 200, 280, 25, c);

			Font::StrDraw(L"田畑　拓大", 500, 280, 25, c);

			Font::StrDraw(L"富永　綾斗", 200, 320, 25, c);

			Font::StrDraw(L"仲宗根　颯汰", 500, 320, 25, c);

			Font::StrDraw(L"永原　颯人", 200, 360, 25, c);

			Font::StrDraw(L"藤田　隆平", 500, 360, 25, c);

			Font::StrDraw(L"本山　佑亮", 200, 400, 25, c);

			Font::StrDraw(L"山口　真優", 500, 400, 25, c);

			Font::StrDraw(L"山田　陵人", 200, 440, 25, c);
		}
		if (m_time >= 1170)
		{
			if (((UserData*)Save::GetData())->Hperfect == 4)
			{
				


			}
			
			else
			{
				Font::StrDraw(L"END", 350, 235, 50, c);
			}
		}

	}
	
	Font::StrDraw(L"PERFECT!!", 275, 185, 50, y);

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 45.0f;
	src.m_bottom = 45.0f;

	dst.m_top = 230.0f;
	dst.m_left = 350.0f;
	dst.m_right = 400.0f;
	dst.m_bottom = 280.0f;

	Draw::Draw(1, &src, &dst, c, 0.0f);

	Font::StrDraw(L"YOU ARE SUPER PLAYER!!", 100, 285, 50, y);

	if (skip == true)
	{
		if(sigo%2==0)
		Font::StrDraw(L"右クリックでタイトルへ戻る ", 530, 0, 18, c);
	}

	//表示：タイトル画面


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

	}
}
	
