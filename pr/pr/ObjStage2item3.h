#pragma once
//�g�p����w�b�_�[
#include "GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;
#define NO 17

class CObjStage2item3 :public CObj
{
public:
	CObjStage2item3() {};
	~CObjStage2item3() {};
	void Init();
	void Action();
	void Draw();
private:
	int map[NO][NO];
};