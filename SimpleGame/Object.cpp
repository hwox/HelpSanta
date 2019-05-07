#include "stdafx.h"
#include "Object.h"
#include "GameValue.h"
#include <math.h>
#include <float.h>
#include <iostream>
#include <Windows.h>

void Object::Update(float _eTime)
{

	m_age += _eTime;
	if (m_age > m_maxAge)
	{
		m_HP = 0;
	}
	m_currentCoolTime += _eTime;

	//속도의 크기 (전체 길이)
	float magVel = sqrtf(my_velX*my_velX + my_velY * my_velY + my_velZ * my_velZ);
	//속도의 단위벡터. 정규화 과정
	float velX = my_velX / magVel;
	float velY = my_velY / magVel;
	float fricX = -velX;
	float fricY = -velY;
	float friction = Frictional_force_num * my_mass * GRAVITY;
	fricX *= friction;
	fricY *= friction;

	if (magVel < FLT_EPSILON) //엡실론이라고 하는건 FLOAT 연산에 오차 안에 들면 0이라고 볼수있는거
	{
		my_velX = 0.f;
		my_velY = 0.f;
		my_velZ = 0.f;
	}
	else
	{
		float accX = fricX / my_mass;
		float accY = fricY / my_mass;

		float afterVelX = my_velX + accX * _eTime;
		float afterVelY = my_velY + accY * _eTime;

		if (afterVelX * my_velX < 0.f)
			my_velX = 0.f;
		else
			my_velX = afterVelX;

		if (afterVelY * my_velY < 0.f)
			my_velY = 0.f;
		else
			my_velY = afterVelY;


		//Gravity
		my_velZ = my_velZ - GRAVITY * _eTime;


		//my_velX = my_velX + accX * _eTime;
		//my_velY = my_velY + accY * _eTime;
	}

	////마찰력 = 마찰계수 * 수직항력
	myFrictional_force = Frictional_force_num * GRAVITY;

	//cal velocity
	my_velX = my_velX + _eTime * my_accX;
	my_velY = my_velY + _eTime * my_accY;
	my_velZ = my_velZ + _eTime * my_accZ;

	//cal position
	x = x + my_velX * _eTime;//(1.f / 60.f);
	y = y + my_velY * _eTime;//(1.f / 60.f);
	z = z + my_velZ * _eTime;//(1.f / 60.f);

	if (z >= 0.f)
	{
		m_state = STATE_AIR;
	}
	else
	{
		m_state = STATE_GROUND;
		my_velZ = 0.f;
		z = 0.f;
	}
}

void Object::getPosition(float * _x, float * _y, float* _z)
{
	*_x = x;
	*_y = y;
	*_z = z;

}

void Object::setPosition(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

void Object::getSize(float* _sizeX, float * _sizeY, float* _sizeZ)
{
	*_sizeX = mySizeX;
	*_sizeY = mySizeY;
	*_sizeZ = mySizeZ;
}

void Object::setSize(float _sizeX, float _sizeY, float _sizeZ)
{
	mySizeX = _sizeX;
	mySizeY = _sizeY;
	mySizeZ = _sizeZ;
}

void Object::getColor(float * r, float * g, float * b, float* a)
{
	*r = my_r;
	*g = my_g;
	*b = my_b;
	*a = my_a;
}

void Object::setColor(float r, float g, float b, float a)
{
	my_r = r;
	my_g = g;
	my_b = b;
	my_a = a;
}

void Object::getVel(float * _velX, float * _velY, float * _velZ)
{
	*_velX = my_velX;
	*_velY = my_velY;
	*_velZ = my_velZ;
}

void Object::setVel(float _velX, float _velY, float _velZ)
{
	my_velX = _velX;
	my_velY = _velY;
	my_velZ = _velZ;
}

void Object::getAcc(float * _accX, float * _accY, float * _accZ)
{
	*_accX = my_accX;
	*_accY = my_accY;
	*_accZ = my_accZ;
}

void Object::setAcc(float _accX, float _accY, float _accZ)
{
	my_accX = _accX;
	my_accY = _accY;
	my_accZ = _accZ;
}


void Object::getMass(float * _mass)
{
	*_mass = my_mass;
}

void Object::setMass(float _mass)
{
	my_mass = _mass;
}

void Object::ApplyForce(float x, float y, float z, float _eTime)
{
	my_accX = x / my_mass;
	my_accY = y / my_mass;
	my_accZ = z / my_mass;

	my_velX = my_velX + my_accX * _eTime;
	my_velY = my_velY + my_accY * _eTime;
	my_velZ = my_velZ + my_accZ * 0.1f;

	my_accX = 0;
	my_accY = 0;
	my_accZ = 0;
}
void Object::getHeight(float * _height)
{
	*_height = my_height;
}

void Object::setHeight(float _height)
{
	my_height = _height;
}

void Object::getFrictional(float * _fric)
{
	*_fric = myFrictional_force;
}

void Object::setFrictional(float _fric)
{
	myFrictional_force = _fric;
}

void Object::getFrictional_num(float * _fric_num)
{
	*_fric_num = Frictional_force_num;
}

void Object::setFrictional_num(float _fric_num)
{
	Frictional_force_num = _fric_num;
}

void Object::SetKind(int _kind)
{
	kind = _kind;
}

void Object::GetKind(int * _kind)
{
	*_kind = kind;
}

void Object::setHP(int _HP)
{
	m_HP = _HP;
}

void Object::getHP(int * _HP)
{
	*_HP = m_HP;
}


void Object::getState(int * _state)
{
	*_state = m_state;
}

void Object::setState(int _state)
{
	m_state = _state;
}

float Object::getAge()
{
	return m_age;
}

void Object::setAge(float _age)
{
	m_age = _age;
}

void Object::setMaxAge(float _maxAge)
{
	m_maxAge = _maxAge;
}

void Object::resetCoolTime()
{
	m_currentCoolTime = 0.f;
}

bool Object::canFire()
{
	if (m_currentCoolTime >= m_coolTime)
		return true;

	return false;
}

Object::Object()
{
	m_age = 0.f;
	m_maxAge = FLT_MAX;
	m_coolTime = 0.5f;
	m_currentCoolTime = m_coolTime;
}


Object::~Object()
{
}
