#define _CRT_SECURE_NO_WARNINGS 1
#define N 1000000  
#define MaxNum 1000000000  
#include <stdio.h>


int S1[N], S2[N], S3[N];

int DiffWeight(int i, int j, int k) {
    return abs(S1[i] - S2[j]) + abs(S2[j] - S3[k]) + abs(S3[k] - S1[i]);
}

int xls_min(int i, int j, int k) {
    if (S1[i] <= S2[j]) {
        if (S1[i] <= S3[k]) {
            return 1;
        }
        return 3;
    }
    else {
        if (S2[j] <= S3[k]) {
            return 2;
        }
        return 3;
    }
}

// n -> 集合的大小  
int findMinDiffWeight(int n);

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &S1[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &S2[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &S3[i]);
    printf("%d\n", findMinDiffWeight(n));
    return 0;
}

int findMinDiffWeight(int n)
{
    int i = 0, j = 0, k = 0;
    int d = 0;
    int D = DiffWeight(i, j, k);

    while (1)
    {
        int m = xls_min(i, j, k);
        if ((i == n - 1 && m == 1) || (j == n - 1 && m == 2) || (k == n - 1 && m == 3))
            return D;
        switch (m)
        {
        case 1:
            if (i < n - 1)
                i++;
            break;
        case 2:
            if (j < n - 1)
                j++;
            break;
        case 3:
            if (k < n - 1)
                k++;
            break;
        }

        d = DiffWeight(i, j, k);
        if (d < D)
            D = d;
    }
}
