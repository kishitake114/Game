#pragma once
//�g�p����w�b�_�[
#include "GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;
#define HNOROAD0 8

class CObjNoRoad0 :public CObj
{
	 public:
		 CObjNoRoad0() {};
		 ~CObjNoRoad0() {};
		 void Init();
		 void Action();
		 void Draw();
	private:
		int map[HNOROAD0][HNOROAD0];
};