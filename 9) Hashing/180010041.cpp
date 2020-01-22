#include<iostream>
#include<string.h>
#include<fstream>
#include<algorithm>

using namespace std;

void hashing(string *took1,string *took2,int *val1,int *val2,int E1,int E2)
{
	int ch=0;
	string wrd1[E1] ;
	string wrd2[E2] ;
    for (int i = 0; i < E1; i++)
        wrd1[i] = took1[i];
    for (int i = 0; i < E2; i++)
        wrd2[i] = took2[i];
	for (int i = 0; i < E1; i++)
	{
		sort(wrd1[i].begin(),wrd1[i].end());
	}
	for (int i = 0; i < E2; i++)
	{
		sort(wrd2[i].begin(),wrd2[i].end());
	}
	ofstream outf("anagrams.txt");
	// for (int i = 0; i < E1; i++)
	// {
	// 	cout<<val1[i]<<"  "<<val2[i]<<endl;
	// }
	// cout<<"\n\n\n";
	for (int i = 0; i < E2; i++)
	{
        bool found= true;
		for (int j = E1-1; j >=0; j--)
		{
            if(wrd2[i] == wrd1[j])
            {
                found= false;
                outf<<took1[j]<<" ";
            }	
            if(j == 0)
            {
                found= false;
                outf<<"\n";
            }	
            // else
            // {
            //     outf<<endl;
            // }						
		}
		if(found)
		{
			outf<<endl;
		}
		// found = false;
	}
}
int ascii(string wrd,int num)
{
	int sum=0;
	int len =wrd.size();
	for (int i = 0; i < len; i++)
	{
		sum = sum + int (wrd[i]);
	}
	sum = sum % num;
	// cout<<wrd[0]<<"  "<<sum<<"  "<< len<<endl;

	return sum;
}

int main(int argc, char **argv )
{
	ifstream fin1(argv[1]);
	int num = atoi(argv[2]);
	ifstream fin2(argv[3]);
	// ofstream outf("anagrams.txt");
	string took1[100000];
	int val1[100000];
	string took2[10000];
	int val2[10000];
	int E1 = 0, E2 = 0;
	string wrd;
	while(fin1>>wrd)
	{
		took1[E1]= wrd;
		val1[E1]=ascii(wrd,num);
		E1++;
	}
	while(fin2>>wrd)
	{
		took2[E2]= wrd;
		val2[E2]=ascii(wrd,num);
		// cout<<val2[E2]<<"\n";
		E2++;
	}

	hashing(took1,took2,val1,val2,E1,E2);

	// char o='t' ,n='w',e='o';
	// int asc = int (o) + int (n) +int (e);
	// cout<<"\n\n\n"<<asc;
}