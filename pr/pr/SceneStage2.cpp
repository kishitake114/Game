//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL_	(0)
#define _HAS_ITERATOR_DEBUGING	(0)

//�g�p����w�b�_�[(GameL)
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL/DrawFont.h"
#include "GameL/UserData.h"
#include "GameL/Audio.h"

//�g�p����w�b�_�[
#include "SceneStage2.h"
#include "GameHead.h"
#include "ObjRoad2.h"
#include "ObjNoRoad2.h"
#include "Background01.h"
#include "ObjStage2item1.h"
#include "ObjStage2item2.h"
#include "ObjStage2item3.h"
#include "ObjStage2LifeiTem.h"
#include "ObjRP.h"

//�R���X�g���N�^
CSceneStage2::CSceneStage2()
{
}

//�f�X�g���N�^
CSceneStage2::~CSceneStage2()
{
}

//�Q�[�����C��������
void CSceneStage2::InitScene()
{
	Audio::LoadAudio(0, L"Stage2.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(1, L"����.wav", ::EFFECT);
	Audio::LoadAudio(2, L"���[�h.wav", ::EFFECT);
	Audio::LoadAudio(3, L"��.wav", ::EFFECT);
	Audio::LoadAudio(4, L"���Z�b�g.wav", ::EFFECT);
	Audio::LoadAudio(5, L"�}�E�X.wav", ::EFFECT);
	Audio::LoadAudio(6, L"�ɂ���.wav", ::EFFECT);
	Audio::LoadAudio(7, L"��������.wav", ::EFFECT);
	Audio::LoadAudio(8, L"�����ӂ�.wav", ::EFFECT);
	Audio::LoadAudio(9, L"�J�E���g.wav", ::EFFECT);
	Audio::LoadAudio(10, L"�X�^�[�g.wav", ::EFFECT);

	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster((0.7 - v));

	Draw::LoadImage(L"image.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"stage0,1background.png", 1, TEX_SIZE_512);

	CObjPlayer* CObj = new CObjPlayer();
	Objs::InsertObj(CObj, OBJ_PLAYER, 20);

	CObjRoad2* CObj2 = new CObjRoad2();
	Objs::InsertObj(CObj2, OBJ_ROAD2, 10);

	CObjNoRoad2* CObjN = new CObjNoRoad2();
	Objs::InsertObj(CObjN, OBJ_NO_ROAD2, 2);

	Draw::LoadImage(L"image3.png", 3, TEX_SIZE_512);

	CObjEnemy2* CObjE2 = new CObjEnemy2();
	Objs::InsertObj(CObjE2, OBJ_ENEMY2, 30);

	CObjBackGround01* CObg = new 	CObjBackGround01();
	Objs::InsertObj(CObg, OBJ_BACKGROUND01, 1);

	CObjTime* CObjT = new CObjTime();
	Objs::InsertObj(CObjT, OBJ_TIME, 2);

	CObjStage2item1* CObjI1 = new CObjStage2item1();
	Objs::InsertObj(CObjI1, OBJ_ITEM, 3);

	CObjStage2item2* CObjI2 = new CObjStage2item2();
	Objs::InsertObj(CObjI2, OBJ_ITEM, 3);

	CObjStage2item3* CObjI3 = new CObjStage2item3();
	Objs::InsertObj(CObjI3, OBJ_ITEM, 3);

	CObjStage2Lifeitem* CObjL = new CObjStage2Lifeitem();
	Objs::InsertObj(CObjL, OBJ_ITEM, 3);

	Draw::LoadImage(L"etc.png", 2, TEX_SIZE_512);

	CObjRP* CObjS = new CObjRP();
	Objs::InsertObj(CObjS, OBJ_SWITCH, 10);

}

//�Q�[�����C�����s��
void CSceneStage2::Scene()
{

}