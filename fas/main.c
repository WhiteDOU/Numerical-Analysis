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
    printf("������ϵ������\n");
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
            scanf("%lf",&a[i][j]);
    }
    printf("�����볣������\n");
    for(i=0;i<N;i++)
        scanf("%lf",&b[i]);
    printf("�������ֵ\n");
    for(i=0;i<N;i++)
        scanf("%lf",&k[i]);
    printf("�����ϵ������\n");
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


   printf("����%d������",n);
    return 0;

}
