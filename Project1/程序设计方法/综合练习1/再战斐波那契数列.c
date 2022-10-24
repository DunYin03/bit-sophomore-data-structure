#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
typedef struct node
{
	long long m[5][5];
}Mat;

Mat a, e;
int m;

Mat mul(Mat x, Mat y)
{
	Mat c;
	memset(c.m, 0, sizeof(c.m));
	for (int i = 1; i <= 2; i++)
		for (int j = 1; j <= 2; j++)
			for (int k = 1; k <= 2; k++)
				c.m[i][j] = c.m[i][j] + x.m[i][k] * y.m[k][j] % m;
	return c;
}
 
Mat ks(Mat x, int y)
{
	Mat ans = e;
	memset(ans.m, 0, sizeof(ans.m));
	for (int i = 1; i <= 2; i++)
		ans.m[i][i] = 1;
	while (y)
	{
		if (y & 1)
			ans = mul(ans, x);
		x = mul(x, x);
		y >>= 1;
	}
	return ans;
}

int main()
{
	int i, j, ans;
	scanf("%d%d%d", &i, &j, &m);
	Mat f;
	memset(f.m, 0, sizeof(f.m));
	f.m[2][1] = i - 1 + i * (1 + sqrt(5)) / 2;
	f.m[1][1] = f.m[2][1] * 2 - i + 1;
	Mat base, res, q;
	base.m[1][1] = 1; base.m[1][2] = 1; base.m[2][1] = 1; base.m[2][2] = 0;
	if (j == 1)
		printf("%d\n", f.m[2][1]);
	else
	{
		res = ks(base, j - 2);
		q = mul(res, f);
		printf("%d\n", q.m[1][1] % m);
	}
}