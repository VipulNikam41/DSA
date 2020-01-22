#include<iostream> 
#include<fstream> 
#include<string.h>
#include<stdlib.h>
using namespace std;

int main(int argc, char **argv)
{
	ifstream fp;
	int i=0,t=0,rng=0,top=0,i1=0,t1=0,rng1=0,top1=0,i2=0,t2=0,rng2=0,top2=0,cnt=0,tmp2=0;
	rng = atoi(argv[2]);
	rng1 = rng;
	int mr[rng],mr1[rng1],mr2[10000];
	fp.open(argv[1]);
	char ch,ch1,ch2;
	int num,num1,num2;
	ofstream outf;
	outf.open("stack.txt",std::ios_base::ate);
	while(fp>>ch){
		switch(ch)
		{
			
			case '+' : fp>>num;
				if(top<rng){
				mr[top]=num;
				top++;	
				outf<<"pushed "<<num<<endl;}
				else outf<<"overflow\n";
				break;
			case '-' :
				outf<<"popped ";
				outf<<mr[top-1]<<endl;
				top--;
				break;
			case '?' : fp>>num; 
				t=0;
				for(int s=0;s<top-1;s++){
				if(mr[s]==num){
					outf<<"found "<<num<<endl;
					t=1;
					break;
					}
				}
				if(t==0){
				outf<<"not found "<<num<<endl;
				}
				break;
			case '!' :
				for(int j=top-1;j>=0;j--){
				outf<<mr[j]<<" ";
		
				}
				outf<<"\n";
				break;
		}

	}
	ifstream fp1;
	fp1.open(argv[1]);
	ofstream outf1;
	outf1.open("queue.txt",std::ios_base::ate);
	while(fp1>>ch1){
		switch(ch1)
		{
			
			case '+' : fp1>>num1;
				if(top1<rng1){
				mr1[top1]=num1;
				top1++;	
				outf1<<"enqueued "<<num1<<endl;}
				else outf1<<"overflow\n";
				break;
			case '-' :
				outf1<<"dequeued "<<mr1[0]<<endl;
				for(int s1=0;s1<rng1;s1++){
				mr1[s1]=mr1[s1+1];
				}
				top1--;
				break;
			case '?' : fp1>>num1; 
				t1=0;
				for(int s1=0;s1<top1-1;s1++){
				if(mr1[s1]==num1){
				outf1<<"found "<<num1<<endl;
				t1=1;
				break;
				}
				}
				if(t1==0){
				outf1<<"not found "<<num1<<endl;
				}
				break;
			case '!' :
				for(int j1=0;j1<top1;j1++)
				{outf1<<mr1[j1]<<" ";
				}
				outf1<<"\n";
				break;
		}
	}
	ifstream fp2;
	fp2.open(argv[1]);
	ofstream outf2;
	outf2.open("dll.txt",std::ios_base::ate);
	while(fp2>>ch2){
		switch(ch2)
		{
			
			case '+' : fp2>>num2;
				rng2++;
				mr2[top2]=num2;
				top2++;	
				outf2<<"inserted "<<num2<<endl;
				break;
			case '-' : fp2>>num2; 
				tmp2=0;
				for(int p=top2;p>=0;p--){
				if(mr2[p]==num2){
					tmp2=1;
					cnt=p;
					break;
					}
				}
				if(tmp2==1){
					outf2<<"deleted ";
					outf2<<num2<<endl;
					//<<cnt;
					for(int index=cnt;index<top2;index++){
						mr2[index]=mr2[index+1];
					}
					top2--;
				}
				else{
					outf2<<"cannot delete ";
					outf2<<num2<<endl;
				}
				break;

			case '?' : fp2>>num2; 
				t2=0;
				for(int s2=0;s2<top2-1;s2++){
				if(mr2[s2]==num2)
					{
					outf2<<"found "<<num2<<endl;
					t2=1;
					break;
					}
				}
				if(t2==0){
				outf2<<"not found "<<num2<<endl;
				}
				break;
			case '!' :
				for(int j2=top2-1;j2>=0;j2--){
				outf2<<mr2[j2]<<" ";
		
				}
				outf2<<"\n";
				break;
		}
	}
	return 0;
	
}
