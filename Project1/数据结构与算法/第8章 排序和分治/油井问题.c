#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h> 
#include<math.h>
#include<time.h>

int a[2000001], * s, * m, * b, * ow;

int main() {
	int n = 0, waste, p, i, h, sn, mn, bn;
	while (~scanf("%d,%d", &waste, &a[n])) ++n; 
	h = n / 2;
	if (n & 1) ++h; 
	s = (int*)malloc(sizeof(int) * n);
	m = (int*)malloc(sizeof(int) * n);
	b = (int*)malloc(sizeof(int) * n);
	srand((unsigned)time(NULL));
	ow = a;
	while (1)
	{
		p = ow[rand() % n]; 
		sn = mn = bn = 0;
		for (i = 0; i < n; ++i)
		{
			if (ow[i] < p)
			{
				s[sn] = ow[i];
				++sn; 
			}
			else if (ow[i] == p)
			{
				m[mn] = p;
				++mn;   //¡­¡­µÈ¡­¡­ 
			}
			else
			{
				b[bn] = ow[i];
				++bn;
			}
		}
		if (sn < h && (sn + mn) >= h) break;
		else if (sn >= h)
		{
			ow = s;
			n = sn;
		}
		else
		{
			ow = b;
			n = bn;
			h = h - mn - sn;
		}
	}
	printf("%d\n", p);
	return 0;
}