#pragma once
//�g�p����w�b�_�[
#include "GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;
#include "ObjRoad.h"

//�I�u�W�F�N�F�v���C���[
class CObjStar :public CObj
{
public:
	CObjStar(){};
	~CObjStar(){};
	void Init();
	void Action();
	void Draw();

private:
	int HardSter;

};