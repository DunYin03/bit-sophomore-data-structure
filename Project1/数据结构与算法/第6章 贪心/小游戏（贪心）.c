#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
struct node
{
	int next;
	int last;
}line[2005];

int cnt, vis[2005], dp[2005][2];
int flag[2005];

int mymin(int x, int y)
{
	return x < y ? x : y;
}

void creat(int a, int b)
{
	cnt++;
	line[cnt].next = b;
	line[cnt].last = flag[a];
	flag[a] = cnt;
}

void dfs(int node)
{
	dp[node][1] = 1;
	for (int i = flag[node]; i > 0; i = line[i].last)
	{
		dfs(line[i].next);
		dp[node][0] += dp[line[i].next][1];
		dp[node][1] += mymin(dp[line[i].next][1], dp[line[i].next][0]);
	}
}

int main()
{
	int n, c, d, m, begin;
	while (~scanf("%d", &n))
	{
		begin = 0;
		cnt = 0;
		memset(dp, 0, sizeof(dp));
		memset(vis, 0, sizeof(vis));
		memset(flag, 0, sizeof(flag));
		for (int i = 0; i < n; i++)
		{
			scanf("%d:(%d) ", &c, &m);
			while (m--)
			{
				scanf("%d", &d);
				creat(c, d);
				vis[d] = 1;
			}
		}
		while (vis[begin] == 1)
			begin++;
		dfs(begin);
		printf("%d\n", mymin(dp[begin][1], dp[begin][0]));
	}
}