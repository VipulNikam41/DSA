#include<iostream>
#include<fstream>

using namespace std;

int partition(int a[],int p,int r);

void merge(int* arr , int p , int q , int r)
{
	int l = (q-p+1);
	int rt = (r-q);
	int L[l];
	int R[rt];

	for(int i=0;i<l;i++)
	{
		L[i] = arr[p+i];
	}
	for(int i=0;i<rt;i++)
	{
		R[i] = arr[q+i+1];
	}

	int j=0,m=0,n=0;
	for(int i=p;i<r && m<l && n<rt;i++)
	{
		if(L[m] >= R[n])
		{
			arr[i] = R[n];
			n++;
		}
		else
		{
			arr[i] = L[m];
			m++;
		}
		j=i;
	}
	j++;
	while(n<rt)
	{
		arr[j] = R[n];
		n++;j++;
	}
	while(m<l)
	{
		arr[j] = L[m];
		m++;j++;
	}
	
}

void quicksort(int a[],int p,int r)
{
	if (p<r)
	{
		int q = partition(a,p,r);
		quicksort(a,p,q-1);
		quicksort(a,q+1,r);
	}
}

void mergesort(int *a,int p,int r)
{
	if (p<r)
	{
		int q = (p+r)/2;
		mergesort(a,p,q);
		mergesort(a,q+1,r);
		merge(a,p,q,r);
	}
}

int exchange(int &a1, int &a2)
{
	int temp;
	temp = a1;
	a1 = a2;
	a2 = temp;
}

int partition(int a[],int p,int r)
{
	int x,i,j;
	x = a[r];
	i=p;
	for(j=p;j<r;j++)
	{
		if(a[j]<=x)
		{
		
			exchange(a[i],a[j]);
				i++;
		}
	}
	exchange(a[i],a[r]);
	return(i);
}

int main(int argc ,char **argv )
{
	ifstream fp(argv[1]);
	int ch,am[100000],i=0,aq[100000];

	ofstream mrg("mergesort.txt");
	ofstream quk("quicksort.txt");

	while(fp>>ch)
	{
		am[i]=ch;
		aq[i]=ch;
		i++;
	}   	   	   	   

	mergesort(am , 0 , i-1);
	quicksort(aq , 0 , i-1);

	for(int jm=0;jm<i-1;jm++)
	{
		mrg<<am[jm]<<endl;
	}
	for(int jq=0;jq<i-1;jq++)
	{
		quk<<aq[jq]<<endl;	
	}

	mrg<<am[i-1];
	quk<<aq[i-1];
}
