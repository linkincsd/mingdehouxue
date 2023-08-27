#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>

int chess[5][5] = { '\0' }, n = 0;          //定义初始化棋盘数组和步数
//棋盘绘制函数
//根据棋盘数组中数值进行输出，值为1则输出X，值为2则输出O，否则输出空
int draw()
{

    system("cls");
    printf("");
    for (int i = 0; i < 5; i++)
    {
        printf("|");
        for (int j = 0; j < 5; j++)
        {
            if (chess[i][j] == 1)
                printf("X");
            else if (chess[i][j] == 2)
                printf("O");
            else
                printf(" ");
            printf("|");
        }
        printf("\n-------------\n");
    }
    return 0;
}