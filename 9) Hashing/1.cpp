#include<iostream>
#include<string.h>
#include<fstream>
#include<algorithm>

using namespace std;

void hashing(string *took1,string *took2,int *val1,int *val2,int E1,int E2)
{
	int ch=0;
	bool found[E2]= {true};
	string wrd1[E1] = took1;
	string wrd2[E2] = took2;
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
		for (int j = 0; j < E1; j++)
		{
			if(val1[j]==val2[i])
			{
				// // found = false;
				// // cout<<val1[i]<<"  "<<val2[j]<<endl;
				// if(took1[j]==took2[i])
				// {
				// 	// found = true;
				// 	outf<<took2[i]<<"\n";
				// 	//cout<<took1[i]<<"\n";
				// 	break;
				// }
				// else
				// {
					int len1 = took1[j].size();
					int len2 = took2[i].size();
				
					// if(len1==len2)
					{
						string wrd1 = took1[j];
						string wrd2 = took2[i];
						sort(wrd1.begin(),wrd1.end());
						sort(wrd2.begin(),wrd2.end());

						if(wrd1 == wrd2)
						{
							found[i] = false;
							outf<<took2[i]<<"\n";
							break;
						}	
						else
						{
							found[i] = false;
							outf<<endl;
						}			
					}
					if(found[i])
					{
						found[i] = true;
						outf<<"\noo";
					}	
				// }
				// if(!// found)
				// 	{
				// 		outf<<endl;
				// 	}
			}
			// if(!// found)
			// 		{
			// 			outf<<endl;
			// 		}
		}
		// if(!// found)
		// {
		// 	outf<<endl;
		// }
		// // found = false;
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
	// sum = sum % num;
	// cout<<wrd[0]<<"  "<<sum<<"  "<< len<<endl;

	return sum;
}

int main(int argc, char **argv )
{
	ifstream fin1(argv[1]);
	int num = atoi(argv[2]);
	ifstream fin2(argv[3]);
	// ofstream outf("anagrams.txt");
	string took1[10000];
	int val1[10000];
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