#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
int cost[10000][10000],k,visit,visited[150000],l,v,count,count1,vst,p;
ofstream outf("out.txt");

int cal_size(int took[10000][2],int *c,int l)
{
	int size=1,k=0,num1,num2;
	while(k!=l)
	{
		int flg1=1,flg2=1;
		num1=took[k][0];
		num2=took[k][1];
		k++;
		for(int i=0;i<size;i++)
		{
			if(num1==c[i])
			{
				flg1=0;
			}
			if(num2==c[i])
			{
				flg2=0;
			}
		}
		if(flg1==1)
		{
			c[size-1]=num1;
			size++;
		}
		if(flg2==1)
		{
			c[size-1]=num2;
			size++;
		}
		//bfs(g,n);
	}
	size--;
	return size;
}
 
int main(int argc, char **argv )
{
    int i,j,k;
    int dup1,dup2;
    ifstream fin1(argv[1]);
	int x,y,w;
	// int i =0;
	int m = 0;
	int c[150000]={0};
	int took[150000][2];
	while(fin1>>x>>y>>w)
	{
		took[m][0]=x;
		took[m][1]=y;
	    m++;// Number of edges in graph
	}
	fin1.close();
	int n = cal_size(took,c,m);
    ifstream fin(argv[1]);
    // cout <<"EDGE Cost";
    while(fin>>x>>y>>w)
    {
        cost[x][y]=w;
        cost[y][x]=w;
    }
    cout<<"done";
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(cost[i][j]==0)
                cost[i][j]=31999;
                visit=1;
    while(visit<n)
    {
        v=31999;
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(cost[i][j]!=31999 && cost[i][j]<v  && cost[i][j]!=-1 )
                {
                    int count =0;
                    for(p=1;p<=n;p++)
                    {
                        if(visited[p]==i || visited[p]==j)
                        count++;
                    }
                    if(count >= 2)
                    {
                        for(p=1;p<=n;p++)
                            if(cost[i][p]!=31999 && p!=j)
                            dup1=p;
                        for(p=1;p<=n;p++)
                            if(cost[j][p]!=31999 && p!=i)
                            dup2=p;
                        
                        if(cost[dup1][dup2]==-1)
                            continue;
                    }
                    l=i;
                    k=j;
                    v=cost[i][j];
                }
        outf <<l<<" "<<k<<" "<<v<<"\n";
        cost[l][k]=-1;
        cost[k][l]=-1;
        visit++;
        int count=0;
        count1=0;
        for(i=1;i<=n;i++)
        {
            if(visited[i]==l)
                count++;
            if(visited[i]==k)
                count1++;
        } 
        if(count==0)
            visited[++vst]=l;
        if(count1==0)
            visited[++vst]=k;
    }
}