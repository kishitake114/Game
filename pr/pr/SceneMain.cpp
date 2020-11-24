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
#include "SceneMain.h"
#include "GameHead.h"
#include "Objplayer.h"
#include "ObjRoad.h"
#include "ObjItem.h"


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
	Audio::LoadAudio(0, L"Stage1.wav", SOUND_TYPE::BACK_MUSIC);

	float Volume = Audio::VolumeMaster(-0.8f);
	Audio::Start(0);



	//Font�쐬
	Font::SetStrTex(L"0123456789���b");
	
	//�O���f�[�^�̓ǂݍ��݁i�X�e�[�W���j
	unique_ptr<wchar_t> p; //�X�e�[�W���|�C���^�[
	int size;			   //�X�e�[�W���傫��
	p = Save::ExternalDataOpen(L"k.csv", &size);//�O���f�[�^�ǂݍ���

	Draw::LoadImage(L"image.png", 0, TEX_SIZE_512);

	CObjPlayer* CObj = new CObjPlayer(0,200.0f);
	Objs::InsertObj(CObj, OBJ_PLAYER, 1);

	CObjEnemy* CObjE = new CObjEnemy();
	Objs::InsertObj(CObjE, OBJ_ENEMY, 1);

	CObjRoad* CObjR = new CObjRoad();
	Objs::InsertObj(CObjR, OBJ_ROAD, 1);

	CObjTime* CObjT = new CObjTime();
	Objs::InsertObj(CObjT, OBJ_TIME, 1);




}

//�Q�[�����C�����s��
void CSceneMain::Scene()
{
	

}
