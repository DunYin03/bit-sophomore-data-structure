#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdio.h>


void qsort(int a[], int start, int end)    //start和end都是指下标
{
	int i, j, temp;
	int tmp;

	i = start;
	j = end;
	tmp = a[start];   //任命为中间分界线，左边比他小，右边比他大,通常第一个元素是基准数

	if (i > j)  //如果下标i大于下标j，函数结束运行
	{
		return;
	}

	while (i != j)
	{
		while (a[j] >= tmp && j > i)
		{
			j--;
		}

		while (a[i] <= tmp && j > i)
		{
			i++;
		}

		if (j > i)
		{
			temp = a[j];
			a[j] = a[i];
			a[i] = temp;
		}
	}

	a[start] = a[i];
	a[i] = tmp;

	qsort(a, start, i - 1);
	qsort(a, i + 1, end);
}


int main()
{
	int n, w, a[100000] = { 0 };
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &w);
	qsort(a, 0, n-1);
	int i, m;
	for (i = 0; i < n; i++)
	{
		if (a[i] > w)
			break;
	}
	if (i == 0)
		printf("0\n");
	if (i == n)
	{
		m = a[n - 1];
		int sum = 0;
		int k;
		for (k = 0; k < n - 1; k++)
		{
			sum += a[k];
			if (sum > m)
				break;
		}
		printf("%d\n", k);
	}
	else
	{
		m = a[i - 1];
		int sum = 0;
		int k;
		for (k = 0; k < n - 1; k++)
		{
			sum += a[k];
			if (sum > m)
				break;
		}
		printf("%d\n", k);
	}
}
