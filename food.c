#include "food.h"


void initFood()
{
    int flag = 0;//0代不重复
    while(1){
        flag = 0;

        //设置食物随机坐标
        srand((unsigned int)time(NULL));
        food.x = rand()%(WIDTH-2) + 1;
        food.y = rand()%(HEIGHT-2) + 1;

        //避免食物坐标和蛇重叠
        for(int i = 0; i < snake.size-1; ++i)
        {
            if(food.x==snake.body[i].x && food.y==snake.body[i].y)
            {
                flag = 1;//1代表重复
                break;
            }
        }
        if(flag == 0)
        {
            break;
        }
    }

}
