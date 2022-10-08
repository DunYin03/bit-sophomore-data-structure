#define _CRT_SECURE_NO_WARNINGS 1
#include <string.h>
#include <stdio.h>

int a[500000];
int tmp[500000];
long long ans;

void Merge(int l, int m, int r)
{
    int i = l;
    int j = m + 1;
    int k = l;
    while (i <= m && j <= r)
    {
        if (a[i] > a[j])
        {
            tmp[k++] = a[j++];
            ans += m - i + 1;
        }
        else
        {
            tmp[k++] = a[i++];
        }
    }
    while (i <= m) tmp[k++] = a[i++];
    while (j <= r) tmp[k++] = a[j++];
    for (int i = l; i <= r; i++)
        a[i] = tmp[i];
}

void Merge_sort(int l, int r)
{
    if (l != r)
    {
        int m = (l + r) / 2;
        Merge_sort(l, m);
        Merge_sort(m + 1, r);
        Merge(l, m, r);
    }
}

int main()
{
    int n;
    while ((scanf("%d", &n))!=EOF)
    {   
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        ans = 0;
        Merge_sort(0, n - 1);
        printf("%lld\n", ans);
    }
    return 0;
}