#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	char data;
	struct Node *left, * right;
}Node,*node;

node root = NULL;

int height(node p)
{
	if (p == NULL)
		return 0;
	else
	{
		if (height(p->right) > height(p->left))
			return height(p->right) + 1;
		else
			return height(p->left) + 1;
	}
}

node LL(node p)
{
	node q = p->left;
	p->left = q->right;
	q->right = p;
	return q;
}

node RR(node p)
{
	node q = p->right;
	p->right = q->left;
	q->left = p;
	return q;
}

node LR(node p)
{
	node q = p->left;
	node r = q->right;
	q->right = r->left;
	r->left= q;
	p->left = r->right;
	r->right = p;
	return r;
}

node RL(node p)
{
	node q = p->right;
	node r = q->left;
	q->left = r->right;
	r->right = q;
	p->right = r->left;
	r->left = p;
	return r;
}

node Insert(char c, node p)
{
	if (p == NULL)
	{
		p = (node)malloc(sizeof(Node));
		p->data = c;
		p->right = p->left = NULL;
	}
	else
	{
		if (c < p->data)
		{
			p->left = Insert(c, p->left);
			if (height(p->left) - height(p->right) > 1)
			{
				if (c < p->left->data)
					p = LL(p);
				else
					p = LR(p);
			}
		}
		else
		{
			p->right = Insert(c, p->right);
			if (height(p->right) - height(p->left) > 1)
			{
				if (c < p->right->data)
					p = RL(p);
				else
					p = RR(p);
			}
		}
	}
	return p;
}

void preorder(node p)
{
	printf("%c", p->data);
	if (p->left)
		preorder(p->left);
	if (p->right)
		preorder(p->right);
}

void inorder(node p)
{
	if (p->left)
		inorder(p->left);
	printf("%c", p->data);
	if (p->right)
		inorder(p->right);
}

void postorder(node p)
{
	if (p->left)
		postorder(p->left);
	if (p->right)
		postorder(p->right);
	printf("%c", p->data);
}

void print(node p, int depth)
{
	int i;
	if (p->right)
		print(p->right, depth + 1);
	for (i = 0; i < depth; i++)
		printf("    ");
	printf("%c\n", p->data);
	if (p->left)
		print(p->left, depth + 1);
}

int main()
{
	char c;
	while (1)
	{
		c = getchar();
		if (c == '\n')
			break;
		root = Insert(c, root);
	}
	printf("Preorder: ");
	preorder(root);
	printf("\nInorder: ");
	inorder(root);
	printf("\nPostorder: ");
	postorder(root);
	printf("\nTree:\n");
	print(root, 0);
	return 0;
}
