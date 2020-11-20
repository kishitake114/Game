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

		float GetX() { return p_x; }
		float GetY() { return p_y; }
		float GetVY() { return p_vy; }
		float GetVX() { return p_vx; }

		void SetX(float x) { p_x=x; }
		void SetY(float y) { p_y=y; }
		void SetVY(float vy) { p_y = vy; }
		void SetVX(float vx) { p_x = vx; }



		bool s_p;
		int HP;
		int num;
		float p_x;	  
		float p_y;	  

	private:
		float mou_x;  //�}�E�X�J�[�\���F��
		float mou_y;  //�}�E�X�J�[�\���F�c
		bool  mou_r;  //�}�E�X�{�^���F�E
		bool  mou_l;  //�}�E�X�{�^���F��

		float p_vx;
		float p_vy;

		float cs_x;   //�摜�؂���p�ϐ�
		float cs_y;


		bool atr;

		bool st_p;
		bool sw;
		bool sei;

		char count;

};