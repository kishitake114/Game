 #pragma once
//�g�p����w�b�_�[
#include "GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;
#include "ObjRoad.h"

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

		float p_x;	  //����@���i�����j
		float p_y;	  //����@�c�i�����j
		float p_vx;
		float p_vy;

		float cs_x;   //�摜�؂���p�ϐ�
		float cs_y;

		bool s_p;

};