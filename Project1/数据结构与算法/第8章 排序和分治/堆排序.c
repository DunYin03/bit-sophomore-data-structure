#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
int a[1005];

void adjust(int x, int k)
{
	int i = x;
	int j = 2 * i;
	int up = a[i];
	while (j <= k)
	{
		if (j < k&& a[j] < a[j + 1])
			j++;
		if (a[j] > up)
		{
			a[i] = a[j];
			i = j;
			j = 2 * i;
		}
		else
			j = k + 1;
	}
	a[i] = up;
}

void heapsort()
{
	for(int i = n / 2; i > 0; i--)
	{
		adjust(i, n);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	int t = 3;
	while (t--)
	{
		heapsort();
		for (int k = 1; k <= n; k++)
		{
			printf("%d ", a[k]);
		}
		printf("\n");
		a[1] = a[n];
		n--;
	}
	return 0;
}