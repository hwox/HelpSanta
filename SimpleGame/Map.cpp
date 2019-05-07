#include "stdafx.h"
#include "Map.h"
#include "Renderer.h"
#include "GameValue.h"

Map::Map(Renderer *m_ren)
{
	block_0 = m_Renderer->CreatePngTexture("./textures/Map/winter_block1.png");
	block_1 = m_Renderer->CreatePngTexture("./textures/Map/winter_block2.png");
	block_2 = m_Renderer->CreatePngTexture("./textures/Map/winter_block3.png");
	block_3 = m_Renderer->CreatePngTexture("./textures/Map/winter_block4.png");
	
	
	block2_0 = m_Renderer->CreatePngTexture("./textures/Map/stage2_winter_block2.png");
	block2_1 = m_Renderer->CreatePngTexture("./textures/Map/stage2_winter_block1.png");

	m_Renderer = m_ren;

	b_width = (WIDTH_SIZE / MAP_SEPERATE) / 100.f;
	b_height = (HEIGHT_SIZE / MAP_SEPERATE) / 100.f;
}


void Map::Stage1_map() {

	for (int i = 0; i < MAP_SEPERATE; i++) {
		for (int j = 0; j < MAP_SEPERATE; j++)
		{

			GLuint temp_block = 0;
			switch (j % 4) {
			case 0:
				temp_block = block_0;
				break;
			case 1:
				temp_block = block_1;
				break;
			case 2:
				temp_block = block_2;
				break;
			case 3:
				temp_block = block_3;
				break;
			}
			m_Renderer->DrawTextureRectDepth(-240 + (i * 20), 240 - (j * 20), 1, 20, 20, 1, 1, 1, 1, temp_block, 1);

		}
	}


}
void Map::Stage2_map() {
	for (int i = 0; i < MAP_SEPERATE/2; i++) {
		for (int j = 0; j < MAP_SEPERATE/2; j++)
		{

			GLuint temp_block = 0;
			switch (j % 2) {
			case 0:
				temp_block = block2_0;
				break;
			case 1:
				temp_block = block2_1;
				break;
			
			}
			m_Renderer->DrawTextureRectDepth(-240 + (i * 40), 240 - (j * 40), 1, 40, 40, 1, 1, 1, 1, temp_block, 1);

		}
	}

}
Map::~Map()
{
}
