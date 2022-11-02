#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>

int main()
{
	int a[105];
	int arr[105][105];
	int n = 0, k = 0, i = 0, j = 0;
	while (~scanf("%d", &a[n]))
		n++;
	int* p = a;
	for (i = 0; i < sqrt(n); i++)
	{
		for (j = 0; j < sqrt(n); j++)
		{
			arr[i][j] = p[j];
		}
		p += (int)sqrt(n);
	}

	for (k = 0; k < sqrt(n); k++)
	{
		for (i = 0; i < sqrt(n); i++)
		{
			for (j = 0; j < sqrt(n); j++)
			{
				arr[i][j] = arr[i][j] || (arr[i][k] && arr[k][j]);
			}
		}
	}

	for (i = 0; i < sqrt(n); i++)
	{
		for (j = 0; j < sqrt(n); j++)
		{
			if (j < (int)sqrt(n) - 1)
				printf("%d ", arr[i][j]);
			else
				printf("%d\n", arr[i][j]);
		}
	}

	return 0;
}