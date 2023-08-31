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
