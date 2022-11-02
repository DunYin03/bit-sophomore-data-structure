#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	unsigned long long  m, k, b;
	unsigned long long ans;
	scanf("%llu %llu", &m, &k);
	unsigned long long cnt = 0;
	b = 1;
	while (b < m)
	{
		cnt += m / b - b + 1;
		b *= 10;
	}
	cnt--;
	unsigned long long a = 1;
	b /= 10;
	if (k >= cnt + 1)
	{
		if (cnt + 1 == k)
			printf("%llu\n",m);
		else
		{
			while (cnt < k)
			{
				a *= 10;
				b *= 10;
				cnt += m * a - b;
			}
			unsigned long long kk = m * a;
			ans = kk - cnt + k - 2;
			printf("%llu\n", ans);
		}
	}
	else
	{
		printf("0\n");
	}
	return 0;
}