#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
long long a[401];
long long dp[401][401] = { 0 };

long long count(int, int);
int main()
{
	int n = 6;
	a[1] = 1;
	scanf("%d", &n);
	printf("%lld\n", count(n, n));
	return 0;
}\
 

long long count(int n, int m)
{
    if (dp[n][m])return dp[n][m];
    if (n == 1 || m == 1)
    {
        dp[n][m] = 1;
        return dp[n][m];
    }
    if (n < m)
    {
        dp[n][m] = count(n, n);
        return dp[n][m];
    }
    if (n == m)
    {
        dp[n][m] = count(n, n - 1) + 1;
        return dp[n][m];
    }
    if (n > m)
    {
        dp[n][m] = count(n - m, m) + count(n, m - 1);
        return dp[n][m];
    }
}
