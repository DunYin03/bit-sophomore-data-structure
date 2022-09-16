#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int a1, a2, temp, k;
	scanf("%d %d %d", &a1, &a2, &k);

	a1 %= 10;
	a2 %= 10;
	for (int i = 0; i < k; i++)
	{
		temp = a1 * a2 % 10;
		a1 = a2;
		a2 = temp;
	}
	printf("%d\n", a2);
}