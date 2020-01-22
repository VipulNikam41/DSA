#include <iostream>
#include<fstream>


using namespace std;

int main(int argc, char **argv )
{
    int flag = 1;
    int x,y,w;
    int elma1[10000];
    int elmb1[10000];
    int w1[10000];
    int elma2[10000];
    int elmb2[10000];
    int w2[10000];
	ifstream fin1(argv[1]);
    ifstream fin2(argv[2]);
    int i1=0;
    while(fin1>>x>>y>>w )
	{
        elma1[i1]=x;
        elmb1[i1]=y;
        w1[i1]=w;
        i1++;
    }
    int i2=0;
    while(fin2>>x>>y>>w )
	{
        elma2[i2]=x;
        elmb2[i2]=y;
        w2[i2]=w;
        i2++;
    }
    // if(i1!=i2)
    // {
    //     cout<<"lines not matched";
    //     flag = 0;
    //     return 0;
    // }
    for(int i=0;i<i1;i++)
    {
        if(w1[i]!=w2[i])
        {
            cout<<"weight not matched for i = "<<i<<"\n";
            flag = 0;
        }
    }
    for(int i=0;i<i1;i++)
    {
        if( elma1[i]!=elma2[i] && elmb1[i]!=elmb2[i] )
        {
            if( elma1[i]!=elmb2[i] && elmb1[i]!=elma2[i] )
            {
                cout<<"elements not matched for i = "<<i<<"\n";
                flag = 0;
            }
        }
    }
    if(flag == 1)
        cout<<"all corect";
}
