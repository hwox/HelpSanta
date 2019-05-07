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
	//글로벌, 로컬, 멤버
	Renderer * m_Renderer = NULL;
	Object* m_Objects[MAX_OBJECTS];
	Obstacle* m_ob = NULL;
	Map* m_Map;
	Item* m_item;

	// sound 정의 
	Sound* m_Sound;

	int m_SoundBG = 0;
	int m_SoundFire = 0;
	int m_SoundExplosion = 0;
	int m_ClearSound = 0;

	int start_index = 0;
	bool start_window; // 귀찮아서 따로 ㅃㅐ기
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

	// 배경
	void Draw_BG(int i);
	void Load_Images();
	void Load_Sounds();
	ScnMgr();
	~ScnMgr();
};

// 오브젝트가 생성되고 유지될 동안 오브젝트의 나이를 가지고 있는
// 변수가 하나 필요. 
// 화면상에 존재하는 오브젝트에서 모두 update가 불리니까
// 불릴 때마다 age를 더해
// 몇초가 지났는지를 해보고 animation 을 시킬 수 있음 
// 전체적으로 1초가 되는 순간 끝난다. 

// 두 번째로는 생명주기 LifeTime이 필요하다
// 얘가 죽어야만 하는 시간. 
// 죽어야만 하는 시간을 setting을 해줘야 하는 거 
// 예를 들면 hero 는 계속 살아있어야 하니까 나이ㅣ를 아무리
// 먹어도 죽지 않게 한다던가

// 그러니까 나이 변수가 lifetime 보다 작으면 걔의 hp를 0으로
// 만드는 식으로 하면 garbage collector가 알아서 없애줄거임

// 응용할 수 있는 게 많은 모든 동작을 시간단위로 하고 싶으면
// 이런식으로 뛰거나 걷는것도 다 처리할 수 있음


