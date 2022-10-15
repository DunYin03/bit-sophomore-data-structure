#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN sizeof(struct node)
typedef struct node
{
	int orderid;
	int code;
	int num;
	float price;
	char type;
	struct node* next;
}Stock,*order;

//所需的变量
order buy, sell;
order b, s;
order b1, s1;
order q, p;
order q1, p1;
int stock_code, num;
float money;
char stock_type;
int count = 1;


void fun1()
{
	b = buy; s = sell; b1 = b->next; s1 = s->next;
	scanf("%d %f %d %c", &stock_code, &money, &num, &stock_type);
	printf("orderid: %04d\n", count++);
	if ('b' == stock_type)
	{
		while (s1 != NULL)
		{
			if (money >= s1->price)
			{
				if (stock_code == s1->code)
				{
					if (num == s1->num)
					{
						printf("deal--price:%6.1f  quantity:%4d  buyorder:%04d  sellorder:%04d\n",
							(money + s1->price) / 2, num, count - 1, s1->orderid);
						num = 0;
						s->next = s1->next;
						free(s1);
						s1 = s->next;
						break;
					}
					else if (num < s1->num)
					{
						printf("deal--price:%6.1f  quantity:%4d  buyorder:%04d  sellorder:%04d\n",
							(money + s1->price) / 2, num, count - 1, s1->orderid);
						s1->num -= num;
						num = 0;
						break;
					}
					else if (num > s1->num)
					{
						printf("deal--price:%6.1f  quantity:%4d  buyorder:%04d  sellorder:%04d\n",
							(money + s1->price) / 2, s1->num, count - 1, s1->orderid);
						num -= s1->num;
						s->next = s1->next;
						free(s1);
						s1 = s->next;
						continue;
					}
				}//stack_code == s1->code
				else
				{
					s = s->next;
					s1 = s->next;
					continue;
				}
			}//money >= s1->price
			else
				break;
		}
		if (num != 0)
		{
			q = buy; p = q->next;
			while (p)
			{
				if (money > p->price)
				{
					order temp = (order)malloc(LEN);
					temp->orderid = count - 1;
					temp->price = money;
					temp->num = num;
					temp->code = stock_code;
					temp->type = stock_type;
					q->next = temp;
					temp->next = p;
					break;
				}
				else
				{
					q = q->next;
					p = q->next;
				}
			}
			if (p == NULL)
			{
				order temp = (order)malloc(LEN);
				temp->orderid = count - 1;
				temp->price = money;
				temp->num = num;
				temp->code = stock_code;
				temp->type = stock_type;
				q->next = temp;
				temp->next = NULL;
			}
		}//num!=0
	}
	if ('s' == stock_type)
	{
		while (b1 != NULL)
		{
			if (money <= b1->price)
			{
				if (stock_code == b1->code)
				{
					if (num == b1->num)
					{
						printf("deal--price:%6.1f  quantity:%4d  sellorder:%04d  buyorder:%04d\n",
							(money + b1->price) / 2, num, count - 1, b1->orderid);
						num = 0;
						b->next = b1->next;
						free(b1);
						b1 = b ->next;
						break;
					}
					else if (num < b1->num)
					{
						printf("deal--price:%6.1f  quantity:%4d  sellorder:%04d  buyorder:%04d\n",
							(money + b1->price) / 2, num, count - 1, b1->orderid);
						b1->num -= num;
						num = 0;
						break;
					}
					else if(num > b1->num)
					{
						printf("deal--price:%6.1f  quantity:%4d  sellorder:%04d  buyorder:%04d\n",
							(money + b1->price) / 2, b1->num, count - 1, b1->orderid);
						num -= b1->num;
						b->next = b1->next;
						free(b1);
						b1 = b->next;
						continue;
					}
				}//
				else
				{
					b = b->next;
					b1 = b->next;
					continue;
				}
			}//money<=b1->price
			else
				break;
		}
		if (num != 0)
		{
			q = sell; p = q->next;
			while (p)
			{
				if (money < p->price)
				{
					order temp = (order)malloc(LEN);
					temp->orderid = count - 1;
					temp->price = money;
					temp->num = num;
					temp->code = stock_code;
					temp->type = stock_type;
					q->next = temp;
					temp->next = p;
					break;
				}
				else
				{
					q = q->next;
					p = q->next;
				}
			}
			if (p == NULL)
			{
				order temp = (order)malloc(LEN);
				temp->orderid = count - 1;
				temp->price = money;
				temp->num = num;
				temp->code = stock_code;
				temp->type = stock_type;
				q->next = temp;
				temp->next = NULL;
			}
		}//num!=0
	}
}

void fun2()
{
	scanf("%d", &stock_code);
	p = buy; q = p->next;
	p1 = sell; q1 = p1->next;
	printf("buy orders:\n");
	while (q)
	{
		if (q->code == stock_code)
		{
			printf("orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: %c\n",
				q->orderid, q->code, q->price, q->num, q->type);			
		}
		p = p->next;
		q = p->next;
	}
	printf("sell orders:\n");
	while(q1)
	{
		if (q1->code == stock_code)
		{
			printf("orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: %c\n",
				q1->orderid, q1->code, q1->price, q1->num, q1->type);
		}
		p1 = p1->next;
		q1 = p1->next;
	}
}

void fun3()
{
	int id;
	int flag1 = 0;
	int flag2 = 0;
	scanf("%d", &id);
	p = buy; q = p->next;
	p1 = sell; q1 = p1->next;
	while (q && !flag1)
	{
		if (id == q->orderid)
		{
			printf("deleted order:orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: %c\n"
				, q->orderid, q->code, q->price, q->num, q->type);
			p->next = q->next;
			flag1 = 1;
			free(q);
		}
		else
		{
			p = p->next;
			q = p->next;
		}
	}
	while (q1&&!flag1&&!flag2)
	{
		if (id == q1->orderid)
		{
			printf("deleted order:orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: %c\n"
				, q1->orderid, q1->code, q1->price, q1->num, q1->type);
			p1->next = q1->next;
			free(q1);
			flag2 = 1;
		}
		else
		{
			p1 = p1->next;
			q1 = p1->next;
		}
	}
	if (!flag1 && !flag2)
		printf("not found\n");
}

int main()
{
	buy = (order)malloc(LEN); buy->next = NULL;
	sell = (order)malloc(LEN); sell->next = NULL;
	int a;
	while (scanf("%d", &a))
	{
		if (a == 0)
			break;
		switch (a)
		{
		case 1: fun1(); break;
		case 2: fun2(); break;
		case 3: fun3(); break;
		}
	}
	return 0;
}