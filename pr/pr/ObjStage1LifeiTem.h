#pragma once
//�g�p����w�b�_�[
#include "GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;
#define NO 14

class CObjStage1Lifeitem :public CObj
{
public:
	CObjStage1Lifeitem() {};
	~CObjStage1Lifeitem() {};
	void Init();
	void Action();
	void Draw();
private:
	int map[NO][NO];
};