#pragma once
//�g�p����w�b�_�[
#include "GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;
#define HROAD2 17

//�I�u�W�F�N�g�F�w�i
class CObjRoad2 :public CObj
{
public:
	CObjRoad2() {};
	~CObjRoad2() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[

	bool s_r;	//���[�h�̃v���O�������~->�v���C���[��
	bool sei;

	int map[HROAD2][HROAD2];
	int memmap[HROAD2][HROAD2];

private:
	int mem[3][3];//����s�[�X�̕ۑ�

	float mou_x;  //�}�E�X�J�[�\���F��
	float mou_y;  //�}�E�X�J�[�\���F�c
	bool  mou_r;  //�}�E�X�{�^���F�E
	bool  mou_l;  //�}�E�X�{�^���F��

	float pxc;	  //���N���b�N�ł��̍��Wx�̒ǉ�
	float pyc;	  //���N���b�N�ł��̍��Wy�̒ǉ�

	float pv_x;
	float pv_y;

	int reset;

	bool f_p;	  //�N���b�N���쐧��

	int s_time;
	int second;

	bool s_count;	//�T�E���h�p�J�E���g

	bool set;
};

