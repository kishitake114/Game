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
	m_time = 3600;
	m_flag_time = false;

	mou_r = false;
	mou_l = false;
}
//�A�N�V����
void CObjTime::Action()
{
	mou_r = Input::GetMouButtonR();
	mou_l = Input::GetMouButtonL();



	if (mou_l == true)
	{
		m_flag_time = true;
	}
    else if (mou_r == true)
	{
		m_flag_time = false;
	}

	//�t���O���I���̎����Ԃ�i�߂�
	if (m_flag_time == true)
	{
		m_time--;
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
	//���F�b�̒l�𕶎���
	if (second < 10)
	{
		swprintf_s(str, L"%d��0%d�b", minute, second);
	}
	else
	{
		swprintf_s(str, L"%d��%d�b", minute, second);
	}

	Font::StrDraw(str, 10, 10, 20, c);
}