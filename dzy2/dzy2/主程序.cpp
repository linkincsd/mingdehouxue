#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <wtypes.h>

int chess[5][5] = { '\0' }, n = 0;                                //�����ʼ����������Ͳ���
BOOL end = false;                                               //�����ʼ����Ϸ�����б��־

//�б���Ӯ��ƽ��
//����Ӯ�ˣ�����1������Ӯ�ˣ�����2��ƽ���򷵻�3
//���ڻ�û�������������Է���0
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
        //б��
        if ((chess[0][0] == 1 && chess[1][1] == 1 && chess[2][2] == 1 && chess[3][3] == 1 && chess[4][4] == 1) || (chess[0][4] == 1 && chess[1][3] == 1 && chess[2][2] == 1 && chess[3][1] == 1 && chess[4][0] == 1))
            return 1;
        else if ((chess[0][0] == 2 && chess[1][1] == 2 && chess[2][2] == 2 && chess[3][3] == 2 && chess[4][4] == 2) || (chess[0][4] == 2 && chess[1][3] == 2 && chess[2][2] == 2 && chess[3][1] == 2 && chess[4][0] == 2))
            return 2;
    }
    //���Ƿ�ƽ��
    else
        return 3;
    return 0;
}

//����������ӣ����ݸ��������������������鸳ֵ
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

//����������������ֵ���������ֵΪ1�����X��ֵΪ2�����O�����������
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

//�������ʼ�˵�
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

    printf("��ӭ����Jack������\n");
    showMenu();
    //���������ж���Ϸ���л��˳�
    std::cin >> in;

    while (in == 1)
    {
        printf("˭���֣�����,������0;������,������1\n");
        std::cin >> first;
        //�����Ⱥ��ֿ�ʼ���飬��if-else���ֶ�
        if (first % 2 == 0)
            while (1)
            {
                draw();
                printf("������λ��x y��\n");
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
                    printf("��Ӯ��!\n");
                    break;
                case 2:
                    end = true;
                    printf("�����ˡ�����������\n");
                    break;
                case 3:
                    end = true;
                    printf("ƽ��\n");
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
            printf("������λ��x y��\n");
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
                printf("��Ӯ��!\n");
                break;
            case 2:
                end = true;
                printf("�����ˡ�����������\n");
                break;
            case 3:
                end = true;
                printf("ƽ��\n");
                break;
            default:
                break;
            }
            if (end)
                break;
        }
        printf("���������(1.yes  2.Thanks)\n");
        int willings;
        std::cin >> willings;
        if (willings != 1)
            break;
    }
    printf("Bye.\n");
    system("pause");
    return 0;
}
