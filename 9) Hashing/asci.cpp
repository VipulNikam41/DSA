#include<iostream>
#include<string.h>
#include<fstream>
#include<algorithm>

using namespace std;

int ascii(string wrd,int num)
{
	int sum=0;
	int len =wrd.size();
	for (int i = 0; i < len; i++)
	{
		sum = sum + int (wrd[i]);
	}
	// sum = sum % num;
	// cout<<wrd[0]<<"  "<<sum<<"  "<< len<<endl;

	return sum;
}

int main()
{
	int num = 10;
	string wrd;
    int val = 0;
	cin>>wrd;
	val=ascii(wrd,num);
	cout<<val<<"\n";
}