#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//有一个用例不过
typedef struct
{
	int row, col;
	int	data; 
}Trip;

int main()
{
	int row1, row2, col1, col2, n1, n2;
	Trip A[100], B[100], C[100],D[100];
	scanf("%d %d %d", &row1, &col1, &n1);
	for (int i = 0; i < n1; i++)
	{
		scanf("%d %d %d", &A[i].row, &A[i].col, &A[i].data);
	}	
	int num[1100] = { 0 };
	int cpot[1100] = { 0 };
	scanf("%d %d %d", &row2, &col2, &n2);
	for (int i = 0; i < n2; i++)
	{
		scanf("%d %d %d", &B[i].row, &B[i].col, &B[i].data);
		num[B[i].col - 1]++;
	}
	cpot[0] = 1;
	for (int i = 1; i < col2; i++)
	{
		cpot[i] = num[i - 1] + cpot[i - 1];
	}
	for (int i = 0; i < n2; i++)
	{
		int k;
		k = cpot[B[i].col - 1] - 1;
		cpot[B[i].col - 1]++;
		C[k].col = B[i].row;
		C[k].row = B[i].col;
		C[k].data = B[i].data;
	}
	for (int i = 0; i < 20; i++)
	{
		D[i].data = 0;
	}
	int count = 1;
	int i = 0;
	int j = 0;
	int temp1, temp2;
	for (i = 0; i < n1; i++)
	{
		for (j = 0; j < n2; j++)
		{
			if (A[i].col == C[j].col)
			{
				temp1 = i;
				temp2 = j;
				goto l;
			}
		}
	}
	l:for (i = 0; i<n1; i++)
	{
		for(j=0; j<n2; j++)
		{
			if (A[i].col == C[j].col)
			{
				/*if (C[j].row != C[temp2].row||A[i].row!=A[temp1].row)
				{
					count++;
					if(C[j].row != C[temp2].row)
						temp2 = j;
					if (A[i].row != A[temp1].row)
						temp1 = i;
				}*/
				D[count].data += A[i].data * C[j].data;	
				D[count].row = A[i].row;
				D[count++].col = C[j].row;
			}
		}
	}

	printf("%d\n%d\n%d\n", row1, col2, count-1);
	for (i = 1; i < count; i++)
	{
		printf("%d,%d,%d\n", D[i].row, D[i].col, D[i].data);
	}
	return 0;
}
//学长的AC代码
#include<stdio.h>  
#include<string.h>  
typedef struct {
    int i, j;
    int e;
}Trip;
typedef struct {
    Trip data[1000];
    int rpos[1000];
    int mu, nu, tu;
}Matrix;
int main()
{
    int i;
    int arow;
    int tp;
    int p;
    int brow;
    int t;
    int q;
    int ccol;
    int ctemp[1000];
    int num[1000];
    int col;
    Matrix A, B, Q;
    scanf("%d%d%d", &A.mu, &A.nu, &A.tu);
    for (i = 1; i <= A.tu; i++)
        scanf("%d%d%d", &A.data[i].i, &A.data[i].j, &A.data[i].e);
    scanf("%d%d%d", &B.mu, &B.nu, &B.tu);
    for (i = 1; i <= B.tu; i++)
        scanf("%d%d%d", &B.data[i].i, &B.data[i].j, &B.data[i].e);
    for (col = 1; col <= A.mu; col++)
        num[col] = 0;
    for (i = 1; i <= A.tu; i++)
        num[A.data[i].i]++;
    A.rpos[1] = 1;
    for (col = 2; col <= A.mu; col++)
        A.rpos[col] = A.rpos[col - 1] + num[col - 1];
    for (col = 1; col <= B.mu; col++)
        num[col] = 0;
    for (i = 1; i <= B.tu; i++)
        num[B.data[i].i]++;
    B.rpos[1] = 1;
    for (col = 2; col <= B.mu; col++)
        B.rpos[col] = B.rpos[col - 1] + num[col - 1];
    Q.mu = A.mu;
    Q.nu = B.nu;
    Q.tu = 0;
    if (A.tu * B.tu != 0) {
        for (arow = 1; arow <= A.mu; arow++) {
            memset(ctemp, 0, sizeof(ctemp));
            Q.rpos[arow] = Q.tu + 1;
            if (arow < A.mu)
                tp = A.rpos[arow + 1];
            else
            {
                tp = A.tu + 1;
            }
            for (p = A.rpos[arow]; p < tp; p++) {
                brow = A.data[p].j;
                if (brow < B.mu)
                    t = B.rpos[brow + 1];
                else
                {
                    t = B.tu + 1;
                }
                for (q = B.rpos[brow]; q < t; q++) {
                    ccol = B.data[q].j;
                    ctemp[ccol] += A.data[p].e * B.data[q].e;
                }
            }
            for (ccol = 1; ccol <= Q.nu; ccol++)
                if (ctemp[ccol]) {
                    Q.tu++;
                    Q.data[Q.tu].i = arow;
                    Q.data[Q.tu].j = ccol;
                    Q.data[Q.tu].e = ctemp[ccol];
                }
        }
    }
    printf("%d\n", Q.mu);
    printf("%d\n", Q.nu);
    printf("%d\n", Q.tu);
    for (i = 1; i <= Q.tu; i++)
        printf("%d,%d,%d\n", Q.data[i].i, Q.data[i].j, Q.data[i].e);
    return 0;
}