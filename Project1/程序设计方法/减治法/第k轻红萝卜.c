#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int a[1000000], b[1000000];

void swap(int *i, int *j)
{
	int temp = *i;
	*i = *j;
	*j = temp;
}


int quickSort(int *arr, int l, int r,int k ) //��·�������� 
{
	if (l == r)
		return arr[l];
	int v = arr[l];
	int lt = l;
	int gt = r+1;
	int i = l+1;
	while (i < gt)
	{
		if (arr[i] < v )						//��i���������׸�����С��������߽�+1���i������i++ 
		{
			swap(&arr[i], &arr[lt+1]);
			lt++;
			i++;
		}

		else if (arr[i] > v)						// ��i���������׸������󣬽����ұ߽�-1���i����
		{
			swap(&arr[i], &arr[gt-1]);
			gt--;
		}
		else									// ��i���������׸�������ȣ��������ȼ��ϣ���ǰָ������ 
		{
			i++;
		}
	}
	//һ��������ɺ���߽����ȫС���׸������� �ұ߽��Ҳ�ȫ������ 

	swap(&arr[l], &arr[lt]);					//��������������߽����Ҳ����֣� 
	if (lt - l >= k)
		return quickSort(arr, l, lt - 1, k);
	else if (gt - l < k)
		return quickSort(arr, gt, r, k - (gt - l));
	else
		return arr[lt];
}

void search(int a[], int l, int r, int k)
{
	for (int i = l; i <= r; i++)
	{
		b[i - l] = a[i];
	}
	int len = r - l;
	printf("%d\n", quickSort(b, 0, len, k));
}


int main()
{
	int n, t, x, k, l, r;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	scanf("%d", &t);
	while (t-- > 0)
	{
		int p;
		scanf("%d", &p);
		if (p == 1)
		{
			scanf("%d%d", &k,&x);
			a[k] = x;
		}
		else
		{
			scanf("%d%d%d", &l, &r, &k);
			search(a, l, r, k);
		}
	}
}