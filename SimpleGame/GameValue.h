#pragma once

#define AMOUNT 0.5f

#define HERO_ID 0
#define MAX_OBJECTS 300
#define SHOOT_NONE -1
#define SHOOT_LEFT 1
#define SHOOT_RIGHT 2
#define SHOOT_UP 3
#define SHOOT_DOWN 4

#define KIND_HERO 0
#define KIND_BULLET 1
#define KIND_BUILDING 2 
#define KIND_HOUSE 5
#define KIND_OBSTACLE_FOUNTAIN 6
#define KIND_OBSTACLE_SLIDE 7
#define KIND_OBSTACLE_DUCK 8
#define KIND_OBSTACLE_TENT 9
#define KIND_OBSTACLE_CAR 20
#define KIND_OBSTACLE_TREE 21
#define KIND_OBSTACLE_STONE 12
#define KIND_OBSTACLE_CIRCLE_STONE 13
#define KIND_OBSTACLE_CHRISTMAS_TREE 14


#define KIND_EFFECT_EXPLOSION 3
#define KIND_EFFECT_HIT 4


#define DOOR_RIGHT 10
#define DOOR_LEFT 11
#define STATE_GROUND 0 // 땅에 붙어있을 경우 마찰력의 영향을 받지만 
#define STATE_AIR 1 // 떠 있을 때 마찰력의 영향을 받지 않는다


#define GRAVITY 9.8


#define GAME_WAITING 0
#define GAME_STAGE1 1
#define GAME_STAGE 2


#define WIDTH_SIZE 1280
#define HEIGHT_SIZE 800
#define MAP_SEPERATE 30