#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int n, m;
int col[20], row[20];
int sls[50], resls[50];
int ans = 0;

int judge()
{
	int i, j;
	for (i = 1; i <= n; i++)
	{
		if (row[i] == 0)
		{
			for (j = 1; j <= n; j++)
			{
				if (col[j] == 0)
				{
					if (resls[i + j] == 0 && sls[n + i - j + 1] == 0)
						return 0;
				}
			}
		}
	}
	return 1;
}

void trackback(int flag, int level, int num)
{
	if (level > n)
	{
		if (num != m)
			return;
		if (judge())
			ans++;
		return;
	}

	if (n - level + num < m)
		return;
	if (!flag)
	{
		trackback(0, level + 1, num);
		trackback(1, level + 1, num + 1);
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (col[i] == 0 && resls[i + level] == 0 && sls[n + level - i + 1] == 0)
			{
				row[level] = level;
				col[i] = i;
				resls[level + i] = 1;
				sls[n + level - i + 1] = 1;
				trackback(0, level + 1, num);
				trackback(1, level + 1, num + 1);
				row[level] = 0;
				col[i] = 0;
				resls[level + i] = 0;
				sls[n + level - i + 1] = 0;
			}
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		col[i] = 0;
		row[i] = 0;
	}
	for (int i = 1; i < 2 * n + 1; i++)
	{
		sls[i] = 0;
		sls[i] = 0;
	}

	trackback(0, 1, 0);
	trackback(1, 1, 1);
	
	printf("%d\n", ans);
	return 0;
}