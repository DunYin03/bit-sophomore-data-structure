#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>


int main()
{
	long long n;
	scanf("%lld", &n);
	long long temp;
	long long sum = 0;
	long long sqsum = 0;//Æ½·½ºÍ
	for (long long i = 1; i <= n - 2; i++)
	{
		scanf("%lld", &temp);
		sum -= temp;
		sum += i;
		sqsum -= temp * temp;
		sqsum += i * i;
	}
	sum += 2 * n - 1;
	sqsum += (n - 1) * (n - 1) + n * n;

	long long aPlusb = sum;
	long long asqPlusbsq = sqsum;
	long long aMulb = (aPlusb * aPlusb - asqPlusbsq) / 2;

	
	long long a, b;
	a = 1;
	for (long long i = 1; i < n; i++)
	{
		b = aPlusb - a;
		if (a * b == aMulb)
			break;
		a++;
	}
		printf("%lld %lld\n", a, b);

	return 0;
}