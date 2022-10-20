#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Bitree
{
	int data;
	struct Bitree* left;
	struct Bitree* right;
}BT, * bt;

int main()
{
	bt T = NULL;
	T = (bt)malloc(sizeof(BT));
	T->data = 0;
	T->left = NULL;
	T->right = NULL;
	int flag = 0;
	char s[100000];
	int n;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%s", &s);
		int len = strlen(s);
		bt p = T;
		for (int i = 0; i < len; i++)
		{
			if (s[i] == '0')
			{
				if (p->left == NULL)
				{
					p->left = (bt)malloc(sizeof(BT));
					p = p->left;
					p->left = NULL;
					p->right = NULL;
					if (i == len - 1)
						p->data = 1;
					else
						p->data = 0;
				}
				else
				{
					if (i == len - 1 || p->left->data == 1)
					{
						flag = 1;
						break;
					}
					else
					{
						p = p->left;
					}
				}
			}//s[i]=='0'
			else
			{
				if (p->right == NULL)
				{
					p->right = (bt)malloc(sizeof(BT));
					p = p->right;
					p->left = NULL;
					p->right = NULL;
					if (i == len - 1)
						p->data = 1;
					else
						p->data = 0;
				}
				else
				{
					if (i == len - 1 || p->right->data == 1)
					{
						flag = 1;
						break;
					}
					else
					{
						p = p->right;
					}
				}
			}
		}//for
		if (flag == 1)
			break;
	}
	if (flag == 0)
		printf("YES\n");
	else
		printf("%s\n", s);
	return 0;
}

