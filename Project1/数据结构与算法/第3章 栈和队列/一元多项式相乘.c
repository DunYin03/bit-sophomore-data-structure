#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>  
#include <stdlib.h>  

typedef struct node
{
    int    coef, exp;//coef为系数,exp指数
    struct node* next;
} NODE;

void multiplication(NODE*, NODE*, NODE*);


void input(NODE* head)
{
    int flag, sign, sum, x;
    char c;

    NODE* p = head;

    while ((c = getchar()) != '\n')
    {
        if (c == '<')
        {
            sum = 0;
            sign = 1;
            flag = 1;
        }
        else if (c == '-')
            sign = -1;
        else if (c >= '0' && c <= '9')
        {
            sum = sum * 10 + c - '0';
        }
        else if (c == ',')
        {
            if (flag == 1)
            {
                x = sign * sum;
                sum = 0;
                flag = 2;
                sign = 1;
            }
        }
        else if (c == '>')
        {
            p->next = (NODE*)malloc(sizeof(NODE));
            p->next->coef = x;
            p->next->exp = sign * sum;
            p = p->next;
            p->next = NULL;
            flag = 0;
        }
    }
}

void output(NODE* head)
{
    while (head->next != NULL)
    {
        head = head->next;
        printf("<%d,%d>,", head->coef, head->exp);
    }
    printf("\n");
}

int main()
{
    NODE* head1, * head2, * head3;

    head1 = (NODE*)malloc(sizeof(NODE));
    input(head1);

    head2 = (NODE*)malloc(sizeof(NODE));
    input(head2);

    head3 = (NODE*)malloc(sizeof(NODE));
    head3->next = NULL;
    multiplication(head1, head2, head3);

    output(head3);
    return 0;
}


void multiplication(NODE* h1, NODE* h2, NODE* h3)
{
    NODE* p1 = h1->next;
    NODE* p2 = h2->next;
    NODE* p3 = h3;
    NODE* p4 = h3;
    int coef, coef1, coef2, exp, exp1, exp2;

    while (p1)
    {
        coef1 = p1->coef;
        exp1 = p1->exp;
        while (p2)
        {
            coef2 = p2->coef;
            exp2 = p2->exp;
            coef = coef1 * coef2;
            if (coef == 0)
            {
                p2 = p2->next;
                continue;
            }
            exp = exp1 + exp2;
            if (p4->next == NULL)//创建第一个节点
            {
                NODE* s = (NODE*)malloc(sizeof(NODE));
                s->coef = coef;
                s->exp = exp;
                s->next = NULL;

                p4->next = s;
            }
            else
            {
                if (p3->next != NULL && exp > p3->next->exp)//指数大
                {
                    p4 = p3;

                    while (p4->next != NULL && exp > p4->next->exp)
                    {
                        p4 = p4->next;
                        p3 = p4;
                    }
                }
                else//指数小
                {
                    while (p4->next != NULL && exp > p4->next->exp)
                    {
                        p4 = p4->next;
                        p3 = p4;
                    }
                }
               

                NODE* temp = p4->next;
                if (p4->next == NULL)//若该结点后为空，建立新结点
                {
                    NODE* s = (NODE*)malloc(sizeof(NODE));
                    s->coef = coef;
                    s->exp = exp;
                    s->next = NULL;

                    p4->next = s;
                }
                else if (temp->exp == exp)//指数相等则合并节点
                {
                    temp->coef += coef;
                    if (temp->coef == 0)//值为0，则删除节点
                    {
                        NODE* dele = temp->next;
                        p4->next = dele;
                        free(temp);
                    }
                }
                else if (temp->exp > exp)//指数大则插入新结点
                {
                    NODE* s = (NODE*)malloc(sizeof(NODE));
                    s->coef = coef;
                    s->exp = exp;

                    p4->next = s;
                    s->next = temp;
                }
            }
            p4 = h3;
            p2 = p2->next;
        }
        p2 = h2->next;
        p1 = p1->next;
    }



    if (h3->next == NULL)
    {
        h3->next = (NODE*)malloc(sizeof(NODE));
        h3->next->coef = 0;
        h3->next->exp = 0;
        h3->next->next = NULL;
    }

}