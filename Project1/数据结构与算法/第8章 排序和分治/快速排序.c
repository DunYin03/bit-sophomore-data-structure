#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int b = 0;
int a[1006];

void insort(int num[], int i, int j)
{
	int k;
	for (i = i + 1; i <= j; i++)
	{
		num[0] = num[i];
		k = i - 1;
		while (num[0] < num[k])
		{
			num[k + 1] = num[k];
			k--;
		}
		num[k + 1] = num[0];
	}
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Median3(int m[], int i, int j)
{
	int c = (i + j) / 2;
	if (m[i] > m[c]) swap(&m[i], &m[c]);
	if (m[i] > m[j]) swap(&m[i], &m[j]);
	if (m[c] > m[j]) swap(&m[c], &m[j]);
	swap(&m[c], &m[j - 1]);
	a[b++] = m[j - 1];
}

void quicksort(int num[], int left, int right)
{
	int i, j;
	Median3(num, left, right);
	i = left;
	j = right - 1;
	int x = num[j];
	while (1)
	{
		while (num[++i] < x);
		while (num[--j] > x);
		if (i < j)
			swap(&num[i], &num[j]);
		else
			break;
	}
	num[right - 1] = num[i];
	num[i] = x;
	if (left + 5 <= i)
		quicksort(num, left, i - 1);
	else
		insort(num, left, i - 1);
	if (i + 5 <= right)
		quicksort(num, i + 1, right);
	else
		insort(num, i + 1, right);
}

int main()
{
	int num[10005], i = 1;
	int j = 1, k = 0;
	while (scanf("%d", &num[i])==1)
	{
		getchar();
		i++;
	}

	if (i > 6)
		quicksort(num, 1, i - 1);
	else
		insort(num, 1, i - 1);

	printf("After Sorting:\n");
	while (j < i)
	{
		printf("%d ", num[j++]);
	}
	printf("\n");
	printf("Median3 Value:\n");
	if (b > 0)
	{
		while (k < b)
		{
			printf("%d ", a[k++]);
		}
	}
	else
		printf("none");
	printf("\n");
	return 0;
}