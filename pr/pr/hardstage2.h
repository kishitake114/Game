#pragma once
//�g�p����w�b�_�[
#include "GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;
#define MAP 17
#define MEM 3

//�I�u�W�F�N�F�v���C���[
class CObjHardStage2 :public CObj
{
public:
	CObjHardStage2() {};
	~CObjHardStage2() {};
	void Init();
	void Action();
	void Draw();

	bool s_r;	//���[�h�̃v���O�������~->�v���C���[��
	bool sei;
	bool swi;

	int map[MAP][MAP];
	int memmap[MAP][MAP];

	int Hmap[MAP][MAP];
	int Hmemmap[MAP][MAP];

	int reset;

private:
	int mem[MEM][MEM];//����s�[�X�̕ۑ�
	int Hmem[MEM][MEM];//����s�[�X�̕ۑ�

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

	bool piece;

	int RESETcount;


};