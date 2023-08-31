#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <wtypes.h>

int chess[5][5] = { '\0' }, n = 0;                                //定义初始化棋盘数组和步数
BOOL end = false;                                               //定义初始化游戏结束判别标志

//判别输赢和平局
//我们赢了，返回1；电脑赢了，返回2；平局则返回3
//存在还没走完的情况，所以返回0
int judge()
{

    int i;
    if (n != 25)
    {
        for (i = 0; i < 5; i++)
            if ((chess[i][0] == 1 && chess[i][1] == 1 && chess[i][2] == 1 && chess[i][3] == 1 && chess[i][4] == 1) ||
                (chess[0][i] == 1 && chess[1][i] == 1 && chess[2][i] == 1 && chess[3][i] == 1 && chess[4][i] == 1))
                return 1;
            else if ((chess[i][0] == 2 && chess[i][1] == 2 && chess[i][2] == 2 && chess[i][3] == 2 && chess[i][4] == 2) ||
                (chess[0][i] == 2 && chess[1][i] == 2 && chess[2][i] == 2 && chess[3][i] == 2 && chess[4][i] == 2))
                return 2;
            else
                continue;
        //斜对
        if ((chess[0][0] == 1 && chess[1][1] == 1 && chess[2][2] == 1 && chess[3][3] == 1 && chess[4][4] == 1) || (chess[0][4] == 1 && chess[1][3] == 1 && chess[2][2] == 1 && chess[3][1] == 1 && chess[4][0] == 1))
            return 1;
        else if ((chess[0][0] == 2 && chess[1][1] == 2 && chess[2][2] == 2 && chess[3][3] == 2 && chess[4][4] == 2) || (chess[0][4] == 2 && chess[1][3] == 2 && chess[2][2] == 2 && chess[3][1] == 2 && chess[4][0] == 2))
            return 2;
    }
    //看是否平局
    else
        return 3;
    return 0;
}

//电脑随机落子，根据赋予的随机数进行棋盘数组赋值
void randomDrop()
{

    int x, y;
    while (1)
    {
        x = rand() % 5;
        y = rand() % 5;
        if (chess[x][y] == '\0')
        {
            chess[x][y] = 2;
            break;
        }
    }
    
}

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

//简单输出开始菜单
void showMenu()
{

    printf("##################################################\n");
    printf("##                                              ##\n");
    printf("##     1.start                  2.exit          ##\n");
    printf("##                                              ##\n");
    printf("##################################################\n");
}

int main()
{

    int in, first = 0;
    int x, y;

    printf("欢迎来到Jack井字棋\n");
    showMenu();
    //根据输入判断游戏进行或退出
    std::cin >> in;

    while (in == 1)
    {
        printf("谁先手？你先,请输入0;电脑先,请输入1\n");
        std::cin >> first;
        //根据先后手开始分组，用if-else语句分段
        if (first % 2 == 0)
            while (1)
            {
                draw();
                printf("请输入位置x y：\n");
                std::cin >> x >> y;
                chess[x - 1][y - 1] = 1;
                randomDrop();
                n += 2;
                draw();
                switch (judge())
                {
                case 0:
                    break;
                case 1:
                    end = true;
                    printf("你赢了!\n");
                    break;
                case 2:
                    end = true;
                    printf("你输了。。。。。。\n");
                    break;
                case 3:
                    end = true;
                    printf("平局\n");
                    break;
                default:
                    break;
                }
                if (end)
                    break;
            }
        else
        {
            draw();
            randomDrop();
            printf("请输入位置x y：\n");
            std::cin >> x >> y;
            chess[x - 1][y - 1] = 1;
            n += 2;
            draw();
            switch (judge())
            {
            case 0:
                break;
            case 1:
                end = true;
                printf("你赢了!\n");
                break;
            case 2:
                end = true;
                printf("你输了。。。。。。\n");
                break;
            case 3:
                end = true;
                printf("平局\n");
                break;
            default:
                break;
            }
            if (end)
                break;
        }
        printf("还想继续吗？(1.yes  2.Thanks)\n");
        int willings;
        std::cin >> willings;
        if (willings != 1)
            break;
    }
    printf("Bye.\n");
    system("pause");
    return 0;
}
