#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>


char find(int len, int n, int k)
{
	if (n == 1)
		return 'h';
	if (n == 2 || n == 3)
		return 's';
	if (n > len && n <= len + 3 + k)
	{
		if (n == len + 1)
			return 'h';
		else
			return 's';
	}
	if (n <= len)
	{
		k--;
		len = (len - k - 3) / 2;
		return find(len, n, k);
	}
	else if (n > len + 3 + k)
	{
		n = n - len - 3 - k;
		k--;
		len = (len - k - 3) / 2;
		return find(len, n, k);
	}
}

int main()
{
	int n;
	int len = 3;
	int i = 0;
	char ans;
	scanf("%d", &n);
	while (n > len)
	{
		i++;
		len = len * 2 + 3 + i;
	}
	len = (len - i - 3) / 2;
	int k = i;
	ans = find(len, n, k);
	printf("%c\n", ans);
	printf("%d\n", i);

	return 0;
}
