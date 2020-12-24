//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL_	(0)
#define _HAS_ITERATOR_DEBUGING	(0)

//�g�p����w�b�_�[(GameL)
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL/UserData.h"
#include "GameL/DrawFont.h"
#include "GameL/Audio.h"

using namespace GameL;

//�g�p����w�b�_�[
#include "SceneStage1.h"
#include "GameHead.h"
#include "Objplayer.h"
#include "hardstage1.h"
#include "ObjHardEnemy.h"

#include "scenehardstage1.h"

CSceneHardstage1::CSceneHardstage1()
{

}

CSceneHardstage1::~CSceneHardstage1()
{

}

void CSceneHardstage1::InitScene()
{
	Audio::LoadAudio(0, L"Stage1.wav", SOUND_TYPE::BACK_MUSIC);

	//Audio::LoadAudio(1, L"���邭.wav", ::EFFECT);

	Audio::LoadAudio(2, L"��.wav", ::EFFECT);

	float Volume = Audio::VolumeMaster(-0.8f);
	Audio::Start(0);

	//Font�쐬
	Font::SetStrTex(L"0123456789���b");

	//�O���f�[�^�̓ǂݍ��݁i�X�e�[�W���j
	unique_ptr<wchar_t> p; //�X�e�[�W���|�C���^�[
	int size;			   //�X�e�[�W���傫��
	p = Save::ExternalDataOpen(L"k.csv", &size);//�O���f�[�^�ǂݍ���

	Draw::LoadImage(L"image.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"stage0,1�w�i.png", 1, TEX_SIZE_512);

	CObjPlayer* CObj = new CObjPlayer();
	Objs::InsertObj(CObj, OBJ_PLAYER, 2);

	CObjHardStage1* CObjh1 = new CObjHardStage1();
	Objs::InsertObj(CObjh1, OBJ_HARD_STAGE1, 2);

	CObjTime* CObjT = new CObjTime();
	Objs::InsertObj(CObjT, OBJ_TIME, 2);

	CObjHardEnemy* CObjE = new  CObjHardEnemy();
	Objs::InsertObj(CObjE, OBJ_HARD_ENEMY, 3);
}

void CSceneHardstage1::Scene()
{

}

