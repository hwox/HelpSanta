#pragma once
class Object
{
private:
	//position
	float x;
	float y;
	float z;

	//size
	//float mySizeX;
	//float mySizeY;
	float mySizeX, mySizeY, mySizeZ;

	//color
	float my_r;
	float my_g;
	float my_b;
	float my_a;



	float my_height;



	float my_velX;
	float my_velY;
	float my_velZ;// 날아다니려면 높이 값 줘야 함

	float my_accX;
	float my_accY;
	float my_accZ;

	float my_mass;

	//마찰력
	float myFrictional_force;
	//오브젝트의 마찰계수
	float Frictional_force_num;


	//특성
	int kind;
	int m_HP;
	int m_state;

	//생긴지 얼마나 됐는지
	float m_age;
	float m_maxAge;

	float m_coolTime;  // 몇초마다 쏠 것인지
	float m_currentCoolTime; // 지난번 쏜 이후로 몇 초 지났는지
public:
	void Update(float _eTime);

	//float getPosition(int key);
	void getPosition(float* x, float* y, float *z);
	void setPosition(float _x, float _y, float _z);

	void getSize(float* _sizeX, float* _sizeY, float *_sizeZ);
	void setSize(float _sizeX, float _sizeY, float _sizeZ);

	void getColor(float* r, float* g, float* b, float* a);
	void setColor(float r, float g, float b, float a);

	void getVel(float* _velX, float* _velY, float* _velZ);
	void setVel(float _velX, float _velY, float _velZ);

	void getAcc(float* _accX, float* _accY, float* _accZ);
	void setAcc(float _accX, float _accY, float _accZ);

	void getMass(float* _mass);
	void setMass(float _mass);

	void getHeight(float* _height);
	void setHeight(float _height);

	//마찰력
	void getFrictional(float* _fric);
	void setFrictional(float _fric);

	//마찰계수
	void getFrictional_num(float* _Frictional_force_num);
	void setFrictional_num(float _Frictional_force_num);

	void ApplyForce(float x, float y, float z, float eTime);

	void SetKind(int kind);
	void GetKind(int* kind);

	void getHP(int* _HP);
	void setHP(int _HP);

	void getState(int* _state);
	void setState(int _HP);

	float getAge();
	void setAge(float _age);

	void setMaxAge(float _maxAge);

	void resetCoolTime();
	bool canFire();

	Object();
	~Object();
};

