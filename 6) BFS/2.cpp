#include<iostream>
#include<fstream>
#include<stack>
#include<algorithm>
#include<vector>
#include<map>
#include<stack>

using namespace std;

int visited1[10000];
// int time[10000];
vector<pair<int,int>> ft;
int Time=0; 

void DFS_go(map<int , vector<int>>mp,int i)
{
	int t = i;
	Time++;
	visited1[t]=1;
	// time[i->first] = Time;
	for(auto j=mp[i].begin();j!=mp[i].end();j++){
		if(visited1[*j]==0)
		{
			visited1[*j]=1;
			//cout << j->second<<"\n";
			DFS_go(mp, *j);
		}
	}
	Time++;
	ft.emplace_back(make_pair(Time,t));
}
void DFS(map<int , vector<int>>mp)
{
	ofstream fout("smt.txt");
	for(int i=0;i<10000;i++)
	{
		visited1[i] = 0;
		// time[i] = 0;
	}
	for(auto i=mp.begin();i!=mp.end();i++){
	if(visited1[i->first]==0)
	{
		//visited1[i->first]=1;
		//cout << i->first[] <<"\n";
		DFS_go(mp,i->first);
	}
}
}

int main(int argc , char** argv){
	ifstream fin(argv[1]);
	map<int , vector<int>>mp;
	int a1 ,b,l=0;
	while(fin >>  a1 >> b)
	{
		mp[a1].push_back(b);
	}

	DFS(mp);
 	sort(ft.begin(),ft.end());
 	for(int i=ft.size()-1;i>=0;i--){
 		cout<<ft[i].second<<endl;
 	}
    return 0;
}