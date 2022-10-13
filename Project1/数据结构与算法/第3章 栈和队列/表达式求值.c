#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAX 9999999

int figure[100];  //��������
char symbol[100]; //���������
//�±�
int topf = -1;
int tops = -1;
//һ��������λ����˳��
char operation[9] = { '+', '-', '*', '/', '(', ')', '#', '^', '%' };
char checklist[9][9] = {
    {'>', '>', '<', '<', '<', '>', '>', '<', '<'},
    {'>', '>', '<', '<', '<', '>', '>', '<', '<'},
    {'>', '>', '>', '>', '<', '>', '>', '<', '>'},
    {'>', '>', '>', '>', '<', '>', '>', '<', '>'},
    {'<', '<', '<', '<', '<', '=', ' ', '<', '<'},
    {'>', '>', '>', '>', ' ', '>', '>', '>', '>'},
    {'<', '<', '<', '<', '<', ' ', '=', '<', '<'},
    {'>', '>', '>', '>', '<', '>', '>', '<', '>'},
    {'>', '>', '>', '>', '<', '>', '>', '<', '>'} };

int number(char* q)
{
    return (int)(*q - '0');
}

void push_figure(int q)
{
    figure[++topf] = q;
}

void push_symbol(char ch)
{
    symbol[++tops] = ch;
}

int pop_figure()
{
    return figure[topf--];
}
//ȡ���ոմ�����������
char pop_symbol()
{
    return symbol[tops--];
}

char compare(char x, char y)
{
    int a, b; //������λ�±��������˳��
    for (int i = 0; i < 9; i++)
    {
        if (operation[i] == x)
        {
            a = i;
            break;
        }
    }
    for (int i = 0; i < 9; i++)
    {
        if (operation[i] == y)
        {
            b = i;
            break;
        }
    }
    //�õ����ȼ���ϵ������Ϊ����ֵ
    return checklist[a][b];
}

int operate(int x, int y, char symbol)
{
    switch (symbol)
    {
    case '+':
        return x + y;
    case '-':
        return x - y;
    case '*':
        return x * y;
    case '/':
        if (y)
            return x / y;
        else
        {
            printf("Divide 0.\n");
            return MAX;
        }
        // C �⺯�� double fmod(double x, double y) ���� x ���� y ��������
    case '%':
        return (int)fmod(x, y);
    case '^':
        if (y >= 0)
            return (int)pow(x, y);
        else
        {
            printf("error.\n");
            return MAX;
        }
    default:
        printf("error.\n");
        return MAX;
    }
}

int main(int argc, char* argv[])
{
    int n;
    int flag; //����0���� Ϊ1������2
    char expression[100], * p, * negative;
    char firstnega = '0';

    scanf("%d", &n);

    while (n--)
    {
        flag = 2;
        memset(expression, '\0', 100);
        scanf("%s", expression);

        strcat(expression, "#");
        p = expression;
        negative = expression;

        // ��һ�������Ǹ������ҵڶ����ַ�������
        // �Ѹ������滻Ϊ0
        //ָ�������ԭ����Ҳ�ᱻ�޸�
        if (*negative == '-' && *(negative + 1) == '(')
        { //�������  -(2+2)+1 ֱ����figure�в���һ��0
            push_figure(number(&firstnega));
        }

        if (*negative == '-' && *(negative + 1) >= '0' && *(negative + 1) <= '9')
        {
            *negative = '0';
        }
        negative++;
        // ����ÿһ���ַ�
        // ǰһ���ַ��������֣�����ַ��ǡ�-����
        // �Ͱ�����ַ��滻Ϊ0
        for (; *negative != '\0'; negative++)
        {
            if ((*(negative - 1) < '0' || *(negative - 1) > '9') && (*negative == '-') && *(negative - 1) != ')')
            {
                *negative = '0';
            }
        }
        //��ջsymbol�в���#
        push_symbol('#');
    k:
        while (*p != '#' || symbol[tops] != '#')
        {
            // ��������
            if (*p >= '0' && *p <= '9')
            {
                if (flag == 0)
                {
                    //���֮ǰ�и����ķ��ŵĻ����Ϊ0��Ȼ��0��������Ϊ�жϱ�־��figure������븺��
                    if (figure[topf] <= 0)
                        push_figure(pop_figure() * 10 + number(p++) * (-1));
                    else
                        push_figure(pop_figure() * 10 + number(p++));
                }
                else
                    push_figure(number(p++));
                //˵���Ѿ������������,ע����һλһλ�Ĳ���
                flag = 0;
            }
            //��������
            else
            {
                //���ǵ��ǣ�+�������
                if (flag == 1)
                {
                    if (*p == '+' || *p == '-' || *p == '*' || *p == '/' || *p == '%' || *p == '^')
                    {
                        printf("error.\n");
                        goto j;
                    }
                }
                //ɨ�赽������ʱ����������Ϊ1
                if (*p == '(')
                {
                    flag = 1;
                }
                else
                    flag = 2;

                if (tops == -1)
                {
                    printf("error.\n");
                    goto j;
                }
                else
                {
                    char ch = pop_symbol(), ans;
                    // ������ɨ�赽��������ź͸ոմ�����Ǹ��������������ȼ��Ƚ�
                    ans = compare(ch, *p);
                    if (ans == ' ')
                    {
                        printf("error.\n");
                        goto j;
                    }
                    //���ȼ�С���������
                    else if (ans == '<')
                    {
                        push_symbol(ch); //��ȡ���������´��ȥ
                        push_symbol(*p++);
                        goto k;
                    }
                    // ���ȼ���ͬ��topsָ����һλ���䶯��ֱ��ɨ����һ��p���������ʱֱ�Ӹ��ǵ���
                    else if (ans == '=')
                    {

                        p++;
                        goto k;
                    }
                    else
                    {
                        //��x,y,ch�������㣬�������ִ��

                        int integer_x, integer_y;
                        integer_y = pop_figure();
                        integer_x = pop_figure();
                        int judge = operate(integer_x, integer_y, ch);
                        if (judge == MAX)
                            goto j;
                        else
                            push_figure(judge);
                        continue;
                    }
                    p++;
                }
            }
        }
        if (topf == 0 && tops == 0)
            printf("%d\n", figure[topf]);
        else
        {
            printf("error.\n");
        }
        // ��ʼ�������¿�ʼ�µ���ʽ����
    j:
        memset(expression, '\0', 100);
        topf = -1;
        tops = -1;
    }
    return 0;
}
