#include <iostream>
#include<fstream>

using namespace std;

int k1=1;
int c[20000][10];


void swap(int &a,int &b)
{
	int temp;
	temp =a;
	a=b;
	b=temp;
}
int radix(int a[20000],int d,int cnt,int j)
{
	int i=0,b;
	b=pow(10,k1);
	k1++;
	for (int i = 0; i < cnt ; i++)
	{
		if(j>=1)
		{
			c[i][j]=a[i]%b-c[i][j-1];
			//cout<<"q"<<c[i][j]<<endl;
		}
		else
		{
			c[i][0]=a[i]%b;
			//cout<<"w"<<c[i][0]<<endl;
		}

	}
	// for (i = 0; i < cnt; i++)
	// {
	// 	for (int k = i+1; k < i; k++)
	// 	{
	// 		if(c[i][j]<c[k][j])
	// 		{
	// 			swap(a[i],a[k]);
	// 			swap(c[i][j],c[k][j]);
	// 		}
	// 	}
	// }
	for (int i = 0; i < cnt ; i++)
		cout<<"e"<<c[i][j]<<endl;
	if(d>1)
	{
		d=d-1;
		j++;
		radix(a,d,cnt,j);
	}		
}   

int main(int argc ,char **argv)
{
	int d =atoi(argv[2]);
	int a[20000],num,cnt;
	ifstream inf(argv[1]);
	fstream outf("rad.txt");
	while(inf>>num)
	{
		a[cnt]=num;
		cnt++;
	}
	radix(a,d,cnt,0);

	for (int i = 0; i < cnt; ++i)
	{
		outf<<a[i]<<endl;
	}
}