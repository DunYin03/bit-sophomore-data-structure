#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int n, c, w[105];
int vis[105] = { 0 };
int max = 0;

void trackback(int i,int wei)
{
	if (c == wei)
	{
		printf("%d\n", c);
		for (int i = 1; i <= n; i++)
			if (vis[i])
				printf("%d ", i);
		printf("\n");
		exit(0);
	}
	if (wei > c)
	{
		if (max < wei - w[i])
			max = wei - w[i];
		return;
	}
	for (int j = i; j <= n; j++)
	{
		if (!vis[j])
		{
			vis[j] = 1;
			trackback(j, wei + w[j]);
			vis[j] = 0;
		}
	}
}

int main()
{
	scanf("%d%d", &c, &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &w[i]);
	}
	trackback(1, w[0]);
	printf("%d\n", max);
	for (int i = 1; i <= n; i++)
		if(vis[i])
			printf("%d ", i);
	printf("\n");

	return 0;
}