#pragma once
//�g�p����w�b�_�[
#include "GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�w�i
class CObjRoad3 :public CObj
{
public:
	CObjRoad3() {};
	~CObjRoad3() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[

	bool s_r;	//���[�h�̃v���O�������~->�v���C���[��
	int map[20][20];
	int memmap[20][20];

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

	bool f_p;	  //�N���b�N���쐧��
	bool test;

	int testx;
	int testy;

	int num;  //�f�o�b�O�p�Fy�ړ�

	int reset;
	int s_time;
	int second;

	bool set;
};
