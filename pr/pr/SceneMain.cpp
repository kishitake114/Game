//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL_	(0)
#define _HAS_ITERATOR_DEBUGING	(0)

//�g�p����w�b�_�[(GameL)
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL/UserData.h"

//�g�p����w�b�_�[
#include "SceneMain.h"
#include "GameHead.h"
#include "Objplayer.h"
#include "ObjNoRoad.h"

//�R���X�g���N�^
CSceneMain::CSceneMain()
{
}

//�f�X�g���N�^
CSceneMain::~CSceneMain()
{
}

//�Q�[�����C��������
void CSceneMain::InitScene()
{
	Draw::LoadImage(L"image.png", 0, TEX_SIZE_512);

	CObjPlayer* CObj = new CObjPlayer();
	Objs::InsertObj(CObj, OBJ_PLAYER, 1);

	CObjNoRoad* CObj1 = new CObjNoRoad();
	Objs::InsertObj(CObj1, OBJ_NO_ROAD, 1);

	//�O���f�[�^�̓ǂݍ��݁i�X�e�[�W���j
	unique_ptr<wchar_t> p; //�X�e�[�W���|�C���^�[
	int size;			   //�X�e�[�W���傫��
	p = Save::ExternalDataOpen(L"Book1.csv", &size);//�O���f�[�^�ǂݍ���
}

//�Q�[�����C�����s��
void CSceneMain::Scene()
{
}
