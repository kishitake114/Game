#pragma once
//�g�p����w�b�_�[
#include "GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;
#define NO 26

class CObjNoRoad4 :public CObj
{
public:
	CObjNoRoad4() {};
	~CObjNoRoad4() {};
	void Init();
	void Action();
	void Draw();
private:
	int map[NO][NO];
};