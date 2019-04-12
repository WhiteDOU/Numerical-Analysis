#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int n;
double h;
double function(double x)
{
    return sin(x)/x;//f(a)=1ֱ�Ӳ��䣬��Ϊ�������֣�
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
    ans+=1+function(b);//����覵㣻
    ans=ans*h/6;
    return ans;
}

int main()
{
    double a=0,b=1;
    double answer=1;
    printf("�����������ֳɵ���Ŀ\n");
    scanf("%d",&n);
    h=(b-a)/n;
    while(fabs(answer-0.9460931)>0.001)
    {
        answer=Simpson(a,b);
        printf("���Ϊ%.8f\n",fabs(answer-0.9460931));
    printf("����simpson����Ľ��Ϊ%.8f\n",answer);
    }
    return 0;
}
