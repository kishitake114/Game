#include "ObjRoad.h"
#include "ObjPlayer.h"
#include "GameL/DrawTexture.h"
#include "GameL/DrawFont.h"
#include "GameHead.h" 
#include "GameL/WinInputs.h"
#include "GameL/HitBoxManager.h"
#include "GameL/SceneObjManager.h"
#include "GameL/UserData.h"

#define PIECE 14
#define SIZE 40.0f


//�C�j�V�����C�Y
void CObjRoad::Init()
{
	CObjPlayer* player = (CObjPlayer*)Objs::GetObj(OBJ_PLAYER);
	CObjTime* time = (CObjTime*)Objs::GetObj(OBJ_TIME);

	((UserData*)Save::GetData())->stage=1;
	
	player->num = 1;

	reset = 0;

	mou_x = 0.0f;
	mou_y = 0.0f;
	mou_r = false;
	mou_l = false;

	pxc = 0.0f;
	pyc = 0.0f;

	pv_x = 0.0f;
	pv_y = 0.0f;

	f_p = false;

	s_r = false;
	sei = false;
	swi = false;

	itemc = 0.0f;

	s_time = 240;
	second = 4;
	set = false;


	CObjPlayer* obj = (CObjPlayer*)Objs::GetObj(OBJ_PLAYER);
	obj->p_x = 0.0f;
	obj->p_y = 200.0f;

	obj->s_p = false;



		int mapdata[PIECE][PIECE] =
	{
	{0,0,2,0,0,2,0,0,2,0,0,2,0,0},
	{0,1,2,1,1,2,1,1,1,1,1,1,1,0},
	{2,2,3,2,1,2,1,2,5,1,2,6,2,2},
	{0,1,2,1,1,2,1,1,2,1,1,1,1,0},
	{0,1,2,1,1,2,1,1,1,1,1,1,1,0},
	{2,1,2,1,2,2,2,2,2,1,1,2,2,2},
	{0,1,2,1,1,2,1,1,2,1,1,2,1,0},
	{0,1,1,1,1,2,1,1,2,1,1,2,1,0},
	{2,2,3,2,1,3,2,2,4,2,2,4,1,2},
	{0,1,1,1,1,1,1,1,2,1,1,1,1,0},
	{0,1,1,1,0,0,0,1,2,1,1,1,1,0},
	{2,2,2,2,0,0,0,1,5,1,2,4,2,2},
	{0,1,1,1,0,0,0,1,2,1,1,1,1,0},
	{0,0,2,0,0,2,0,0,2,0,0,2,0,0},
	};

	memcpy(map, mapdata, sizeof(int) * (PIECE * PIECE));

	for (int i = 0; i < PIECE; i++)
	{
		for (int j = 0; j < PIECE; j++)
		{

			memmap[i][j] = map[i][j];

		}
	}

	/*int alfhamap[8][8] =
	{
		{0,0,2,0,0,2,0,0,},
		{0,1,2,1,1,2,1,0,},
		{2,2,2,2,1,2,1,2,},
		{0,1,2,1,1,2,1,0,},
		{0,1,1,1,0,0,0,0,},
		{2,2,2,2,0,0,0,2,},
		{0,1,1,1,0,0,0,0,},
		{0,0,2,0,0,2,0,0,},
	};

	memcpy(map, alfhamap, sizeof(int) * (8 * 8));*/

		int mem[3][3] =
		{
			{0,0,0},
			{0,0,0},
			{0,0,0},
		};
}


//�A�N�V����
void CObjRoad::Action()
{
	CObjTime* time = (CObjTime*)Objs::GetObj(OBJ_TIME);

	if (set == false)
	{
		s_time--;
		if (s_time % 60 == 0)
		{
			second--;
		}
		if (second == 0)
		{
			s_r = true;
			set = true;
			time->m_flag_time = true;
		}	

	}

	CObjPlayer* player = (CObjPlayer*)Objs::GetObj(OBJ_PLAYER);
	CObjEnemy* Enemy = (CObjEnemy*)Objs::GetObj(OBJ_ENEMY);
	float px = player->GetX();
	float py = player->GetY();

	//map�ɃA�N�Z�X

	//�ʍs�s��
	for (int i = 0; i < PIECE; i++)
	{
		for (int j = 0; j < PIECE; j++)
		{
			if (map[i][j]  <= 1)
			{
				float x = j * SIZE;
				float y = i * SIZE;

				if ((px + SIZE > x) && (px < x + SIZE) && (py + SIZE > y) && (py < y + SIZE))
				{
					//�x�N�g���쐬
					float vx = px - x;
					float vy = py - y;

					float len = sqrt(vx * vx + vy * vy);

					float r = atan2(vy, vx);
					r = r * 180.0f / 3.14f;

					if (r <= 0.0f)
					{
						r = abs(r);
					}

					else
					{
						r = 360.0f - abs(r);
					}

					//��
					if (r > 45 && r < 135)
					{
						player->SetVY(y - SIZE);
					}

					//��
					else if (r > 135 && r < 225)
					{
						player->SetVX(x - SIZE);
					}

					//��
					else if (r > 225 && r < 315)
					{
						player->SetVY(y + SIZE);
					}

					else
					{
						player->SetVX(x + SIZE);
					}
				}
	
			}

			
		}

	}
	//�A�C�e���i�P�j
	for (int i = 0; i < PIECE; i++)
	{
		for (int j = 0; j < PIECE; j++)
		{
			if (map[i][j] == 3)
			{
				float x = j * SIZE;
				float y = i * SIZE;

				if ((px + SIZE > x) && (px < x + SIZE) && (py + SIZE > y) && (py < y + SIZE))
				{
					//�x�N�g���쐬
					float vx = px - x;
					float vy = py - y;

					float len = sqrt(vx * vx + vy * vy);

					float r = atan2(vy, vx);
					r = r * 180.0f / 3.14f;

					if (r <= 0.0f)
					{
						r = abs(r);
					}

					else
					{
						r = 360.0f - abs(r);
					}

					if (r > 45 && r < 315)
					{
						if (map[i][j] == 3)
						{
							map[i][j] = 2;
						}

						player->atk++;
					}

				}
			}
		}
	}
	//�A�C�e���i�Q�j
	for (int i = 0; i < PIECE; i++)
	{
		for (int j = 0; j < PIECE; j++)
		{
			if (map[i][j] == 4)
			{
				float x = j * SIZE;
				float y = i * SIZE;

				if ((px + SIZE > x) && (px < x + SIZE) && (py + SIZE > y) && (py < y + SIZE))
				{
					//�x�N�g���쐬
					float vx = px - x;
					float vy = py - y;

					float len = sqrt(vx * vx + vy * vy);

					float r = atan2(vy, vx);
					r = r * 180.0f / 3.14f;

					if (r <= 0.0f)
					{
						r = abs(r);
					}

					else
					{
						r = 360.0f - abs(r);
					}

					if (r > 45 && r < 315)
					{
						if (map[i][j] == 4)
						{
							map[i][j] = 2;
						}

						player->atk+=2;
					}

				}
			}
		}
	}
	//�A�C�e���i�R�j
	for (int i = 0; i < PIECE; i++)
	{
		for (int j = 0; j < PIECE; j++)
		{
			if (map[i][j] == 5)
			{
				float x = j * SIZE;
				float y = i * SIZE;

				if ((px + SIZE > x) && (px < x + SIZE) && (py + SIZE > y) && (py < y + SIZE))
				{
					//�x�N�g���쐬
					float vx = px - x;
					float vy = py - y;

					float len = sqrt(vx * vx + vy * vy);

					float r = atan2(vy, vx);
					r = r * 180.0f / 3.14f;

					if (r <= 0.0f)
					{
						r = abs(r);
					}

					else
					{
						r = 360.0f - abs(r);
					}

					if (r > 45 && r < 315)
					{
						if (map[i][j] == 5)
						{
							map[i][j] = 2;
						}

						player->atk+=3;
					}

				}
			}
		}
	}
	//�񕜃A�C�e��
	for (int i = 0; i < PIECE; i++)
	{
		for (int j = 0; j < PIECE; j++)
		{
			if (map[i][j] == 6)
			{
				float x = j * SIZE;
				float y = i * SIZE;

				if ((px + SIZE > x) && (px < x + SIZE) && (py + SIZE > y) && (py < y + SIZE))
				{
					//�x�N�g���쐬
					float vx = px - x;
					float vy = py - y;

					float len = sqrt(vx * vx + vy * vy);

					float r = atan2(vy, vx);
					r = r * 180.0f / 3.14f;

					if (r <= 0.0f)
					{
						r = abs(r);
					}

					else
					{
						r = 360.0f - abs(r);
					}

					if (r > 45 && r < 315)
					{
						if (map[i][j] == 6)
						{
							map[i][j] = 2;
						}

						if (player->HP < 5)
						{
							player->HP++;
						}
					}

				}
			}
		}
	}

	mou_x = (float)Input::GetPosX();
	mou_y = (float)Input::GetPosY();
	mou_r = Input::GetMouButtonR();
	mou_l = Input::GetMouButtonL();

	//���N���b�N�ō��W���L�^
	if (mou_l == true)
	{
		if (f_p == true)
		{
			pxc = mou_x;
			pyc = mou_y;

			f_p = false;
		}
	}
	else
	{
		f_p = true;

	}


	//���[�h���̃v���O����
	if (s_r == true)
	{
		

		//�E�N���b�N�ő��쒆�~
		if (mou_r == true)
		{
			s_r = false;
			Enemy->atk = false;
		}

		//1���1�}�X��
		if (mou_x > 40.0f && mou_x < 155.0f && mou_y>40.0f && mou_y < 155.0f)
		{

			if (mou_l == true)
			{
				//�P��ځi�P�}�X�ځj���i�E�j1�}�X�ړ��@
				if (map[1][4] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[1 + i][1 + j];
						}
							

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][1 + j] = 0;

						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][4 + j] = mem[i][j];
				
						}
					
					}

				}

				//�P��ځi�P�}�X�ځj���i���j1�}�X�ړ��@
				if (map[4][1] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[1 + i][1 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][1 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][1 + j] = mem[i][j];
							pv_y = -120;
						}
					}
				}
			}
		}

		//1��ڂQ�}�X�� 
		if (mou_x > 155.0f && mou_x < 273.0f && mou_y>40.0f && mou_y < 155.0f)
		{
			if (mou_l == true)
			{
				//�P��ځi2�}�X�ځj���i���j1�}�X�ړ��@
				if (map[4][4] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[1 + i][4 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][4 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][4 + j] = mem[i][j];
							pv_y = -120.0f;
						}
					}

				}

				//�P��ځi2�}�X�ځj���i���j1�}�X�ړ��@
				if (map[1][1] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[1 + i][4 + j];

						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][4 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][1 + j] = mem[i][j];
							pv_x = -120.0f;
						}
					}

				}

				//�P��ځi2�}�X�ځj���i�E�j1�}�X�ړ��@
				if (map[1][7] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[1 + i][4 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][4 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][7 + j] = mem[i][j];
							pv_x = -120.0f;
						}
					}

				}
			}
		}

		//1��ځi3�}�X�ځj
		if (mou_x > 274.0f && mou_x < 394.0f && mou_y>40.0f && mou_y < 155.0f)
		{
			if (mou_l == true)
			{

				//�i�R�}�X�ځj���i���j1�}�X�ړ�
				if (map[4][7] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[1 + i][7 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][7 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][7 + j] = mem[i][j];
							pv_y = -120.0f;
						}
					}
				}
				//�P��ځi�R�}�X�ځj���i���j1�}�X�ړ�
				if (map[1][4] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[1 + i][7 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][7 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][4 + j] = mem[i][j];
							pv_x = 120.0f;
						}
					}
				}
				//�P��ځi�R�}�X�ځj���i�E�j1�}�X�ړ�
				if (map[1][10] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[1 + i][7 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][7 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][10 + j] = mem[i][j];
							pv_x = -120.0f;
						}
					}

				}
			}
		}

		//1��ڂS�}�X��
		if (mou_x > 395.0f && mou_x < 520.0f && mou_y>40.0f && mou_y < 155.0f)
		{
			if (mou_l == true)
			{

				//�P��ځi�S�}�X�ځj���i���j1�}�X�ړ�
				if (map[4][10] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[1 + i][10 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][10 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][10 + j] = mem[i][j];
							pv_x = 120.0f;
						}
					}
				}
				//�P��ځi�S�}�X�ځj���i���j1�}�X�ړ�
				if (map[1][7] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[1 + i][10 + j];

					
						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][10 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][7 + j] = mem[i][j];
							pv_x = 120.0f;
						}
					}
				}
			}
		}

		//2���
		if (mou_x > 40.0f && mou_x < 155.0f && mou_y>156.0f && mou_y < 273.0f)
		{
			if (mou_l == true)
			{
				//2��ځi�P�}�X�ځj���i��j1�}�X�ړ�
				if (map[1][1] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[4 + i][1 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][1 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][1 + j] = mem[i][j];
							pv_y += 120;
						}
					}
				}

				//2��ځi�P�}�X�ځj���i�E�j1�}�X�ړ�
				if (map[4][4] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[4 + i][1 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][1 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][4 + j] = mem[i][j];
							pv_x = 120;
						}
					}
				}

				//2��ځi�P�}�X�ځj���i���j1�}�X�ړ�
				if (map[7][1] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[4 + i][1 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][1 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][1 + j] = mem[i][j];
							pv_x = 120;
						}
					}
				}
			}
		}

		//2��ځi2�}�X�ځj
		if (mou_x > 156.0f && mou_x < 273.0f && mou_y>156.0f && mou_y < 273.0f)
		{
			if (mou_l == true)
			{
				//2��ځi2�}�X�ځj���i���j1�}�X�ړ�
				if (map[4][1] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[4 + i][4 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][4 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][1 + j] = mem[i][j];
							pv_x = -120;
						}
					}

				}

				//2��ځi2�}�X�ځj���i��j1�}�X�ړ�
				if (map[1][4] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[4 + i][4 + j];

						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][4 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][4 + j] = mem[i][j];
							pv_y = 120;
						}
					}
				}

				//2��ځi2�}�X�ځj���i�E�j1�}�X�ړ�
				if (map[7][4] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[4 + i][4 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][4 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][4 + j] = mem[i][j];
							pv_y = 120;
						}
					}
				}

				//2��ځi2�}�X�ځj���i���j1�}�X�ړ�
				if (map[4][7] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[4 + i][4 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][4 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][7 + j] = mem[i][j];
							pv_y = 120;
						}
					}
				}
			}
		}

		//2��ځi3�}�X�ځj
		if (mou_x > 274.0f && mou_x < 394.0f && mou_y>155.0f && mou_y < 274.0f)
		{
			if (mou_l == true)
			{
				//2��ځi3�}�X�ځj���i���j1�}�X�ړ�
				if (map[4][4] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[4 + i][7 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][7 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][4 + j] = mem[i][j];
							pv_x = -120;
						}
					}

				}

				//2��ځi3�}�X�ځj���i��j1�}�X�ړ�
				if (map[1][7] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[4 + i][7 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][7 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][7 + j] = mem[i][j];
							pv_y = 120;
						}
					}
				}

				//2��ځi3�}�X�ځj���i�E�j1�}�X�ړ�
				if (map[4][10] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[4 + i][7 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][7 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][10 + j] = mem[i][j];
							pv_y = 120;
						}
					}
				}

				//2��ځi3�}�X�ځj���i���j1�}�X�ړ�
				if (map[7][7] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[4 + i][7 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][7 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][7 + j] = mem[i][j];
							pv_y = 120;
						}
					}
				}
			}
		}

		//2��ځi4�}�X�ځj
		if (mou_x > 394.0f && mou_x < 520.0f && mou_y>156.0f && mou_y < 273.0f)
		{
			if (mou_l == true)
			{
				//2��ځi4�}�X�ځj���i���j1�}�X�ړ�
				if (map[4][7] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[4 + i][10 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][10 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][7 + j] = mem[i][j];
							pv_x = -120;
						}
					}

				}

				//2��ځi4�}�X�ځj���i��j1�}�X�ړ�
				if (map[1][10] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[4 + i][10 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][10 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[1 + i][10 + j] = mem[i][j];
							pv_y = 120;
						}
					}
				}

				//2��ځi4�}�X�ځj���i���j1�}�X�ړ�
				if (map[7][10] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[4 + i][10 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][10 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][10 + j] = mem[i][j];
							pv_y = 120;
						}
					}
				}
			}
		}

		//3���
		if (mou_x > 40.0f && mou_x < 155.0f && mou_y>274.0f && mou_y < 394.0f)
		{
			if (mou_l == true)
			{
				//3��ځi�P�}�X�ځj���i��j1�}�X�ړ�
				if (map[4][1] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[7 + i][1 + j];

						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][1 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][1 + j] = mem[i][j];
							pv_y += 120;
						}
					}
				}

				//3��ځi�P�}�X�ځj���i�E�j1�}�X�ړ�
				if (map[7][4] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[7 + i][1 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][1 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][4 + j] = mem[i][j];
							pv_x = 120;
						}
					}
				}

				//3��ځi�P�}�X�ځj���i���j1�}�X�ړ�
				if (map[10][1] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[7 + i][1 + j];

						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][1 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][1 + j] = mem[i][j];
							pv_x = 120;
						}
					}
				}
			}
		}

		//3��ځi2�}�X�ځj
		if (mou_x > 156.0f && mou_x < 273.0f && mou_y>274.0f && mou_y < 394.0f)
		{
			if (mou_l == true)
			{
				//3��ځi2�}�X�ځj���i���j1�}�X�ړ�
				if (map[7][1] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[7 + i][4 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][4 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][1 + j] = mem[i][j];
							pv_x = -120;
						}
					}

				}

				//3��ځi2�}�X�ځj���i��j1�}�X�ړ�
				if (map[4][4] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[7 + i][4 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][4 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][4 + j] = mem[i][j];
							pv_y = 120;
						}
					}
				}

				//3��ځi2�}�X�ځj���i�E�j1�}�X�ړ�
				if (map[7][7] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[7 + i][4 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][4 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][7 + j] = mem[i][j];
							pv_y = 120;
						}
					}
				}

				//3��ځi2�}�X�ځj���i���j1�}�X�ړ�
				if (map[10][4] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[7 + i][4 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][4 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][4 + j] = mem[i][j];
							pv_y = 120;
						}
					}
				}
			}
		}

		//3��ځi3�}�X�ځj
		if (mou_x > 274.0f && mou_x < 393.0f && mou_y>274.0f && mou_y < 394.0f)
		{
			if (mou_l == true)
			{
				//3��ځi3�}�X�ځj���i���j1�}�X�ړ�
				if (map[7][4] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[7 + i][7 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][7 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][4 + j] = mem[i][j];
							pv_x = -120;
						}
					}

				}

				//3��ځi3�}�X�ځj���i��j1�}�X�ړ�
				if (map[4][7] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[7 + i][7 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][7 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][7 + j] = mem[i][j];
							pv_y = 120;
						}
					}
				}

				//3��ځi3�}�X�ځj���i�E�j1�}�X�ړ�
				if (map[7][10] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[7 + i][7 + j];

						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][7 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][10 + j] = mem[i][j];
							pv_y = 120;
						}
					}
				}

				//3��ځi3�}�X�ځj���i���j1�}�X�ړ�
				if (map[10][7] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[7 + i][7 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][7 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][7 + j] = mem[i][j];
							pv_y = 120;
						}
					}
				}
			}
		}

		//3��ځi4�}�X�ځj
		if (mou_x > 394.0f && mou_x < 520.0f && mou_y>274.0f && mou_y < 394.0f)
		{
			if (mou_l == true)
			{
				//3��ځi4�}�X�ځj���i���j1�}�X�ړ�
				if (map[7][7] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[7 + i][10 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][10 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][7 + j] = mem[i][j];
							pv_x = -120;
						}
					}

				}

				//3��ځi4�}�X�ځj���i��j1�}�X�ړ�
				if (map[4][10] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[7 + i][10 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][10 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[4 + i][10 + j] = mem[i][j];
							pv_y = 120;
						}
					}
				}

				//3��ځi4�}�X�ځj���i���j1�}�X�ړ�
				if (map[10][10] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[7 + i][10 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][10 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][10 + j] = mem[i][j];
							pv_y = 120;
						}
					}
				}
			}
		}

		//4���
		if (mou_x > 40.0f && mou_x < 155.0f && mou_y>394.0f && mou_y < 520.0f)
		{
			if (mou_l == true)
			{
				//4��ځi�P�}�X�ځj���i��j1�}�X�ړ�
				if (map[7][1] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[10 + i][1 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][1 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][1 + j] = mem[i][j];
							pv_y += 120;
						}
					}
				}

				//4��ځi�P�}�X�ځj���i�E�j1�}�X�ړ�
				if (map[10][4] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[10 + i][1 + j];

							
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][1 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][4 + j] = mem[i][j];
							pv_x = 120;
						}
					}
				}
			}
		}

		//4��ځi2�}�X�ځj
		if (mou_x > 156.0f && mou_x < 273.0f && mou_y>394.0f && mou_y < 520.0f)
		{
			if (mou_l == true)
			{
				//4��ځi2�}�X�ځj���i���j1�}�X�ړ�
				if (map[10][1] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[10 + i][4 + j];

					
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][4 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][1 + j] = mem[i][j];
							pv_x = -120;
						}
					}

				}

				//4��ځi2�}�X�ځj���i��j1�}�X�ړ�
				if (map[7][4] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[10 + i][4 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][4 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][4 + j] = mem[i][j];
							pv_y = 120;
						}
					}
				}

				//4��ځi2�}�X�ځj���i�E�j1�}�X�ړ�
				if (map[10][7] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[10 + i][4 + j];

						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][4 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][7 + j] = mem[i][j];
							pv_y = 120;
						}
					}
				}
			}
		}

		//4��ځi3�}�X�ځj
		if (mou_x > 274.0f && mou_x < 393.0f && mou_y> 394.0f && mou_y < 520.0f)
		{
			if (mou_l == true)
			{
				//4��ځi3�}�X�ځj���i���j1�}�X�ړ�
				if (map[10][4] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[10 + i][7 + j];

						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][7 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][4 + j] = mem[i][j];
							pv_x = -120;
						}
					}

				}

				//4��ځi3�}�X�ځj���i��j1�}�X�ړ�
				if (map[7][7] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[10 + i][7 + j];

		
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][7 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][7 + j] = mem[i][j];
							pv_y = 120;
						}
					}
				}

				//4��ځi3�}�X�ځj���i�E�j1�}�X�ړ�
				if (map[10][10] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[10 + i][7 + j];

						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][7 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][10 + j] = mem[i][j];
							pv_y = 120;
						}
					}
				}
			}
		}

		//4��ځi4�}�X�ځj
		if (mou_x > 394.0f && mou_x < 520.0f && mou_y>394.0f && mou_y < 520.0f)
		{
			if (mou_l == true)
			{
				//4��ځi4�}�X�ځj���i���j1�}�X�ړ�
				if (map[10][7] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[10 + i][10 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][10 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][7 + j] = mem[i][j];
							pv_x = -120;
						}
					}

				}

				//4��ځi4�}�X�ځj���i��j1�}�X�ړ�
				if (map[7][10] == 0)
				{
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							mem[i][j] = map[10 + i][10 + j];
						}

						for (int j = 0; j < 3; j++)
						{
							map[10 + i][10 + j] = 0;
						}

						for (int j = 0; j < 3; j++)
						{
							map[7 + i][10 + j] = mem[i][j];
							pv_y = 120;
						}
					}
				}
			}
		}

	}

	if (player->battle == true)
	{
		
		if (pxc > 444.0f && pxc < 765.0f && pyc>301 && pyc < 312)
		{
			player->battle = false;
			Scene::SetScene(new CSceneStage2);

			if (player->HP == 5 && reset == 0)
			{
				((UserData*)Save::GetData())->Hperfect++;
			}
		}


		s_r = false;
	}

	//���Z�b�g�{�^���̃v���O����
	if (s_r == false&&set==true)
	{
		if (mou_x > 645.0f && mou_x < 764.0f && mou_y>497.0f && mou_y < 533.0f)
		{
			if (mou_l == true)
			{
				for (int i = 0; i < PIECE; i++)
				{
					for (int j = 0; j < PIECE; j++)
					{
						map[i][j] = memmap[i][j];
					}
				}

				time->m_time = 3600;
				time->m_flag_time = false;

				s_r = true;

				player->s_p = false;

				player->p_x = player->memp_x;
				player->p_y = player->memp_y;

				player->atk = 0;

				reset++;

			}
		}
	}
}

//�h���[
void CObjRoad::Draw()
{

	float c[4]  = { 1.0f,1.0f,1.0f,1.0f };
	float r[4]  = { 1.0f,0.0f,0.0f,1.0f };
	float g[4]  = { 0.0f,1.0f,0.0f,1.0f };
	float b[4]  = { 0.0f,0.0f,1.0f,1.0f };
	float gl[4] = { 0.3f,0.3f,0.3f,1.0f };
	float y[4] = { 1.0f,1.0f,0.0f,1.0f };
	float p[4] = { 1.0f,0.5f,0.5f,1.0f };

	RECT_F src;
	RECT_F dst;

	//�\���F�}�E�X�J�[�\���ƃ{�^��
	wchar_t str[256];

	CObjEnemy* Enemy = (CObjEnemy*)Objs::GetObj(OBJ_ENEMY);
	CObjPlayer* player = (CObjPlayer*)Objs::GetObj(OBJ_PLAYER);

	if (set == false)
	{
		if (second > 1)
		{
			swprintf_s(str, L"%d", second-1);
			Font::StrDraw(str, 642, 350, 100, c);
		}
		else
		{
			Font::StrDraw(L"GO!", 642, 350, 100, r);
		}
	}


	if (s_r == true)
	{
		Font::StrDraw(L"Road", 600, 30, 40, r);
	}

	if (player->battle == false)
	{

		if (s_r == true||set==false)
		{
			swprintf_s(str, L"RESET");
			Font::StrDraw(str, 650, 500, 50, gl);
		}

		else
		{
			swprintf_s(str, L"RESET");
			Font::StrDraw(str, 650, 500, 50, b);
		}
	}
	else
	{
		if (player->HP == 5 && reset==0)
		{ 
			Font::StrDraw(L"PERFECT", 600, 250, 30, y);
		}

		else
		{
			Font::StrDraw(L"YOU WIN", 600, 250, 30, c);

			swprintf_s(str, L"�󂯂��_���[�W: %d",5-player->HP);
			Font::StrDraw(str, 580, 350, 20, c);

			swprintf_s(str, L"���Z�b�g��: %d", reset);
			Font::StrDraw(str, 580, 375, 20, c);
		}
			

		Font::StrDraw(L"Next", 650, 300, 25, c);
	}
	//�\���F�ʍs��


	src.m_top = 90.0f;
	src.m_left = 45.0f;
	src.m_right = 85.0f;
	src.m_bottom = 125.0f;
	
	for (int i = 0; i < PIECE; i++)
	{
		for (int j = 0; j < PIECE; j++)
		{

			if (map[i][j] == 2)
			{
				dst.m_top = i * SIZE;
				dst.m_left = j * SIZE;
				dst.m_right = dst.m_left + SIZE;
				dst.m_bottom = dst.m_top + SIZE;

				Draw::Draw(0, &src, &dst, c, 0.0f);
			}

		}
	}

	//�\���F�ʍs�s��

	src.m_top = 90.0f;
	src.m_left = 0.0f;
	src.m_right = 45.0f;
	src.m_bottom = 125.0f;

	for (int i = 0; i < PIECE; i++)
	{
		for (int j = 0; j < PIECE; j++)
		{
			if (map[i][j] == 1)
			{
				dst.m_top = i * SIZE;
				dst.m_left = j * SIZE;
				dst.m_right = dst.m_left + SIZE;
				dst.m_bottom = dst.m_top + SIZE;

				Draw::Draw(0, &src, &dst, c, 0.0f);

			}
		}
	}
	
	//�\���F�A�C�e��1
	src.m_top = 130.0f;
	src.m_left = 1.0f;
	src.m_right = 51.0f;
	src.m_bottom = 180.0f;

	for (int i = 0; i < PIECE; i++)
	{
		for (int j = 0; j < PIECE; j++)
		{
			if (map[i][j] == 3)
			{
				dst.m_top = i * SIZE;
				dst.m_left = j * SIZE;
				dst.m_right = dst.m_left + SIZE;
				dst.m_bottom = dst.m_top + SIZE;

				Draw::Draw(0, &src, &dst, c, 0.0f);

			}
		}
	}
	src.m_top = 130.0f;
	src.m_left = 152.0f;
	src.m_right = 203.0f;
	src.m_bottom = 180.0f;

	//�\���F�񕜃A�C�e��
	for (int i = 0; i < PIECE; i++)
	{
		for (int j = 0; j < PIECE; j++)
		{
			if (map[i][j] == 6)
			{
				dst.m_top = i * SIZE;
				dst.m_left = j * SIZE;
				dst.m_right = dst.m_left + SIZE;
				dst.m_bottom = dst.m_top + SIZE;

				Draw::Draw(0, &src, &dst, c, 0.0f);

			}
		}
	}


	//�\���F�A�C�e��2
	src.m_top = 130.0f;
	src.m_left = 52.0f;
	src.m_right = 101.0f;
	src.m_bottom = 180.0f;

	for (int i = 0; i < PIECE; i++)
	{
		for (int j = 0; j < PIECE; j++)
		{
			if (map[i][j] == 4)
			{
				dst.m_top = i * SIZE;
				dst.m_left = j * SIZE;
				dst.m_right = dst.m_left + SIZE;
				dst.m_bottom = dst.m_top + SIZE;

				Draw::Draw(0, &src, &dst, c, 0.0f);

			}
		}
	}

	//�\���F�A�C�e��3
	src.m_top = 130.0f;
	src.m_left = 102.0f;
	src.m_right = 151.0f;
	src.m_bottom = 180.0f;

	for (int i = 0; i < PIECE; i++)
	{
		for (int j = 0; j < PIECE; j++)
		{
			if (map[i][j] == 5)
			{
				dst.m_top = i * SIZE;
				dst.m_left = j * SIZE;
				dst.m_right = dst.m_left + SIZE;
				dst.m_bottom = dst.m_top + SIZE;

				Draw::Draw(0, &src, &dst, c, 0.0f);

			}
		}
	}


}


