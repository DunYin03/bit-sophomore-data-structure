#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int a[1000000], b[1000000];

void swap(int *i, int *j)
{
	int temp = *i;
	*i = *j;
	*j = temp;
}


int quickSort(int *arr, int l, int r,int k ) //三路快速排序 
{
	if (l == r)
		return arr[l];
	int v = arr[l];
	int lt = l;
	int gt = r+1;
	int i = l+1;
	while (i < gt)
	{
		if (arr[i] < v )						//第i个整数比首个整数小，交换左边界+1与第i个数，i++ 
		{
			swap(&arr[i], &arr[lt+1]);
			lt++;
			i++;
		}

		else if (arr[i] > v)						// 第i个整数比首个整数大，交换右边界-1与第i个数
		{
			swap(&arr[i], &arr[gt-1]);
			gt--;
		}
		else									// 第i个整数与首个整数相等，则归入相等集合，当前指针右移 
		{
			i++;
		}
	}
	//一轮排序完成后，左边界左边全小于首个整数， 右边界右侧全部大于 

	swap(&arr[l], &arr[lt]);					//交换首数字与左边界最右侧数字， 
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