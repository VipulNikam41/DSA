#include<iostream>
#include<fstream>
#include<queue>
#include<algorithm>
#include<map>
#include<stack>

using namespace std;


int DFS(map<int , vector<int>>mp;)
{
	bool visited1[10000];
	ofstream fout("smt.txt");
	for(int i=0;i<10000;i++)
	{
		visited1[i] = false;
	}

	stack<int>stk;
	stk.push(s);
	visited[s] = true;
	fout << s <<  " 0" << endl;
	while(stk.size() > 0){
		int t = stk.front();
		stk.pop();

		for(int i=0;i<mp[t].size();i++){
			if(visited[mp[t][i]]){
				continue;
			}
			else{
				stk.push(mp[t][i]);
				visited[mp[t][i]] = true;
				dist[mp[t][i]] = dist[t] + 1;
				fout << mp[t][i] << " " << dist[mp[t][i]] << endl;
			}
		}
	}
	for(auto i=mp.begin();i!=mp.end();i++){
		if(!visited[i->first]){
				fout << i->first << " " << dist[i->first] << endl;
		}
		for(int j=0;j<i->second.size();j++){
			if(!visited[i->second[j]]){
				fout << i->second[j] << " " << dist[i->second[j]] << endl;
			}
		}
	}
	fout.close();
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
 
    return 0;
}
