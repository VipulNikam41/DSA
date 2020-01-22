#include<iostream>
#include<fstream>
#include <limits.h> 
#include <stdio.h> 
  
using namespace std;

int main(int argc, char **argv )
{ 
    ifstream fin1(argv[1]);
    ifstream fin2(argv[2]);
    int x,y,E1=0,E2=0;
    int took1[10000][2];
    int took2[10000][2];
    int flg[10000]={0};
    while(fin1>>x>>y)
	{
		took1[E1][0]=x;
		took1[E1][1]=y;
	    E1++;// Number of edges in graph
	}
    while(fin2>>x>>y)
	{
		took2[E2][0]=x;
		took2[E2][1]=y;
	    E2++;// Number of edges in graph
	}
    if(E1!=E2)
    {
        cout<<"number of lines not matched.."<<endl;
    }
    for(int i =0;i<E1;i++)
    {
        for(int j =0;j<E1;j++)
        {
            if(took1[i][0]==took2[j][0] && took1[i][1]==took2[j][1])
            {
                flg[i] = 1;
            }
        }
        if(flg[i]==0)
        {
            cout<<"line not matched.. at i = "<<i<<endl;
        }
    }
    // for(int j =0;j<E1;j++)
    // {
    //     if(flg[j]==0)
    //     {
    //         cout<<took2[j][0]<<endl;
    //     }
    // }

}
