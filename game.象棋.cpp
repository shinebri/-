
#include<stdio.h>
#include<easyx.h>
#include<stdlib.h>
#include<time.h>

#define ROW 10
#define COL 9
#define WIDTH 50
#define LENGTH 60

int E[10][9] = { 0 };
int x = 0, y = 0;
void X(int x, int y);
void drawMap();
void print(int map[ROW][COL]);
void mouseEvent(int map[ROW][COL]);
void drawQizi(int map[ROW][COL]);
//int moveRule(int map[ROW][COL], int b, int a,int p);
int judge(int map[ROW][COL])
{
	int m = 0, n = 0;
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if(map[i][j] == 1)
			{
				 m = 1;
			}
			if (map[i][j] == 11)
			{
				 n = 11;
			}
		}
	}
	if (m == 1 && n == 11)
	{
		return 1;
	}
	if (m == 1 && n == 0)
	{
		return 2;
	}
	if (m == 0 && n ==11)
	{
		return 3;
	}
}

int main()
{

	
	initgraph(498, 630);// EW_SHOWCONSOLE
loop:
	//画出原始棋盘
	drawMap();

	int map[ROW][COL] = { 0 };
	map[0][0] = 5; map[0][1] = 4; map[0][2] = 3; map[0][3] = 2; map[0][4] = 1; map[0][5] = 2; map[0][6] = 3; map[0][7] = 4;
	map[0][8] = 5; map[2][1] = 6; map[2][7] = 6; map[3][0] = 7; map[3][2] = 7; map[3][4] = 7; map[3][6] = 7; map[3][8] = 7;
	map[9][0] = 15; map[9][1] = 14; map[9][2] = 13; map[9][3] = 12; map[9][4] = 11; map[9][5] = 12; map[9][6] = 13; map[9][7] = 14;
	map[9][8] = 15; map[7][1] = 16; map[7][7] = 16; map[6][0] = 17; map[6][2] = 17; map[6][4] = 17; map[6][6] = 17; map[6][8] = 17;

	print(map);
	drawQizi(map);

	BeginBatchDraw();


	 while(1)
	 {
		 //鼠标点击
		 mouseEvent(map);
		 FlushBatchDraw();
		int t= judge(map);
		if (t != 1)
		{
			if (t == 2)
			{
				int ret = MessageBox(GetHWnd(), "黑方取得了胜利，还要再来一局吗？", "hint", MB_OKCANCEL);
				if (ret == IDOK)
				{
					
					goto loop;
					
				}
				else if (ret == IDCANCEL)
				{
					exit(678);
				}
			}
			if (t == 3)
			{
				int ret = MessageBox(GetHWnd(), "红方取得了胜利，还要再来一局吗？", "hint", MB_OKCANCEL);
				if (ret == IDOK)
				{

					goto loop;

				}
				else if (ret == IDCANCEL)
				{
					exit(678);
				}
			}
		}

	 }
	 EndBatchDraw();
	 
	getchar();//防止程序关闭
	return 0;
}

void drawMap()
{
	IMAGE beijing;
	loadimage(&beijing, "背景图.jpg");
	putimage(0, 0, &beijing);
	setlinecolor(LIGHTCYAN);
	setlinestyle(PS_SOLID, 2);
	line(199, 45, 299, 165);
	line(299, 45, 199, 165);
	line(199, 585, 299, 465);
	line(299, 585, 199, 465);
	for (int i = 0; i < ROW; i++)
	{
		line(49, 45 + i * LENGTH, 449, 45 + i * LENGTH);
		line(49 + i * WIDTH, 45, 49 + i * WIDTH, 285);
		line(49 + i * WIDTH, 345, 49 + i * WIDTH, 585);
	}
	line(49, 45, 49, 585);
	line(449, 45, 449, 585);
	line(49, 45, 449, 45);
	line(49, 585, 449, 585);
	line(44, 40, 454, 40);
	line(44, 590, 454, 590);
	line(44, 40, 44, 590);
	line(454, 40, 454, 590);

	X(1, 2); X(1, 7); X(7, 2); X(7, 7); X(2, 3);
	X(4, 3); X(6, 3); X(2, 6); X(4, 6); X(6, 6);
	X(0, 3); X(0, 6); X(8, 3); X(8, 6);
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	settextstyle(55, 0, _T("华文行楷"));
	outtextxy(99, 290, _T("楚河"));
	outtextxy(299, 290, _T("汉界"));
}

void X(int m,int n)
{
	int x = m * 50 + 49;
	int y = n * 60 + 45;

	
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 2);
	if (m > 0 && m < 8)
	{
		line(x - 5, y - 5, x - 5, y - 20); line(x - 5, y + 5, x - 5, y + 20);  line(x - 5, y - 5, x - 20, y - 5); line(x - 20, y + 5, x - 5, y + 5);
		line(x + 5, y - 5, x + 20, y - 5);  line(x + 5, y + 5, x + 20, y + 5); line(x + 5, y - 5, x + 5, y - 20); line(x + 5, y + 5, x + 5, y + 20);
	}
	else if (m == 0)
	{
		line(x + 5, y - 5, x + 20, y - 5);  line(x + 5, y + 5, x + 20, y + 5); line(x + 5, y - 5, x + 5, y - 20); line(x + 5, y + 5, x + 5, y + 20);
	}
	else
	{
		line(x - 5, y - 5, x - 5, y - 20); line(x - 5, y + 5, x - 5, y + 20);  line(x - 5, y - 5, x - 20, y - 5); line(x - 20, y + 5, x - 5, y + 5);
	}
}

void print(int map[ROW][COL])
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			printf("%-2d ", map[i][j]);
		}
		printf("\n");
	}
}


void drawQizi(int map[ROW][COL])
{
	for (int m = 0; m < ROW; m++)
	{
		for (int n = 0; n < COL; n++)
		{
			//drawQizi(map, i, j);
			if (map[m][n] == 0)
				{
						//return 0;
				

				}
			if (map[m][n] <= 17 && map[m][n] > 0)
					{
						int x = 49 + n * 50;
						int y = 45 + m * 60;
						if (map[m][n] <= 7)
						{
							setlinecolor(BLACK);
							setlinestyle(PS_SOLID, 2);
							circle(x, y, 20);
							setfillcolor(LIGHTCYAN);
							setlinecolor(WHITE);
							fillcircle(x, y, 18);
							setbkmode(TRANSPARENT);
							settextcolor(BLACK);
							settextstyle(30, 0, _T("华文楷体"));
						}
						if (map[m][n] > 7)
						{
							setlinecolor(RED);
							setlinestyle(PS_SOLID, 2);
							circle(x, y, 20);
							setfillcolor(LIGHTCYAN);
							setlinecolor(WHITE);
							fillcircle(x, y, 18);
							setbkmode(TRANSPARENT);
							settextcolor(RED);
							settextstyle(30, 0, _T("华文楷体"));
						}
				
						if (map[m][n] % 10 == 5)
						{
							outtextxy(x - 14, y - 13, _T("車"));
						}
						if (map[m][n] % 10 == 4)
						{
							outtextxy(x - 14, y - 13, _T("馬"));
						}
						if (map[m][n] == 3)
						{
							outtextxy(x - 14, y - 14, _T("象"));
						}if (map[m][n] == 13)
						{
							outtextxy(x - 14, y - 14, _T("相"));
						}if (map[m][n] == 2)
						{
							outtextxy(x - 15, y - 13, _T("士"));
						}if (map[m][n] == 12)
						{
							outtextxy(x - 15, y - 13, _T("仕"));
						}if (map[m][n] == 1)
						{
							outtextxy(x - 14, y - 13, _T("將"));
						}if (map[m][n] == 11)
						{
							outtextxy(x - 14, y - 13, _T("帥"));
						}if (map[m][n] % 10 == 6)
						{
							outtextxy(x - 14, y - 14, _T("炮"));
						}if (map[m][n] == 7)
						{
							outtextxy(x - 14, y - 13, _T("卒"));
						}if (map[m][n] == 17)
						{
							outtextxy(x - 14, y - 13, _T("兵"));
						}
					}
		}
	}
}

void mouseEvent(int map[ROW][COL])
{
	
	ExMessage msg;
	if (peekmessage(&msg, EM_MOUSE))
	{
		int a = (msg.x + 25 - 49) / WIDTH;
		int b = (msg.y + 30 - 45) / LENGTH;
		if ( (a*50+34)<msg.x&&msg.x<(a*50+64)&& (b * 60 + 30) < msg.y && msg.y < (b * 60 + 60))
		{
			static int redfang = 1;
			if (msg.message == WM_LBUTTONDOWN)
			{
				
				//printf("a=%d\n", a); printf("b=%d\n", b); printf("x=%d\n", x); printf("y=%d\n", y);
				
				//if (retfang == 1 && (map[y][x] >= 11 && map[y][x] <= 17))
				//(map[b][a] <= 7 && map[b][a] > 0 && E[y][x] >= 11 && E[y][x] <= 17) ||
				

				printf("ret=%d\n", redfang);
				printf("%d\n", map[b][a]);
				printf("%d\n", E[y][x]);
				printf("a=%d\n", a); printf("b=%d\n", b); printf("x=%d\n", x); printf("y=%d\n", y);
				
				print(map);
				print(E);
					if (((map[b][a] == 0 && E[y][x] != 0)&& (E[y][x] > 10 && E[y][x] <= 17)) || ((map[b][a] >= 1 && map[b][a] <= 7) && (E[y][x] > 10 && E[y][x] <= 17)))
					{

						if (redfang % 2 == 1)
						{
							//p= moveRule(map,b,a,p);
							//map[b][a] = p;
							//print(map);

							if (map[y][x] == 7 && b == 4 && x == a&&y==3)//小卒子在自己家只能向前 
							{
								map[y][x] = 0;
								printf("a=%d\n", a); printf("b=%d\n", b); printf("x=%d\n", x); printf("y=%d\n", y);
								map[b][a] = E[y][x];
								print(map);
								E[y][x] = 0;
								redfang++;
							}
							if (map[y][x] == 7 && ((x == a && b == y + 1) || (b == y && (a == x - 1 || a == x + 1))) && b > 4)//小卒子在别人家可以向左和右
							{
								map[y][x] = 0;
								printf("a=%d\n", a); printf("b=%d\n", b); printf("x=%d\n", x); printf("y=%d\n", y);
								map[b][a] = E[y][x];
								print(map);
								E[y][x] = 0;
								redfang++;

							}
							if (map[y][x] == 17 && b == 5 && x == a&&y==6)//小卒子在自己家只能向前
							{
								map[y][x] = 0;
								printf("a=%d\n", a); printf("b=%d\n", b); printf("x=%d\n", x); printf("y=%d\n", y);
								map[b][a] = E[y][x];
								print(map);
								E[y][x] = 0;
								redfang++;

							}
							if (map[y][x] == 17 && ((x == a && b == y - 1) || (b == y && (a == x - 1 || a == x + 1))) && b < 5)//小卒子在别人家可以向左和右
							{
								map[y][x] = 0;
								printf("a=%d\n", a); printf("b=%d\n", b); printf("x=%d\n", x); printf("y=%d\n", y);
								map[b][a] = E[y][x];
								print(map);
								E[y][x] = 0;
								redfang++;

							}
							if (map[y][x] == 1 && (x == a && (y - 1 == b || y + 1 == b) || (y == b && (x + 1 == a || x - 1 == a))) && (a >= 3 && a <= 5) && (b >= 0 && b <= 2))//将的自闭九宫格
							{
								map[y][x] = 0;
								printf("a=%d\n", a); printf("b=%d\n", b); printf("x=%d\n", x); printf("y=%d\n", y);
								map[b][a] = E[y][x];
								print(map);
								E[y][x] = 0;
								redfang++;
							}
							if (map[y][x] == 11 && (x == a && (y - 1 == b || y + 1 == b) || (y == b && (x + 1 == a || x - 1 == a))) && (a >= 3 && a <= 5) && (b >= 7 && b <= 9))//帅的自闭九宫格
							{
								map[y][x] = 0;
								printf("a=%d\n", a); printf("b=%d\n", b); printf("x=%d\n", x); printf("y=%d\n", y);
								map[b][a] = E[y][x];
								print(map);
								E[y][x] = 0;
								redfang++;

							}
							if (map[y][x] == 2 && ((x - 1 == a && y - 1 == b) || (x + 1 == a && y - 1 == b) || (x - 1 == a && y + 1 == b) || (x + 1 == a && y + 1 == b)) && (a >= 3 && a <= 5) && (b >= 0 && b <= 2))//士的自闭九宫格
							{
								map[y][x] = 0;
								printf("a=%d\n", a); printf("b=%d\n", b); printf("x=%d\n", x); printf("y=%d\n", y);
								map[b][a] = E[y][x];
								print(map);
								E[y][x] = 0;
								redfang++;
							}
							if (map[y][x] == 12 && ((x - 1 == a && y - 1 == b) || (x + 1 == a && y - 1 == b) || (x - 1 == a && y + 1 == b) || (x + 1 == a && y + 1 == b)) && (a >= 3 && a <= 5) && (b >= 7 && b <= 9))//士的自闭九宫格
							{
								map[y][x] = 0;
								printf("a=%d\n", a); printf("b=%d\n", b); printf("x=%d\n", x); printf("y=%d\n", y);
								map[b][a] = E[y][x];
								print(map);
								E[y][x] = 0;
								redfang++;
							}

							if (map[y][x] == 3 && (a >= 0 && a <= 8) && (b >= 0 && b <= 4))//相
							{
								printf("%d\n", map[y][x]);
								//&& (((x - 2 == a && y - 2 == b)&&(map[y-1][x-1]==0)) || ((x + 2 == a && y - 2 == b) && (map[y - 1][x + 1] == 0)) || ((x - 2 == a && y + 2 == b) &&( map[y + 1][x - 1] == 0)) || ((x + 2 == a && y + 2 == b) && (map[y + 1][x + 1] == 0)))
								if (map[y + 1][x + 1] == 0 && (x + 2 == a && y + 2 == b) && (x + 2 <= 8 && y + 2 <= 9))
								{

									map[y][x] = 0;

									printf("a=%d\n", a); printf("b=%d\n", b); printf("x=%d\n", x); printf("y=%d\n", y);
									map[b][a] = E[y][x];
									print(map);
									E[y][x] = 0;
									redfang++;
								}

								if (map[y - 1][x - 1] == 0 && (x - 2 == a && y - 2 == b) && (x - 2 >= 0 && y - 2 >= 0))
								{

									map[y][x] = 0;
									printf("a=%d\n", a); printf("b=%d\n", b); printf("x=%d\n", x); printf("y=%d\n", y);
									map[b][a] = E[y][x];
									print(map);
									E[y][x] = 0;
									redfang++;
								}
								printf("%d\n", map[y][x]);
								if (map[y - 1][x + 1] == 0 && (x + 2 == a && y - 2 == b) && (x + 2 <= 8 && y - 2 >= 0))
								{

									map[y][x] = 0;
									printf("a=%d\n", a); printf("b=%d\n", b); printf("x=%d\n", x); printf("y=%d\n", y);
									map[b][a] = E[y][x];
									print(map);
									E[y][x] = 0;
									redfang++;
								}
								printf("%d\n", map[y][x]);
								if (map[y + 1][x - 1] == 0 && (x - 2 == a && y + 2 == b) && (x - 2 >= 0 && y + 2 <= 9))
								{

									map[y][x] = 0;
									printf("a=%d\n", a); printf("b=%d\n", b); printf("x=%d\n", x); printf("y=%d\n", y);
									map[b][a] = E[y][x];
									print(map);
									E[y][x] = 0;
									redfang++;
								}

							}
							if (map[y][x] == 13 && ((x - 2 == a && y - 2 == b) || (x + 2 == a && y - 2 == b) || (x - 2 == a && y + 2 == b) || (x + 2 == a && y + 2 == b)) && (a >= 0 && a <= 8) && (b >= 5 && b <= 9))//相
							{
								map[y][x] = 0;
								printf("a=%d\n", a); printf("b=%d\n", b); printf("x=%d\n", x); printf("y=%d\n", y);
								map[b][a] = E[y][x];
								print(map);
								E[y][x] = 0;
								redfang++;
							}


							if (map[y][x] % 10 == 5)//車的行棋规则
							{
								printf("我来这了");
								int c = 0;
								printf("a=%d\n", a); printf("b=%d\n", b); printf("x=%d\n", x); printf("y=%d\n", y);
								if (a == x && y > b)
								{
									int s = 0; printf("hh\n");
									for (int i = 0; i < y - b - 1; i++)
									{
										s = s + map[y - (i + 1)][x];
									}
									if (s != 0)
									{
										c = 1;
									}
								}
								if (a == x && y < b)
								{
									int s = 0; printf("在2这\n");
									for (int i = 1; i < b - y; i++)
									{
										s = s + map[y + i][x];
									}
									if (s != 0)
									{
										c = 2;
									}
								}
								if (b == y && x < a)
								{
									int s = 0; printf("在3这\n");
									for (int i = 1; i < a - x; i++)
									{
										s = s + map[y][x + i];
									}
									if (s != 0)
									{
										c = 3;
									}
								}
								if (b == y && a < x)
								{
									int s = 0; printf("hh\n");
									for (int i = 1; i < x - a; i++)
									{
										s = s + map[y][x - i];
									}
									if (s != 0)
									{
										c = 4;
									}
								}
								printf("c=%d\n", c);
								if (x == a && c == 0)
								{
									map[y][x] = 0;
									map[b][a] = E[y][x];
									print(map);
									E[y][x] = 0;
									redfang++;
								}
								if (y == b && c == 0)
								{
									map[y][x] = 0;
									map[b][a] = E[y][x];
									print(map);
									E[y][x] = 0;
									redfang++;
								}
							}
							if (map[y][x] % 10 == 6 && (map[b][a] == 0))//炮的行棋规则
							{
								int c = 0;
								printf("a=%d\n", a); printf("b=%d\n", b); printf("x=%d\n", x); printf("y=%d\n", y);
								if (a == x && y > b)
								{
									int s = 0; printf("hh\n");
									for (int i = 0; i < y - b - 1; i++)
									{
										s = s + map[y - (i + 1)][x];
									}
									if (s != 0)
									{
										c = 1;
									}
								}
								if (a == x && y < b)
								{
									int s = 0; printf("在2这\n");
									for (int i = 1; i < b - y; i++)
									{
										s = s + map[y + i][x];
									}
									if (s != 0)
									{
										c = 2;
									}
								}
								if (b == y && x < a)
								{
									int s = 0; printf("在3这\n");
									for (int i = 1; i < a - x; i++)
									{
										s = s + map[y][x + i];
									}
									if (s != 0)
									{
										c = 3;
									}
								}
								if (b == y && a < x)
								{
									int s = 0; printf("hh\n");
									for (int i = 1; i < x - a; i++)
									{
										s = s + map[y][x - i];
									}
									if (s != 0)
									{
										c = 4;
									}
								}
								printf("c=%d\n", c);
								if (x == a && c == 0)
								{
									map[y][x] = 0;
									map[b][a] = E[y][x];
									print(map);
									E[y][x] = 0;
									redfang++;

								}
								if (y == b && c == 0)
								{
									map[y][x] = 0;
									map[b][a] = E[y][x];
									print(map);
									E[y][x] = 0;
									redfang++;

								}
							}

							if (map[y][x] % 10 == 6 && ((map[b][a] <= 7 && map[b][a] > 0 && E[y][x] >= 11 && E[y][x] <= 17) || (map[b][a] >= 11 && map[b][a] <= 17 && E[y][x] > 0 && E[y][x] <= 7)))//炮的隔山打牛
							{
								int c = 0;
								printf("a=%d\n", a); printf("b=%d\n", b); printf("x=%d\n", x); printf("y=%d\n", y);
								if (a == x && y > b)
								{
									for (int i = 1; i < y - b; i++)
									{
										if (map[y - i][x] != 0)
										{
											c++;
										}
									}
								}
								if (a == x && b > y)
								{
									for (int i = 1; i < b - y; i++)
									{
										if (map[y + i][x] != 0)
										{
											c++;
										}
									}
								}
								if (b == y && a > x)
								{
									for (int i = 1; i < a - x; i++)
									{
										if (map[y][x + i] != 0)
										{
											c++;
										}
									}
								}
								if (b == y && x > a)
								{
									for (int i = 1; i < x - a; i++)
									{
										if (map[y][x - i] != 0)
										{
											c++;
										}
									}
								}
								printf("c=%d\n", c);
								if (x == a && c == 1)
								{
									map[y][x] = 0;
									map[b][a] = E[y][x];
									print(map);
									E[y][x] = 0;
									redfang++;
								}
								printf("c=%d\n", c);
								if (y == b && c == 1)
								{
									map[y][x] = 0;
									map[b][a] = E[y][x];
									print(map);
									E[y][x] = 0;
									redfang++;
								}
							}

							if (map[y][x] % 10 == 4)//马的行为规范
							{
								if (map[y - 1][x] == 0 && ((b == y - 2 && a == x - 1) || (b == y - 2 && a == x + 1)))
								{
									map[y][x] = 0;
									map[b][a] = E[y][x];
									print(map);
									E[y][x] = 0;
									redfang++;
								}
								if (map[y + 1][x] == 0 && ((b == y + 2 && a == x - 1) || (b == y + 2 && a == x + 1)))
								{
									map[y][x] = 0;
									map[b][a] = E[y][x];
									print(map);
									E[y][x] = 0;
									redfang++;
								}
								if (map[y][x - 1] == 0 && ((b == y - 1 && a == x - 2) || (b == y + 1 && a == x - 2)))
								{
									map[y][x] = 0;
									map[b][a] = E[y][x];
									print(map);
									E[y][x] = 0;
									redfang++;
								}
								if (map[y][x + 1] == 0 && ((b == y - 1 && a == x + 2) || (b == y + 1 && a == x + 2)))
								{
									map[y][x] = 0;
									map[b][a] = E[y][x];
									print(map);
									E[y][x] = 0;
									redfang++;
								}
							}

							drawMap();
							drawQizi(map);
							
						}
					}
					printf("分界线\n");
					
					printf("ret=%d\n", redfang);
					if (((map[b][a] == 0 && E[y][x] != 0) && (E[y][x] > 0 && E[y][x] <= 7)) || ((map[b][a] >= 11 && map[b][a] <= 17) && (E[y][x] > 0 && E[y][x] <= 7)))
					{

						if (redfang % 2 == 0)
						{
							if (map[y][x] == 7 && b == 4 && x == a&&y==3)//小卒子在自己家只能向前 
							{
								map[y][x] = 0;
								printf("a=%d\n", a); printf("b=%d\n", b); printf("x=%d\n", x); printf("y=%d\n", y);
								map[b][a] = E[y][x];
								print(map);
								E[y][x] = 0;
								redfang++;
							}
							if (map[y][x] == 7 && ((x == a && b == y + 1) || (b == y && (a == x - 1 || a == x + 1))) && b > 4)//小卒子在别人家可以向左和右
							{
								map[y][x] = 0;
								printf("a=%d\n", a); printf("b=%d\n", b); printf("x=%d\n", x); printf("y=%d\n", y);
								map[b][a] = E[y][x];
								print(map);
								E[y][x] = 0;
								redfang++;
							}
							if (map[y][x] == 17 && b == 5 && x == a&&y==6)//小卒子在自己家只能向前
							{
								map[y][x] = 0;
								printf("a=%d\n", a); printf("b=%d\n", b); printf("x=%d\n", x); printf("y=%d\n", y);
								map[b][a] = E[y][x];
								print(map);
								E[y][x] = 0;
								redfang++;
							}
							if (map[y][x] == 17 && ((x == a && b == y - 1) || (b == y && (a == x - 1 || a == x + 1))) && b < 5)//小卒子在别人家可以向左和右
							{
								map[y][x] = 0;
								printf("a=%d\n", a); printf("b=%d\n", b); printf("x=%d\n", x); printf("y=%d\n", y);
								map[b][a] = E[y][x];
								print(map);
								E[y][x] = 0;
								redfang++;
							}
							if (map[y][x] == 1 && (x == a && (y - 1 == b || y + 1 == b) || (y == b && (x + 1 == a || x - 1 == a))) && (a >= 3 && a <= 5) && (b >= 0 && b <= 2))//将的自闭九宫格
							{
								map[y][x] = 0;
								printf("a=%d\n", a); printf("b=%d\n", b); printf("x=%d\n", x); printf("y=%d\n", y);
								map[b][a] = E[y][x];
								print(map);
								E[y][x] = 0;
								redfang++;
							}
							if (map[y][x] == 11 && (x == a && (y - 1 == b || y + 1 == b) || (y == b && (x + 1 == a || x - 1 == a))) && (a >= 3 && a <= 5) && (b >= 7 && b <= 9))//帅的自闭九宫格
							{
								map[y][x] = 0;
								printf("a=%d\n", a); printf("b=%d\n", b); printf("x=%d\n", x); printf("y=%d\n", y);
								map[b][a] = E[y][x];
								print(map);
								E[y][x] = 0;
								redfang++;
							}
							if (map[y][x] == 2 && ((x - 1 == a && y - 1 == b) || (x + 1 == a && y - 1 == b) || (x - 1 == a && y + 1 == b) || (x + 1 == a && y + 1 == b)) && (a >= 3 && a <= 5) && (b >= 0 && b <= 2))//士的自闭九宫格
							{
								map[y][x] = 0;
								printf("a=%d\n", a); printf("b=%d\n", b); printf("x=%d\n", x); printf("y=%d\n", y);
								map[b][a] = E[y][x];
								print(map);
								E[y][x] = 0;
								redfang++;
							}
							if (map[y][x] == 12 && ((x - 1 == a && y - 1 == b) || (x + 1 == a && y - 1 == b) || (x - 1 == a && y + 1 == b) || (x + 1 == a && y + 1 == b)) && (a >= 3 && a <= 5) && (b >= 7 && b <= 9))//士的自闭九宫格
							{
								map[y][x] = 0;
								printf("a=%d\n", a); printf("b=%d\n", b); printf("x=%d\n", x); printf("y=%d\n", y);
								map[b][a] = E[y][x];
								print(map);
								E[y][x] = 0;
								redfang++;
							}

							if (map[y][x] == 3 && (a >= 0 && a <= 8) && (b >= 0 && b <= 4))//相
							{
								printf("%d\n", map[y][x]);
								//&& (((x - 2 == a && y - 2 == b)&&(map[y-1][x-1]==0)) || ((x + 2 == a && y - 2 == b) && (map[y - 1][x + 1] == 0)) || ((x - 2 == a && y + 2 == b) &&( map[y + 1][x - 1] == 0)) || ((x + 2 == a && y + 2 == b) && (map[y + 1][x + 1] == 0)))
								if (map[y + 1][x + 1] == 0 && (x + 2 == a && y + 2 == b) && (x + 2 <= 8 && y + 2 <= 9))
								{

									map[y][x] = 0;

									printf("a=%d\n", a); printf("b=%d\n", b); printf("x=%d\n", x); printf("y=%d\n", y);
									map[b][a] = E[y][x];
									print(map);
									E[y][x] = 0;
									redfang++;
								}

								if (map[y - 1][x - 1] == 0 && (x - 2 == a && y - 2 == b) && (x - 2 >= 0 && y - 2 >= 0))
								{

									map[y][x] = 0;
									printf("a=%d\n", a); printf("b=%d\n", b); printf("x=%d\n", x); printf("y=%d\n", y);
									map[b][a] = E[y][x];
									print(map);
									E[y][x] = 0;
									redfang++;
								}
								printf("%d\n", map[y][x]);
								if (map[y - 1][x + 1] == 0 && (x + 2 == a && y - 2 == b) && (x + 2 <= 8 && y - 2 >= 0))
								{

									map[y][x] = 0;
									printf("a=%d\n", a); printf("b=%d\n", b); printf("x=%d\n", x); printf("y=%d\n", y);
									map[b][a] = E[y][x];
									print(map);
									E[y][x] = 0;
									redfang++;
								}
								printf("%d\n", map[y][x]);
								if (map[y + 1][x - 1] == 0 && (x - 2 == a && y + 2 == b) && (x - 2 >= 0 && y + 2 <= 9))
								{

									map[y][x] = 0;
									printf("a=%d\n", a); printf("b=%d\n", b); printf("x=%d\n", x); printf("y=%d\n", y);
									map[b][a] = E[y][x];
									print(map);
									E[y][x] = 0;
									redfang++;
								}

							}
							if (map[y][x] == 13 && ((x - 2 == a && y - 2 == b) || (x + 2 == a && y - 2 == b) || (x - 2 == a && y + 2 == b) || (x + 2 == a && y + 2 == b)) && (a >= 0 && a <= 8) && (b >= 5 && b <= 9))//相
							{
								map[y][x] = 0;
								printf("a=%d\n", a); printf("b=%d\n", b); printf("x=%d\n", x); printf("y=%d\n", y);
								map[b][a] = E[y][x];
								print(map);
								E[y][x] = 0;
								redfang++;
							}


							if (map[y][x] % 10 == 5)//車的行棋规则
							{
								printf("我来这了");
								int c = 0;
								printf("a=%d\n", a); printf("b=%d\n", b); printf("x=%d\n", x); printf("y=%d\n", y);
								if (a == x && y > b)
								{
									int s = 0; printf("hh\n");
									for (int i = 0; i < y - b - 1; i++)
									{
										s = s + map[y - (i + 1)][x];
									}
									if (s != 0)
									{
										c = 1;
									}
								}
								if (a == x && y < b)
								{
									int s = 0; printf("在2这\n");
									for (int i = 1; i < b - y; i++)
									{
										s = s + map[y + i][x];
									}
									if (s != 0)
									{
										c = 2;
									}
								}
								if (b == y && x < a)
								{
									int s = 0; printf("在3这\n");
									for (int i = 1; i < a - x; i++)
									{
										s = s + map[y][x + i];
									}
									if (s != 0)
									{
										c = 3;
									}
								}
								if (b == y && a < x)
								{
									int s = 0; printf("hh\n");
									for (int i = 1; i < x - a; i++)
									{
										s = s + map[y][x - i];
									}
									if (s != 0)
									{
										c = 4;
									}
								}
								printf("c=%d\n", c);
								if (x == a && c == 0)
								{
									map[y][x] = 0;
									map[b][a] = E[y][x];
									print(map);
									E[y][x] = 0;
									redfang++;
								}
								if (y == b && c == 0)
								{
									map[y][x] = 0;
									map[b][a] = E[y][x];
									print(map);
									E[y][x] = 0;
									redfang++;
								}
							}
							if (map[y][x] % 10 == 6 && (map[b][a] == 0))//炮的行棋规则
							{
								int c = 0;
								printf("a=%d\n", a); printf("b=%d\n", b); printf("x=%d\n", x); printf("y=%d\n", y);
								if (a == x && y > b)
								{
									int s = 0; printf("hh\n");
									for (int i = 0; i < y - b - 1; i++)
									{
										s = s + map[y - (i + 1)][x];
									}
									if (s != 0)
									{
										c = 1;
									}
								}
								if (a == x && y < b)
								{
									int s = 0; printf("在2这\n");
									for (int i = 1; i < b - y; i++)
									{
										s = s + map[y + i][x];
									}
									if (s != 0)
									{
										c = 2;
									}
								}
								if (b == y && x < a)
								{
									int s = 0; printf("在3这\n");
									for (int i = 1; i < a - x; i++)
									{
										s = s + map[y][x + i];
									}
									if (s != 0)
									{
										c = 3;
									}
								}
								if (b == y && a < x)
								{
									int s = 0; printf("hh\n");
									for (int i = 1; i < x - a; i++)
									{
										s = s + map[y][x - i];
									}
									if (s != 0)
									{
										c = 4;
									}
								}
								printf("c=%d\n", c);
								if (x == a && c == 0)
								{
									map[y][x] = 0;
									map[b][a] = E[y][x];
									print(map);
									E[y][x] = 0;
									redfang++;
								}
								if (y == b && c == 0)
								{
									map[y][x] = 0;
									map[b][a] = E[y][x];
									print(map);
									E[y][x] = 0;
									redfang++;
								}
							}

							if (map[y][x] % 10 == 6 && ((map[b][a] <= 7 && map[b][a] > 0 && E[y][x] >= 11 && E[y][x] <= 17) || (map[b][a] >= 11 && map[b][a] <= 17 && E[y][x] > 0 && E[y][x] <= 7)))//炮的隔山打牛
							{
								int c = 0;
								printf("a=%d\n", a); printf("b=%d\n", b); printf("x=%d\n", x); printf("y=%d\n", y);
								if (a == x && y > b)
								{
									for (int i = 1; i < y - b; i++)
									{
										if (map[y - i][x] != 0)
										{
											c++;
										}
									}
								}
								if (a == x && b > y)
								{
									for (int i = 1; i < b - y; i++)
									{
										if (map[y + i][x] != 0)
										{
											c++;
										}
									}
								}
								if (b == y && a > x)
								{
									for (int i = 1; i < a - x; i++)
									{
										if (map[y][x + i] != 0)
										{
											c++;
										}
									}
								}
								if (b == y && x > a)
								{
									for (int i = 1; i < x - a; i++)
									{
										if (map[y][x - i] != 0)
										{
											c++;
										}
									}
								}
								printf("c=%d\n", c);
								if (x == a && c == 1)
								{
									map[y][x] = 0;
									map[b][a] = E[y][x];
									print(map);
									E[y][x] = 0;
									redfang++;
								}
								printf("c=%d\n", c);
								if (y == b && c == 1)
								{
									map[y][x] = 0;
									map[b][a] = E[y][x];
									print(map);
									E[y][x] = 0;
									redfang++;
								}
							}

							if (map[y][x] % 10 == 4)//马的行为规范
							{
								if (map[y - 1][x] == 0 && ((b == y - 2 && a == x - 1) || (b == y - 2 && a == x + 1)))
								{
									map[y][x] = 0;
									map[b][a] = E[y][x];
									print(map);
									E[y][x] = 0;
									redfang++;
								}
								if (map[y + 1][x] == 0 && ((b == y + 2 && a == x - 1) || (b == y + 2 && a == x + 1)))
								{
									map[y][x] = 0;
									map[b][a] = E[y][x];
									print(map);
									E[y][x] = 0;
									redfang++;
								}
								if (map[y][x - 1] == 0 && ((b == y - 1 && a == x - 2) || (b == y + 1 && a == x - 2)))
								{
									map[y][x] = 0;
									map[b][a] = E[y][x];
									print(map);
									E[y][x] = 0;
									redfang++;
								}
								if (map[y][x + 1] == 0 && ((b == y - 1 && a == x + 2) || (b == y + 1 && a == x + 2)))
								{
									map[y][x] = 0;
									map[b][a] = E[y][x];
									print(map);
									E[y][x] = 0;
									redfang++;
								}
							}

							drawMap();
							drawQizi(map);
							
							printf("%d\n",redfang);
						}
					}
					if (map[b][a] != 0)//换
					{
						x = a;
						y = b;
						E[y][x] = map[b][a];
					}
					print(E);
				
			}
		}
	}
}




