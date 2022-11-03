#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int x;
	int y;
	int dis;
}road[4000],temp;

int n = 0, m = 0;
int tree[1005];

void init()
{
	for (int i = 0; i <= n; ++i)
	{
		tree[i] = i;
	}
}

int find(int n)
{
	if (tree[n] == n)
		return n;
	else
		return find(tree[n]);
}

int judge(int x, int y)
{
	int a = find(x);
	int b = find(y);
	if (a != b)
	{
		tree[a] = b;
		return 1;
	}
	else
		return 0;
}

void sort()
{
	for (int i = 0; i < m-1; i++)
	{
		for (int j = i + 1; j < m; j++)
		{
			if (road[i].dis > road[j].dis)
			{
				temp = road[i];
				road[i] = road[j];
				road[j] = temp;
			}
		}
	}
}

void kruskal()
{
	int side = 0;
	int sum = 0;
	init();
	sort();
	for (int i = 0; i < m; i++)
	{
		if (judge(road[i].x, road[i].y))
		{
			side++;
			sum += road[i].dis;
		}
		if (side == n - 1)
			break;
	}
	if (side != n - 1)
		printf("-1\n");
	else
		printf("%d\n", sum);
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &road[i].x, &road[i].y, &road[i].dis);
	}

	kruskal();
	return 0;
}