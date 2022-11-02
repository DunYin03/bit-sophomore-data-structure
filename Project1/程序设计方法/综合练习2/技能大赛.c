#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int ans[105][105];

typedef struct node
{
	int game1;
	int game2;
	int gnum;
	struct node* equl;
	struct node* next;
}G;

int main()
{
	int n;
	int flag;
	G s[105];
	for (int i = 1; i <= 100; i++)
	{
		s[i].game1 = s[i].game2 = s[i].gnum = 0;
		s[i].equl = NULL;
		s[i].next = NULL;
	}
	int level = 1, order = 1;
	scanf("%d", &n);
	char ch;
	int temp;
	getchar();
	for (int i = 1; i <= n; i++)
	{
		order = level;
		scanf("%d", &temp);
		ch = getchar();
		s[temp].game1 = order;
		s[temp].gnum++;
		level++;
		while (ch == ' ')
		{
			scanf("%d", &temp);
			ch = getchar();
			s[temp].game1 = order;
			s[temp].gnum++;
			level++;
		}
	}
	scanf("%d", &n);
	getchar();
	level = 1, order = 1;
	for (int i = 1; i <= n; i++)
	{
		order = level;
		scanf("%d", &temp);
		ch = getchar();
		s[temp].game2 = order;
		s[temp].gnum++;
		level++;
		while (ch == ' ')
		{
			scanf("%d", &temp);
			ch = getchar();
			s[temp].game2 = order;
			s[temp].gnum++;
			level++;
		}
	}
	G* p = NULL;//指向低排名
	G* q=NULL;
	G* m=NULL;
	int i;
	for (i = 1; i <= 100; i++)
	{
		if (s[i].gnum == 2)
		{
			p = &s[i];
			break;
		}
	}
	i++;
	for (; i <= 100; i++)
	{
		if (s[i].gnum == 2)
		{
			if (s[i].game1 + s[i].game2 < p->game1 + p->game2)//目前的总名次更低
			{
				s[i].next = p;
				p = &s[i];
			}
			else if (s[i].game1 + s[i].game2 == p->game1 + p->game2)//目前的总名次相等
			{
				s[i].equl = p;
				p = &s[i];
			}
			else
			{
				p->next = &s[i];
			}
		}
	}

	for (i = 1; i <= 100; i++)
	{
		q = p;
		if (s[i].gnum == 1)
		{
			if (s[i].game1 != 0)
			{
				k:if (s[i].game1 < q->game1)//名次较小
				{
					flag = 0;
					m = q;
					while (m)
					{
						if (s[i].game1 >= m->game1)
						{
							flag = 1;//不能放入
							break;
						}
						if (m->equl != NULL)
							m = m->equl;
						else
							m = m->next;
					}
					if (flag == 0)
					{
						s[i].next = q;
						p = &s[i];
					}
				}
				else if (s[i].game1 == q->game1)
				{
					m = q;
				j:
					flag = 0;				
					while (1)
					{
						if (m->equl != NULL)
							m = m->equl;
						else
							m = m->next;
						if (m == NULL)
							break;
						if (s[i].game1 == m->game1)
						{
							flag = 1;//有同名次
							break;
						}
					}
					if (flag == 0)
					{
						if (m = q->equl)
						{
							s[i].equl = m;
							q->equl = &s[i];
						}
						else if (m = q->next)
						{
							s[i].next = m;
							q->equl = &s[i];
						}
						else
						{
							q->equl = &s[i];
						}
					}
					else
					{
						if (q->equl == m)
						{
							q = q->equl;
							goto j;
						}		
					}
				}
				else if (s[i].game1 > q->game1)
				{
					if (m = q->equl)
					{
						q = m;
						goto k;
					}						
					else if (m = q->next)
					{
						q = m;
						goto k;
					}
					else
					{
						q->next = &s[i];
					}
				}
			}
			else
			{
			o:if (s[i].game2 < q->game2)//名次较小
			{
				flag = 0;
				m = q;
				while (m)
				{
					if (s[i].game2 >= m->game2)
					{
						flag = 1;//不能放入
						break;
					}
					if (m->equl != NULL)
						m = m->equl;
					else
						m = m->next;
				}
				if (flag == 0)
				{
					s[i].next = q;
					p = &s[i];
				}
			}
			else if (s[i].game2 == q->game2)
			{
				m = q;
			n:
				flag = 0;
				while (1)
				{
					if (m->equl != NULL)
						m = m->equl;
					else
						m = m->next;
					if (m == NULL)
						break;
					if (s[i].game2 == m->game2)
					{
						flag = 1;//有同名次
						break;
					}
				}
				if (flag == 0)
				{
					if (m = q->equl)
					{
						s[i].equl = m;
						q->equl = &s[i];
					}
					else if (m = q->next)
					{
						s[i].next = m;
						q->equl = &s[i];
					}
					else
					{
						q->equl = &s[i];
					}
				}
				else
				{
					if (q->equl == m)
					{
						q = q->equl;
						goto n;
					}
				}
			}
			else if (s[i].game2 > q->game2)
			{
				if (m = q->equl)
				{
					q = m;
					goto o;
				}
				else if (m = q->next)
				{
					q = m;
					goto o;
				}
				else
				{
					q->next = &s[i];
				}
			}
			}
		}
	}
	



	return 0;
}