#pragma once
//�g�p����w�b�_�[
#include "GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�F�v���C���[
class CObjRoad :public CObj
{
public:
	CObjRoad() {};
	~CObjRoad() {};
	void Init();
	void Action();
	void Draw();
	void player(bool r);

	bool s_r;	//���[�h�̃v���O�������~->�v���C���[��
	bool sei;
	bool swi;

	int map[14][14];
	int memmap[14][14];
	int reset;


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

	float itemc;

	int s_time;
	int second;

	bool set;


};