#pragma once
//�g�p����w�b�_�[
#include "GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;
#define NO 17

class CObjStage2item2 :public CObj
{
public:
	CObjStage2item2() {};
	~CObjStage2item2() {};
	void Init();
	void Action();
	void Draw();
private:
	int map[NO][NO];
};