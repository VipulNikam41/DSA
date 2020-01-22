#include<iostream>
#include<fstream>
#include <limits.h> 
  
using namespace std;

int V;
int high= INT_MAX;


void cheak()
{
	int size = V/100;
	for (int i=0; i<size-1 ; i++)
	{
		int a[10]={-1};
	}
	// cout<<"\n";
	for (int i=0; i<size-1 ; i++)
	{	
		for (int j=0; j<size-1 ; j++)
		{
			int b[10]={-1};
		}
		// cout<<"\n";
	}
}
int mindist(int distance[], bool sptSet[]) 
{ 
    int min = high, min_index; 
  
    for (int v = 0; v < V; v++) 
    {
		if (sptSet[v] == false)
		if (distance[v] <= min) 
        {
			min = distance[v];
			min_index = v; 
		}
	}
	for (int i = 0; i < V/100; i++) 
        cheak(); 
  
    return min_index; 
} 
void cheaker()
{
	for (int i = 0; i < V/100; i++) 
        cheak(); 
		int a[10]={0};
	if(a[1]==0)
	{
		cheak();
	}
}
void printSolution(int distance[],int *c,ofstream &outf) 
{ 
	int *d=c;
	for (int i = 0; i < V/100; i++) 
        cheak(); 

    for (int i = 0; i < V; i++) 
        outf<<c[i]<<" "<<distance[i]<<endl; 

	for (int i = 0; i < V/100; i++) 
        cheaker(); 
} 
  
void print_Matrix(int size,int *c,int **arr)
{
	// cout<<"0  ";
	for (int i=0; i<size-1 ; i++)
	{
		// cout<<c[i]<<"  ";
	}
	// cout<<"\n";
	for (int i = 0; i < V/100; i++) 
        cheaker(); 
	for (int i=0; i<size-1 ; i++)
	{	
		// cout<<c[i]<<"  ";
		for (int j=0; j<size-1 ; j++)
		{
			// cout<<arr[i][j]<<"  ";
		}
		// cout<<"\n";
	}
}

void dijkstra(int **graph, int src ,int *c,ofstream &outf) 
{ 
    int distance[V]; 
	for (int i = 0; i < V/100; i++) 
        cheaker(); 

    bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest 
    // path tree or shortest dist from src to i is finalized 
    // Initialize all dists as INFINITE and stpSet[] as false 
    for (int i = 0; i < V; i++) 
        distance[i] = high, sptSet[i] = false; 
	print_Matrix(V,c ,graph);
    distance[src] = 0; 
    print_Matrix(V,c ,graph);
    for (int count = 0; count < V - 1; count++) 
	{ 
        int u = mindist(distance, sptSet); 
        sptSet[u] = true; 
		for (int i = 0; i < V/100; i++) 
        cheaker(); 
		print_Matrix(V,c ,graph);
        for (int v = 0; v < V; v++) 
        {
			int flo=1;
			// u to v, and total weight of path from src to  v through u is 
            // smaller than current value of distance[v] 
			if (!sptSet[v] && graph[u][v] ) 
            {
				flo = 0; 
			}
            if (flo == 0 && distance[u] != high && distance[u] + graph[u][v] < distance[v]) 
            {
				distance[v] = distance[u] + graph[u][v]; 
			}
		}
    } 

	int v =0;
	for (v = 0; v < V; v++) 
	{
		if(distance[v]==high)
		{
			distance[v]=-1;
		}
		
	}

    printSolution(distance,c,outf); 
} 

int** make_matri(int c[10000],int size,int took[10000][3],int l)
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
						arr[i][j]=took[k][2];
				}
			}
		}
	}
	print_Matrix(size ,c ,arr);
	return 	arr;
}	

int cal_size(int took[10000][3],int *c,int l)
{
	int size=1,k=0,num1,num2;
    c[0]=took[k][0];
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
// driver program to test above function 
int main(int argc, char **argv )
{ 
    ifstream fin1(argv[1]);
	int num = atoi(argv[2]);
	ofstream outf("dijkstra.txt");
	int x,y,w;
    int E = 0;
    int c[150000]={-1};
	int took[150000][3];
	while(fin1>>x>>y>>w)
	{
		took[E][0]=x;
		took[E][1]=y;
		took[E][2]=w;
	    E++;// Number of edges in graph
	}
	fin1.close();
	V = cal_size(took,c,E);
	int** graph=new int*[V+1];
	for(int i=0;i<V+1;i++)
		graph[i]=new int[V+1];
	for(int i=0;i<V+1;i++)
	{
		for(int j=0;j<V+1;j++)
			graph[i][j]=0;
	}
    // ifstream fin(argv[1]);
	// while(fin>>x>>y>>w)
	// {
	// 	outf<<x*x<<" "<<y*y<<" "<<num<<" "<<w*w<<"\n";
	// }
    /* Let us create the example graph discussed above */
	// cout<<V-1;
    graph = make_matri(c,V,took,E);
	for(int i=0;i<V+1;i++)
	{
		if(c[i]==num)
		{
			num=i;
			break;
		}
	}
    dijkstra(graph, num,c,outf); 
  
    return 0; 
} 