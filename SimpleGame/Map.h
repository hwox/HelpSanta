#pragma once
#include <fstream>
#include <iostream>
#include "Renderer.h"

class Map
{
	Renderer * m_Renderer = NULL;
	GLuint block_0 = 0;
	GLuint block_1 = 0;
	GLuint block_2 = 0;
	GLuint block_3 = 0;

	GLuint block2_0 = 0;
	GLuint block2_1 = 0;

	float b_width;
	float b_height;

public:
	//int NextStage;


	Map(Renderer *m_ren);

	void Stage1_map();
	void Stage2_map();

	~Map();
};

