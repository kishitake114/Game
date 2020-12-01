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
#include "SceneStage3.h"
#include "GameHead.h"
#include "ObjStage3.h"

//�R���X�g���N�^
CSceneStage3::CSceneStage3()
{
}

//�f�X�g���N�^
CSceneStage3::~CSceneStage3()
{
}

//�Q�[�����C��������
void CSceneStage3::InitScene()
{
	Audio::LoadAudio(0, L"Stage3.wav", SOUND_TYPE::BACK_MUSIC);

	Audio::LoadAudio(1, L"���邭.wav", ::EFFECT);

	Audio::LoadAudio(2, L"��.wav", ::EFFECT);


	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster(-0.8f);

	//�O���f�[�^�̓ǂݍ��݁i�X�e�[�W���j
	unique_ptr<wchar_t> p; //�X�e�[�W���|�C���^�[
	int size;			   //�X�e�[�W���傫��
	p = Save::ExternalDataOpen(L"k.csv", &size);//�O���f�[�^�ǂݍ���

	Draw::LoadImage(L"image.png", 0, TEX_SIZE_512);


	CObjPlayer* CObj = new CObjPlayer(0.0f, 30.0f);
	Objs::InsertObj(CObj, OBJ_PLAYER, 1);

	CObjStage3* CObj3 = new CObjStage3();
	Objs::InsertObj(CObj3, OBJ_STAGE3, 1);


	Draw::LoadImage(L"image2.png", 1, TEX_SIZE_512);

	CObjEnemy3* CObjE3 = new CObjEnemy3();
	Objs::InsertObj(CObjE3, OBJ_ENEMY3, 2);

	CObjTime* CObjT = new CObjTime();
	Objs::InsertObj(CObjT, OBJ_TIME, 3);

	CObjnul* CObjn = new CObjnul();
	Objs::InsertObj(CObjn, OBJ_NUL, 1);
}

//�Q�[�����C�����s��
void CSceneStage3::Scene()
{

}