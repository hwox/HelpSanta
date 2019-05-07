#pragma once
#include "Renderer.h"

class Obstacle
{

	Renderer * m_Renderer = NULL;

	GLuint Duck = 0;
	GLuint Slide = 0;
	GLuint HOUSE = 0;
	GLuint Fountain = 0;
	GLuint Hit_Effect[5] = {};
	GLuint Tent = 0;

	GLuint R_Door = 0;
	GLuint L_Door = 0;

	GLuint Explosion = 0;
	GLuint Stone_Circle = 0;
	GLuint Tree = 0;
	GLuint Stone = 0;
	GLuint Car = 0;
	GLuint Christmas_Tree = 0;

public:
	Obstacle(Renderer *m_renderer);
	void Draw_House(float x, float y, float z,float sizex, float sizey);
	void Draw_Slide(float x, float y, float z, float sizex, float sizey);
	void Draw_Duck(float x, float y, float z, float sizex, float sizey);
	void Draw_Fountain(float x, float y, float z, float sizex, float sizey);
	void Draw_Tent(float x, float y, float z, float sizex, float sizey);
	void Draw_Car(float x, float y, float z, float sizex, float sizey);
	void Draw_StoneCircle(float x, float y, float z, float sizex, float sizey);
	void Draw_Tree(float x, float y, float z, float sizex, float sizey);
	void Draw_Stone(float x, float y, float z, float sizex, float sizey);
	void Draw_Christmas_Tree(float x, float y, float z, float sizex, float sizey);

	void Draw_LeftDoor(float x, float y, float z, float sizex, float sizey);
	void Draw_RightDoor(float x, float y, float z, float sizex, float sizey);
	void Draw_Effect(float x, float y, float z, float seq, int shoot_num);
	void Draw_Explosion(float x, float y, float z, float seq);
		~Obstacle();
};

