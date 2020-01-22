#include<iostream>
#include<cstring>
using namespace std;
struct tree
{
	int x,y,h,d,c,p;
	int cut,cuth;
};
int nearest_tree(tree *tr,int x1, int y1,int min,int k)
{
	int x2,y2,z2,out;
	for(int i=0;i<k;i++)
	{
		if(tr[i].cut==0 && (tr[i].x != x1 || tr[i].y != y1))
		{
			x2 =abs(tr[i].x - x1);
			y2 = abs(tr[i].y - y1);
			z2 = x2 + y2;
			if(z2<=min)
			{
				 out = i;
				 min = z2;
			}
		}
	}
	return out;
}
int show(tree *tr,int x1, int y1,int k,int out,int t,int incr)
{
		int val1 = tr[out].x-x1;
		if(val1>=0){
			if(t>abs(val1)){
				for(int j=0;j<abs(val1);j++){
					cout<<"move right"<<endl;
					incr++;
				}
			}
			else{
				for(int j=0;j<t;j++){
					cout<<"move right"<<endl;
					incr++;
				}
			}	
		}
	    else{
	    	if(t>abs(val1)){
				for(int j=0;j<abs(val1);j++){
					cout<<"move left"<<endl;
					incr++;
				}
			}
			else{
				for(int j=0;j<t;j++){
					cout<<"move left"<<endl;
					incr++;
				}
			}	
	    }
	    int val2 = tr[out].y-y1;
		if(val2>=0){
			if(t>abs(val2)){
				for(int j=0;j<abs(val2);j++){
					cout<<"move up"<<endl;
					incr++;
				}
			}
			else{
				for(int j=0;j<t;j++){
					cout<<"move up"<<endl;
					incr++;
				}
			}	
		}
	    else{
	    	if(t>abs(val1)){
				for(int j=0;j<abs(val1);j++){
					cout<<"move down"<<endl;
					incr++;
				}
			}
			else{
				for(int j=0;j<t;j++){
					cout<<"move down"<<endl;
					incr++;
				}
			}	
	    }
}
int main()
{
	int t,n,k;	
	cin>>t;
	cin>>n;
	cin>>k;
	tree tr[k];
	//cout<<"tree details: "<<endl;
	for(int i=0;i<k;i++)
	{
		cin>>tr[i].x;
		cin>>tr[i].y;
		cin>>tr[i].h;
		cin>>tr[i].d;
		cin>>tr[i].c;
		cin>>tr[i].p;
		tr[i].cut = 0;
		tr[i].cuth = 0;
	}
	int x1,y1;
	x1 =0;
	y1 =0;
	int min = 5000;
	int index;
	int pro[4];
	int x3r,x3l,y3u,y3d;
	while(t>=0)
	{
	    index = nearest_tree(tr,x1,y1,min,k); 
	    tr[index].cut =1;
	    tr[index].cuth = 1;
	    t=t-(abs(tr[index].x-x1)+abs(tr[index].y-y1));
	    t=t-tr[index].d;
	    int max,yo;
	    //for(int i=0;i<k;i++)
		{
		    if(x3r<=(tr[index].x+tr[index].h))
		    {
	    		for(int j=0;j<k;j++)
		    	if(tr[j].x==x1)
		    	{
		    		tr[j].cuth =1;
		    		pro[0]=pro[0]+tr[j].h*tr[j].c*tr[j].p;
		    	}
		    }
		    if(x3l<=abs(tr[index].x-tr[index].h))
		    {
		    	for(int j=0;j<k;j++)
		    	if(tr[j].x==x1)
		    	{
			    	tr[j].cuth =1;
			    	pro[1]=pro[1]+tr[j].h*tr[j].c*tr[j].p;
			    }
		    }
		    if(y3u<=(tr[index].y+tr[index].h))
		    {
		    	for(int j=0;j<k;j++)
		    	if(tr[j].y==y1)
		    	{
			    	tr[j].cuth =1;
			    	pro[2]=pro[2]+tr[j].h*tr[j].c*tr[j].p;
			    }
		    }
		    if(y3d<=abs(tr[index].y-tr[index].h))
		    {
		    	for(int j=0;j<k;j++)
		    	if(tr[j].y==y1)
		    	{
			    	tr[j].cuth =1;
			    	pro[3]=pro[3]+tr[j].h*tr[j].c*tr[j].p;
			    }
		    }
		    for (int i = 0; i < 4; i++)
		    {
		   		if(pro[i]<max)
		   		{
		   			max=pro[i];
		   			yo=i;
		   		}
		    };
	 	}
			if(yo==0)
			{
				for(int j=0;j<k;j++)
					if(tr[j].x==x1)
						tr[j].cut =1;
			}
			else if(yo==1)
			{
				for(int j=0;j<k;j++)
					if(tr[j].x==x1)
						tr[j].cut =1;
			}
			else if(yo==2)
			{
				for(int j=0;j<k;j++)
					if(tr[j].y==y1)
						tr[j].cut =1;
			}
			else if(yo==3)
			{
				for(int j=0;j<k;j++)
					if(tr[j].y==y1)
						tr[j].cut =1;
			}
			int incr=0;
			show(tr,x1,y1,k,index,t,incr);
		x1=tr[index].x;
	    y1=tr[index].y;

	}
}