#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>  
#include <stdlib.h>  

typedef struct node
{
    int         data;
    struct node* next;
} NODE;

void output(NODE*, int);
void change(int, int, NODE*);

void output(NODE* head, int kk)
{
    int k = 0;

    printf("0.");
    while (head->next != NULL && k < kk)
    {
        printf("%d", head->next->data);
        head = head->next;
        k++;
    }
    printf("\n");
}

int main()
{
    int n, m, k;
    NODE* head;

    scanf("%d%d%d", &n, &m, &k);
    head = (NODE*)malloc(sizeof(NODE));
    head->next = NULL;
    head->data = -1;
    change(n, m, head);
    output(head, k);
    return 0;
}

void change(int n, int m, NODE* head)
{
    NODE* p = (NODE*)malloc(sizeof(NODE));
    p = head;
    int a[10000],b[10000];
    int k = 0;
    int flag = -1;
    int qtt, rmd;
    n = 10 * n;
    for (int i = 0; i < 10000; i++)
    {
        a[i] = -1;
        b[i] = -1;
    }
    while (flag == -1)
    {
        qtt = n / m;
        rmd = n % m;
        for (int i = 0; i < k; i++)
            if (a[i] == qtt && b[i] == rmd)
                flag = i;
        if (flag == -1)
        {
            NODE* q = (NODE*)malloc(sizeof(NODE));
            a[k] = qtt;
            b[k] = rmd;
            k++;
            p->next = q;
            q->data = qtt;
            q->next = NULL;
            p = p->next;
            n = rmd * 10;
        }
        if (rmd == 0)
            break;
    }
    if (flag != -1)
    {
        NODE* q = head->next;
        for (int i = 0; i < flag; i++)
        {
            q = q->next;
        }
        p->next = q;
    }
}