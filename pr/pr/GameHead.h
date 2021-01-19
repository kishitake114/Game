#pragma once

//�I�u�W�F�N�g�l�[��------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,	//�I�u�W�F�N�g������(�֎~)
	//�Q�[���Ŏg���I�u�W�F�N�g�̖��O
	//OBJ_�����ƕ\�L
	OBJ_TITLE,
	OBJ_NO_ROAD,
	OBJ_GAME_OVER,
	OBJ_CLEAR,

	OBJ_PLAYER,

	OBJ_RULE,
	OBJ_RULE2,

	OBJ_ROAD1,
	OBJ_ROAD2,
	OBJ_ROAD3,
	OBJ_ROAD4,
	OBJ_ROAD5,

	OBJ_TIME,
	OBJ_ITEM,

	OBJ_ENEMY,
	OBJ_ENEMY2,
	OBJ_ENEMY3,
	OBJ_ENEMY4,

	OBJ_HARD_ENEMY,
	OBJ_HARD_ENEMY2,
	OBJ_HARD_ENEMY3,
	OBJ_HARD_ENEMY4,

	OBJ_STAR,

	OBJ_BACKGROUND01,

	OBJ_HARD_STAGE1,
	OBJ_HARD_STAGE2,
	OBJ_HARD_STAGE3,
	OBJ_HARD_STAGE4,
	OBJ_HARD_STAGE5,

	OBJ_NO_ROAD0,
	OBJ_NO_ROAD1,
	OBJ_NO_ROAD2,
	OBJ_NO_ROAD3,
	OBJ_NO_ROAD4,
};
//------------------------------------------------

//�����蔻�葮��----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//�������� �S�Ă̑����Ɠ����蔻�肪���s�����
	//�ȉ��@�����������m�ł͓����蔻��͎��s����Ȃ�
	//�����͒ǉ��\�����A�f�o�b�N���̐F�͏����ݒ蕪��������
	ELEMENT_PLAYER,
	ELEMENT_ENEMY,
	ELEMENT_ITEM,
	ELEMENT_MAGIC,
	ELEMENT_FIELD,
	ELEMENT_RED,
	ELEMENT_GREEN,
	ELEMENT_BLUE,
	ELEMENT_BLACK,
	ELEMENT_WHITE,
};
//------------------------------------------------

//------------------------------------------------
//�Z�[�u�����[�h�ƃV�[���Ԃ̂���肷��f�[�^
struct UserData
{
	int mSeveData;	//�T���v���Z�[�u�f�[�^
	int Hperfect;
	int EXperfect;
	int stage;
	
};
//------------------------------------------------


//�Q�[�����Ŏg�p�����O���[�o���ϐ��E�萔�E��--


//------------------------------------------------
//�Q�[�����Ŏg�p����N���X�w�b�_------------------


//------------------------------------------------

//�Q�[���V�[���I�u�W�F�N�g�w�b�_------------------
#include "ObjPlayer.h"

#include "ObjTitle.h"

//�X�e�[�W�P�̃v���O�����f�[�^
#include "ObjRoad.h"
#include "ObjEnemy.h"
#include "ObjNoRoad1.h"
#include "ObjStage1item1.h"
#include "ObjStage1item2.h"
#include "ObjStage1item3.h"
#include "ObjStage1LifeiTem.h"

//�X�e�[�W�Q�̃v���O�����f�[�^
#include "ObjRoad2.h"
#include "ObjNoRoad2.h"
#include "ObjEnemy2.h"
#include "ObjStage2item1.h"
#include "ObjStage2item2.h"
#include "ObjStage2item3.h"
#include "ObjStage2LifeiTem.h"

//�X�e�[�W�R�̃v���O�����f�[�^
#include "ObjRoad3.h"
#include "ObjEnemy3.h"

#include "ObjGameOver.h"
#include "ObjClear.h"
#include "ObjRule.h"
#include "ObjRule2.h"

#include "ObjNoRoad0.h"

#include "ObjStage4.h"
#include "ObjStage5.h"
#include "ObjTime.h"
#include "ObjEnemy4.h"
#include "ObjHardEnemy.h"
#include "ObjHardEnemy2.h"
#include "hardstage1.h"
#include "hardstage2.h"

#include "Objstar.h"

//------------------------------------------------

//�Q�[���V�[���N���X�w�b�_------------------------
#include "SceneStage1.h"
#include "SceneTitle.h"
#include "SceneGameOver.h"
#include "SceneClear.h"
#include "SceneRule.h"
#include "SceneRule2.h"
#include "SceneStage2.h"
#include "SceneStage3.h"
#include "SceneStage4.h"
#include "SceneStage5.h"
#include "scenehardstage1.h"
#include "sceneHardstage2.h"

//-----------------------------------------------
//�V�[���X�^�[�g�N���X---------------------------

//�Q�[���J�n���̃V�[���N���X�o�^
#define SET_GAME_START   CSceneStage2
//-----------------------------------------------