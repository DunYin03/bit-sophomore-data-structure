#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
int ans;
void deal(int n, int m)
{
	if (n<m+1)
	{
		ans += 0;
		return;
	}
	else if (n == m + 1)
	{
		ans += 1;
		return;
	}
	else
	{
		n = n - m - 1;
		ans += 1;
		int layer = 1;

		if (n == 0 || layer > m)
		{
			return;
		}
		int temp;
		temp = (int)pow(2.0, layer * 1.0) - 1;
		while (n - temp > 0)
		{
			ans += (int)pow(2.0, layer - 1.0);
			layer++;
			n -= temp;
			temp = (int)pow(2.0, layer * 1.0) - 1;
			if (layer > m)
				return;
		}
		if (n - temp == 0)
		{
			ans += (int)pow(2.0, layer - 1.0);
			return;
		}
		else
		{
			deal(n, layer - 1); 
		}
	}
}
int main()
{
	int T, n, m;
	scanf("%d", &T);
	while (T-- > 0)
	{
		scanf("%d%d", &n, &m);
		ans = 0;
		deal(n, m);
		printf("%d\n", ans);
	}
}