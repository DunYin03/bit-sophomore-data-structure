#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
float variance(int a[], int n)
{
	float avg = 0;
	float res = 0;
	for (int i = 0; i < n; i++)
		avg += a[i];
	avg /= n;
	for (int i = 0; i < n; i++)
		res += (a[i] - avg) * (a[i] - avg);
	res /= n;
	return res;
}
int main()
{
	int n, a[1000] = { 0 };
	int k;
	float res;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	res = variance(a, n);
	if (res == 0)
		printf("No answer!\n");
	else
	{
		int a = 1, b = 2;
		while (b * b * res <= k)
		{
			a++;
			b++;
		}
		if (k - a * a * res > b * b * res - k)
			printf("%d\n", b);
		else
			printf("%d\n", a);
	}
}
