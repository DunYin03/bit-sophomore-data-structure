#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


int change(int a, int b, int c, int d)
{
	int count = 0;
	int long a1 = a * c * c * d;
	for (int i = 1; i < d * c / b; i++)
	{
		int a2 = c * d - b * i;
		if (a1 % a2 == 0)
		{
			int a3 = a1 / a2;
			if ((a3 - a * c) % b == 0)
				count++;
		}
	}
	return count;
}

int main()
{
	int a, b, c, d, t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%d %d %d %d", &a, &b, &c, &d);
		printf("%d\n", change(a, b, c, d));
	}
	return 0;
}
