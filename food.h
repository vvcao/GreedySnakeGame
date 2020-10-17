#ifndef FOOD_H
#define FOOD_H
#include "wall.h"
#include "snake.h"
#include <stdlib.h>
#include <time.h>

//食物结构体
struct FOOD{
    int x;//坐标
    int y;//y坐标
}food;


void initFood();


#endif // FOOD_H
