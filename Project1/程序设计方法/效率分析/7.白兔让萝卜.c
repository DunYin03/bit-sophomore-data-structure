#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int n;
int a[200005];
void findminandmax(int n); 
int cmp(int i, int j)
{
    if (i <= 0 || i > 2 * n || j <= 0 || j > 2 * n) return -2;
    if (a[i] > a[j]) return 1;
    if (a[i] == a[j]) return 0;
    if (a[i] < a[j]) return -1;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= 2 * n; i++)
        scanf("%d", &a[i]);
    findminandmax(n);
    return 0;
}

void findminandmax(int n)
{
    int max = 1;
    int min = 1;

    for (int i = 1; i <= n * 2; i = i + 2)
    {
        if (cmp(i, i + 1) == 1)
        {
            if (cmp(min, i + 1) == 1)
                min = i + 1;
            if (cmp(max, i) == -1)
                max = i;
        }
        else
        {
            if (cmp(min, i) == 1)
                min = i;
            if (cmp(max, i + 1) == -1)
                max = i + 1;
        }
    }

    printf("%d %d\n", min, max);
}