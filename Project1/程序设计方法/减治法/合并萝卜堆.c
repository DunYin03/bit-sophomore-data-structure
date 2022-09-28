#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

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
	int n, a[100000];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	qsort(a, 0, n - 1);
	if (n == 0)
		printf("%d\n", a[0]);
	else
	{
		long long sum = 0;
		long long add = a[0];
		for (int i = 1; i < n; i++)
		{
			add += a[i];
			sum += add;
		}
		printf("%lld\n", sum);
	}

}