#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int n;
int p[20][20], q[20][20], pq[20][20];
int maxsum[20] = { 0 };
int sum = 0;
int ans = 0;
int vis[20] = {0};

#define max(a, b) (((a) > (b)) ? (a) : (b))

void dfs(int i)
{
	if (i > n)
	{
		ans = max(ans, sum);
		return;
	}

	int cnt = 0;
	for (int j = i; j <= n; j++)
		cnt += maxsum[j];
	if (sum + cnt < ans)
		return;

	for (int j = 1; j <= n; j++)
	{
		if (vis[j])
			continue;
		else
		{
			vis[j] = 1;
			sum += pq[i][j];
			dfs(i + 1);
			vis[j] = 0;
			sum -= pq[i][j];
		}		
	}
}


int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &p[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &q[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			pq[i][j] = p[i][j] * q[j][i];
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			maxsum[i] = max(maxsum[i], pq[i][j]);
	}
	dfs(1);
	printf("%d\n", ans);

	return 0;
}