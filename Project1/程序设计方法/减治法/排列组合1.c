#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#define PI 3.1415926
#include <stdio.h>
#include <math.h>

int n, vir[8] = { 0 };
int a[8];

void dfs(int step)
{
	int i, k;

	if (step == n)
	{
		for (int i = 0; i < n - 1; i++)
			printf("%d ", a[i] + 1);
		for (int i = 0; i < n; i++)
			if (!vir[i])
				printf("%d\n", i + 1);
	}
	else
	{
		for (k = 0; k < n; k++)
		{
			if (!vir[k])
			{
				vir[k] = 1;
				a[step - 1] = k;
				dfs(step + 1);
				vir[k] = 0;
			}
		}
	}
}

int main()
{
	int a[8];
	scanf("%d", &n);
	dfs(1);
	return 0;
}