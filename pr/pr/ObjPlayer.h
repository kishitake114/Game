#pragma once
//�g�p����w�b�_�[
#include "GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�F�v���C���[
class CObjPlayer :public CObj
{
	public:
		CObjPlayer() {};
		~CObjPlayer() {};
		void Init();
		void Action();
		void Draw();
	private:
		float mou_x;  //�}�E�X�J�[�\���F��
		float mou_y;  //�}�E�X�J�[�\���F�c
		bool  mou_r;  //�}�E�X�{�^���F�E
		bool  mou_l;  //�}�E�X�{�^���F��
};