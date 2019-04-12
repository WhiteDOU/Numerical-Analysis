#include<stdio.h>
#include<math.h>
#define N 10
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
    double b[N],x[N],y[N],x0[N];
    int i,j,n=0,m;
    double a[N][N]={{4,-1,0,0,0,0,0,0,0,0},{-1,4,-1,0,0,0,0,0,0,0},{0,-1,4,-1,0,0,0,0,0,0},{0,0,-1,4,-1,0,0,0,0,0},{0,0,0,-1,4,-1,0,0,0,0},{0,0,0,0,-1,4,-1,0,0,0},{0,0,0,0,0,-1,4,-1,0,0},{0,0,0,0,0,0,-1,4,-1,0},{0,0,0,0,0,0,0,-1,4,-1},{0,0,0,0,0,0,0,0,-1,4}};
    double sum=0,difs=1,precision=0.000001;

    printf("请输入常数矩阵\n");
    for(i=0;i<N;i++)
        scanf("%lf",&b[i]);
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
