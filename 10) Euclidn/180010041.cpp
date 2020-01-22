#include<iostream>

using namespace std;


int q;
int r;
int s=0,t=0;

int euclidean(int a,int b,int s1,int s2, int t1,int t2)
{
    while(b!=0)
    {
        q = a / b;
        r = a % b;
        s = s1 - s2*q;
        t = t1 - t2*q;
        // cout << q <<" "<< a <<" "<< b <<" "<< r <<" "<< s1 <<" "<< s2 <<" "<< s <<" "<< t1 <<" "<< t2 <<" "<< t <<"\n";
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

    int a1,b1,flag=0;

    int GCD = 1;

    if(a>=b)
    {
        a1=a;
        b1=b;
    }
    else if(a<b)
    {
        flag=1;
        a1=b;
        b1=a;
    }
    
    GCD = euclidean(a1,b1,1,0,0,1);
    if(flag==0)
        cout<< GCD <<" "<< s <<" "<< t <<"\n";
    else
        cout<< GCD <<" "<< t <<" "<< s <<"\n";
}