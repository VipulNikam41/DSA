#include<iostream> 
#include<fstream>
#include<list> 
using namespace std; 
  
// Graph class represents a directed graph 
// using adjacency list representation 
ofstream outs("sms.txt");
ofstream outt("smt.txt");

class Graph 
{ 
    int V;    // No. of vertices 
  
    // Pointer to an array containing 
    // adjacency lists 
    list<int> *adj; 
  
    // A recursive function used by DFS 
    void DFSUtil(int v, bool visited[]); 
public: 
    Graph(int V);   // Constructor 
  
    // function to add an edge to graph 
    void addEdge(int v, int w); 
  
    // DFS traversal of the vertices 
    // reachable from v 
    void DFS(int v); 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); // Add w to v’s list. 
} 
  
void Graph::DFSUtil(int v, bool visited[]) 
{ 
    // Mark the current node as visited and 
    // print it 
    visited[v] = true; 
    outt << v << " "; 
  
    // Recur for all the vertices adjacent 
    // to this vertex 
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
            DFSUtil(*i, visited); 
} 
  
// DFS traversal of the vertices reachable from v. 
// It uses recursive DFSUtil() 
void Graph::DFS(int v) 
{ 
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 
  
    // Call the recursive helper function 
    // to print DFS traversal 
    DFSUtil(v, visited); 
} 
  
// Driver code 
int main(int argc,char **argv) 
{ 
    // Create a graph given in the above diagram 
    ifstream fp(argv[1]);
    int n = atoi(argv[2]);
    int num,size=1,nodes;
    int num1,num2;
    int c[1000]={0};
    while(fp>>num)
    {
        num1 = num;
        fp>>num2;
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
    }
    Graph g(size-1);
    ifstream f(argv[1]);
    while(f>>num)
    {
        num1 = num;
        f>>num2;
        g.addEdge(num1, num2); 
    } 
    g.DFS(3); 
  
    return 0; 
}