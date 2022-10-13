#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char s[1010];
int len1 = 0, len2 = -1;	//len1����len2��ʾÿ����Ҫȡ�����䳤��
void gethead();	//ȡ��ͷ
void gettail();	//ȡ��β

int main()
{
	int n = 0, m = 0;
	memset(s, 0, sizeof(s));
	scanf("%s", s);
	printf("generic list: %s\n", s);
	len2 = strlen(s) - 1;

	int ans = 0;
	while (~scanf("%d", &ans))
	{
		if (ans == 1)	//ȡ��ͷ
			gethead();
		else			//ȡ��β
			gettail();

		if (len1 == len2)	//������ʣԭ�ӣ�ֹͣ����
			break;
	}
	return 0;
}
void gethead()
{
	printf("destroy tail\nfree list node\ngeneric list: ");
	int temp = -1;
	int i = len1;	//ÿ�δ���һ�ε�λ�ÿ�ʼȡ
	while (s[i] != '\0')
	{
		if (s[i] == '(')
		{
			temp++;
			if (temp == 0)
				len2 = len1 = i + 1;
			i++;
			continue;
		}
		if (s[i] == ')')
		{
			temp--;
			if (temp == 0)	//��һ�������ź���ĵ�һ�����ž��Ǳ�ͷ
			{
				len2 = i;
				break;
			}
			i++;
			continue;
		}
		if (s[i] == ',' && temp == 0) //���е�һ������֮ǰ�ģ����Ǳ�ͷ
		{
			len2 = i - 1;
			break;
		}
		i++;
	}
	//�����ͷ
	for (int j = len1; j <= len2; j++)
	{
		printf("%c", s[j]);
	}
	printf("\n");
}
void gettail()
{
	printf("free head node\nfree list node\ngeneric list: ");
	int temp = -1;
	int vis = 0;
	int i = len1;
	while (s[i] != '\0')
	{
		if (i == len2)	//�ձ�
		{
			vis = 1;
			break;
		}
		if (s[i] == '(')temp++;
		if (s[i] == ')')temp--;
		if (s[i] == ',' && temp == 0) //���еĵ�һ������֮��ģ����Ǳ�β
		{
			s[i] = '(';
			len1 = i;
			break;
		}
		i++;
	}
	if (vis == 1)	//�ձ�ֱ�����
	{
		printf("()\n");
		return;
	}
	//�����β
	for (int j = len1; j <= len2; j++)
	{
		printf("%c", s[j]);
	}
	printf("\n");
}
