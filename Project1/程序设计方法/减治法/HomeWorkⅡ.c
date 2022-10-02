#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>

double right, left;
double x[100005][2];

double MAX(int n,double a)
{
	double max = 0;
	for (int i = 0; i < n; i++)
	{
		double temp = sqrt(((x[i][0] - a) * (x[i][0] - a) + x[i][1] * x[i][1]));
		if (max < temp)
			max = temp;
	}
	return max;
}

int main()
{
	int n;
	scanf("%d", &n);
	scanf("%lf%lf", &x[0][0], &x[0][1]);
	right = left = x[0][0];
	for (int i = 1; i < n; i++)
	{
		scanf("%lf%lf", &x[i][0], &x[i][1]);
		if (x[i][0] > right)
			right = x[i][0];
		if (x[i][0] < left)
			left = x[i][0];
	}
	while (right - left >= 10e-6)
	{
		double l1 = (right - left) / 3 + left;
		double l2 = right - (right - left) / 3;
		if (MAX(n, l1) > MAX(n, l2))
			left = l1;
		else if(MAX(n, l1) < MAX(n, l2))
			right = l2;
		else
		{
			left = l1;
			right = l2;
		}
	}
	printf("%.4lf\n", MAX(n, left));

}