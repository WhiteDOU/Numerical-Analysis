#include<stdio.h>
#include<math.h>
#define N 2
#define TIMES 100
float dif(float *kk,float *k)
{
    int i;
    float sum=0,R[N],max;
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
    double sum=0,difs,precision=1.0e-3;
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
            printf("%f  ",a[i][j]);
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
            else if(i>j)
                sum+=a[i][j]*kk[j];
           }
            kk[i]=(b[i]-sum)/a[i][i];
           for(m=0;m<N;m++)
           {
            printf("%f  ",kk[i]);
            k[m]=kk[m];
            difs=dif(k,kk);
           }
        }
        n++;
    }


   printf("经过%d后计算出",n);
    return 0;

}
