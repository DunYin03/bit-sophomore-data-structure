#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int n;
long long a[100000];

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

int main()
{
    long long sum = 0;
    long long temp = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
    }
    for(int i = n/2;i>=1;i--)
        find(i, n);
    if (n == 0)
        printf("%lld\n", a[0]);
    else
    {
        for (int i = 1; i < n; i++)
        {
            temp = a[1];
            a[1] = a[n - i + 1];
            find(1, n - i);
            sum += a[1] + temp;
            a[1] += temp;
            find(1, n - i);
        }
        printf("%lld\n", sum);
    }

}