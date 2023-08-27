#include<iostream>
#include<ctime>
using namespace std;
void choose();            //电脑或者玩家先手判断
void chessboard();        //打印棋盘
void start(int x);        //游戏开始
void judge();             //判断胜负
void menu();              //打印菜单
char chess[3][3] =
{
	{'  ','  ','  '},
	{'  ','  ','  '},
	{'  ','  ','  '}
};
void menu()
{
	for (int i = 0; i < 26; i++)
		cout << "*";
	cout << endl;
	cout << "**\t1.开始游戏\t**" << endl;
	cout << "**\t0.退出游戏\t**" << endl;
	for (int i = 0; i < 26; i++)
	{
		cout << "*";
	}
	cout << endl;
	int n;
	cin >> n;
	if (n == 1)
	{
		chessboard();
		choose();
	}
	else exit(0);
}
void chessboard()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << chess[i][j];
			if (j < 2)
			{
				cout << " | ";
			}
		}
		cout << "\n";
		if (i < 2)
		{
			cout << "—————" << endl;
		}
	}
	cout << "\n";
}
void choose()
{
	int x;
	cout << "请选择先手（1 - 电脑  0 - 玩家)" << endl;
	cin >> x;
	int z = 0;
	if (x == 1)
		start(x);
	else if (x == 0)
		start(x);
}
void start(int x)
{
	bool flag = x;//flag=0,为人，反之则为电脑
	int m, n;
	if (flag == 0)
	{
	flag0:
		cout << "请输入横坐标1-3，空格隔开后输入纵坐标1-3" << endl;
		cin >> m >> n;
		while (chess[m - 1][n - 1] != ' ')
		{
			cout << "非法输入，请重新输入" << endl;
			cin >> m >> n;
		}
		chess[m - 1][n - 1] = 'X';//人画X，电脑画O
		chessboard();
		judge();
		goto flag1;
	}
	if (flag == 1)
	{
	flag1:
		srand((unsigned)time(NULL));
		int p = rand() % 3 + 1;
		int q = rand() % 3 + 1;
		if (chess[p - 1][q - 1] != ' ')
		{
			goto flag1;
		}
		chess[p - 1][q - 1] = 'O';
		chessboard();
		judge();
		goto flag0;
	}
}
void judge()
{
	for (int h = 0; h < 3; h++)
	{
		if (chess[h][0] == chess[h][1] && chess[h][1] == chess[h][2] && chess[h][0] != ' ')
		{
			if (chess[h][0] == 'X')			//横向判断
			{
				cout << "！！玩家获胜！！" << endl;
				system("pause");
				menu();
			}
			else if (chess[h][0] == 'O')
			{
				cout << "！！电脑获胜！！" << endl;
				system("pause");
				menu();
			}
		}
		if (chess[0][h] == chess[1][h] && chess[1][h] == chess[2][h] && chess[2][h] != ' ')
		{
			if (chess[0][h] == 'X')			//纵向判断
			{
				cout << "！！玩家获胜！！" << endl;
				system("pause");
				menu();
			}
			else if (chess[0][h] == 'O')
			{
				cout << "！！电脑获胜！！" << endl;
				system("pause");
				menu();
			}
		}
		if ((chess[0][0] == chess[1][1] && chess[1][1] == chess[2][2] && chess[2][2] != ' ') ||
			(chess[2][0] == chess[1][1] && chess[1][1] == chess[1][2] && chess[1][2] != ' '))
		{
			if (chess[1][1] == 'X')
			{
				cout << "！！玩家获胜！！" << endl;
				system("pause");
				menu();
			}
			if (chess[1][1] == 'O')
			{
				cout << "！！电脑获胜！！" << endl;
				system("pause");
				menu();
			}
		}
	}
	if (chess[0][0] != ' ' && chess[0][1] != ' ' && chess[0][2] != ' '
		&& chess[1][0] != ' ' && chess[1][1] != ' ' && chess[1][2] != ' '
		&& chess[2][0] != ' ' && chess[2][1] != ' ' && chess[2][2] != ' ')
	{
		cout << "平局" << endl;
		system("pause");
		menu();
	}
}
int main()
{
	menu();
	return 0;
}



   