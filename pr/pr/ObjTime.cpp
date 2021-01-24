//�g�p����w�b�_�[�t�@�C��
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "GameL/WinInputs.h"
#include "GameL/SceneManager.h"
#include "GameHead.h"
#include "ObjTime.h"
#include "ObjRoad.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjTime::Init()
{
	m_flag_time = false;

	mou_r = false;
	mou_l = false;

	plas = 0;

	CObjPlayer* player = (CObjPlayer*)Objs::GetObj(OBJ_PLAYER);

	if (player->num == 1)
	{
		;
	}

	if (player->num == 2)
	{
		plas = 1800;
	}

	if (player->num >= 3)
	{
		plas = 3600;
	}

	m_time = 3600 + plas;
}
//�A�N�V����
void CObjTime::Action()
{
	mou_r = Input::GetMouButtonR();
	mou_l = Input::GetMouButtonL();

	CObjPlayer* player = (CObjPlayer*)Objs::GetObj(OBJ_PLAYER);
	
	if (mou_r == true)
	{
		m_flag_time = false;
		
	}

	//�t���O���I���̎��A���Ԃ����炷
	if (m_flag_time == true)
	{
		m_time--;
	}

	//�O�b�ɂȂ�����A�P���ɖ߂�
	if (m_time == 0)
	{
		player->HP--;		//m_Time��0->PlayerHP��-1����B
		m_time = 3600+plas;
	}


}
//�h���[
void CObjTime::Draw()
{
	//m_time����b�������߂�
	int minute;//��
	int second;//�b

	second = (m_time / 60) % 60;//�b
	minute = (m_time / 60) / 60;//��

	float c[4] = { 1.0f,1.0f, 1.0f, 1.0f, };
	wchar_t str[128];

	Font::StrDraw(L"TIME", 600, 0, 40, c);

	//���F�b�̒l�𕶎���
	if (second < 10)
	{
		swprintf_s(str, L"%d 0%d", minute, second);
	}
	else
	{
		swprintf_s(str, L"%d %d", minute, second);
	}

	Font::StrDraw(str, 720, 0, 40, c);

	if (m_time )
	{
		Font::StrDraw(L":", 740, 0, 40, c);
	}
}