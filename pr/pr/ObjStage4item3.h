#pragma once
//�g�p����w�b�_�[
#include "GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;
#define HITEM43 26

class CObjStage4item3 :public CObj
{
public:
	CObjStage4item3() {};
	~CObjStage4item3() {};
	void Init();
	void Action();
	void Draw();
private:
	int map[HITEM43][HITEM43];
};