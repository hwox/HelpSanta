#include "stdafx.h"
#include "Obstacle.h"
#include "Renderer.h"

Obstacle::Obstacle(Renderer *m_ren)
{
	m_Renderer = m_ren;

	HOUSE = m_Renderer->CreatePngTexture("./textures/house2.png");
	Slide  = m_Renderer->CreatePngTexture("./textures/slide.png");
	Fountain = m_Renderer->CreatePngTexture("./textures/fountain.png");
	Duck = m_Renderer->CreatePngTexture("./textures/duck.png");
	Tent = m_Renderer->CreatePngTexture("./textures/tent.png");

	Hit_Effect[0] = m_Renderer->CreatePngTexture("./textures/Effect/1.png");
	Hit_Effect[1] = m_Renderer->CreatePngTexture("./textures/Effect/2.png");
	Hit_Effect[2] = m_Renderer->CreatePngTexture("./textures/Effect/3.png");
	Hit_Effect[3] = m_Renderer->CreatePngTexture("./textures/Effect/4.png");
	Hit_Effect[4] = m_Renderer->CreatePngTexture("./textures/Effect/5.png");

	R_Door = m_Renderer->CreatePngTexture("./textures/door_right.png");
	L_Door = m_Renderer->CreatePngTexture("./textures/door_left.png");

	Explosion = m_Renderer->CreatePngTexture("./textures/explosion.png");

	Stone_Circle = m_Renderer->CreatePngTexture("./textures/stone_circle.png");
	Tree = m_Renderer->CreatePngTexture("./textures/tree.png");
	Stone = m_Renderer->CreatePngTexture("./textures/stone.png");
	Car = m_Renderer->CreatePngTexture("./textures/car.png");
	Christmas_Tree = m_Renderer->CreatePngTexture("./textures/christmas_tree.png");
}


void Obstacle::Draw_House(float x, float y, float z,float sizex, float sizey) {
	m_Renderer->DrawTextureRect(
		200,100, 1, sizex, sizey, 1, 1, 1, 1, HOUSE);
}

void Obstacle::Draw_Slide(float x, float y, float z, float sizex, float sizey) {
	m_Renderer->DrawTextureRect(
		x, y, 1, sizex,sizey, 1, 1, 1, 1, Slide);
}


void Obstacle::Draw_Duck(float x, float y, float z, float sizex, float sizey) {
	m_Renderer->DrawTextureRect(
		x, y, 1, sizex, sizey, 1, 1, 1, 1, Duck);
}
void Obstacle::Draw_Tent(float x, float y, float z, float sizex, float sizey) {
	m_Renderer->DrawTextureRect(
		x, y, 1, sizex, sizey, 1, 1, 1, 1, Tent);
}

void Obstacle::Draw_Car(float x, float y, float z, float sizex, float sizey) {
	m_Renderer->DrawTextureRect(
		x, y, 1, sizex, sizey, 1, 1, 1, 1, Car);
}
void Obstacle::Draw_StoneCircle(float x, float y, float z, float sizex, float sizey) {
	m_Renderer->DrawTextureRect(
		x, y, 1, sizex, sizey, 1, 1, 1, 1, Stone_Circle);
}
void Obstacle::Draw_Tree(float x, float y, float z, float sizex, float sizey) {
	m_Renderer->DrawTextureRect(
		x, y, 1, sizex, sizey, 1, 1, 1, 1, Tree);
}
void Obstacle::Draw_Stone(float x, float y, float z, float sizex, float sizey) {
	m_Renderer->DrawTextureRect(
		x, y, 1, sizex, sizey, 1, 1, 1, 1, Stone);
}
void Obstacle::Draw_Christmas_Tree(float x, float y, float z, float sizex, float sizey) {
	m_Renderer->DrawTextureRect(
		x, y, 1, sizex, sizey, 1, 1, 1, 1, Christmas_Tree);
}

void Obstacle::Draw_Fountain(float x, float y, float z, float sizex, float sizey) {
	m_Renderer->DrawTextureRect(
		x, y, 1, sizex,sizey, 1, 1, 1, 1, Fountain);
}
void Obstacle::Draw_LeftDoor(float x, float y, float z, float sizex, float sizey) {
	m_Renderer->DrawTextureRect(
		x, y, 1, sizex, sizey, 1, 1, 1, 1, L_Door);
}
void Obstacle::Draw_RightDoor(float x, float y, float z, float sizex, float sizey) {
	m_Renderer->DrawTextureRect(
		x, y, 1, sizex, sizey, 1, 1, 1, 1, R_Door);
}


void Obstacle::Draw_Effect(float x, float y, float z, float seq,int shoot_num) {

	m_Renderer->DrawTextureRectSeqXYHeight(
		x,y, 1,
		30,
		30,
		1,1,1,1,
		Hit_Effect[shoot_num],
		seq, 0,
		5, 1,
		z);
}
void Obstacle::Draw_Explosion(float x, float y, float z, float seq) {

	m_Renderer->DrawTextureRectSeqXYHeight(
		x, y, 1,
		50,
		50,
		1, 1, 1, 1,
		Explosion,
		seq, 0,
		4, 1,
		z);
}
Obstacle::~Obstacle()
{
}
