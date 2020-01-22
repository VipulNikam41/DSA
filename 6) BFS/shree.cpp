#include<iostream>
#include<fstream>
#include<queue>
#include<algorithm>
#include<map>

using namespace std;

int visited[10000];
queue<int>q;
int visited1[10000];
// int time[10000];
vector<pair<int,int>> ft;
int Time=0; 

int dist[10000];

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
	}
	for(auto i=mp.begin();i!=mp.end();i++)
	{
		if(visited1[i->first]==0)
		{
			DFS_go(mp,i->first);
		}
	}
}

void minus1(int *s,int a)
{
	for(int i=0;i<10000;i++)
	{
		s[i] = a;
	}
}
int BFS_go(map<int , vector<int>>mp,int s)
{
	ofstream fout("sms.txt");
	fout << s <<  " 0" << endl;
	while(q.size() > 0)
	{
		int t = q.front();
		q.pop();

		for(int i=0;i<mp[t].size();i++){
			if(visited[mp[t][i]]==3){
				continue;
			}
			else
			{
				q.push(mp[t][i]);
				visited[mp[t][i]] = 3;
				dist[mp[t][i]] = dist[t] + 1;
				fout << mp[t][i] << " " << dist[mp[t][i]] << endl;
			}
		}
	}
	for(auto i=mp.begin();i!=mp.end();i++){
		if(-3 == visited[i->first]){
				fout << i->first << " " << dist[i->first] << endl;
		}
		for(int j=0;j<i->second.size();j++){
			if(-3 == visited[i->second[j]]){
				fout << i->second[j] << " " << dist[i->second[j]] << endl;
			}
		}
	}
}

void BFS(map<int , vector<int>>mp , int s)
{
	minus1(visited,-3);
	minus1(dist,-1);
	DFS(mp);
	dist[s] = 0;
	q.push(s);
	visited[s] = 3;
	BFS_go(mp,s);
}

int printerT(map<int , vector<int>>mp)
{
	ofstream outt("smt.txt");
 	for(int i=ft.size()-1;i>=0;i--)
 	{
 		outt<<ft[i].second<<endl;
 	}
}

int main(int argc , char** argv){
	ifstream fin(argv[1]);
	map<int , vector<int>>mp;
	int a1 ,b,l=0;
	int took[10000][2];
	int n=0;
	n=atoi(argv[2]);
	while(fin >> a1)
	{
		fin>>b;
		mp[a1].push_back(b);
	}
	BFS(mp , n);
 	sort(ft.begin(),ft.end());
 	printerT(mp);
 
    return 0;
}