#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int x,n;
int guess(int y)
{
    if (y < 1 || y > n) return -1;
    if (x >= y) return 1;
    if (x < y) return 0;
}

void guessnumber(int n)
{
    int left = 1;
    int right = n;
    int mid = (left + right) / 2;
    while (left != right)
    {
        if (guess(mid))
        {
            printf("%d\n", mid);
            left = mid;
            mid = (left + right) / 2;
        }
        else
        {
            printf("%d\n", mid);
            right = mid;
            mid = (left + right) / 2;
        }
        if (mid == left)
        {
                break;
        }
    }
    printf("%d\n", mid);
}

int main()
{
    scanf("%d%d", &x, &n);
    guessnumber(n);
    return 0;
}