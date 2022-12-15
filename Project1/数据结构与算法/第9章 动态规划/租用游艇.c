#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int r[210][210];
int f[210];
int mymin(int a, int b)
{
	return a > b ? b : a;
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			scanf("%d", &r[i][j]);
	f[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		f[i] = r[1][i];
	}
	for (int j = 1; j <= n; j++)
	{
		for (int i = 1; i < j; i++)
		{
			f[j] = mymin(f[j], r[i][j] + f[i]);
		}
	}
	printf("%d\n", f[n]);
	return 0;
}
