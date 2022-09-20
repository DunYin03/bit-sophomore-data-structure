#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>

int x[200], y[200];

double lengh(int i, int j)
{
	return sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
}

double packed(int n)
{
	double sum = 0;
	int right = 0;
	int left = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			right = 0;
			left = 0;
			int k = 1;
			while(k <= n)
			{
				if (x[i] * y[j] + x[k] * y[i] + x[j] * y[k] - x[k] * y[j] - x[j] * y[i] - x[i] * y[k] > 0)
					right = 1;
				else if(x[i] * y[j] + x[k] * y[i] + x[j] * y[k] - x[k] * y[j] - x[j] * y[i] - x[i] * y[k] < 0)
					left = 1;
				k++;
			}
			if (right != left)
			{
				sum += lengh(i, j);
				break;
			}
		}
	}
	return sum;
}

double max(double a, double b)
{
	return  a > b ? a : b;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d", &x[i], &y[i]);
	}
	if (n == 1)
		printf("0\n");
	else if (n == 2)
		printf("%f", lengh(1, 2));
	else if (n == 3)
	{
		int i = 1, j = 2, k = 3;
		if (x[i] * y[j] + x[k] * y[i] + x[j] * y[k] - x[k] * y[j] - x[j] * y[i] - x[i] * y[k] != 0)
			printf("%lf", lengh(1, 2) + lengh(1, 3) + lengh(2, 3));
		else
			printf("%lf", max(max(lengh(1, 2), lengh(1, 3)), lengh(2, 3)));
	}
	else
		printf("%g", packed(n));
}

