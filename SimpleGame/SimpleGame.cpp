/*
Copyright 2017 Lee Taek Hee (Korea Polytech University)

This program is free software: you can redistribute it and/or modify
it under the terms of the What The Hell License. Do it plz.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY.
*/

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
//헤더파일은 64비트나 32비트나 차이가 없다. 왜? 컴파일되어서 나오는 게 아니라 항상 환경에 맞게 새로 컴파일 되기 때문에
#include "Dependencies\glew.h"
#include "Dependencies\freeglut.h"
#include "ScnMgr.h"
#include "GameValue.h"



ScnMgr* manager = NULL;

DWORD g_prevTime = 0;


bool g_keyW = false;
bool g_keyA = false;
bool g_keyS = false;
bool g_keyD = false;
bool g_keySP = false;

int g_Shoot = SHOOT_NONE;

int start_push=0;
bool howto;
bool GameStart;


void RenderScene(void)
{
	//update 
	//번쩍거리는 이유 gpu cpu 성능차이 작은연산이라 하더라도 성능에 따른 속도차이가 있기 때문.
	//좋은 컴에서는 loop가 더 많이돌기때문

	if (g_prevTime == 0) {
		g_prevTime = timeGetTime();
		return;
	}

	//
	DWORD currTime = timeGetTime();

	DWORD elapsedTime = currTime - g_prevTime;



	g_prevTime = currTime;


	//dword는 정수이기 때무넹 float 이하는 다짤림 그래서 반ㄷㅅ ㅣ(float) 해줘야 해
	float eTime = (float)elapsedTime / 1000.f;

	////////////////////////////////////////////////////////////

	if (!GameStart) {
		// 시작화면

		manager->Draw_BG(0);
		// 뭐 누르면 status ==1;
	}

	else if (GameStart) {

		// 게임 시작 

		//switch (status) {
		//case 1:
		//	manager->Draw_BG(1); // stage1
		//	break;
		//case 2:
		//	manager->Draw_BG(2); // stage2
		//	break;
		//case 3:
		//	manager->Draw_BG(3); // gameover
		//	break;
		//}

	}


	/////////////////////////////////////////////////////////


	manager->Update(eTime);

	float forceX = 0.f;
	float forceY = 0.f;
	float forceZ = 0.f;
	float amount = 15;
	float z_amount = 200;

	if (g_keyW) {
		forceY += amount;
	}
	if (g_keyS) {
		forceY -= amount;
	}
	if (g_keyA) {


		forceX -= amount;

	}
	if (g_keyD) {


		forceX += amount;

	}
	if (g_keySP) {
		forceZ += z_amount;
	}


	manager->ApplyForce(forceX, forceY, forceZ, eTime);

	manager->Update(eTime);

	manager->RenderScene();
	manager->Shoot(g_Shoot);

	manager->GarbageCollector();
	manager->DoCollisionTest();
	glutSwapBuffers();
}

//콜백함수들. 누르는 순간 이벤트가 발생해서 호출이 된다
void Idle(void)
{
	RenderScene();
}

void MouseInput(int button, int state, int x, int y)
{
	RenderScene();
}

void KeyUpInput(unsigned char key, int x, int y)
{
	/*manager->KeyInput(key,x,y);
	RenderScene();*/

	// 이제 여기서 할거기때문에 renderscene을 다시 호출할필요는 업소
	if (key == 'w')
	{
		g_keyW = false;


	}
	else if (key == 'a')
	{
		g_keyA = false;

	}
	else if (key == 's')
	{
		g_keyS = false;

	}
	else if (key == 'd')
	{
		g_keyD = false;

	}
	else if (key == ' ')
	{
		g_keySP = false;
	}

}

void KeyDownInput(unsigned char key, int x, int y) {

	//manager->KeyUpInput(key, x, y);
	//RenderScene();

	if (!GameStart)
	{
		if (key == 'P' || key == 'p') {
			start_push++;

			if (start_push == 1) {
				manager->Draw_Howto();
			}
			else if (start_push == 2) {
				GameStart = true;
				manager->SetStatus(1);
			}
		}
	}
	else if (GameStart) {
		if (key == 'w' || key == 'W')
		{
			g_keyW = true;

		}
		else if (key == 'a' || key == 'A')
		{
			g_keyA = true;
		}
		else if (key == 's' || key == 'S')
		{
			g_keyS = true;
		}
		else if (key == 'd' || key == 'D')
		{
			g_keyD = true;
		}
		else if (key == ' ')
		{
			g_keySP = true;
		}

	}

}
void SpecialKeyDownInput(int key, int x, int y)
{
	if (GameStart)
	{	//if (key == GLUT_KEY_UP) {
		switch (key) {
		case GLUT_KEY_UP:
			g_Shoot = SHOOT_UP;

			break;
		case GLUT_KEY_DOWN:
			g_Shoot = SHOOT_DOWN;
			break;
		case GLUT_KEY_LEFT:
			g_Shoot = SHOOT_LEFT;
			break;
		case GLUT_KEY_RIGHT:
			g_Shoot = SHOOT_RIGHT;
			break;

		}
	}
	//}
}
void SpecialKeyUpInput(int key, int x, int y)
{
	g_Shoot = SHOOT_NONE;
}


int main(int argc, char **argv)
{
	// Initialize GL things
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(WIDTH_SIZE, HEIGHT_SIZE);
	glutCreateWindow("Game Software Engineering KPU");

	glewInit();
	if (glewIsSupported("GL_VERSION_3_0"))
	{
		std::cout << " GLEW Version is 3.0\n ";
	}
	else
	{
		std::cout << "GLEW 3.0 not supported\n ";
	}


	//콜백함수 등록
	glutDisplayFunc(RenderScene);
	glutIdleFunc(Idle);
	glutKeyboardFunc(KeyDownInput);
	glutKeyboardUpFunc(KeyUpInput);
	glutMouseFunc(MouseInput);

	glutSpecialFunc(SpecialKeyDownInput);
	glutSpecialUpFunc(SpecialKeyUpInput);

	/*int a = GLUT_KEY_UP;
	int a = GLUT_KEY_DOWN;
	int a = GLUT_KEY_LEFT;
	int a = GLUT_KEY_RIGHT;*/

	//init scnmgr

	glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);

	manager = new ScnMgr();

	//초당 60번씩 루프를 돈다
	glutMainLoop();

	delete manager;

	return 0;
}

