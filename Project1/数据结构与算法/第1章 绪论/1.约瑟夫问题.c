#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main() 
{
	int n, k, m;
	int a[10000] = { 0 };

	scanf("%d,%d,%d", &n, &k, &m);
	if (n < 1 || k < 1 || m < 1)
		printf("n,m,k must bigger than 0.\n");
	else if (k > n)
		printf("k should not bigger than n.\n");
	else
	{
		for (int i = 1; i <= n; i++)
			a[i] = 1;
		int sum = n - 1;
		int temp;
		int i = k;
		int count = 0;
		while (sum-- >= 0)
		{
			temp = m;
			while (temp > 0)
			{
				if (a[i] == 1)
					temp--;
				i++;
				if (i > n)
					i = 1;
			}
			i--;
			if (i < 1)
				i = n;
			a[i] = 0;
			count++;
			if(count !=10)
			printf("%d ", i);
			if (count == 10)
			{
				printf("%d\n",i);
				count = 0;
			}
			while (a[i] == 0)
			{
				i++;
				if (i > n)
					i = 1;
			}
			if (sum == 0)
				break;
		}
		for (int i = 1; i < n; i++)
		{
			if (a[i] == 1)
				printf("%d", i);
		}
		printf("\n");
	}
	return 0;
}
