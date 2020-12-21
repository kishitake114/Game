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
#include "ObjStage2.h"

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

	Audio::LoadAudio(1, L"���邭.wav", ::EFFECT);

	Audio::LoadAudio(2, L"��.wav", ::EFFECT);

	float Volume = Audio::VolumeMaster(-0.8f);

	Draw::LoadImage(L"image.png", 0, TEX_SIZE_512);

	CObjPlayer* CObj = new CObjPlayer();
	Objs::InsertObj(CObj, OBJ_PLAYER, 1);

	CObjStage2* CObj2 = new CObjStage2();
	Objs::InsertObj(CObj2, OBJ_STAGE2, 1);


	Draw::LoadImage(L"image3.png", 1, TEX_SIZE_512);

	CObjEnemy2* CObjE2 = new CObjEnemy2();
	Objs::InsertObj(CObjE2, OBJ_ENEMY2, 2);

	CObjTime* CObjT = new CObjTime();
	Objs::InsertObj(CObjT, OBJ_TIME, 3);

}

//�Q�[�����C�����s��
void CSceneStage2::Scene()
{

}