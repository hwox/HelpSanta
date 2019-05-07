#pragma once
#include "Renderer.h"
#include "Object.h"
#include "GameValue.h"
#include "Sound.h"
#include "Map.h"
#include "Obstacle.h"
#include "Item.h"


class ScnMgr
{
private:
	//�۷ι�, ����, ���
	Renderer * m_Renderer = NULL;
	Object* m_Objects[MAX_OBJECTS];
	Obstacle* m_ob = NULL;
	Map* m_Map;
	Item* m_item;

	// sound ���� 
	Sound* m_Sound;

	int m_SoundBG = 0;
	int m_SoundFire = 0;
	int m_SoundExplosion = 0;
	int m_ClearSound = 0;

	int start_index = 0;
	bool start_window; // �����Ƽ� ���� ������
	bool howto_window;
	//Object* m_Object;

	GLuint Player_texture = 0;
	GLuint m_snowParticle = 0;
	GLuint Snowball_Texture = 0;
	GLuint m_bTexture = 0;
	GLuint BackGround_texture[4] = {};
	GLuint Start_Press = 0;
	GLuint Start_Bg = 0;
	GLuint End_Bg = 0;
	GLuint Over_Bg = 0;
	GLuint Number_image[10] = {};
	GLuint Howto_image = 0;

	bool stage1;
	bool stage1_2;
	bool stage2;
	bool gameover;
	bool gameEnd;

	int stage1_count = 0;
	int stage2_count = 0;

	int player_hp_bar = 1;

	int status;
	int shoot_random; // shoot_hit_effect 


	float b_width;
	float b_height;

	int coin;

public:
	void KeyInput(unsigned char key, int x, int y);
	void RenderScene(void);
	void ApplyForce(
		float x, float y, float z,
		float eTime);

	void Update(float _eTime);
	void DoCollisionTest();

	void AddObject(float x, float y, float z,
		float sx, float sy, float sz,
		float vx, float vy, float vz,
		int kind, int hp, int state, float maxAge);

	int FindEmptyObjectSloat();
	void DeleteObject(int id);
	void GarbageCollector();
	void SetStatus(int _set) {
		status = _set;
	}
	void Stage1_2_Obstacle();
	void Obstacle_Destroy_Check();
	bool RRcollision(
		float minX, float minY,
		float maxX, float maxY,
		float minX1, float minY1,
		float maxX1, float maxY1);

	bool BBcollision(
		float minX, float minY, float minZ,
		float maxX, float maxY, float maxZ,
		float minX1, float minY1, float minZ1,
		float maxX1, float maxY1, float maxZ1);
	void Shoot(int shootID);
	void ProcessCollision(int i, int j);
	//void Draw_House(float x, float y, float z);
	//void Draw_Slide(float x, float y, float z);
	//void Draw_Duck(float x, float y, float z);
	//void Draw_Fountain(float x, float y, float z);
	void Stage1_Obstacle();
	void Stage2_Obstacle();
	void Draw_Howto();

	// ���
	void Draw_BG(int i);
	void Load_Images();
	void Load_Sounds();
	ScnMgr();
	~ScnMgr();
};

// ������Ʈ�� �����ǰ� ������ ���� ������Ʈ�� ���̸� ������ �ִ�
// ������ �ϳ� �ʿ�. 
// ȭ��� �����ϴ� ������Ʈ���� ��� update�� �Ҹ��ϱ�
// �Ҹ� ������ age�� ����
// ���ʰ� ���������� �غ��� animation �� ��ų �� ���� 
// ��ü������ 1�ʰ� �Ǵ� ���� ������. 

// �� ��°�δ� �����ֱ� LifeTime�� �ʿ��ϴ�
// �갡 �׾�߸� �ϴ� �ð�. 
// �׾�߸� �ϴ� �ð��� setting�� ����� �ϴ� �� 
// ���� ��� hero �� ��� ����־�� �ϴϱ� ���̤Ӹ� �ƹ���
// �Ծ ���� �ʰ� �Ѵٴ���

// �׷��ϱ� ���� ������ lifetime ���� ������ ���� hp�� 0����
// ����� ������ �ϸ� garbage collector�� �˾Ƽ� �����ٰ���

// ������ �� �ִ� �� ���� ��� ������ �ð������� �ϰ� ������
// �̷������� �ٰų� �ȴ°͵� �� ó���� �� ����


