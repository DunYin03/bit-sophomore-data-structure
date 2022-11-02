#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
unsigned long long ans;
unsigned long long num[1000005], cost[1000005];
unsigned long long move[1000005];
unsigned long long stock[1000005];
unsigned long long s[1000005];
int key = 1;
int k = 1;


void merge(unsigned long long arr[], int start, int mid, int end) {
	unsigned long long result[1000005];
	int k = 0;
	int i = start;
	int j = mid + 1;
	while (i <= mid && j <= end) {
		if (arr[i] < arr[j]) {
			result[k++] = arr[i++];
		}
		else {
			result[k++] = arr[j++];
		}
	}
	if (i == mid + 1) {
		while (j <= end)
			result[k++] = arr[j++];
	}
	if (j == end + 1) {
		while (i <= mid)
			result[k++] = arr[i++];
	}
	for (j = 0, i = start; j < k; i++, j++) {
		arr[i] = result[j];
	}
}

void mergeSort(unsigned long long arr[], int start, int end) {
	if (start >= end)
		return;
	int mid = (start + end) / 2;
	mergeSort(arr, start, mid);
	mergeSort(arr, mid + 1, end);
	merge(arr, start, mid, end);
}


int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%llu", &num[i]);
	for (int i = 1; i <= n; i++)
		scanf("%llu", &cost[i]);
	mergeSort(num, 1, n);
	mergeSort(cost, 1, n);
	for (int i = 1; i < n; i++)
	{
		if (num[i] == num[i + 1])
		{
			stock[key++] = num[i];
		}
		else if (num[i] == num[i + 1] - 1)
		{
			continue;
		}
		else
		{
			if (key == 1)
				continue;
			int temp = 1;
			while (key > 1)
			{
				int top = stock[--key];
				move[k++] = num[i] + temp - top;
				temp++;
				if (num[i] + temp == num[i + 1])
					break;
			}
		}
	}
	int temp = 1;
	while (key > 1)
	{
		int top = stock[--key];
		move[k++] = num[n] + temp - top;
		temp++;
	}
	k--;
	mergeSort(move, 1, k);
	for (int i = 1; i <= k; i++)
		ans += cost[i] * move[k - i + 1];
	if (n == 1)
		ans = 0;
	printf("%llu\n", ans);
	return 0;
}