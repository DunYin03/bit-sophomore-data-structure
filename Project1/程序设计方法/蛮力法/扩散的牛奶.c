#define _CRT_SECURE_NO_WARNINGS 1
#define PI 3.1415926
#include <stdio.h>
#include <math.h>

int x[6], y[6], n, vir[6] = {0};
double len[6][6] = { 0 };
double R[6] = { 0 };
int x1, x2, y3, y2;
double max;
int min(int a, int b)
{
	return a > b ? b : a;
}

void dfs(int step, double s)//step为牛奶的滴速，s为目前牛奶面积
{
	int i, k;
	double r = 0;

	if (step == n + 1)
	{
		max = s > max ? s : max;
	}
	else
	{
		for (k = 0; k < n; k++)
		{
			if (!vir[k])
			{
				r = min(min(abs(x[k] - x1), abs(x[k] - x2)), min(abs(y[k] - y3), abs(y[k] - y2)));
				for (i = 0; i < n; i++)
					if (vir[i])
						if (r > len[i][k] - R[i])
							r = len[i][k] - R[i];
				r = r < 0 ? 0 : r;
				vir[k] = 1;
				R[k] = r;
				dfs(step + 1, s + PI * r * r);
				vir[k] = 0;
				R[k] = 0;
			}
		}
	}
}

int main()
{
	int a[6];
	scanf("%d", &n);
	scanf("%d %d %d %d", &x1, &y3, &x2, &y2);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &x[i], &y[i]);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (i != j)
			{
				len[i][j] = len[j][i] = sqrt(1.0 * (x[i] - x[j]) * (x[i] - x[j]) + 1.0 * (y[i] - y[j]) * (y[i] - y[j]));
			}
		}
	}
	int S = abs(x1 - x2) * abs(y3 - y2);
	dfs(1, 0.0);
	printf("%d\n", (int)(S - max + 0.5));
	return 0;
}