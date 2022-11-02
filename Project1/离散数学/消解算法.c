#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
int s[600][40] = { 0 };
int sum0 = -1, sum1 = -1, sum2 = 0;

void store(char* str)
{
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			s[sum2][str[i] - 'a'] = 1;
		}
		else if (str[i] == '&')
		{
			sum2++;
		}
		else if (str[i] == '!')
		{
			s[sum2][str[++i] - 'a'] = 2;
		}
	}
}

int same(int a[], int b[])
{
	for (int i = 0; i < 26; i++)
	{
		if (a[i] != b[i])
			return 0;
	}
	return 1;
}

int check(int c[])
{
	for (int i = 0; i <= sum2; i++)
	{
		if (same(s[i], c))
			return 0;
	}
	return 1;
}

int res(int* a, int* b)
{
	int single = 0;
	int couple = 0;
	for (int i = 0; i < 26; i++)
	{
		if (!a[i] && !b[i])
			continue;
		else if ((a[i] == 1 && b[i] == 2) || (a[i] == 2 && b[i] == 1))
		{
			couple++;
		}
		else
		{
			single++;
		}
	}

	if (couple != 1)
		return 1;
	if (!single)
		return 0;

	int c[30];
	for (int i = 0; i < 26; i++)
	{
		if ((!a[i] && !b[i]) || (a[i] + b[i] == 3))
			c[i] = 0;
		else if (a[i] == 1 || b[i] == 1)
			c[i] = 1;
		else
			c[i] = 2;
	}

	if (check(c))
	{
		sum2++;
		for (int i = 0; i < 26; i++)
		{
			s[sum2][i] = c[i];
		}
	}

	return 1;
}

int main()
{
	char str[100];
	scanf("%s", str);
	store(str);
	do
	{
		sum0 = sum1;
		sum1 = sum2;
		for (int i = 0; i <= sum0; i++)
		{
			for (int j = sum0 + 1; j <= sum1; j++)
			{
				if (!res(s[i], s[j]))
				{
					printf("NO\n");
					return 0;
				}
			}
		}
		for (int i = sum0 + 1; i <= sum1; i++)//
		{
			for (int j = i + 1; j <= sum1; j++)
			{
				if (!res(s[i], s[j]))
				{
					printf("NO\n");
					return 0;
				}
			}
		}
	} while (sum2 > sum1);
	printf("YES\n");
	return 0;
}