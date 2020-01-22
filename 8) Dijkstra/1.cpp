#include<iostream>
#include<fstream>

using namespace std;

int main(int argc, char **argv )
{
	ifstream fin(argv[1]);
	int num = atoi(argv[2]);
	ofstream outf("dijkstra.txt");
	int x,y,w;
	while(fin>>x>>y>>w)
	{
		outf<<x*x<<" "<<y*y<<" "<<num<<" "<<w*w<<"\n";
	}
}