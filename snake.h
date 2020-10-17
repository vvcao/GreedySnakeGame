#ifndef SNAKE_H
#define SNAKE_H

#include <stdio.h>
#include "wall.h"


//定义蛇身结构体
struct BODY{
    int x;
    int y;
};

//蛇的结构体
struct SNAKE{
    struct BODY body[(WIDTH-1) * (HEIGHT-1)];//定义蛇身数组
    int size;//蛇的大小
}snake;


//初始化蛇
void initSnake();

//蛇的偏移量
int offset_X;
int offset_Y;

//记录蛇尾位置
int tail_X;
int tail_Y;

#endif // SNAKE_H
