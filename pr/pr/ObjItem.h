#pragma once
//�g�p����w�b�_�[
#include "GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

class CObjItem :public CObj
{
public:
	CObjItem(float x, float y) ;
	~CObjItem() {};
	void Init();
	void Action();
	void Draw();
	float m_x;
	float m_y;


private:
	float mou_x;  //�}�E�X�J�[�\���F��
	float mou_y;  //�}�E�X�J�[�\���F�c
	bool  mou_r;  //�}�E�X�{�^���F�E
	bool  mou_l;  //�}�E�X�{�^���F��

	int map[14][14];
	
};
