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
//��������� 64��Ʈ�� 32��Ʈ�� ���̰� ����. ��? �����ϵǾ ������ �� �ƴ϶� �׻� ȯ�濡 �°� ���� ������ �Ǳ� ������
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
	//��½�Ÿ��� ���� gpu cpu �������� ���������̶� �ϴ��� ���ɿ� ���� �ӵ����̰� �ֱ� ����.
	//���� �Ŀ����� loop�� �� ���̵��⶧��

	if (g_prevTime == 0) {
		g_prevTime = timeGetTime();
		return;
	}

	//
	DWORD currTime = timeGetTime();

	DWORD elapsedTime = currTime - g_prevTime;



	g_prevTime = currTime;


	//dword�� �����̱� ������ float ���ϴ� ��©�� �׷��� �ݤ��� ��(float) ����� ��
	float eTime = (float)elapsedTime / 1000.f;

	////////////////////////////////////////////////////////////

	if (!GameStart) {
		// ����ȭ��

		manager->Draw_BG(0);
		// �� ������ status ==1;
	}

	else if (GameStart) {

		// ���� ���� 

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

//�ݹ��Լ���. ������ ���� �̺�Ʈ�� �߻��ؼ� ȣ���� �ȴ�
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

	// ���� ���⼭ �Ұű⶧���� renderscene�� �ٽ� ȣ�����ʿ�� ����
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


	//�ݹ��Լ� ���
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

	//�ʴ� 60���� ������ ����
	glutMainLoop();

	delete manager;

	return 0;
}

