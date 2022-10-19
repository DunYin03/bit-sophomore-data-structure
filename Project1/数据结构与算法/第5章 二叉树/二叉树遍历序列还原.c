#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
typedef struct Bitree
{
	char d;
	struct Bitree* r;
	struct Bitree* l;
}BT,*bt;

bt creattree(char post[], char in[], int i, int j, int k, int m)
{
	bt T;
	T = (bt)malloc(sizeof(BT));
	T->d = post[j];
	int n = k;
	while (in[n] != post[j])
		n++;
	if (in[k] == post[j])
		T->l = NULL;
	else
	{
		T->l = creattree(post, in, i, i + n - k - 1, k, n - 1);
	}
	if (in[m] == post[j])
		T->r = NULL;
	else
	{
		T->r = creattree(post, in, i + n - k, j - 1, n + 1, m);
	}
	return T;
}

int levelorder(bt T, int level)
{
	if (!T || level < 0)
		return 0;
	if (level == 0)
	{
		printf("%c", T->d);
		return 1;
	}
	return levelorder(T->l, level - 1) + levelorder(T->r, level - 1);
}
int main()
{
	char in[200], post[200];
	scanf("%s", &in);
	scanf("%s", &post);
	int len = strlen(in);
	bt T;
	T = creattree(post, in, 0, len - 1, 0, len - 1);
	for (int i = 0;; i++)
	{
		if (!levelorder(T, i))
			break;
	}
	printf("\n");

	return 0;
}
	