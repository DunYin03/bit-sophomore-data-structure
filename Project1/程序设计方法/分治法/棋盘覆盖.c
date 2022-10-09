#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


int a[2000][2000];
int b[2000][2000];
int count = 1;


void chess(int tr, int tc, int dr, int dc, int size)
{
	if (1 == size)//退出条件
		return;
	int t = count++;
	int s = size / 2;

	//左上角
	if (tr + s > dr && tc + s > dc)
		chess(tr, tc, dr, dc, s);
	else
	{
		a[tr + s - 1][tc + s - 1] = t;
		chess(tr, tc, tr + s - 1,tc + s - 1,s);
	}

	//右上角
	if (tr + s > dr && tc + s <= dc)
		chess(tr, tc + s, dr, dc, s);
	else
	{
		a[tr + s - 1][tc + s] = t;
		chess(tr, tc + s, tr + s - 1, tc + s, s);
	}

	//左下角
	if(tr + s <= dr && tc + s > dc)
		chess(tr+s, tc, dr, dc, s);
	else
	{
		a[tr + s][tc + s - 1] = t;
		chess(tr+s, tc, tr + s, tc + s - 1, s);
	}

	//右下角
	if (tr + s <= dr && tc + s <= dc)
		chess(tr + s, tc+s, dr, dc, s);
	else
	{
		a[tr + s][tc + s] = t;
		chess(tr + s, tc+s, tr + s, tc + s, s);
	}
}

void renew(int size)
{
	int count = 0;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
				if (a[i][j] == a[i + 1][j] && a[i + 1][j] == a[i][j + 1])
				{
					b[i][j] = b[i + 1][j] = b[i][j + 1] = ++count;
				}
				if (a[i][j] == a[i + 1][j + 1] && a[i + 1][j+1] == a[i][j + 1])
				{
					b[i][j] = b[i + 1][j+1] = b[i][j + 1] = ++count;
				}
				if (a[i][j] == a[i + 1][j + 1] && a[i + 1][j + 1] == a[i+1][j])
				{
					b[i][j] = b[i + 1][j + 1] = b[i+1][j] = ++count;
				}
				if (a[i][j+1] == a[i + 1][j + 1] && a[i + 1][j + 1] == a[i + 1][j])
				{
					b[i][j+1] = b[i + 1][j + 1] = b[i + 1][j] = ++count;
				}
			
		}
	}
}

int main()
{
	int n, x, y;
	scanf("%d%d%d", &n, &x, &y);
	x--;
	y--;
	int size = 1;
	for (int i = 0; i < n; i++)
	{
		size *= 2;
	}
	chess(0, 0, x, y, size);
	a[x][y] == 0;
	renew(size);
	b[x][y] = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			printf("%d ",b[i][j]);
		printf("\n");
	}
		
}

