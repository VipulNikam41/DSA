
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;

int a[1000];

int parent(int num){
	return (num-1)/2;
}


void heapify(int* arr ,int i, int size){
	int largest = i;
	int left=2*i+1;
	int right=left+1;
	if(size > left && arr[left] > arr[largest]){
		largest = left;
	}
	if(size > right && arr[right] > arr[largest]){
		largest = right;
	}
	if(i!=largest){
		int temp  = arr[largest];
		arr[largest] = arr[i];
		arr[i] = temp;
		heapify(arr , largest , size);	
	}
}

void form(int size){
	for(int i=parent(size-1);i>=0;--i){
		heapify(a , i , size);
	}
}

void insert(int &size , int data){
	a[size] = data;
	size = size+1;
	form(size);
}

  


int main(int argc, char **argv)
{
	ifstream fp(argv[1]);
	int i=0,j=0,temp=0;
	int b[1000];
	string ch;
	int num,key;
	int top =0;
	ofstream outf("heap.txt");
	while(fp>>ch)
	{   
		if(ch=="insert")
		{
			fp>>num;
			insert(top  , num);
			outf<<num<<" inserted\n";
			  
		}
		else if(ch=="maximum")
		{

			if(top==0){
				outf<<endl;
			}
			else{
				outf<<a[0]<<endl;
			}
		}
		else if(ch=="extract-max")
		{
			if(top==0){
				outf<<endl;
				continue;
			}
			int t = a[0];
			a[0] = a[top-1];
			top = top-1;
			heapify(a , 0 , top);
			outf<<t<<endl;
		}
		else if(ch=="increase-key")
		{
				fp>>num>>key;
				if(a[num] > key){
					outf<<key<<" is less than the current key at "<<num<<endl;
				}
				else{
					a[num] = key;
					form(top);
					outf<<"Key at "<<num<<" changed to "<<key<<endl;
				}
		}
		else if(ch=="sort")
		{
			int sam=top;
			vector<int>ans;
	int* trial =new int[sam];
	for(int i=0;i<sam;i++){
		trial[i] = a[i];
	}
	while(sam > 0){
		ans.push_back(trial[0]);
		trial[0] = trial[sam-1];
		sam = sam-1;
		heapify(trial , 0 , sam);
	}
	for(int i=ans.size()-1;i>=0;--i){
		outf<<ans[i]<<" ";
	}	
			outf<<endl;
		}
	}
	return 0;
}