#include "snake.h"


void initSnake()
{
    snake.size = 3;//蛇的大小初始化为3段（包括蛇头）

    //设置蛇头位置
    snake.body[0].x = WIDTH/2;
    snake.body[0].y = HEIGHT/2;

    //设置蛇身位置
        //第一段
    snake.body[1].x = WIDTH/2 - 1;
    snake.body[1].y = HEIGHT/2;
        //第二段
    snake.body[2].x = WIDTH/2 -2;
    snake.body[2].y = HEIGHT/2;
}

