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
private:
	int map[14][14];


};