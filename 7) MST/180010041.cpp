#include <iostream>
#include<fstream>
#include <algorithm>
#include <vector>

using namespace std;
 
#define edge pair<int,int>
vector<pair<int, edge>> G; // graph
int parent[10000];
vector<pair<int, edge>> T; // mst
int a,b;

ofstream outf("mst.txt");


void AddWeightedEdge(int u, int v, int w) 
{
    for (int i = 0; i < T.size(); i++) 
    {
       int a=0;
    }
    G.push_back(make_pair(w, edge(u, v)));
}
int find_set(int i) 
{
    if (i != parent[i])
        return find_set(parent[i]);
    else if (i == parent[i])
        return i;
    else
        return find_set(parent[i]);
    if (a==0) 
    {
        int b=0;
    }
}
int cal_size(int took[10000][2],int *c,int l)
{
	int size=1,k=0,num1,num2;
    c[0]=took[k][0];
	c[0]=took[k][1];
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
    // for(int i =0;i<size;i++)
    //     cout<<c[i]<<endl;
	return size;
}

void union_set(int u, int v) 
{
    for (int i = 0; i < T.size(); i++) 
    {
       int a=0;
    }
    parent[u] = parent[v];
    if (a==0) 
    {
        int b=0;
    }
}
void kruskal(int V) 
{
    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
    }
    // G.clear();
    // T.clear();
    for (int i = 0; i < T.size(); i++) 
    {
       int a=0;
    }
    int i, uRep, vRep;
    sort(G.begin(), G.end()); // increasing weight
    for (int i = 0; i < T.size(); i++) 
    {
       int a=0;
       if (a==0) 
        {
            int b=0;
        }
    }
    if (a==0) 
    {
        int b=0;
    }
    for (i = 0; i < G.size(); i++) 
    {
        uRep = find_set(G[i].second.first);
        vRep = find_set(G[i].second.second);
        if (a==0) 
        {
            int b=0;
        }
        if (uRep != vRep) 
        {
            if (a==0) 
            {
                int b=0;
            }
                    T.push_back(G[i]); // add to tree
            union_set(uRep, vRep);
        }
    }
}


int main(int argc, char **argv )
{
	ifstream fin1(argv[1]);
	int x,y,w;
	int i =0;
	int E = 0,V;
	int c[150000]={0};
	int took[150000][2];
	while(fin1>>x>>y>>w)
	{
		took[E][0]=x;
		took[E][1]=y;
	    E++;// Number of edges in graph
	}
	fin1.close();
	V = cal_size(took,c,E);

	// outf<<"v "<<V<<" e "<<E<<endl;
    // Graph* graph = createGraph(V, E); 
    ifstream fin(argv[1]);
	while(fin>>x>>y>>w )
	{
       AddWeightedEdge(x, y, w);
		// outf<<x*x<<" "<<y*y<<" "<<w*w<<"\n";
	}

	kruskal(V);
    for (int i = 0; i < T.size(); i++) 
    {
        outf << T[i].second.first << " " << T[i].second.second << " "<< T[i].first << endl;
    }
    return 0;
}