#pragma once
//�g�p����w�b�_�[
#include "GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;
#define NO 20

class CObjStage3Lifeitem :public CObj
{
public:
	CObjStage3Lifeitem() {};
	~CObjStage3Lifeitem() {};
	void Init();
	void Action();
	void Draw();
private:
	int map[NO][NO];
};