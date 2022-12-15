#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
int a[2010], m[2010][2010], s[2010][2010];
const int inf = 2147483647;
void traceback(int i, int j) 
{
    if (i == j) 
    {
        printf("A%d", i);
        return;
    }
    printf("(");
    traceback(i, s[i][j]);
    traceback(s[i][j] + 1, j);
    printf(")");
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int r = 2; r <= n; r++)
    {
        for (int i = 1; i <= n - r + 1; i++) 
        {
            int j = i + r - 1;
            m[i][j] = inf;
            for (int k = i; k < j; k++)
            {
                int t = m[i][k] + m[k + 1][j] + a[i - 1] * a[k] * a[j];
                if (t < m[i][j])
                {
                    m[i][j] = t;
                    s[i][j] = k; 
                }
            }
        }
    }
    printf("%d\n", m[1][n]); 
    if (n == 1) printf("(A1)");
    else traceback(1, n); 
    printf("\n");
    return 0;
}
