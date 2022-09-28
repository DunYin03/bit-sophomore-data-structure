#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int n;
long long a[100000] = {0};

void swap(int i, int j)
{
	long long temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void qsort(long long a[], int start, int end)    //start��end����ָ�±�
{
	int i, j;
	long long tmp,temp;

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
	long long sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &a[i]);
	}
	qsort(a, 0, n - 1);
	if (n == 0)
		printf("%lld\n", a[0]);
	else
	{
		for (int i = 0; i < n - 1; i++)
		{
			a[i + 1] += a[i];
			sum += a[i + 1];
			for (int k = i + 1; k < n; k++)
				if (a[k] > a[k + 1])
					swap(k, k + 1);
				else
					break;
		}
		printf("%lld\n", sum);
	}

}