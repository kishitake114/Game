#pragma once
//使用するヘッダー
#include "GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

class CObjItem :public CObj
{
public:
	CObjItem() {};
	~CObjItem() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_x;
	float m_y;
};
