#pragma once
//�g�p����w�b�_�[
#include "GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;
#define NO  20

class CObjNoRoad3 :public CObj
{
public:
	CObjNoRoad3() {};
	~CObjNoRoad3() {};
	void Init();
	void Action();
	void Draw();
private:
	int map[NO][NO];
};