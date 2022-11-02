#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
double ans = 0;
void st(int a[], int start, int end)    //start��end����ָ�±�
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

	st(a, start, i - 1);
	st(a, i + 1, end);
}

void change(int a[], int left, int right)
{
	while(left<right)
	{
		a[0] = a[left];
		a[left] = a[right];
		a[right] = a[0];
		left++;
		right--;
	}
}

int main()
{
	int m, n;
	int a[100005];
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
	}
	st(a, 1, n);
	for (int i = 1; i <= n; ++i)
	{
		if (ans <= a[i])
		{
			ans = (ans * (i - 1) + m) / i;
		}
		else
		{
			ans = ans * (i - 1) / i;
		}
	}
	printf("%.2lf ", ans);
	ans = 0;
	change(a, 1, n);
	for (int i = 1; i <= n; ++i)
	{
		if (ans <= a[i])
		{
			ans = (ans * (i - 1) + m) / i;
		}
		else
		{
			ans = ans * (i - 1) / i;
		}
	}
	printf("%.2lf\n", ans);
}