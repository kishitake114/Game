#pragma once
//�g�p����w�b�_�[
#include "GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;
#define NO 14

class CObjStage1item3 :public CObj
{
public:
	CObjStage1item3() {};
	~CObjStage1item3() {};
	void Init();
	void Action();
	void Draw();
private:
	int map[NO][NO];
};