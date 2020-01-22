#include<iostream>
#include<fstream>

using namespace std;

class Edge  
{  
    public: 
    int src, dest, weight;  
};  
 ofstream outf("out.txt");
// a structure to represent a connected, undirected  
// and weighted graph  
class Graph  
{  
    public: 
    // V-> Number of vertices, E-> Number of edges  
    int V, E;  
  
    // graph is represented as an array of edges.  
    // Since the graph is undirected, the edge  
    // from src to dest is also edge from dest  
    // to src. Both are counted as 1 edge here.  
    Edge* edge;  
};  
  
// Creates a graph with V vertices and E edges  
Graph* createGraph(int V, int E)  
{  
    Graph* graph = new Graph;  
    graph->V = V;  
    graph->E = E;  
  
    graph->edge = new Edge[E];  
  
    return graph;  
}  
  
// A structure to represent a subset for union-find  
class subset  
{  
    public: 
    int parent;  
    int rank;  
};  
  
// A utility function to find set of an element i  
// (uses path compression technique)  
int find(subset subsets[], int i)  
{  
    // find root and make root as parent of i  
    // (path compression)  
    if (subsets[i].parent != i)  
        subsets[i].parent = find(subsets, subsets[i].parent);  
  
    return subsets[i].parent;  
}  
  
// A function that does union of two sets of x and y  
// (uses union by rank)  
void Union(subset subsets[], int x, int y)  
{  
    int xroot = find(subsets, x);  
    int yroot = find(subsets, y);  
  
    // Attach smaller rank tree under root of high  
    // rank tree (Union by Rank)  
    if (subsets[xroot].rank < subsets[yroot].rank)  
        subsets[xroot].parent = yroot;  
    else if (subsets[xroot].rank > subsets[yroot].rank)  
        subsets[yroot].parent = xroot;  
  
    // If ranks are same, then make one as root and  
    // increment its rank by one  
    else
    {  
        subsets[yroot].parent = xroot;  
        subsets[xroot].rank++;  
    }  
}  
  
// Compare two edges according to their weights.  
// Used in qsort() for sorting an array of edges  
int myComp(const void* a, const void* b)  
{  
    Edge* a1 = (Edge*)a;  
    Edge* b1 = (Edge*)b;  
    return a1->weight > b1->weight;  
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
// The main function to construct MST using Kruskal's algorithm  
void KruskalMST(Graph* graph)  
{  
    int V = graph->V;  
    Edge result[V]; // Tnis will store the resultant MST  
    int e = 0; // An index variable, used for result[]  
    int i = 0; // An index variable, used for sorted edges  
  
    // Step 1: Sort all the edges in non-decreasing  
    // order of their weight. If we are not allowed to  
    // change the given graph, we can create a copy of  
    // array of edges  
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);  
  
    // Allocate memory for creating V ssubsets  
    subset *subsets = new subset[( V * sizeof(subset) )];  
  
    // Create V subsets with single elements  
    for (int v = 0; v < V; ++v)  
    {  
        subsets[v].parent = v;  
        subsets[v].rank = 0;  
    }  
  
    // Number of edges to be taken is equal to V-1  
    while (e < V - 1 && i < graph->E)  
    {  
        // Step 2: Pick the smallest edge. And increment  
        // the index for next iteration  
        Edge next_edge = graph->edge[i++];  
  
        int x = find(subsets, next_edge.src);  
        int y = find(subsets, next_edge.dest);  
  
        // If including this edge does't cause cycle,  
        // include it in result and increment the index  
        // of result for next edge  
        if (x != y)  
        {  
            result[e++] = next_edge;  
            Union(subsets, x, y);  
        }  
        // Else discard the next_edge  
    }  
  
    // print the contents of result[] to display the  
    // built MST  
    //outf<<"Following are the edges in the constructed MST\n";  
    cout<<e;
    for (i = 0; i < e; ++i)  
        outf<<result[i].src<<" "<<result[i].dest<<" "<<result[i].weight<<endl;  
    return;  
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
    Graph* graph = createGraph(V, E); 
    ifstream fin(argv[1]);
	while(fin>>x>>y>>w )
	{
		// outf<<x*x<<" "<<y*y<<" "<<w*w<<"\n";
		graph->edge[i].src = x;  
	    graph->edge[i].dest = y;  
	    graph->edge[i].weight = w;  
	    i++;
	}

	KruskalMST(graph);  
}