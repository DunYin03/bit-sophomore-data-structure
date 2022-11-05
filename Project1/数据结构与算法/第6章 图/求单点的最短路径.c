#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 0x3f3f3f

int road[1005][1005], d[1005];
int vis[1005];
int n, m, num = 0;

void dijkstra(int s)
{
	for (int i = 0; i < n; i++)
	{
		d[i] = road[s][i];
		vis[i] = 0;
	}
	d[s] = 0;
	vis[s] = 1;
	for (int i = 0; i < n; i++)
	{
		int temp = max;
		int v;
		for (int j = 0; j < n; j++)
		{
			if (!vis[j] && temp > d[j])
			{
				temp = d[j];
				v = j;
			}
		}
		if (temp == max)
			break;
		vis[v] = 1;
		for (int j = 0; j < n; j++)
		{
			if (!vis[j] && d[v] + road[v][j] < d[j])
			{
				d[j] = d[v] + road[v][j];
			}
		}
	}
}

int main()
{
	int x, y, dis;
	char a, b, c;
	scanf("%d,%d,%c", &m, &n, &c);
	getchar();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			road[i][j] = (i == j) ? 0 : max;
		}
	}

	for (int i = 0; i < n; i++)
	{
		scanf("<%c,%c,%d>", &a, &b, &dis);
		getchar();
		x = a - 'a';
		y = b - 'a';
		if (road[x][y] > dis)
			road[x][y] = dis;
	}
	num = c - 'a';
	dijkstra(num);
	for (int i = 0; i < m; i++)
	{
		printf("%c:%d\n", i + 'a', d[i]);
	}
	return 0;
}