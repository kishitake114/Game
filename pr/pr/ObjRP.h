#pragma once
//�g�p����w�b�_�[
#include "GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

class CObjRP :public CObj
{
	public:
		CObjRP() {};
		~CObjRP() {};
		void Init();
		void Action();
		void Draw();
		bool sc;	//�X�^�[�g���ƃN���A���̂���

	private:
		bool sw;	//ROAD��PLAYER�̕\����
};