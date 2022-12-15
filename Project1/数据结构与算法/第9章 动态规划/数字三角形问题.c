#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int dp[110][110];

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
			scanf("%d", &dp[i][j]);
	for (int i = n - 2; i >= 0; i--) {
		for (int j = 0; j <= i; j++) {
			dp[i][j] = mymax(dp[i][j] + dp[i + 1][j], dp[i][j] + dp[i + 1][j + 1]);
		}
	}
	printf("%d\n", dp[0][0]);
	return 0;
}
