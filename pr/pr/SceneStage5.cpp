//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL_	(0)
#define _HAS_ITERATOR_DEBUGING	(0)

//�g�p����w�b�_�[(GameL)
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL/DrawFont.h"
#include "GameL/UserData.h"

//�g�p����w�b�_�[
#include "SceneStage5.h"
#include "GameHead.h"
#include "ObjStage5.h"
#include "Background01.h"

//�R���X�g���N�^
CSceneStage5::CSceneStage5()
{
}

//�f�X�g���N�^
CSceneStage5::~CSceneStage5()
{
}

//�Q�[�����C��������
void CSceneStage5::InitScene()
{
	//�O���f�[�^�̓ǂݍ��݁i�X�e�[�W���j
	unique_ptr<wchar_t> p; //�X�e�[�W���|�C���^�[
	int size;			   //�X�e�[�W���傫��
	p = Save::ExternalDataOpen(L"k.csv", &size);//�O���f�[�^�ǂݍ���

	Draw::LoadImage(L"image.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"stage0,1�w�i.png", 1, TEX_SIZE_512);

	CObjPlayer* CObj = new CObjPlayer(0.0f, 200.0f);
	Objs::InsertObj(CObj, OBJ_PLAYER, 1);

	CObjStage5* CObj5 = new CObjStage5();
	Objs::InsertObj(CObj5, OBJ_STAGE5, 1);

	CObjnul* CObjn = new CObjnul();
	Objs::InsertObj(CObjn, OBJ_NUL, 1);

	CObjBackGround01* CObbg = new 	CObjBackGround01();
	Objs::InsertObj(CObbg, OBJ_BACKGROUND01, 0);

}

//�Q�[�����C�����s��
void CSceneStage5::Scene()
{
	
}