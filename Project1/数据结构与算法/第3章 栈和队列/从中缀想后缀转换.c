#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>   
#include<ctype.h>  
#include<stdlib.h>  


typedef struct Node
{
    char symbol;
    struct Node* next;
}NODE;


NODE* head, * p;

void InitStack()
{
    head = (NODE*)malloc(sizeof(NODE));
    head->symbol = NULL;
    head->next = NULL;
}

void Push(char ch)
{
    p = (NODE*)malloc(sizeof(NODE));
    p->symbol = ch;
    p->next = head->next;
    head->next = p;
}

void Pop()
{
    p = head->next;
    head->next = p->next;
    free(p);
}

int main()
{
    int N;
    char ch;
    scanf("%d\n", &N);

    while (N--)
    {
        InitStack();
        while ((ch = getchar()) && ch != '#')
        {
            if ((ch>='a'&&ch<='z')||(ch>='A'&&ch <='Z'))
            {
                putchar(ch);
            }

            else if (ch == '(') Push(ch);

            else if (ch == ')')
            {
                while (head->next->symbol != '(')
                {
                    putchar(head->next->symbol);
                    Pop();
                }

                Pop();
            }

            else
            {
                if (head->next == NULL) Push(ch);

                else
                {
                    int x, y;//x=ch,y=top of the stack  
                    while (1)
                    {
                        if (head->next == NULL)
                        {
                            Push(ch);
                            break;
                        }

                        char ch1 = head->next->symbol;

                        switch (ch)
                        {
                        case '^': {x = 7; break; }
                        case '*': {x = 4; break; }
                        case '/': {x = 4; break; }

                        case '+': {x = 2; break; }
                        case '-': {x = 2; break; }
                        }

                        switch (ch1)
                        {
                        case '^': {y = 6; break; }
                        case '*': {y = 5; break; }
                        case '/': {y = 5; break; }
                        case '(': {y = 1; break; }
                        case '+': {y = 3; break; }
                        case '-': {y = 3; break; }
                        }

                        if (y > x || y == x)
                        {
                            putchar(ch1);
                            Pop();
                            continue;
                        }

                        else
                        {
                            Push(ch);
                            break;
                        }
                    }
                }
            }
        }

        while (head->next != NULL)
        {
            putchar(head->next->symbol);
            Pop();
        }

        putchar('\n');
        ch = getchar();
    }
}
