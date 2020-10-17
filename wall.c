#include "wall.h"

//光标定位
void gotoxy(int x, int y)
{
    COORD p;
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    p.X = x;
    p.Y = y;
    SetConsoleCursorPosition(handle, p);
}

//初始化墙
void initWall()
{
    for(int i = 0; i < HEIGHT; ++i)
    {
        for(int j = 0; j < WIDTH; ++j)
        {
            if(i==0 || i==HEIGHT-1 || j==0 || j==WIDTH-1)
            {
                printf("*");//墙的边界用'*'表示
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    //游戏名字显示
    gotoxy(WIDTH+5, 5);
    printf("GreedySnakeGame");

}


