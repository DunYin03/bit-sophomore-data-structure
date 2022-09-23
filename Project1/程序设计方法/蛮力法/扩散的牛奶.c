//#define _CRT_SECURE_NO_WARNINGS 1
////text text
//#include<stdio.h>  
//#include<math.h>  
//#include<stdlib.h>  
//int main()
//{
//    int n, p[200][2], k, i, j, f1, f2, f3, a, b, c;
//    double d, total = 0;
//    scanf("%d", &n);
//    for (i = 0; i < n; i++)
//    {
//        scanf("%d %d", &p[i][0], &p[i][1]);
//        for (j = 0; j < i; j++)
//        {
//            if ((p[i][0] == p[j][0]) && (p[i][1] == p[j][1]))
//            {
//                n--;
//                i--;
//            }
//        }
//
//    }
//    if (n == 1) total = 0;
//    else
//    {
//        for (k = 0; k < n - 1; k++)
//        {
//            for (i = k + 1; i < n; i++)
//            {
//                a = p[k][1] - p[i][1]; //ax+by=c a=y2-y1 b=x1-x2 c=x1y2-x2y1  
//                b = p[i][0] - p[k][0];
//                c = p[i][0] * p[k][1] - p[k][0] * p[i][1];
//                f1 = 0;
//                f2 = 0;
//                f3 = 0;
//                for (j = 0; j < n; j++)
//                {
//                    if (a * p[j][0] + b * p[j][1] > c) f1++;
//                    if (a * p[j][0] + b * p[j][1] < c) f2++;
//                    if ((a * p[j][0] + b * p[j][1] == c) && (((p[j][0] - p[k][0]) * (p[j][0] - p[i][0]) > 0) || ((p[j][1] - p[k][1]) * (p[j][1] - p[i][1]) > 0))) f3++; //排除掉共线的多余点   
//                }
//                if (((f1 == 0) || (f2 == 0)) && (f3 == 0))
//                {
//                    d = sqrt(pow((double)(p[k][0] - p[i][0]), 2.0) + pow((double)(p[k][1] - p[i][1]), 2.0));
//                    total += d;
//                    //printf("%f,%d,%d\n",d,f1,f2);  
//                    //system("pause");  
//                }
//
//            }
//        }
//    }
//    printf("%lf\n", total);
//}