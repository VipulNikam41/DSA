#include<iostream>
#include<fstream>
#include<queue>
#include<algorithm>
#include<map>

using namespace std;

bool visited[10000];
int visited1[10000];
// int time[10000];
vector<pair<int,int>> ft;
int Time=0; 
int rad=100000;
int si=100000;
int dia=0;

int dist[10000];

void BFS(map<int , vector<int>>mp , int s)
{
	for(int i=0;i<10000;i++)
	{
		visited[i] = false;
		dist[i] = -1;
	}
	int k = s;
	int maxi = 0;
	dist[s] = 0;
	queue<int>q;
	q.push(s);
	visited[s] = true;

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
				// fout <<k<<" "<< mp[t][i] << " " << dist[mp[t][i]] << endl;
			}
		}
	}
	for(auto i=mp.begin();i!=mp.end();i++)
	{
		if(!visited[i->first])
		{
			// fout<<k<<" ";
			// fout << i->first << " " << dist[i->first]<< endl;
			if(dist[i->first]>maxi)
			{
				maxi=dist[i->first];
			}
		}
		for(int j=0;j<i->second.size();j++)
		{
			if(!visited[i->second[j]])
			{
				// fout<<k<<" ";
				// fout << i->second[j] << " " << dist[i->second[j]]<< endl;
			}
			if(dist[i->second[j]]>maxi)
			{
				maxi=dist[i->second[j]];
			}
		}
	}
	// fout<<"maxi: "<<maxi<<"########\n";
	if(maxi<rad)
	{
		rad=maxi;
	}
	if(maxi>dia)
	{
		dia=maxi;
	}
}

int cycle(map<int , vector<int>>mp , int s, int k)
{
	int maxi1=9;
	if(k!=s)
	{
		for(int i=0;i<mp[s].size();i++)
		{
			// fout << mp[s][0] << " " ;
			cycle(mp,mp[s][0],k);
		}
	}
	// fout1<<"########\n";
	if(maxi1<si)
	{
		si=maxi1;
	}
	return maxi1;
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
		for (int i=0; i<size ; i++)
		{
			if(num1==c[i])
			{
				for (int j=0; j<size ; j++)
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
	return arr;
}	

int main(int argc , char** argv){
	ifstream fin(argv[1]);
	map<int , vector<int>>mp;
	int a1 ,b,l=0;
	int took[10000][2];
	int V,E=0;
	int max=0;
	int **arr;
    int min=1000000;
	int c[150000]={0};
	int ql[10000]={1},val[10000];
	while(fin >>  a1 >> b)
	{
		mp[a1].push_back(b);
		mp[b].push_back(a1);
		took[E][0]=a1;
		took[E][1]=b;
		E++;
	}
	ofstream outf("parameters.txt");
	V = cal_size(took,c,E);
	int j=0;
    for(auto i=mp.begin();i!=mp.end();i++)
    {
		if(i->second.size()>max)
		{
			max=i->second.size();
		}
		if(i->second.size()<min)
		{
			min=i->second.size();
		}
		if(i->second.size()==1)
		{
			ql[j]=0;
			val[j]=1000000;
		}
		j++;
	}
	outf<<V<<endl;
    outf<<E<<endl;
	outf<<min<<endl;
    outf<<max<<endl;
	for(int i =0; i<V;i++)
	{
		BFS(mp , c[i]);
	}
	outf<<rad<<endl;
    outf<<dia<<endl;
    outf<<"3"<<endl;
    // arr=bfs(c,V,took,E);
	// BFS(mp , 4);
	// cout<<mp[3][2];
	for(int i =0; i<V;i++)
	{
		if(ql[i]==1)
			val[i]=cycle(mp , mp[c[i]][0],c[i]);
	}
 	sort(ft.begin(),ft.end());
 
    return 0;
}