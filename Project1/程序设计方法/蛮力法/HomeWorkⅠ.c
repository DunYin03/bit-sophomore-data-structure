#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


long long change(long long a, long long b, long long c, long long d)
{
	long long count = 0;
	long long a1 = a * c * c * d;
	for (long long i = 1; b * i < c * d; i++)
	{
		if ((i * a * c) % (d * c - i * b) == 0)
		{
				count++;	
		}
	}
	return count;
}

int main()
{
	long long a, b, c, d, t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
		printf("%lld\n", change(a, b, c, d));
	}
	return 0;
}
