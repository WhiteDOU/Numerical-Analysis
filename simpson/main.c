#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int n;
double h;
double function(double x)
{
    return sin(x)/x;//f(a)=1直接补充，此为反常积分；
}
double Simpson(double a,double b)
{
    double ans,x,xk;
    int i;
    x=a;
    xk=x+h/2;
    ans=4*function(xk);
    for(i=1;i<=n-1;i++)
    {
        x=x+h;
        xk=x+h/2.0;
        ans=ans+4*function(xk)+2*function(x);
    }
    ans+=1+function(b);//补充瑕点；
    ans=ans*h/6;
    return ans;
}

int main()
{
    double a=0,b=1;
    double answer=1;
    printf("请输入把区间分成的数目\n");
    scanf("%d",&n);
    h=(b-a)/n;
    while(fabs(answer-0.9460931)>0.001)
    {
        answer=Simpson(a,b);
        printf("误差为%.8f\n",fabs(answer-0.9460931));
    printf("复化simpson求积的结果为%.8f\n",answer);
    }
    return 0;
}
