#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int a[105], dp[1000000];
int flag[100000] = {0};
int main()
{
	int s, t, m, l;
	scanf("%d", &l);
	scanf("%d %d %d", &s, &t, &m);
	int base = s * t;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &a[i]);
	}
	a[0] = 0;
	for(int i =1;i<m;i++)
		for(int j =i+1;j<=m;j++)
			if (a[i] > a[j])
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
	if (s == t)
	{
		int count = 0;
		for (int i = 1; i <= m; i++)
			if (a[i] % s == 0)
				count++;
		printf("%d\n", count);
		return 0;
	}
	int num = 0;
	for (int i = 1,last=0; i <= m; i++)
	{
		if (a[i] - last > 100)
		{
			num += a[i] - last - 100;
		}
		last = a[i];
		a[i] -= num;
		flag[a[i]] = 1;
	}
	l = a[m] + 100;
	memset(dp, 0x77, sizeof(dp));
	dp[0] = 0;
	for (int i = 1; i <= l; i++)
	{
		for (int j = s; j <= t; j++)
		{
			if (i - j >= 0)
			{
				if (dp[i] > dp[i - j] + flag[i])
					dp[i] = dp[i - j] + flag[i];
			}
		}
	}
	int ans = 150;
	for (int i = l - t; i <= l; i++)
		if (ans > dp[i])
			ans = dp[i];
	printf("%d\n", ans);

	return 0;
}