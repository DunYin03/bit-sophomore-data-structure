#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int a[10], b[10], f[10000000];
int main()
{
	int s, d, n;
	scanf("%d%d%d", &s, &n, &d);

	for (int i = 1; i <= d; i++)
	{
		scanf("%d%d", &a[i], &b[i]);
		a[i] /= 1000;
	}

	while (n--)
	{
		
		for (int i = 1; i <= d; i++)
		{
			for (int j = a[i]; j <= s/1000; j++)
			{
				if (f[j] < f[j - a[i]] + b[i])
					f[j] = f[j - a[i]] + b[i];
			}
		}
		s += f[s/1000];
	}
	printf("%d\n", s);

	return 0;
}