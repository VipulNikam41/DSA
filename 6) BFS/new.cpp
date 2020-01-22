#include<iostream>
#include<fstream>
#include<queue>

using namespace std;

int dist[10000][10000]={0};
int o=0;

int q[10000+1][10000+1]={0};


int shorter(int **arr,int s,int size)
{
	queue<int> q;
	//int size = arr[0].size;
	int temp,index;
	int flag[size+1]={0};
	int dist[size+1]={0};
	q.emplace(arr[s][0]);
	flag[s] = 1;
	dist[s] = 0;
	while(q.size()!=0)
	{
		temp = q.front();
		cout<<temp<<" | ";
		index =-1;
		for(int i=1;i<size+1;i++)
		{
			if(arr[i][0]==temp)
			{
				index = i;
			}
		}
		cout<<"index : "<<index<<endl;
		if(index ==-1)
		{
			cout<<"ERROR";
			return 0;
		}
		q.pop();
		for(int i=1;i<=size;i++)
		{
			if((arr[index][i]==1)&&flag[i]==0){
				cout<<arr[index][i]<<" || ";
				flag[i]=1;
				dist[i] = dist[index] + 1;
				q.emplace(arr[index][i]);
			}
		}
	}
	cout<<"\n\nANSWER\n";
	for(int i=1;i<=size;i++){
		cout<<arr[i][0]<<" "<<dist[i]<<endl;
	}
	return 0;
	//if (cons !=n || o == 0)
	// {
	// 	int k=0,p;
	// 	// int q[size+1][size+1]={0};
	// 	// cout<<n<<endl;
	// 	for (int j=1 ; j<=size ; j++)
	// 		if(arr[p][j]==1)
	// 		{
	// 			q[j][0]=arr[0][j];
	// 			// if(dist[j][0]==0)
	// 			dist[j][0]+=s;
	// 			// else if(dist[j][0]==1)
	// 			// dist[j][0]++;
	// 			shorter(q[j][0],arr,size,cons);
	// 			k++;
	// 		}
	// 		// o=1;
	// 		s++;
	// }

	// else 
	// 	return 0;

	

}
int bfs(int c[10000],int size,int took[10000][2],int l,int n)
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
	for (int i=1; i<size+1 ; i++)
	{
		arr[0][i]=c[i-1];
		arr[i][0]=c[i-1];
	}

	for (int k=0; k<l ; k++)
	{
		num1=took[k][0];
		num2=took[k][1];
		//cout<<num1<<"&"<<num2<<endl;
		for (int i=1; i<=size+1 ; i++)
		{
			if(num1==c[i-1])
			{
				for (int j=1; j<=size+1 ; j++)
				{
					if(num2==c[j-1])
						arr[i][j]=1;
				}
			}
		}
	}

	for (int i=0; i<=size ; i++)
	{	
		for (int j=0; j<=size ; j++)
			cout<<arr[i][j]<<"  ";
		cout<<"\n";
	}
	for (int j=1 ; j<=size ; j++)
	{
		if(n==arr[j][0])
		{
			p = j;
		}
	}
	shorter(arr,p,size);
	//cout<<"\nand here we go"<<endl;
	//for (int i=0; i<=size ; i++)
	//{
	//	cout<<dist[i][0]<<"  ";
	//}
}	

int main(int argc,char **argv)
{
	ifstream fp(argv[1]);
	int n = atoi(argv[2]);
	int num,size=1,nodes;
	int num1,num2;
	int took[10000][2];
	ofstream outs("sms.txt");
	ofstream outt("smt.txt");
	int c[1000]={0};
	int l=0;
	while(fp>>num)
	{
		num1 = num;
		fp>>num2;
		took[l][0]=num1;
		took[l][1]=num2;
		l++;
		int flg1=1,flg2=1;
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
	// for (int i=0; i<l ; i++)
	// 	cout<<took[i][0]<<"&"<<took[i][1]<<endl;
	bfs(c,size,took,l,n);

}