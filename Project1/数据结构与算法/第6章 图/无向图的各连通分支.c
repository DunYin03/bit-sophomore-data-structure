#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int record[100] = { 0 };
typedef struct
{
	int id;
	int num;
	int link[100];
}node;

int cmp(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}

node dot[100];

void bfs(int pt)
{
	int flag = 1;
	int num = 0;
	qsort(dot[pt].link, dot[pt].num, sizeof(int), cmp);
	for (int i = 0; i < dot[pt].num; i++)
	{
		if (dot[dot[pt].link[i]].id == 0)
		{
			flag = 0;
			printf("-%d", dot[pt].link[i]);
			dot[dot[pt].link[i]].id = 1;
			record[num] = dot[pt].link[i];
			num++;
		}
	}
	if (flag)
		return;
	for (int i = 0; i < num; i++)
	{
		bfs(record[i]);
	}
	return;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		dot[i].id = 0;
		dot[i].num = 0;
	}

	int f, t;
	while (1)
	{
		scanf("%d", &f);
		if (f == -1)
			break;
		scanf("%d", &t);
		dot[f].link[dot[f].num] = t;
		dot[f].num++;
		dot[t].link[dot[t].num] = f;
		dot[t].num++;
	}

	for (int i = 0; i < n; i++)
	{
		if (dot[i].id == 0)
		{
			printf("%d", i);
			dot[i].id = 1;
			bfs(i);
			printf("\n");
		}
	}
	return 0;
}