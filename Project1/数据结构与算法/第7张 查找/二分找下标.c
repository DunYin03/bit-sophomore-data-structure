#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int temp,n;
	int flag = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		if (temp == i)
		{
			printf("%d ", i);
			flag = 1;
		}
	}
	if (flag == 0)
		printf("No ");
	printf("\n");
}