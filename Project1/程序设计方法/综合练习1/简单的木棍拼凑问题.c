#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int a[105];
int vis[105] = {0};
int m, n, len;
int sum = 0;

void dfs(int k, int last, int rest)
{
	if (k == m)
	{
		printf("%d\n", len);
		exit(0);
	}
	if (rest == 0)
	{
		int i;
		for (i = 1; i <= n; i++)
			if (vis[i]==0)
				break;
		vis[i] = 1;
		dfs(k + 1, i, len - a[i]);
		vis[i] = 0;
	}
	for (int i = last + 1; i <= n; i++)
	{
		if (vis[i] == 0 && a[i] <= rest)
		{
			vis[i] = 1;
			dfs(k, i, rest - a[i]);
			vis[i] = 0;
			while (a[i] == a[i + 1])
				i++;
		}
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		sum += a[i];
	}
	for (int i = 1; i < n; i++)
	{
		int max = i;
		for (int j = i + 1; j <= n; j++)
			if (a[max] < a[j])
				max = j;
		if (max != i)
		{
			int temp = a[max];
			a[max] = a[i];
			a[i] = temp;
		}	
	}
	for (len = a[1]; len <= sum; len++)
	{
		if (sum % len != 0)
			continue;
		m = sum / len;
		vis[1] = 1;
		dfs(1, 1, len - a[1]);
	}

	return 0;
}