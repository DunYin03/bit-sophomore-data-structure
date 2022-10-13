#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
typedef struct
{
	int row, col, data;
}Trip;

int main()
{
	int row, col, n;
	int num[100] = {0};
	int cpot[100] = {0};
	scanf("%d %d %d", &row, &col, &n);
	Trip A[1010], B[1010];
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d", &A[i].col, &A[i].row, &A[i].data);
		num[A[i].row - 1]++;
	}
	printf("num:");
	for (int i = 0; i < col; i++)
		printf("%d,",num[i]);
	printf("\n");
	cpot[0] = 1;
	for (int i = 1; i < col; i++)
	{
		cpot[i] = num[i - 1] + cpot[i - 1];
	}
	printf("cpot:");
	for (int i = 0; i < col; i++)
		printf("%d,", cpot[i]);
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		int k;
		k = cpot[A[i].row - 1]-1;
		cpot[A[i].row - 1]++;
		B[k].col = A[i].row;
		B[k].row = A[i].col;
		B[k].data = A[i].data;
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d,%d,%d\n", B[i].col, B[i].row, B[i].data);
	}


	return 0;
}