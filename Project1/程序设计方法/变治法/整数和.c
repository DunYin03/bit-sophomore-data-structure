#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int a[1000000];


void qsort(int a[], int start, int end)    //start��end����ָ�±�
{
	int i, j, temp;
	int tmp;

	i = start;
	j = end;
	tmp = a[start];   //����Ϊ�м�ֽ��ߣ���߱���С���ұ߱�����,ͨ����һ��Ԫ���ǻ�׼��

	if (i > j)  //����±�i�����±�j��������������
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
	int n, x;
	scanf("%d%d", &n, &x);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	qsort(a, 0, n - 1);
	int* p, * q;
	p = &a[0];
	q = &a[n - 1];
	while (p < q)
	{
		if (*p + *q == x)
			break;
		if (*p + *q < x)
			p++;
		else
			q--;
	}
	if (p < q)
		printf("true\n");
	else
		printf("false\n");


	return 0;
}