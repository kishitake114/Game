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
#include "SceneStage4.h"
#include "GameHead.h"
#include "ObjStage4.h"

//�R���X�g���N�^
CSceneStage4::CSceneStage4()
{
}

//�f�X�g���N�^
CSceneStage4::~CSceneStage4()
{
}

//�Q�[�����C��������
void CSceneStage4::InitScene()
{
	Audio::LoadAudio(0, L"Stage4.wav", BACK_MUSIC);

	Audio::LoadAudio(1, L"���邭.wav", EFFECT);

	Audio::LoadAudio(2, L"��.wav", EFFECT);


	float Volume = Audio::VolumeMaster(-0.8f);
	Audio::Start(0);

	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster(-0.8f);

	//�O���f�[�^�̓ǂݍ��݁i�X�e�[�W���j
	unique_ptr<wchar_t> p; //�X�e�[�W���|�C���^�[
	int size;			   //�X�e�[�W���傫��
	p = Save::ExternalDataOpen(L"k.csv", &size);//�O���f�[�^�ǂݍ���

	Draw::LoadImage(L"image.png", 0, TEX_SIZE_512);

	CObjPlayer* CObj = new CObjPlayer(0.0f, 200.0f);
	Objs::InsertObj(CObj, OBJ_PLAYER, 1);

	CObjStage4* CObj4 = new CObjStage4();
	Objs::InsertObj(CObj4, OBJ_STAGE4, 1);

	CObjTime* CObjT = new CObjTime();
	Objs::InsertObj(CObjT, OBJ_TIME, 1);

	Draw::LoadImage(L"image2.png", 1, TEX_SIZE_512);

	CObjEnemy4* CObjE4 = new CObjEnemy4();
	Objs::InsertObj(CObjE4, OBJ_ENEMY4, 2);

	CObjnul* CObjn = new CObjnul();
	Objs::InsertObj(CObjn, OBJ_NUL, 1);

}

//�Q�[�����C�����s��
void CSceneStage4::Scene()
{

}