#pragma once
//�g�p����w�b�_�[
#include "GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;
#define HITEML4 26

class CObjStage4Lifeitem :public CObj
{
public:
	CObjStage4Lifeitem() {};
	~CObjStage4Lifeitem() {};
	void Init();
	void Action();
	void Draw();
private:
	int map[HITEML4][HITEML4];
};