#pragma once
//�g�p����w�b�_�[
#include "GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;
#define HNOROAD2 17

class CObjNoRoad2 :public CObj
{
public:
	CObjNoRoad2() {};
	~CObjNoRoad2() {};
	void Init();
	void Action();
	void Draw();
private:
	int map[HNOROAD2][HNOROAD2];
};