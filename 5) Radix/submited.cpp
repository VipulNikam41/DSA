#include <iostream>
#include<fstream>
#include<map>
#include<cmath>
#include<vector>

using namespace std;

int power(int i)
{
	int r=1;
	for(int k=0;k<i;k++)
	{
		r=r*10;
	}
	return r;
}
int* countSort(int* arr , int n , int t)
{
	map<int , vector<int>>d;
	int bh = power(t);
	for(int i=0;i<n;i++)
	{
		d[(arr[i]/bh)%10].push_back(arr[i]);
	}
	int* res = new int[n];
	int j=0;
	for(auto i=d.begin();i!=d.end();i++)
	{
		for(int k=0;k<(i->second.size());k++)
		{
			res[j++] = i->second[k];
		}
	}
	return res;
}
int* radix(int a[20000],int d,int cnt)
{
	int* res = new int[cnt];
	for(int i=0;i<d;i++)
	{
		res = countSort(a , cnt , i);
		a = res;
	}
	return res;		
}
void show(ofstream &outf , int* arr ,int size)
{
	for(int i=0;i<size;i++)
	{
		outf<<arr[i]<<endl;
	}
}

int main(int argc ,char **argv)
{
	int d =atoi(argv[2]);
	int a[20000];
	int cnt,num;
	ifstream inf(argv[1]);
	ofstream outf("radix.txt");
	while(inf>>num)
	{
		a[cnt]=num;
		cnt++;
	}
	int* res = radix(a ,d, cnt);
	show(outf , res , cnt);
	return 0;
}
