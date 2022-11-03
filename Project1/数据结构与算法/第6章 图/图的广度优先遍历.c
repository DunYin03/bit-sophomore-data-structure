#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct
{
	char name;
	int sonlist[100];
	int sonnum;
	int vir;
}Node[100];

void bfs(int find)
{
	int after[100], afnum = 0, i, get;
	if (Node[find].vir == 0)
	{
		printf("%c", Node[find].name);
		Node[find].vir = 1;
	}
	for (i = Node[find].sonnum - 1; i >= 0; --i)
	{
		get = Node[find].sonlist[i];
		if (Node[get].vir == 0)
		{
			after[afnum] = get;
			afnum++;
			printf("%c", Node[get].name);
			Node[get].vir = 1;
		}
	}
	for (i = 0; i < afnum; ++i)
	{
		bfs(after[i]);
	}

	
}

int main()
{
	char c;
	int n = 0, a, b;
	while(1)
	{
		c = getchar();
		getchar();
		if (c == '*')
			break;
		else
		{
			Node[n].name = c;
			Node[n].vir = 0;
			Node[n].sonnum = 0;
			n++;
		}
	}

	while (1)
	{
		scanf("%d,%d", &a, &b);
		if (a == -1 && b == -1)
			break;
		else
		{
			Node[a].sonlist[Node[a].sonnum] = b;
			Node[a].sonnum++;
			Node[b].sonlist[Node[b].sonnum] = a;
			Node[b].sonnum++;
		}
	}

	printf("the ALGraph is\n");
	for (int i = 0; i < n; i++)
	{
		printf("%c", Node[i].name);
		for (int j = Node[i].sonnum - 1; j >= 0; --j)
		{
			printf(" %d", Node[i].sonlist[j]);
		}
		printf("\n");
	}

	printf("the Breadth-First-Seacrh list:");
	for (int i = 0; i < n; i++)
	{
		if (Node[i].vir == 0)
			bfs(i);
	}
	printf("\n");
	return 0;
}