#include<iostream>
#include<fstream>
#include<queue>
#include<algorithm>
#include<map>
#include <vector>
#include<stack>

using namespace std;

int main(int argc, char **argv )
{
	ifstream fin(argv[1]);
	int x,y,w;
	int i =0;
	map<int , vector<int> >mp;
	int E = 0,V;
	int c[10000]={0};
	int took[10000][2];
	//V = cal_size(took,c,E);
	//outf<<"v "<<V<<" e "<<E<<endl;
    //Graph* graph = createGraph(V, E); 
	while(fin>>x>>y>>w)
	{
		//outf<<x*x<<" "<<y*y<<" "<<w*w<<"\n";
		mp[x].push_back(y);
	}
	//KruskalMST(graph);  
}