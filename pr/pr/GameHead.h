#pragma once

//�I�u�W�F�N�g�l�[��------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,	//�I�u�W�F�N�g������(�֎~)
	//�Q�[���Ŏg���I�u�W�F�N�g�̖��O
	//OBJ_�����ƕ\�L
	OBJ_PLAYER,
	OBJ_TITLE,
	OBJ_NO_ROAD,
	OBJ_ROAD,
	OBJ_GAME_OVER,
	OBJ_ENEMY,
	OBJ_CLEAR,
	OBJ_RULE,
	OBJ_RULE2,
	OBJ_STAGE2,
	OBJ_STAGE3,
	OBJ_STAGE4,
	OBJ_STAGE5,
	OBJ_TIME,
	OBJ_ITEM,
	OBJ_ENEMY2,
	OBJ_ENEMY3,
	OBJ_ENEMY4,
	OBJ_NUL,
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
	
};
//------------------------------------------------


//�Q�[�����Ŏg�p�����O���[�o���ϐ��E�萔�E��--



//------------------------------------------------
//�Q�[�����Ŏg�p����N���X�w�b�_------------------


//------------------------------------------------

//�Q�[���V�[���I�u�W�F�N�g�w�b�_------------------
#include "ObjPlayer.h"
#include "ObjTitle.h"
#include "Objnul.h"
#include "ObjRoad.h"
#include "ObjGameOver.h"
#include "ObjEnemy.h"
#include "ObjClear.h"
#include "ObjRule.h"
#include "ObjRule2.h"
#include "ObjStage2.h"
#include "ObjStage3.h"
#include "ObjStage4.h"
#include "ObjStage5.h"
#include "ObjTime.h"
#include "ObjItem.h"
#include "ObjEnemy2.h"
#include "ObjEnemy3.h"
#include "ObjEnemy4.h"

//------------------------------------------------

//�Q�[���V�[���N���X�w�b�_------------------------
#include "SceneMain.h"
#include "SceneTitle.h"
#include "SceneGameOver.h"
#include "SceneClear.h"
#include "SceneRule.h"
#include "SceneRule2.h"
#include "SceneStage2.h"
#include "SceneStage3.h"
#include "SceneStage4.h"
#include "SceneStage5.h"

//-----------------------------------------------

//�V�[���X�^�[�g�N���X---------------------------
//�Q�[���J�n���̃V�[���N���X�o�^
#define SET_GAME_START  CSceneClear
//-----------------------------------------------