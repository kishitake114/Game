#pragma once
//�g�p����w�b�_�[
#include "GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
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
