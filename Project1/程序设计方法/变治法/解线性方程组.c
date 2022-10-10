#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
double a[102][102];
int flag = 0;

void swap(double *a, double *b)
{
	double temp = *a;
	*a = *b;
	*b = temp;
}

void select(int n)
{
	double temp;
	for (int i = 0; i < n; i++)
	{
		int r = i;
		for (int j = i + 1; j < n; j++)
			if (fabs(a[j][i]) > fabs(a[r][i]))
				r = j;
		if (r != i)
			for (int j = i; j <= n; j++)
				swap(&a[i][j], &a[r][j]);
		for (int j = i + 1; j < n; j++)//每行进行消元
		{
			if (a[j][i] == 0.0)
				continue;
			temp = a[j][i] / a[i][i];
			for (int k = i; k <= n; k++)
			{
				a[j][k] -= temp * a[i][k];
			}
		}
	}
}


void gauss(int n) 
{
	select(n);
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = i + 1; j < n; j++)
		{
			a[i][n] -= a[i][j] * a[j][n];
		}
		if (0.0 == a[i][i])
		{
			flag = 1;
			break;
		}
		a[i][n] /= a[i][i];//系数化为1
	}
}


int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= n; j++)
			scanf("%lf", &a[i][j]);
	gauss(n);
	if (1 == flag)
		printf("No Solution\n");	
	else
	{
		for (int i = 0; i < n; i++)
			printf("%.2lf\n", a[i][n]);
	}
	
	return 0;
}