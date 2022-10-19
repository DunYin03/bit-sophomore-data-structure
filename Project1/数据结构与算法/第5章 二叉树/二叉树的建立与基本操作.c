#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Bitree
{
	char d;
	struct Bitree* r;
	struct Bitree* l;
}BT;

int leafnum = 0;

BT* creatBitree(BT* root)
{
	char ch;
	ch = getchar();
	if (ch == '\0')
		;
	if (ch == '#')
		root = NULL;
	else
	{
		root = (BT*)malloc(sizeof(BT));
		root->d = ch;
		root->r = NULL;
		root->l = NULL;
		root->l = creatBitree(root->l);
		root->r = creatBitree(root->r);
		if (root->r == NULL && root->l == NULL)
			leafnum++;
	}
	return root;
}

void printtree(BT* root,int rank)
{
	if (root == NULL)
		return;
	for (int i = 0; i < rank; i++)
		printf("    ");
	printf("%c\n", root->d);
	printtree(root->l, rank + 1); 
	printtree(root->r, rank + 1);
}

void printpreorder(BT* head)
{
	if (head == NULL)
		return;
	printf("%c", head->d);
	printpreorder(head->l);
	printpreorder(head->r);
}

void printinorder(BT* head)
{
	if (head == NULL)
		return;
	printinorder(head->l);
	printf("%c", head->d);	
	printinorder(head->r);
}

void printpostorder(BT* head)
{
	if (head == NULL)
		return;
	printpostorder(head->l);
	printpostorder(head->r);
	printf("%c", head->d);
}

void swap(BT* head)
{
	BT* p = NULL;
	if (head == NULL)
		return;
	p = head->l;
	head->l = head->r;
	head->r = p;
	swap(head->l);
	swap(head->r);
}

int main()
{

	BT* head = NULL;

	head = creatBitree(head);

	printf("BiTree\n");
	printtree(head, 0);

	printf("pre_sequence  : ");
	printpreorder(head);
	printf("\n");

	printf("in_sequence   : ");
	printinorder(head);
	printf("\n");
	
	printf("post_sequence : ");
	printpostorder(head);
	printf("\n");


	printf("Number of leaf: %d\n", leafnum);

	swap(head);
	printf("BiTree swapped\n");
	printtree(head, 0);

	printf("pre_sequence  : ");
	printpreorder(head);
	printf("\n");

	printf("in_sequence   : ");
	printinorder(head);
	printf("\n");

	printf("post_sequence : ");
	printpostorder(head);
	printf("\n");

	return 0;
}