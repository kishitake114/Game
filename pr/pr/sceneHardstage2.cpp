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
#include "sceneHardstage2.h"
#include "GameHead.h"
#include "hardstage2.h"



CSceneHardstage2::CSceneHardstage2()
{
}

CSceneHardstage2::~CSceneHardstage2()
{
}

void CSceneHardstage2::InitScene()
{
	Audio::LoadAudio(0, L"Stage2.wav", SOUND_TYPE::BACK_MUSIC);

//	Audio::LoadAudio(1, L"���邭.wav", ::EFFECT);

	Audio::LoadAudio(2, L"��.wav", ::EFFECT);

	float Volume = Audio::VolumeMaster(-0.8f);
	Audio::Start(0);


	//�O���f�[�^�̓ǂݍ��݁i�X�e�[�W���j
	unique_ptr<wchar_t> p; //�X�e�[�W���|�C���^�[
	int size;			   //�X�e�[�W���傫��
	p = Save::ExternalDataOpen(L"k.csv", &size);//�O���f�[�^�ǂݍ���

	Draw::LoadImage(L"image.png", 0, TEX_SIZE_512);

	CObjPlayer* CObj = new CObjPlayer();
	Objs::InsertObj(CObj, OBJ_PLAYER, 1);

	CObjHardStage2* CObj2 = new CObjHardStage2();
	Objs::InsertObj(CObj2, OBJ_HARD_STAGE2, 1);

	CObjHardEnemy2* CObjE2 = new CObjHardEnemy2();
	Objs::InsertObj(CObjE2, OBJ_HARD_ENEMY2, 2);

	Draw::LoadImage(L"image3.png", 1, TEX_SIZE_512);

	CObjTime* CObjT = new CObjTime();
	Objs::InsertObj(CObjT, OBJ_TIME, 3);
}

void CSceneHardstage2::Scene()
{
}
