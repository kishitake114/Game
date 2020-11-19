//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL_	(0)
#define _HAS_ITERATOR_DEBUGING	(0)

//�g�p����w�b�_�[(GameL)
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL/DrawFont.h"
#include "GameL/UserData.h"

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
	//�O���f�[�^�̓ǂݍ��݁i�X�e�[�W���j
	unique_ptr<wchar_t> p; //�X�e�[�W���|�C���^�[
	int size;			   //�X�e�[�W���傫��
	p = Save::ExternalDataOpen(L"k.csv", &size);//�O���f�[�^�ǂݍ���

	Draw::LoadImage(L"image.png", 0, TEX_SIZE_512);

	CObjPlayer* CObj = new CObjPlayer();
	Objs::InsertObj(CObj, OBJ_PLAYER, 1);

	CObjStage2* CObj2 = new CObjStage2();
	Objs::InsertObj(CObj2, OBJ_STAGE2, 1);

	Draw::LoadImage(L"image.png", 0, TEX_SIZE_512);

	CObjEnemy2* CObjE2 = new CObjEnemy2();
	Objs::InsertObj(CObjE2, OBJ_ENEMY2, 1);

}

//�Q�[�����C�����s��
void CSceneStage2::Scene()
{

}