#pragma once
//�g�p����w�b�_�[
#include "GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

class CObjBackGround01 :public CObj
{
public:
	CObjBackGround01() {};
		~CObjBackGround01() {};
		void Init();
		void Action();
		void Draw();
	private:
		int stage;

};
