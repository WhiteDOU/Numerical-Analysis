#include<stdio.h>
#include<math.h>
#define N 8
double dif(double *x,double *y)
{
    int i;
    double R[N],max;
    for(i=0;i<N;i++)
        R[i]=fabs(x[i]-y[i]);
    max=R[0];
    for(i=1;i<N;i++)
        if(max<R[N])
            max=R[N];
    return max;
}
main()
{
    double x[N],y[N],x0[N];
    int i,j,n=0,m;
    double a[N][N]={4, 2, -4, 0, 2, 4, 0, 0,
    2, 2, -1, -2, 1, 3, 2, 0,
    -4, -1, 14, 1, -8, -3, 5,
    6,0, -2, 1, 6, -1, -4, -3,
    3,2, 1, -8, -1, 22, 4, -10,
    -3,4, 3, -3, -4, 4, 11, 1,
    -4,0, 2, 5, -3, -10, 1, 14,
    2,0, 0, 6, 3, -3, -4, 2, 19};
    double b[N]={0,-6,6,23,11,-22,-15,45};
    double sum=0,difs=1,precision=0.00001;
    printf("请输入初值\n");
    for(i=0;i<N;i++)
        scanf("%lf",&x0[i]);
   for(i=0;i<N;i++)
   {
       x[i]=x0[i];
       y[i]=0;
   }
   for(n=0;;n++)
   {
       for(i=0;i<N;i++)
       {
           sum=0;
           for(j=0;j<i;j++)
               sum=sum+a[i][j]*y[j];
           for(j=i+1;j<N;j++)
               sum=sum+a[i][j]*x[j];
           y[i]=(b[i]-sum)/a[i][i];
       }
        if(n%20==0)
           {
               printf("%dth:",n);
               for(i=0;i<N;i++)
               {
                   printf("%lf ",y[i]);
                   if((i+1)%8==0)
            printf("\n");
               }
           }

       difs=dif(x,y);
       if(difs>precision)
           for(i=0;i<N;i++)
               x[i]=y[i];
       else break;
   }
   printf("\n经过%d次迭代后解出方程：\n",n+1);
   for(i=0;i<N;i++)
       printf("%lf     ",y[i]);
}
