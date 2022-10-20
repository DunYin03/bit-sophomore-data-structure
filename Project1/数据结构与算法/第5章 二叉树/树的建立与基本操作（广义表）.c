#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	char c, s[100];
	int num = 0, level[100], degree[100] = { 0 }, p[100] = { 0 };
	int depth = -1, i, j, max = 0;
	while (1)
	{
		c = getchar();
		if (c == '\n')
			break;
		switch (c)
		{
		case '(':
			depth++;
			break;
		case ')':
			depth--;
			break;
		case ',':
			break;
		default:
			num++;
			s[num] = c;
			level[num] = depth;
			break;
		}
	}

	for (int i = 1; i <= num; i++)
	{
		for (int j = 0; j < level[i]; j++)
			printf("    ");
		printf("%c\n", s[i]);
	}

	for (int i = 1; i <= num; i++)
	{
		for (int j = i + 1; j <= num; j++)
		{
			if (level[j] == level[i])
				break;
			if (level[j] == level[i] + 1)
				degree[i]++;
		}
	}
	for (int i = 1; i <= num; i++)
	{
		if (degree[i] > max)
			max = degree[i];
	}
	for (int i = 1; i <= num; i++)
		p[degree[i]]++;
	printf("Degree of tree: %d\n", max);
	for (int i = 0; i <= max; i++)
	{
		printf("Number of nodes of degree %d: %d\n", i, p[i]);
	}
	return 0;
}