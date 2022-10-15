#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(struct node)
typedef struct node
{
	long long number;
	long long width;
	long long height;
	struct node* pre;
	struct node* next;
}Hole,*hole;

long long ans[114514];

int main()
{
	hole left, right, prehole, cur, deep;
	long long n;
	long long a, b;
	left = (hole)malloc(LEN);
	left->width = 0;
	left->height = 114514;
	left->pre = left->next = NULL;
	prehole = left;
	deep = left;
	scanf("%lld", &n);
	
	for (long long i = 0; i < n; i++)
	{
		scanf("%lld %lld", &a, &b);
		cur = (hole)malloc(LEN);
		cur->width = a;
		cur->height = b;
		cur->pre = prehole;
		cur->next = NULL;
		cur->number = i;
		prehole->next = cur;
		prehole = cur;
		
		if (deep->height > b)
			deep = cur;
	}

	right = (hole)malloc(LEN);
	right->width = 0;
	right->height = 114514;
	right->pre = cur;
	cur->next = right;
	right->next = NULL;

	long long time = 0;
	while (deep->pre->height != deep->next->height)
	{
		ans[deep->number] = time + deep->width;
		if (deep->pre->height > deep->next->height)
		{
			time += (deep->next->height - deep->height) * deep->width;
			deep->next->width += deep->width;
			deep->pre->next = deep->next;
			deep->next->pre = deep->pre;
			deep = deep->next;
		}
		else
		{
			time += (deep->pre->height - deep->height) * deep->width;
			deep->pre->width += deep->width;
			deep->pre->next = deep->next;
			deep->next->pre = deep->pre;
			deep = deep->pre;
		}

		if (deep->height < deep->pre->height && deep->height < deep->next->height)
		{
			continue;
		}
		else if (deep->pre->height > deep->next->height)
		{
			while (deep->height > deep->next->height)
			{
				deep = deep->next;
			}
		}
		else
		{
			while (deep->height > deep->pre->height)
			{
				deep = deep->pre;
			}
		}
	}
	ans[deep->number] = time + deep->width;

	for (long long i = 0; i < n; i++)
	{
		printf("%lld\n", ans[i]);
	}


	return 0;
}