#pragma once
//�g�p����w�b�_�[
#include "GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�F�v���C���[
class CObjEnemy3 :public CObj
{
public:
	CObjEnemy3() {};
	~CObjEnemy3() {};
	void Init();
	void Action();
	void Draw();
private:
	int HP;
	float p_x;
	float p_y;

	float atr_x;
	float atr_y;
	float cs_xe;

	int plx;
	int ply;

	int ran;

	int memx;
	int memy;

	bool se;

};
