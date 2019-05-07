#include "stdafx.h"
#include "ScnMgr.h"
#include "Renderer.h"
#include "Object.h"
#include "Item.h"


ScnMgr::ScnMgr()
{
	m_Renderer = NULL;
	m_Objects[HERO_ID] = NULL;

	// Initialize Renderer
	m_Renderer = new Renderer(500, 500);
	m_Map = new Map(m_Renderer);
	m_item = new Item();
	if (!m_Renderer->IsInitialized())
	{
		std::cout << "Renderer could not be initialized.. \n";
	}


	for (int i = 0; i < MAX_OBJECTS; ++i)
	{
		m_Objects[i] = NULL;
	}

	//Creat hero object
	m_Objects[HERO_ID] = new Object();
	m_Objects[HERO_ID]->setPosition(0.0f, 0.0f, 0.0f);
	m_Objects[HERO_ID]->setColor(1.0f, 0.7f, 0.6f, 1.0f);
	m_Objects[HERO_ID]->setSize(0.7f, 0.7f, 0.7f);
	m_Objects[HERO_ID]->setVel(0.0f, 0.f, 0.f);
	m_Objects[HERO_ID]->setAcc(0.f, 0.f, 0.f);
	m_Objects[HERO_ID]->setMass(5.f);
	m_Objects[HERO_ID]->setFrictional_num(0.1f);
	m_Objects[HERO_ID]->setFrictional(1.f);
	m_Objects[HERO_ID]->SetKind(KIND_HERO);
	m_Objects[HERO_ID]->setHP(10000);


	m_Sound = new Sound();




	 m_ob = new Obstacle(m_Renderer);
	Load_Images();
	Load_Sounds();


	Stage1_Obstacle();// �ϴ� ����ٰ� stage1
	stage1 = true;
	m_Sound->PlaySound(m_SoundBG, true, 3.f);
}

void ScnMgr::Load_Images() {

	//����캼
	Snowball_Texture = m_Renderer->CreatePngTexture("./textures/Effect/snowball.png"); //

	// �� ��ƼŬ
	m_snowParticle = m_Renderer->CreatePngTexture("./textures/Effect/snowflake.png"); //


	// ��Ÿ �÷��̾�
	Player_texture = m_Renderer->CreatePngTexture("./textures/Player/santa_cloud.png"); //

	// press key
	Start_Press = m_Renderer->CreatePngTexture("./textures/start.png"); // 700,100 4
	Start_Bg = m_Renderer->CreatePngTexture("./textures/start_window.png");

	Number_image[0] = m_Renderer->CreatePngTexture("./textures/number/number_0.png");
	Number_image[1] = m_Renderer->CreatePngTexture("./textures/number/number_1.png");
	Number_image[2] = m_Renderer->CreatePngTexture("./textures/number/number_2.png");
	Number_image[3] = m_Renderer->CreatePngTexture("./textures/number/number_3.png");
	Number_image[4] = m_Renderer->CreatePngTexture("./textures/number/number_4.png");
	Number_image[5] = m_Renderer->CreatePngTexture("./textures/number/number_5.png");
	Number_image[6] = m_Renderer->CreatePngTexture("./textures/number/number_6.png");
	Number_image[7] = m_Renderer->CreatePngTexture("./textures/number/number_7.png");
	Number_image[8] = m_Renderer->CreatePngTexture("./textures/number/number_8.png");
	Number_image[9] = m_Renderer->CreatePngTexture("./textures/number/number_9.png");


	Over_Bg = m_Renderer->CreateBmpTexture("./textures/game_over.png");
	End_Bg = m_Renderer->CreatePngTexture("./textures/clear.png");

	Howto_image = m_Renderer->CreatePngTexture("./textures/howto.png");

	b_width = (WIDTH_SIZE / MAP_SEPERATE) / 100.f;
	b_height = (HEIGHT_SIZE / MAP_SEPERATE) / 100.f;


}
void ScnMgr::Load_Sounds() {
	m_SoundBG = m_Sound->CreateSound("./Sounds/BGM.mp3");
	m_SoundFire = m_Sound->CreateSound("./Sounds/shoot.wav");
	m_SoundExplosion = m_Sound->CreateSound("./Sounds/item.wav");
	m_ClearSound = m_Sound->CreateSound("./Sounds/Clear.mp3");
}
void ScnMgr::Draw_BG(int i) {

	switch (i) {
	case 0:
		// \����ȭ�� 
		start_window = true;
		break;
	case 1:
		start_window = false;
		m_Map->Stage1_map();
		
		break;
	case 2:
		m_Map->Stage2_map();
		break;
	case 3:

		
		gameEnd = true;
		// ��
		break;
	case 4:
		gameover = true;

		// ���ӿ���
		break;

	}

}


void ScnMgr::Stage1_Obstacle() {

	// ������ ��


	AddObject(2.2f, 1.9f, 0.5f,
		1.0f,1.5f,1.5f,
		0.f, 0.f, 0.f,
		DOOR_RIGHT,
		10000000000000,
		STATE_GROUND, FLT_MAX);


	// �̲���Ʋ

	AddObject(1.3f, 0.3f, 0.0f,
		1.5f, 1.5f, 0.5f,
		0.f, 0.f, 0.f,
		KIND_OBSTACLE_SLIDE,
		100,
		STATE_GROUND, FLT_MAX);


	// duck
	AddObject(-2.2f, 0.f, 0.0f,
		1.f, 1.f, 1.f,
		0.f, 0.f, 0.f,
		KIND_OBSTACLE_DUCK,
		100,
		STATE_GROUND, FLT_MAX);
	// duck
	AddObject(-2.2f, -1.5f, 0.0f,
		1.f, 1.f, 1.f,
		0.f, 0.f, 0.f,
		KIND_OBSTACLE_DUCK,
		100,
		STATE_GROUND, FLT_MAX);

	////fountain
	//AddObject(-2.f, -2.f, 0.0f,
	//	1.f, 1.f, 0.5f,
	//	0.f, 0.f, 0.f,
	//	KIND_OBSTACLE_FOUNTAIN,
	//	100,
	//	STATE_GROUND, FLT_MAX);

	// Tent
	AddObject(0.8f, 1.5f, 0.0f,
		1.f, 1.f, 0.5f,
		0.f, 0.f, 0.f,
		KIND_OBSTACLE_TENT,
		200,
		STATE_GROUND, FLT_MAX);




}
void ScnMgr::Stage1_2_Obstacle() {




	// �̲���Ʋ

	AddObject(1.3f, 0.3f, 0.0f,
		1.5f, 1.5f, 0.5f,
		0.f, 0.f, 0.f,
		KIND_OBSTACLE_SLIDE,
		100,
		STATE_GROUND, FLT_MAX);


	// duck
	AddObject(-2.2f, 0.f, 0.0f,
		1.f, 1.f, 1.f,
		0.f, 0.f, 0.f,
		KIND_OBSTACLE_DUCK,
		100,
		STATE_GROUND, FLT_MAX);
	// duck
	AddObject(-2.2f, -1.5f, 0.0f,
		1.f, 1.f, 1.f,
		0.f, 0.f, 0.f,
		KIND_OBSTACLE_DUCK,
		100,
		STATE_GROUND, FLT_MAX);

	////fountain
	//AddObject(-2.f, -2.f, 0.0f,
	//	1.f, 1.f, 0.5f,
	//	0.f, 0.f, 0.f,
	//	KIND_OBSTACLE_FOUNTAIN,
	//	100,
	//	STATE_GROUND, FLT_MAX);

	// Tent
	AddObject(0.8f, 1.5f, 0.0f,
		1.f, 1.f, 0.5f,
		0.f, 0.f, 0.f,
		KIND_OBSTACLE_TENT,
		200,
		STATE_GROUND, FLT_MAX);




}
void ScnMgr::Stage2_Obstacle() {

	// ���� ��

	AddObject(-2.2f, 1.9f, 0.5f,
		1.5f, 1.5f, 1.5f,
		0.f, 0.f, 0.f,
		DOOR_LEFT,
		10000000000000,
		STATE_GROUND, FLT_MAX);



	// ����
	AddObject(1.4f, 0.3f, 0.0f,
		1.f, 1.f, 0.5f,
		0.f, 0.f, 0.f,
		KIND_OBSTACLE_FOUNTAIN,
		160,
		STATE_GROUND, FLT_MAX);
	AddObject(1.8f, 0.3f, 0.0f,
		1.f, 1.f, 0.5f,
		0.f, 0.f, 0.f,
		KIND_OBSTACLE_FOUNTAIN, 
		160,
		STATE_GROUND, FLT_MAX);


	//��
	AddObject(1.0f, 0.3f, 0.0f,
		1.f, 1.f, 0.5f,
		0.f, 0.f, 0.f,
		KIND_OBSTACLE_DUCK,
		160,
		STATE_GROUND, FLT_MAX);

	AddObject(0.7f, 0.3f, 0.0f,
		1.f, 1.f, 0.5f,
		0.f, 0.f, 0.f,
		KIND_OBSTACLE_DUCK,
		160,
		STATE_GROUND, FLT_MAX);

	//��
	AddObject(2.3f, -1.3f, 0.0f,
		1.f, 1.f, 0.5f,
		0.f, 0.f, 0.f,
		KIND_OBSTACLE_TENT,
		240,
		STATE_GROUND, FLT_MAX);

	//Ŭ��
	AddObject(-1.f, -2.f, 0.0f,
		1.f, 1.f, 0.5f,
		0.f, 0.f, 0.f,
		KIND_OBSTACLE_SLIDE,
		160,
		STATE_GROUND, FLT_MAX);
	AddObject(-0.6f, -2.f, 0.0f,
		1.f, 1.f, 0.5f,
		0.f, 0.f, 0.f,
		KIND_OBSTACLE_SLIDE,
		160,
		STATE_GROUND, FLT_MAX);
	AddObject(-0.2f, -2.f, 0.0f,
		1.f, 1.f, 0.5f,
		0.f, 0.f, 0.f,
		KIND_OBSTACLE_SLIDE,
		160,
		STATE_GROUND, FLT_MAX);


	//������
	//AddObject(-2.f, -2.f, 0.0f,
	//	0.5f, 0.5f, 0.5f,
	//	0.f, 0.f, 0.f,
	//	KIND_OBSTACLE_CIRCLE_STONE,
	//	200,
	//	STATE_GROUND, FLT_MAX);
}
void ScnMgr::KeyInput(unsigned char key, int x, int y)
{

	// ���� simplegame.cpp���� �̰� key�Լ��� manager->KeyInput���� ȣ�� ���ϴϱ� �ִ� �� �ʿ����


}

int g_seq = 0;
float g_time = 0;
void ScnMgr::RenderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1, 1, 1.f, 0.2f);

	m_Objects[HERO_ID]->getHP(&player_hp_bar);

	player_hp_bar /= 100;

	
	Draw_BG(status);

	for (int i = 0; i < MAX_OBJECTS; ++i)
	{
		if (m_Objects[i] != NULL)
		{
			float x, y, z, sizeX, sizeY, sizeZ, r, b, g, a;
			int kind;
			m_Objects[i]->getPosition(&x, &y, &z);
			m_Objects[i]->getSize(&sizeX, &sizeY, &sizeZ);
			m_Objects[i]->getColor(&r, &g, &b, &a);
			m_Objects[i]->GetKind(&kind);
			// Renderer Test


			std::cout << y << std::endl;

			if (y > 50 || y < -50 || x < -50 || x > 50) {
				status = 4;
			}
			//int seqX, seqY;
			//seqX = g_seq % 4; //%����Ÿ�ϰ���
			//seqY = (int)(g_seq / 4);
			//g_seq++;
			//if (g_seq > 15)
			//	g_seq = 0;

			float newX, newY, newZ, newW, newH;

			newX = x * 100.f;
			newY = y * 100.f;
			newZ = z * 100.f;
			newW = sizeX * 80.f;
			newH = sizeY * 80.f;

			if (start_window) {

				start_index++;
				
				int index = 0;
				if (start_index / 50==0) {
					index = 0;
				}
				else if (start_index / 50 == 1) {
					index = 1;
				}
				else if (start_index / 50 == 2) {
					index = 2;
				}
				else if (start_index / 50 == 3) {
					index = 3;
				}
				else if (start_index / 50 == 4) {
					index = 0;
					start_index = 0;
				}
				m_Renderer->DrawTextureRectDepth(0,0, 0, 1280, 720, 1, 1, 1, 1, Start_Bg, 1);

				if (!howto_window) {
					m_Renderer->DrawTextureRectSeqXYHeight(
						0, -150, 1, 300, 80, r, g, b, a,
						Start_Press, index, 0, 4, 1, newZ);
				}
				if (howto_window) {
					m_Renderer->DrawTextureRectHeight(
						0, -100, 1, 300, 380, 1, 1, 1, 1, Howto_image, 1);
				}
			}
			else if (gameEnd) {
				m_Renderer->DrawTextureRectDepth(0, 0, 0, 1280, 720, 1, 1, 1, 1, End_Bg, 1);
			}
			else if (gameover) {
				m_Renderer->DrawTextureRectDepth(0, 0, 0, 1280, 720, 1, 1, 1, 1, Over_Bg, 1);
			}
			else {
	
				m_item->GetCoin(&coin);

				GLuint temp_10=0;
				GLuint temp_1=0;

				int count_10_coin;
				int count_1_coin;

				count_10_coin = coin / 10;
				count_1_coin = coin % 10;
				m_Renderer->DrawTextureRectDepth(-230 , 230, 1, 30, 30, 1, 1, 1, 1, Number_image[count_10_coin], 0.f);
				m_Renderer->DrawTextureRectDepth(-230+20 , 230, 1, 30, 30, 1, 1, 1, 1, Number_image[count_1_coin], 0.f);

				m_Renderer->DrawParticleClimate(
					0, 0, 1,
					1,
					1, 1, 1, 1,
					-1.0f, 0.1f,
					m_snowParticle,
					0.5f,
					g_time);

				if (kind == KIND_HERO) {

					float age = m_Objects[i]->getAge();
					float seqNum = age / 0.1f;
					int seqNumInt = ((int)seqNum) % 4; // �� �̹��� �����
					seqNum *= 4.f;

					int seqX, seqY;
					seqX = ((int)g_seq) % 4;  // ���� Ÿ�� ����
					seqY = ((int)g_seq / 4);

					g_seq++;
					if (g_seq > 12) {
						g_seq = 0;
					}
					m_Renderer->DrawSolidRectGauge(
						newX, newY + newH, 1, newW, 3,0,0,0, 1, newZ, (float)player_hp_bar/100
					);
					m_Renderer->DrawTextureRectSeqXYHeight(
						newX, newY, 1, newW, newH, r, g, b, a,
						Player_texture, seqNumInt, 0, 4, 1, newZ);
				}
				else if (kind == KIND_BULLET) {
					m_Renderer->DrawTextureRectHeight(
						newX, newY, 1, newW, newH, 1, 1, 1, 1, Snowball_Texture, newZ);
				}
				else if (kind == KIND_EFFECT_HIT) {

					float age = m_Objects[i]->getAge();
					float seqNum = age / 0.1f;
					int seqNumInt = ((int)seqNum) % 5;//
					seqNum *= 5.f;//�� �̹��� ����

					int seqX, seqY;
					seqX = ((int)g_seq) % 5; //%����Ÿ�ϰ���
					seqY = (int)(g_seq / 5);
					g_seq++;
					if (g_seq > 15)
						g_seq = 0;
					m_ob->Draw_Effect(newX, newY, newZ, seqNumInt, shoot_random);

				}
				else if (kind == KIND_HOUSE) {
					m_ob->Draw_House(newX,newY,newZ,newW,newH);
				}
				else if (kind == KIND_OBSTACLE_DUCK) {
					m_ob->Draw_Duck(newX, newY, newZ,newW, newH);
				}
				else if (kind == KIND_OBSTACLE_FOUNTAIN) {
					m_ob->Draw_Fountain(newX, newY, newZ,newW,newH);
				}
				else if (kind == KIND_OBSTACLE_SLIDE) {
					m_ob->Draw_Slide(newX, newY, newZ, newW, newH);
				}
				else if (kind == KIND_OBSTACLE_TENT) {
					m_ob->Draw_Tent(newX, newY, newZ, newW, newH);
				}
				else if (kind == DOOR_RIGHT) {
					m_ob->Draw_RightDoor(newX, newY, newZ, newW, newH);
				}
				else if (kind == DOOR_LEFT) {
					m_ob->Draw_LeftDoor(newX, newY, newZ, newW, newH);
				}
				else if(kind == KIND_EFFECT_EXPLOSION)
				{
					float age = m_Objects[i]->getAge();
					float seqNum = age / 0.5f;
					int seqNumInt = ((int)seqNum) % 4;//
					seqNum *= 4.f;//�� �̹��� ����

					int seqX, seqY;
					seqX = ((int)g_seq) % 4; //%����Ÿ�ϰ���
					seqY = (int)(g_seq / 4);
					g_seq++;
					if (g_seq > 15)
						g_seq = 0;
					m_ob->Draw_Explosion(newX, newY, newZ, seqNumInt);
				
				}
				else if (kind == KIND_OBSTACLE_CAR) {
					m_ob->Draw_Car(newX, newY, newZ, newW, newH);
				}
				else if (kind == KIND_OBSTACLE_TREE) {
					m_ob->Draw_Tree(newX, newY, newZ, newW, newH);
				}
				else if (kind == KIND_OBSTACLE_STONE) {
					m_ob->Draw_Stone(newX, newY, newZ, newW, newH);
				}
				else if (kind == KIND_OBSTACLE_CIRCLE_STONE) {
					m_ob->Draw_StoneCircle(newX, newY, newZ, newW, newH);
				}
				else if (kind == KIND_OBSTACLE_CHRISTMAS_TREE) {
					m_ob->Draw_Christmas_Tree(newX, newY, newZ, newW, newH);
				}

			}

		}
	}

	//drawparticle - �� ������ ���ư� 
	//DrawParticleClimate - ȭ�� ��ü


	g_time += 0.001f;
}

void ScnMgr::Draw_Howto() {

	howto_window = true;
}
void ScnMgr::ApplyForce(float x, float y, float z, float eTime)
{
	int state;
	m_Objects[HERO_ID]->getState(&state);
	if (state == STATE_AIR)
	{		// �����̸� ���̻� �������� �ʰ�
		z = 0.f;

	}
	m_Objects[HERO_ID]->ApplyForce(x, y, z, eTime);
}

float g_temp = 0.0f;
void ScnMgr::Update(float _eTime)
{

	for (int i = 0; i < MAX_OBJECTS; ++i)
	{
		if (m_Objects[i] != NULL)
			m_Objects[i]->Update(_eTime);
	}
	//m_Objects[HERO_ID]->setSize(g_temp, g_temp);
	//g_temp += 5.f;
	//if (g_temp > 200.f)
	//	g_temp = 0;
}

void ScnMgr::DoCollisionTest()
{
	// ȭ��󿡼� �����ϴ� ��������Ʈ�� ��� ���� �� �����ϵ���.
	// n���� ������ n���� ������Ʈ���� ��� collision �� ���ؾ���
	// �Ѹ���� ����� n*n�� �Ǿ�� ��.

	for (int i = 0; i < MAX_OBJECTS; ++i) {
		// �ߺ����� �� ���� ���ϸ� �ǹǷ� j�� ���۵Ǵ� �κ��� 1��
		if (m_Objects[i] == NULL)
		{
			continue;
		}

		int collisionCount = 0;

		for (int j = i + 1; j < MAX_OBJECTS; ++j)
		{

			if (m_Objects[j] == NULL)
			{
				continue;
			}


			if (i == j)
			{
				continue;
			}


			float px, py, pz;
			float sx, sy, sz;
			float minX, minY, maxX, maxY, maxZ, minZ;
			m_Objects[i]->getPosition(&px, &py, &pz);
			m_Objects[i]->getSize(&sx, &sy, &sz);
			minX = px - sx / 2.f;
			maxX = px + sx / 2.f;
			minY = py - sy / 2.f;
			maxY = py + sy / 2.f;
			minZ = pz - sz / 2.f;
			maxZ = pz + sz / 2.f;


			float px1, py1, pz1;
			float sx1, sy1, sz1;
			float minX1, minY1, maxX1, maxY1, maxZ1, minZ1;
			m_Objects[j]->getPosition(&px1, &py1, &pz1);
			m_Objects[j]->getSize(&sx1, &sy1, &sz1);
			minX1 = px1 - sx1 / 2.f;
			maxX1 = px1 + sx1 / 2.f;
			minY1 = py1 - sy1 / 2.f;
			maxY1 = py1 + sy1 / 2.f;
			minZ1 = pz1 - sz1 / 2.f;
			maxZ1 = pz1 + sz1 / 2.f;

			// �ڱ�� �ڱ⸦ ���ϸ� ������ �浹�̴ϱ� ����ó��.
			// ���� ������Ʈ�� ���ϸ� access bias�� �ߴϱ� �굵

			if (BBcollision(minX, minY, minZ,
				maxX, maxY, maxZ,
				minX1, minY1, minZ1,
				maxX1, maxY1, maxZ1))
			{
				collisionCount++;
				ProcessCollision(i, j);
			}


			if (collisionCount > 0)
			{
				//std::cout << "collision\n" << std::endl;
				m_Objects[i]->setColor(0, 1, 0, 1);
			}
			else
			{
				m_Objects[i]->setColor(1, 1, 1, 1);
			}

		}
	}

}


void ScnMgr::GarbageCollector()
{
	for (int i = 0; i < MAX_OBJECTS; ++i) {
		if (m_Objects[i] != NULL && i != HERO_ID)
		{
			float x, y, z;
			m_Objects[i]->getPosition(&x, &y, &z);

			int kind;
			m_Objects[i]->GetKind(&kind);

			int hp;
			m_Objects[i]->getHP(&hp);

			float vx, vy, vz, mag; //mag=�ӵ���ũ��
			m_Objects[i]->getVel(&vx, &vy, &vz);
			mag = sqrtf(vx * vx + vy * vy);

			if (x > 2.5f || x<-2.5f || y>2.5f || y < -2.5f || z > 2.5f || z < -2.5f)
			{
				DeleteObject(i);// �ߺ� ������ ���� ���ؼ�
				// ������ ũ�⸦ 500,500���� �س���
				// �׷��ϱ� ���ͷ� ���� 2.5m, 2.5m��
				// ������ m�� ���߱�� �߱� ������ 2.5 > , -2.5 < �̷��� �Ȱ���
				continue;
			}
			if (kind == KIND_BULLET || kind == KIND_EFFECT_HIT || kind == KIND_EFFECT_EXPLOSION)
			{
				if (hp <= 0)
				{
					DeleteObject(i);
					continue;
				}
			}
			if ( kind == KIND_BUILDING  || kind == KIND_HOUSE || kind == KIND_OBSTACLE_DUCK || kind == KIND_OBSTACLE_SLIDE ||
				kind == KIND_OBSTACLE_FOUNTAIN || kind ==KIND_OBSTACLE_TENT)
			{
				if (hp <= 0)
				{
					// ���� coin �߰��ؾߵż� �������� 
					DeleteObject(i);
					AddObject(x, y, z, 1, 1, 1, 0, 0, 0, KIND_EFFECT_EXPLOSION, 10, STATE_AIR, 0.5f);
					int temp = coin + 15;
					if (temp > 99) {
						coin = 99;
					}
					else {
						coin += 15;
					}
					m_item->SetCoin(coin);

					Obstacle_Destroy_Check();
					continue;
				}
			}

			if (kind == KIND_BULLET)
			{
				if (mag < FLT_EPSILON)
				{
					DeleteObject(i);
					continue;
				}
			}

			if (kind == KIND_HERO) {
				if (hp <= 0)
				{
					DeleteObject(i);
					status = 4;

				}
			}

		}

	}
}
void ScnMgr::Obstacle_Destroy_Check() {
	if (stage1) {
		stage1_count++;

		if (stage1_count > 3) {
			Stage1_2_Obstacle();
			stage1_2 = true;
			stage1 = false;
			stage1_count = 0;
		}
	}
	
	if (stage1_2) {
		stage1_count++;

		if (stage1_count > 4) {
			Stage2_Obstacle();
			stage1_2 = false;
			stage2 = true;
			status = 2;
		}
	}

	if (stage2) {
		stage2_count++;

		if (stage2_count > 8) {
			m_Sound->PlaySound(m_ClearSound, false, 4.f);
			stage2 = false;
			status = 3; // 3�� ���̾� 4�� ������
		}
	}

}
bool ScnMgr::RRcollision(float minX, float minY, float maxX, float maxY, float minX1, float minY1, float maxX1, float maxY1)
{
	if (maxX < minX1)
		return false;
	if (maxX1 < minX)
		return false;
	if (maxY < minY1)
		return false;
	if (maxY1 < minY)
		return false;

	return false;
}

bool ScnMgr::BBcollision(
	float minX, float minY, float minZ,
	float maxX, float maxY, float maxZ,
	float minX1, float minY1, float minZ1,
	float maxX1, float maxY1, float maxZ1)
{
	if (maxX < minX1)
		return false;
	if (maxX1 < minX)
		return false;
	if (maxY < minY1)
		return false;
	if (maxY1 < minY)
		return false;
	if (maxZ < minZ1)
		return false;
	if (maxZ1 < minZ)
		return false;

	return true;
}

void ScnMgr::ProcessCollision(int i, int j)
{
	if (m_Objects[i] == NULL || m_Objects[j] == NULL)
	{
		return;
	}

	Object* ob1 = m_Objects[i];
	Object* ob2 = m_Objects[j];

	int kind1, kind2;
	ob1->GetKind(&kind1);
	ob2->GetKind(&kind2);// ������ ������ �޾ƿ��� ��

	if (kind1 == KIND_BUILDING && kind2 == KIND_BULLET)
	{
		// kind1�� �����̰� kidn2�� �Ѿ��� �� �� �� if�� �ȿ� ����
		int hp1, hp2;
		ob1->getHP(&hp1);//building
		ob2->getHP(&hp2);//bullet

		hp1 = hp1 - hp2;// // ���� ������ ü�¿��� �Ѿ��� ü�¸�ŭ ���ش�. apply damage
		hp2 = 0;

		ob1->setHP(hp1);
		ob2->setHP(hp2);

		m_Sound->PlaySound(m_SoundExplosion, false, 3.f);

		float x, y, z;
		ob2->getPosition(&x, &y, &z);
		AddObject(x, y, z, 1, 1, 1, 0, 0, 0, KIND_EFFECT_HIT, 10, STATE_AIR, 0.5f);


	}

	//1���� �Ѿ��� �� �����ϱ� �ݴ��� ���̽��� 
	if (kind1 == KIND_BULLET && kind2 == KIND_BUILDING)
	{
		int hp1, hp2;
		ob1->getHP(&hp1);//bullet
		ob2->getHP(&hp2);//building

		hp1 = 0;
		hp2 = hp2 - hp1;//apply damage

		ob1->setHP(hp1);
		ob2->setHP(hp2);

		m_Sound->PlaySound(m_SoundExplosion, false, 3.f);

		float x, y, z;
		ob2->getPosition(&x, &y, &z);
		AddObject(x, y, z, 1, 1, 1, 0, 0, 0, KIND_EFFECT_HIT, 10, STATE_AIR, 0.5f);

	}

	////////////////////////////////////////////////////////////////////////////////////////

	// ����� ���̶� �浹üũ
	if (kind1 == KIND_HOUSE && kind2 == KIND_BULLET)
	{

		int hp1, hp2;
		ob1->getHP(&hp1);//building
		ob2->getHP(&hp2);//bullet

		hp1 = hp1 - hp2;
		hp2 = 0;

		ob1->setHP(hp1);
		ob2->setHP(hp2);

		m_Sound->PlaySound(m_SoundExplosion, false, 3.f);

		float x, y, z;
		ob2->getPosition(&x, &y, &z);
		AddObject(x, y, z, 1, 1, 1, 0, 0, 0, KIND_EFFECT_HIT, 10, STATE_AIR, 0.5f);

	}

	if (kind1 == KIND_BULLET && kind2 == KIND_HOUSE)
	{
		int hp1, hp2;
		ob1->getHP(&hp1);//bullet
		ob2->getHP(&hp2);//building

		hp1 = 0;
		hp2 = hp2 - hp1;//apply damage

		ob1->setHP(hp1);
		ob2->setHP(hp2);

		m_Sound->PlaySound(m_SoundExplosion, false, 3.f);

		float x, y, z;
		ob2->getPosition(&x, &y, &z);
		AddObject(x, y, z, 1, 1, 1, 0, 0, 0, KIND_EFFECT_HIT, 10, STATE_AIR, 0.5f);

	}

	//////////////////////////////////////////////////////////////////////////////////////// �м�


	if (kind1 == KIND_OBSTACLE_FOUNTAIN && kind2 == KIND_BULLET)
	{

		int hp1, hp2;
		ob1->getHP(&hp1);//building
		ob2->getHP(&hp2);//bullet

		hp1 = hp1 - hp2;
		hp2 = 0;

		ob1->setHP(hp1);
		ob2->setHP(hp2);

		m_Sound->PlaySound(m_SoundExplosion, false, 3.f);

		float x, y, z;
		ob2->getPosition(&x, &y, &z);
		AddObject(x, y, z, 1, 1, 1, 0, 0, 0, KIND_EFFECT_HIT, 10, STATE_AIR, 0.5f);

	}

	if (kind1 == KIND_BULLET && kind2 == KIND_OBSTACLE_FOUNTAIN)
	{
		int hp1, hp2;
		ob1->getHP(&hp1);//bullet
		ob2->getHP(&hp2);//building

		hp1 = 0;
		hp2 = hp2 - hp1;//apply damage

		ob1->setHP(hp1);
		ob2->setHP(hp2);

		m_Sound->PlaySound(m_SoundExplosion, false, 3.f);

		float x, y, z;
		ob2->getPosition(&x, &y, &z);
		AddObject(x, y, z, 1, 1, 1, 0, 0, 0, KIND_EFFECT_HIT, 10, STATE_AIR, 0.5f);

	}

	//////////////////////////////////////////////////////////////////////////////////////// �̲���Ʋ


	if (kind1 == KIND_OBSTACLE_SLIDE && kind2 == KIND_BULLET)
	{

		int hp1, hp2;
		ob1->getHP(&hp1);//building
		ob2->getHP(&hp2);//bullet

		hp1 = hp1 - hp2;
		hp2 = 0;

		ob1->setHP(hp1);
		ob2->setHP(hp2);

		m_Sound->PlaySound(m_SoundExplosion, false, 3.f);

		float x, y, z;
		ob2->getPosition(&x, &y, &z);
		AddObject(x, y, z, 1, 1, 1, 0, 0, 0, KIND_EFFECT_HIT, 10, STATE_AIR, 0.5f);

	}

	if (kind1 == KIND_BULLET && kind2 == KIND_OBSTACLE_SLIDE)
	{
		int hp1, hp2;
		ob1->getHP(&hp1);//bullet
		ob2->getHP(&hp2);//building

		hp1 = 0;
		hp2 = hp2 - hp1;//apply damage

		ob1->setHP(hp1);
		ob2->setHP(hp2);

		m_Sound->PlaySound(m_SoundExplosion, false, 3.f);

		float x, y, z;
		ob2->getPosition(&x, &y, &z);
		AddObject(x, y, z, 1, 1, 1, 0, 0, 0, KIND_EFFECT_HIT, 10, STATE_AIR, 0.5f);

	}

	//////////////////////////////////////////////////////////////////////////////////////// ����


	if (kind1 == KIND_OBSTACLE_DUCK && kind2 == KIND_BULLET)
	{

		int hp1, hp2;
		ob1->getHP(&hp1);//building
		ob2->getHP(&hp2);//bullet

		hp1 = hp1 - hp2;
		hp2 = 0;

		ob1->setHP(hp1);
		ob2->setHP(hp2);

		m_Sound->PlaySound(m_SoundExplosion, false, 3.f);

		float x, y, z;
		ob2->getPosition(&x, &y, &z);
		AddObject(x, y, z, 1, 1, 1, 0, 0, 0, KIND_EFFECT_HIT, 10, STATE_AIR, 0.5f);

	}

	if (kind1 == KIND_BULLET && kind2 == KIND_OBSTACLE_DUCK)
	{
		int hp1, hp2;
		ob1->getHP(&hp1);//bullet
		ob2->getHP(&hp2);//building

		hp1 = 0;
		hp2 = hp2 - hp1;//apply damage

		ob1->setHP(hp1);
		ob2->setHP(hp2);

		m_Sound->PlaySound(m_SoundExplosion, false, 3.f);

		float x, y, z;
		ob2->getPosition(&x, &y, &z);
		AddObject(x, y, z, 1, 1, 1, 0, 0, 0, KIND_EFFECT_HIT, 10, STATE_AIR, 0.5f);

	}


	//////////////////////////////////////////////////////////////////////////////////////// ��Ʈ


	if (kind1 == KIND_OBSTACLE_TENT && kind2 == KIND_BULLET)
	{

		int hp1, hp2;
		ob1->getHP(&hp1);//building
		ob2->getHP(&hp2);//bullet

		hp1 = hp1 - hp2;
		hp2 = 0;

		ob1->setHP(hp1);
		ob2->setHP(hp2);

		m_Sound->PlaySound(m_SoundExplosion, false, 3.f);

		float x, y, z;
		ob2->getPosition(&x, &y, &z);
		AddObject(x, y, z, 1, 1, 1, 0, 0, 0, KIND_EFFECT_HIT, 10, STATE_AIR, 0.5f);

	}

	if (kind1 == KIND_BULLET && kind2 == KIND_OBSTACLE_TENT )
	{
		int hp1, hp2;
		ob1->getHP(&hp1);//bullet
		ob2->getHP(&hp2);//building

		hp1 = 0;
		hp2 = hp2 - hp1;//apply damage

		ob1->setHP(hp1);
		ob2->setHP(hp2);

		m_Sound->PlaySound(m_SoundExplosion, false, 3.f);

		float x, y, z;
		ob2->getPosition(&x, &y, &z);
		AddObject(x, y, z, 1, 1, 1, 0, 0, 0, KIND_EFFECT_HIT, 10, STATE_AIR, 0.5f);

	}

	//////////////////////////////////////////////////////////////////////////////////////// ��


	if (kind1 == KIND_OBSTACLE_CAR && kind2 == KIND_BULLET)
	{

		int hp1, hp2;
		ob1->getHP(&hp1);//building
		ob2->getHP(&hp2);//bullet

		hp1 = hp1 - hp2;
		hp2 = 0;

		ob1->setHP(hp1);
		ob2->setHP(hp2);

		m_Sound->PlaySound(m_SoundExplosion, false, 3.f);

		float x, y, z;
		ob2->getPosition(&x, &y, &z);
		AddObject(x, y, z, 1, 1, 1, 0, 0, 0, KIND_EFFECT_HIT, 10, STATE_AIR, 0.5f);

	}

	if (kind1 == KIND_BULLET && kind2 == KIND_OBSTACLE_CAR)
	{
		int hp1, hp2;
		ob1->getHP(&hp1);//bullet
		ob2->getHP(&hp2);//building

		hp1 = 0;
		hp2 = hp2 - hp1;//apply damage

		ob1->setHP(hp1);
		ob2->setHP(hp2);

		m_Sound->PlaySound(m_SoundExplosion, false, 3.f);

		float x, y, z;
		ob2->getPosition(&x, &y, &z);
		AddObject(x, y, z, 1, 1, 1, 0, 0, 0, KIND_EFFECT_HIT, 10, STATE_AIR, 0.5f);

	}


	//////////////////////////////////////////////////////////////////////////////////////// ����


	if (kind1 == KIND_OBSTACLE_TREE && kind2 == KIND_BULLET)
	{

		int hp1, hp2;
		ob1->getHP(&hp1);//building
		ob2->getHP(&hp2);//bullet

		hp1 = hp1 - hp2;
		hp2 = 0;

		ob1->setHP(hp1);
		ob2->setHP(hp2);

		m_Sound->PlaySound(m_SoundExplosion, false, 3.f);

		float x, y, z;
		ob2->getPosition(&x, &y, &z);
		AddObject(x, y, z, 1, 1, 1, 0, 0, 0, KIND_EFFECT_HIT, 10, STATE_AIR, 0.5f);

	}

	if (kind1 == KIND_BULLET && kind2 == KIND_OBSTACLE_TREE)
	{
		int hp1, hp2;
		ob1->getHP(&hp1);//bullet
		ob2->getHP(&hp2);//building

		hp1 = 0;
		hp2 = hp2 - hp1;//apply damage

		ob1->setHP(hp1);
		ob2->setHP(hp2);

		m_Sound->PlaySound(m_SoundExplosion, false, 3.f);

		float x, y, z;
		ob2->getPosition(&x, &y, &z);
		AddObject(x, y, z, 1, 1, 1, 0, 0, 0, KIND_EFFECT_HIT, 10, STATE_AIR, 0.5f);

	}

	//////////////////////////////////////////////////////////////////////////////////////// ��


	if (kind1 == KIND_OBSTACLE_STONE && kind2 == KIND_BULLET)
	{

		int hp1, hp2;
		ob1->getHP(&hp1);//building
		ob2->getHP(&hp2);//bullet

		hp1 = hp1 - hp2;
		hp2 = 0;

		ob1->setHP(hp1);
		ob2->setHP(hp2);

		m_Sound->PlaySound(m_SoundExplosion, false, 3.f);

		float x, y, z;
		ob2->getPosition(&x, &y, &z);
		AddObject(x, y, z, 1, 1, 1, 0, 0, 0, KIND_EFFECT_HIT, 10, STATE_AIR, 0.5f);

	}

	if (kind1 == KIND_BULLET && kind2 == KIND_OBSTACLE_STONE)
	{
		int hp1, hp2;
		ob1->getHP(&hp1);//bullet
		ob2->getHP(&hp2);//building

		hp1 = 0;
		hp2 = hp2 - hp1;//apply damage

		ob1->setHP(hp1);
		ob2->setHP(hp2);

		m_Sound->PlaySound(m_SoundExplosion, false, 3.f);

		float x, y, z;
		ob2->getPosition(&x, &y, &z);
		AddObject(x, y, z, 1, 1, 1, 0, 0, 0, KIND_EFFECT_HIT, 10, STATE_AIR, 0.5f);

	}

	//////////////////////////////////////////////////////////////////////////////////////// ������


	if (kind1 == KIND_OBSTACLE_CIRCLE_STONE && kind2 == KIND_BULLET)
	{

		int hp1, hp2;
		ob1->getHP(&hp1);//building
		ob2->getHP(&hp2);//bullet

		hp1 = hp1 - hp2;
		hp2 = 0;

		ob1->setHP(hp1);
		ob2->setHP(hp2);

		m_Sound->PlaySound(m_SoundExplosion, false, 3.f);

		float x, y, z;
		ob2->getPosition(&x, &y, &z);
		AddObject(x, y, z, 1, 1, 1, 0, 0, 0, KIND_EFFECT_HIT, 10, STATE_AIR, 0.5f);

	}

	if (kind1 == KIND_BULLET && kind2 == KIND_OBSTACLE_CIRCLE_STONE)
	{
		int hp1, hp2;
		ob1->getHP(&hp1);//bullet
		ob2->getHP(&hp2);//building

		hp1 = 0;
		hp2 = hp2 - hp1;//apply damage

		ob1->setHP(hp1);
		ob2->setHP(hp2);

		m_Sound->PlaySound(m_SoundExplosion, false, 3.f);

		float x, y, z;
		ob2->getPosition(&x, &y, &z);
		AddObject(x, y, z, 1, 1, 1, 0, 0, 0, KIND_EFFECT_HIT, 10, STATE_AIR, 0.5f);

	}

	//////////////////////////////////////////////////////////////////////////////////////// ũ������������


	if (kind1 == KIND_OBSTACLE_CHRISTMAS_TREE && kind2 == KIND_BULLET)
	{

		int hp1, hp2;
		ob1->getHP(&hp1);//building
		ob2->getHP(&hp2);//bullet

		hp1 = hp1 - hp2;
		hp2 = 0;

		ob1->setHP(hp1);
		ob2->setHP(hp2);

		m_Sound->PlaySound(m_SoundExplosion, false, 3.f);

		float x, y, z;
		ob2->getPosition(&x, &y, &z);
		AddObject(x, y, z, 1, 1, 1, 0, 0, 0, KIND_EFFECT_HIT, 10, STATE_AIR, 0.5f);

	}

	if (kind1 == KIND_BULLET && kind2 == KIND_OBSTACLE_CHRISTMAS_TREE)
	{
		int hp1, hp2;
		ob1->getHP(&hp1);//bullet
		ob2->getHP(&hp2);//building

		hp1 = 0;
		hp2 = hp2 - hp1;//apply damage

		ob1->setHP(hp1);
		ob2->setHP(hp2);

		m_Sound->PlaySound(m_SoundExplosion, false, 3.f);

		float x, y, z;
		ob2->getPosition(&x, &y, &z);
		AddObject(x, y, z, 1, 1, 1, 0, 0, 0, KIND_EFFECT_HIT, 10, STATE_AIR, 0.5f);

	}

	///////////////////////////////////////////////////////////////////////////////////////

	if (kind1 == KIND_HERO && (kind2 == KIND_BUILDING || kind2 == KIND_HOUSE || kind2 == KIND_OBSTACLE_DUCK || kind2 == KIND_OBSTACLE_SLIDE ||
		kind2 == KIND_OBSTACLE_FOUNTAIN || kind2 == KIND_OBSTACLE_TENT ||kind2 == KIND_OBSTACLE_TENT || kind2 == KIND_OBSTACLE_CAR ||
			kind2 == KIND_OBSTACLE_TREE || kind2 == KIND_OBSTACLE_STONE ||
			kind2 == KIND_OBSTACLE_CIRCLE_STONE || kind2 == KIND_OBSTACLE_CHRISTMAS_TREE
		))
	{

		int hp1, hp2;
		ob1->getHP(&hp1);//building
		ob2->getHP(&hp2);//bullet

		hp1 = hp1 - hp2*2;
		hp2 = 0;

		ob1->setHP(hp1);
		ob2->setHP(hp2);


		m_Sound->PlaySound(m_SoundExplosion, false, 3.f);

		float x, y, z;
		ob2->getPosition(&x, &y, &z);
		AddObject(x, y, z, 1, 1, 1, 0, 0, 0, KIND_EFFECT_HIT, 10, STATE_AIR, 0.5f);

	}
}

void ScnMgr::Shoot(int shootID)
{
	
	if (shootID == SHOOT_NONE || coin <= 0 )
		return;// shoot id�� none�̸� �߻��ϸ� �ȵǴϱ� 

	float amount = 3.f; //3m/s
	float bvX, bvY, bvZ; //�Ѿ��� �ӵ� �ʱ�� 0.f

	bvX = 0.f;
	bvY = 0.f;
	bvZ = 0.f;

	//���⿡ ���� x�� y�� �� �ο�. 
	switch (shootID)
	{
	case SHOOT_UP:
		bvX = 0.f;
		bvY = amount;
		break;
	case SHOOT_DOWN:
		bvX = 0.f;
		bvY = -amount;
		break;
	case SHOOT_RIGHT:
		bvX = amount;
		bvY = +0.f;
		break;
	case SHOOT_LEFT:
		bvX = -amount;
		bvY = 0.f;
		break;
	}
	float pX, pY, pZ; // ��ǥ�� �޾ƿ���
	m_Objects[HERO_ID]->getPosition(&pX, &pY, &pZ);

	float vX, vY, vZ; // �ӵ� �޾ƿ���
	m_Objects[HERO_ID]->getVel(&vX, &vY, &vZ);

	bvX = bvX + vX;
	bvY = bvY + vY;
	bvZ = bvZ + vZ;

	if (m_Objects[HERO_ID]->canFire())
	{
		int random = rand() % 5;
		shoot_random = random;

		AddObject(pX, pY, pZ,
			0.2f, 0.2f, 0.2f,
			bvX, bvY, bvZ,
			KIND_BULLET, 20, STATE_AIR, FLT_MAX);
		coin--;
		m_item->SetCoin(coin);
		m_Sound->PlaySound(m_SoundFire, false, 3.f);
		m_Objects[HERO_ID]->resetCoolTime();
	}


}

void ScnMgr::AddObject(float x, float y, float z,
	float sx, float sy, float sz,
	float vx, float vy, float vz,
	int kind, int hp, int state, float maxAge)
{
	int id = FindEmptyObjectSloat(); //id�� get�ϸ� 

	if (id < 0)
	{
		return;
	}
	m_Objects[id] = new Object(); //�ű⿡ ���ο� ������Ʈ�� ����� ��
	m_Objects[id]->setPosition(x, y, z);
	m_Objects[id]->setColor(1.0f, 0.7f, 0.6f, 1.0f);
	m_Objects[id]->setSize(sx, sy, sz);
	m_Objects[id]->setVel(vx, vy, vz);
	m_Objects[id]->setAcc(0.f, 0.f, 0.f);
	m_Objects[id]->setMass(1.f);
	m_Objects[id]->setFrictional_num(0.1f);
	m_Objects[id]->setFrictional(1.f);
	m_Objects[id]->SetKind(kind);
	m_Objects[id]->setHP(hp);
	m_Objects[id]->setState(state);
	m_Objects[id]->setMaxAge(maxAge);

}

int ScnMgr::FindEmptyObjectSloat()
{
	for (int i = 0; i < MAX_OBJECTS; ++i)
	{
		if (m_Objects[i] == NULL)
		{
			//std::cout << i << std::endl;
			return i;
		}
	}

	std::cout << "No more empty slot \n" << std::endl;
	return -1;
}

void ScnMgr::DeleteObject(int id)
{
	if (m_Objects[id] != NULL)
	{
		delete m_Objects[id];
		m_Objects[id] = NULL;
	}
}



ScnMgr::~ScnMgr()
{
	if (m_Renderer)
	{
		delete m_Renderer;
		m_Renderer = NULL;
	}
	if (m_Objects[HERO_ID])
	{
		delete m_Objects[HERO_ID];
		m_Objects[HERO_ID] = NULL;
	}
}
