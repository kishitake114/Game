#pragma once
//�g�p����w�b�_�[
#include "GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;
#define HITEM33 20

class CObjStage3item3 :public CObj
{
public:
	CObjStage3item3() {};
	~CObjStage3item3() {};
	void Init();
	void Action();
	void Draw();
private:
	int map[HITEM33][HITEM33];
};