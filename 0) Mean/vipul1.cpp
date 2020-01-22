#include<iostream>
#include<fstream>
#include<iomanip>

//#include<bits/stdc++.h>
using namespace std;

int main(int argc, char **argv)
{
	ifstream fp;
	fp.open(argv[1]);
	int tot=0,num=0,max=0,min,temp;
	float avg;	
	while(fp>>temp)
	{
		tot+=temp;
		num++;
		if(temp>max) max=temp;
		if(num==1)
		{min=temp;}
		else if(temp<min) min=temp;
	}
	avg=float(tot)/float(num);
	ofstream outf;
	outf.open("output.txt");
	outf<<num<<endl<<min<<endl<<max<<endl<<tot;
	outf<<endl<<setprecision (2) << fixed<<avg;
	return 0;
}
