#include<iostream>
#include<fstream>
#include<queue>
#include<algorithm>
#include<map>
#include<stack>

using namespace std;

bool visited[10000];
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
void BFS(map<int , vector<int>>mp , int s)
{
	ofstream fout("sd.txt");
	for(int i=0;i<10000;i++)
	{
		visited[i] = false;
		dist[i] = -1;
	}
	dist[s] = 0;
	queue<int>q;
	q.push(s);
	visited[s] = true;
	fout << s <<  " 0" << endl;
	while(q.size() > 0){
		int t = q.front();
		q.pop();

		for(int i=0;i<mp[t].size();i++){
			if(visited[mp[t][i]]){
				continue;
			}
			else{
				q.push(mp[t][i]);
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
int** bfs(int c[10000],int size,int took[10000][2],int l)
{
	//int arr[size+1][size+1]={0};
	int** arr=new int*[size+1];
	for(int i=0;i<size+1;i++)
		arr[i]=new int[size+1];
	for(int i=0;i<size+1;i++)
	{
		for(int j=0;j<size+1;j++)
			arr[i][j]=0;
	}
		// for (int i=0; i<size ; i++)
		// 	cout<<c[i]<<endl;
	
	int num,p;
	int num1,num2;
	// int arr[size+1][size+1]={0};

	for (int k=0; k<l ; k++)
	{
		num1=took[k][0];
		num2=took[k][1];
		//cout<<num1<<"&"<<num2<<endl;
		for (int i=0; i<=size ; i++)
		{
			if(num1==c[i])
			{
				for (int j=0; j<=size ; j++)
				{
					if(num2==c[j])
						arr[i][j]=1;
				}
			}
		}
	}

	for (int i=0; i<size ; i++)
	{	
		for (int j=0; j<size ; j++)
			cout<<arr[i][j]<<"  ";
		cout<<"\n";
	}
	return 	arr;
}	

int main(int argc , char** argv){
	ifstream fin(argv[1]);
	map<int , vector<int>>mp;
	int a1 ,b,l=0;
	int took[10000][2];
	while(fin >>  a1 >> b)
	{
		mp[a1].push_back(b);
	}
	ofstream outt("ts.txt");
	BFS(mp , stoi(argv[2]));
	DFS(mp);
 	sort(ft.begin(),ft.end());
 	for(int i=ft.size()-1;i>=0;i--){
 		outt<<ft[i].second<<endl;
 	}
 
    return 0;
}