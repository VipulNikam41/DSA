#include<stdio.h>
#include<stdlib.h>

int s=0,t=0;

int euclidean(int a,int b,int s1,int s2, int t1,int t2)
{
    while(b!=0)
    {
        int q;
        int r;
        q = a / b;
        r = a % b;
        s = s1 - s2*q;
        t = t1 - t2*q;
        a = b;
        b = r;
        s1 = s2;
        s2 = s;
        t1 = t2;
        t2 = t;
        euclidean(a,b,s1,s2,t1,t2);
    }
    s = s1;
    t = t1;
    return a;
}

int main(int argc, char **argv )
{
    int a = atoi(argv[1]);
	int b = atoi(argv[2]);

    int flag=0;

    int GCD = 1;

    if(a<b)
    {
        flag=1;
        int temp = a;
        a=b;
        b=temp;
    }
    
    GCD = euclidean(a,b,1,0,0,1);

    if(flag==0)
        printf("%d %d %d \n",GCD,s,t);
    else
        printf("%d %d %d \n",GCD,t,s);
}