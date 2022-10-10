#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int search(int n,int m)
{
	if (2 == n)
	{
		if (1 == m)
		{
			return 3;
		}
		else
		{
			return 4;
		}
	}
	else if (3 <= n)
	{
		if (1 == m)
		{
			return 4;
		}
		else if (2 == m)
		{
			return 7;
		}
		else
		{
			return 8;
		}
	}
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	if (0 == m)
		printf("1\n");
	else if (1 == n)
		printf("2\n");
	else
	{
		printf("%d\n", search(n, m));
	}
	return 0;
}
