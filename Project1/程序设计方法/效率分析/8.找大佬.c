#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int n;
int good[1000][1000];
void guessdalao(int n); 
int better(int a, int b);
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            int t;
            scanf("%d", &t);
            good[i][j] = t;
        }
    guessdalao(n);
    return 0;
}



int better(int a, int b)
{
    if (a <= 0 || a > n || b <= 0 || b > n) return -1;
    return good[a][b];
}
void guessdalao(int n)
{
    int max = 1;
    int flag = 0;
    for (int i = 2; i <= n; i ++ )
    {
        if (better(max, i) == 0)
            max = i;
    }
    for (int i = 1; i < max; i++)
    {
        if (better(max, i) == 0)
            flag++;
    }
    for (int i = max + 1; i <= n; i++)
    {
        if (better(max, i) == 0)
            flag++;
    }
    for (int i = 1; i < max; i++)
    {
        if (better(i, max) == 1)
            flag++;
    }
    for (int i = max + 1; i <= n; i++)
    {
        if (better(i, max) == 1)
            flag++;
    }
    if (flag == 0)
        printf("%d\n", max);
    else
        printf("-1\n");
    
}
