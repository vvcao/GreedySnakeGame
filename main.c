#include <stdio.h>
#include <stdlib.h>
#include "wall.h"
#include "snake.h"
#include "food.h"
#include <conio.h>
#include <windows.h>

int score = 0;//分数记录

void update()//更新显示
{
    for(int i = 0; i < snake.size; ++i)
    {
        gotoxy(snake.body[i].x, snake.body[i].y);
        if(i==0)
        {
            printf("@");//蛇头表示
        }
        else{
            printf("#");//蛇身表示
        }
    }
    gotoxy(food.x, food.y);
    printf("x");
}


//offset_X = 1;
//offset_Y = 0;

//死亡判断
int isDeath()
{

    //撞墙
    if(snake.body[0].x>=WIDTH-1 || snake.body[0].y>=HEIGHT-1 || snake.body[0].x<=0 || snake.body[0].y<=0)
    {
        return 1;
    }
    //咬到自己
    for(int i = 1; i < snake.size-1; i++)
    {
        if(snake.body[0].x==snake.body[i].x && snake.body[0].y==snake.body[i].y)
        {
            gotoxy(snake.body[i].x, snake.body[i].y);
            printf("@");//重新显示蛇头
            return 1;
        }
    }

    return 0;
}

//判断是否吃到食物
int eatFood()
{
    if(snake.body[0].x==food.x && snake.body[0].y==food.y)
    {
        initFood();
        snake.size++;
        return 1;
    }
    return 0;
}

//定义隐藏光标函数
void HideCursor()
{
    CONSOLE_CURSOR_INFO cursor;
    cursor.bVisible = FALSE;
    cursor.dwSize = sizeof(cursor);
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorInfo(handle, &cursor);
}

int main()
{
    //隐藏光标
    HideCursor();

    initWall();
    initSnake();
    initFood();
    update();


    char key = 'a';
    char preKey;
    while(1)
    {
        //控制蛇的移动
        preKey = key;//记录上一次方向键


        if(kbhit())//，有按键按下返回真，没有按键按下返回0（防阻塞）
        {
            key = _getch();

            //防止反向移动
            if((preKey=='a' && key=='d') || (preKey=='d' && key=='a') || (preKey=='w' && key=='s') || (preKey=='s' && key=='w'))
            {
                key = preKey;
            }
        }

        switch (key) {
        //左移
        case 'a':
            offset_X = -1;
            offset_Y = 0;
            break;
            //右移
        case 'd':
            offset_X = 1;
            offset_Y = 0;
            break;
            //上移
        case 'w':
            offset_X = 0;
            offset_Y = -1;
            break;
            //下移
        case 's':
            offset_X = 0;
            offset_Y = 1;
            break;
        default:
            break;
        }



        if(isDeath() == 1)//死亡判断
        {
            gotoxy(WIDTH/2, HEIGHT/2);
            printf("GAME OVER!");
            break;
        }


        gotoxy(WIDTH+5, 6);
        printf("score: %d", score);//分数显示
        if(eatFood()==1)
        {
            score++;
        }


        tail_X = snake.body[snake.size-1].x;
        tail_Y = snake.body[snake.size-1].y;
        for(int i = snake.size-1; i > 0; --i)
        {
            snake.body[i].x = snake.body[i-1].x;
            snake.body[i].y = snake.body[i-1].y;
        }

        //控制蛇头的移动
        snake.body[0].x += offset_X;
        snake.body[0].y += offset_Y;

        gotoxy(tail_X, tail_Y);
        printf(" ");


        update();
        Sleep(100);
    }

    return 0;
}
