//使用するヘッダーファイル
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "GameL/WinInputs.h"
#include "GameL/SceneManager.h"
#include "GameHead.h"
#include "ObjTime.h"
#include "ObjRoad.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjTime::Init()
{
	m_flag_time = false;

	mou_r = false;
	mou_l = false;

	plas = 0;

	CObjPlayer* player = (CObjPlayer*)Objs::GetObj(OBJ_PLAYER);

	if (player->num == 1)
	{
		;
	}

	if (player->num == 2)
	{
		plas = 1800;
	}

	if (player->num >= 3)
	{
		plas = 3600;
	}

	m_time = 3600 + plas;
}
//アクション
void CObjTime::Action()
{
	mou_r = Input::GetMouButtonR();
	mou_l = Input::GetMouButtonL();

	CObjPlayer* player = (CObjPlayer*)Objs::GetObj(OBJ_PLAYER);
	
	if (mou_r == true)
	{
		m_flag_time = false;
		
	}

	//フラグがオンの時、時間を減らす
	if (m_flag_time == true)
	{
		m_time--;
	}

	//０秒になったら、１分に戻す
	if (m_time == 0)
	{
		player->HP--;		//m_Timeが0->PlayerHPを-1する。
		m_time = 3600+plas;
	}


}
//ドロー
void CObjTime::Draw()
{
	//m_timeから秒分を求める
	int minute;//分
	int second;//秒

	second = (m_time / 60) % 60;//秒
	minute = (m_time / 60) / 60;//分

	float c[4] = { 1.0f,1.0f, 1.0f, 1.0f, };
	wchar_t str[128];

	Font::StrDraw(L"TIME", 600, 0, 40, c);

	//分：秒の値を文字列化
	if (second < 10)
	{
		swprintf_s(str, L"%d 0%d", minute, second);
	}
	else
	{
		swprintf_s(str, L"%d %d", minute, second);
	}

	Font::StrDraw(str, 720, 0, 40, c);

	if (m_time )
	{
		Font::StrDraw(L":", 740, 0, 40, c);
	}
}