#include<stdio.h>
#include<math.h>
#define N 3
#define TIMES 100
double dif(double *kk,double *k)
{
    int i;
    double R[N],max;
    for(i=0;i<N;i++)
        R[i]=fabs(kk[i]-k[i]);
    max=R[0];
    for(i=1;i<N;i++)
        if(max<R[N])
            max=R[N];
    return R[N];
}
main()
{
    double a[N][N],b[N],k[N],kk[N];
    int i,j,n=0,m;
    double sum=0,difs=1,precision=0.000001;
    printf("请输入系数矩阵\n");
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
            scanf("%lf",&a[i][j]);
    }
    printf("请输入常数矩阵\n");
    for(i=0;i<N;i++)
        scanf("%lf",&b[i]);
    printf("请输入初值\n");
    for(i=0;i<N;i++)
        scanf("%lf",&k[i]);
    printf("请输出系数矩阵\n");
    for(i=0;i<N;i++){
        for(j=0;j<N;j++)
         {
            printf("%lf ",a[i][j]);
         }
         printf("\n");
    }
    for(i=0;i<N;i++)
        kk[i]=0;
   while(difs>precision)
    {
        for(i=0;i<N;i++)
        {
            sum=0;
            for(j=0;j<N;j++)
           {
            if(i<j)
                sum+=a[i][j]*k[j];
            if(i>j)
                sum+=a[i][j]*kk[j];
           }
            kk[i]=(b[i]-sum)/a[i][i];
        }
        difs=dif(kk,k);
           for(i=0;i<N;i++)
           {
            printf("%lf  ",kk[i]);
            k[i]=kk[i];
           }
           n++;
    }

printf("经过%d后出答案",n);
}
