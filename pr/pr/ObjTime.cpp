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
	m_time = 3600;
	m_flag_time = false;

	mou_r = false;
	mou_l = false;
}
//アクション
void CObjTime::Action()
{
	mou_r = Input::GetMouButtonR();
	mou_l = Input::GetMouButtonL();



	if (mou_l == true)
	{
		m_flag_time = true;
	}
    else if (mou_r == true)
	{
		m_flag_time = false;
	}

	//フラグがオンの時時間を進める
	if (m_flag_time == true)
	{
		m_time--;
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
	//分：秒の値を文字列化
	if (second < 10)
	{
		swprintf_s(str, L"%d分0%d秒", minute, second);
	}
	else
	{
		swprintf_s(str, L"%d分%d秒", minute, second);
	}

	Font::StrDraw(str, 10, 10, 20, c);
}