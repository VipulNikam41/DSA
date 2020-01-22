#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
struct tree
{
	int x,y,h,d,c,p;
	int cut;
};
int nearest_tree(tree *tr,int x1, int y1,int min,int k)
{
	int x2,y2,z2,out;
	out =-1;
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
int pro_tree(tree *tr,int x1, int y1,int min,int k,int tem)
{
	int x2,y2,z2,out;
	out =-1;
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
int cut_up(tree *tr,int index,int k,int tem)
{
	int min = 1000;
	int value =0;
	int dot =-1;
	for(int i =0;i<k;i++)
	{
		if(tr[i].cut ==0 && tr[i].x == tr[index].x && tr[i].y>tr[index].y)
		{
			if(tr[i].y<min)
			{
				min= tr[i].y;
				dot =i;
			}
		}
	}
	value = tr[index].h*tr[index].d*tr[index].p;
	if(min-tr[index].y<tr[index].h || min ==1000)
	{
		if(tr[dot].h*tr[dot].d*tr[dot].c<tr[index].h*tr[index].d*tr[index].c && dot>0)
		{
      		value = value+cut_up(tr,dot,k,tem);
      	}
	}
	return value;
}
void assign_up_cut(tree *tr,int index,int k)
{
  	int min = 1000;
	int value =0;
	int dot =-1;
	for(int i =0;i<k;i++)
	{
		if(tr[i].cut ==0 && tr[i].x == tr[index].x && tr[i].y>tr[index].y)
		{
			if(tr[i].y<min)
			{
				min= tr[i].y;
				dot =i;
			}
		}
	}
	tr[index].cut =1;
	if(min-tr[index].y<tr[index].h || min ==1000)
	{
		if(tr[dot].h*tr[dot].d*tr[dot].c<tr[index].h*tr[index].d*tr[index].c && dot>0)
		{
      		assign_up_cut(tr,dot,k);
      	}
	}
}
int cut_down(tree *tr,int index,int k,int tem)
{
	int min = 1000;
	int value =0;
	int dot =-1;
	for(int i =0;i<k;i++)
	{
		if(tr[i].cut ==0 && tr[i].x == tr[index].x && tr[i].y<tr[index].y)
		{
			if(tr[i].y<min)
			{
				min= tr[i].y;
				dot =i;
			}
		}
	}
	value = tr[index].h*tr[index].d*tr[index].p;
	if(abs(min-tr[index].y)<tr[index].h || min ==1000)
	{
		
		if(tr[dot].h*tr[dot].d*tr[dot].c<tr[index].h*tr[index].d*tr[index].c && dot>0)
		{
      		value = value+cut_down(tr,dot,k,tem);
      	}
	}
	return value;
}
void assign_down_cut(tree *tr,int index,int k)
{
	int min = 1000;
	int value =0;
	int dot =-1;
	for(int i =0;i<k;i++)
	{
		if(tr[i].cut ==0 && tr[i].x == tr[index].x && tr[i].y<tr[index].y)
		{
			if(tr[i].y<min)
			{
				min= tr[i].y;
				dot =i;
			}
		}
	}
	tr[index].cut =1;
	if(abs(min-tr[index].y)<tr[index].h || min ==1000)
	{
		if(tr[dot].h*tr[dot].d*tr[dot].c<tr[index].h*tr[index].d*tr[index].c && dot>0){
      		assign_down_cut(tr,dot,k);
      	}
	}
}

int cut_right(tree *tr,int index,int k,int tem)
{
	int min = 1000;
	int value =0;
	int dot =-1;
	for(int i =0;i<k;i++)
	{
		if(tr[i].cut ==0 && tr[i].y == tr[index].y && tr[i].x>tr[index].x)
		{
			if(tr[i].x<min)
			{
				min= tr[i].x;
				dot =i;
			}
		}
	}
	value = tr[index].h*tr[index].d*tr[index].p;
	if(abs(min-tr[index].x)<tr[index].h || min ==1000)
	{
		if(tr[dot].h*tr[dot].d*tr[dot].c<tr[index].h*tr[index].d*tr[index].c && dot>0)
		{
      		value = value+cut_right(tr,dot,k,tem);
      	}
	}
	return value;
}
void assign_right_cut(tree *tr,int index,int k)
{
	int min = 1000;
	int value =0;
	int dot =-1;
	for(int i =0;i<k;i++)
	{
		if(tr[i].cut ==0 && tr[i].y == tr[index].y && tr[i].x>tr[index].x)
		{
			if(tr[i].x<min)
			{
				min= tr[i].x;
				dot =i;
			}
		}
	}
	tr[index].cut =1;
	if(abs(min-tr[index].x)<tr[index].h || min ==1000)
	{
		if(tr[dot].h*tr[dot].d*tr[dot].c<tr[index].h*tr[index].d*tr[index].c && dot>0)
		{
      		assign_right_cut(tr,dot,k);
      	}
	}
}
int cut_left(tree *tr,int index,int k,int tem)
{
	int min = 1000;
	int value =0;
	int dot =-1;
	for(int i =0;i<k;i++)
	{
		if(tr[i].cut ==0 && tr[i].y == tr[index].y && tr[i].x<tr[index].x)
		{
			if(tr[i].x<min)
			{
				min= tr[i].x;
				dot =i;
			}
		}
	}
	value = tr[index].h*tr[index].d*tr[index].p;
	if(abs(min-tr[index].x)<tr[index].h || min ==1000)
	{	
		if(tr[dot].h*tr[dot].d*tr[dot].c<tr[index].h*tr[index].d*tr[index].c && dot>0)
		{
      		value = value+cut_left(tr,dot,k,tem);
      	}
	}
	return value;
}
void assign_left_cut(tree *tr,int index,int k)
{
	int min = 1000;
	int value =0;
	int dot =-1;
	for(int i =0;i<k;i++){
		if(tr[i].cut ==0 && tr[i].y == tr[index].y && tr[i].x<tr[index].x){
			if(tr[i].x<min){
				min= tr[i].x;
				dot =i;
				//cout<<dot<<endl;
			}
		}
	}
	tr[index].cut=1;
	if(abs(min-tr[index].x)<tr[index].h || min ==1000){
		
		if(tr[dot].h*tr[dot].d*tr[dot].c<tr[index].h*tr[index].d*tr[index].c && dot>0){
      		assign_left_cut(tr,dot,k);
      	}
	}
}
int time_calaculator(tree *tr,int index,int x1,int y1)
{
	int dist = abs(tr[index].x-x1)+abs(tr[index].y-y1);
	int tm_cut = tr[index].d;
	int Total_time = dist + tm_cut;
	return Total_time;
}
int gain(vector<float> v)
{
	int max=0;
	int index;
	for(int i=0;i<v.size();i++)
	{
        if(v[i]>max)
        {
         	max=v[i];
         	index=i;
        }
	}
 	return index;	
}
int gain1(vector<int> v)
{
	int max=0;
	int index;
	for(int i=0;i<v.size();i++)
	{
        if(v[i]>max)
        {
         	max=v[i];
         	index=i;
        }
	}
 	return index;	
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
	}
	int x1,y1;
	x1 =0;
	y1 =0;
	int min = 5000;
	int index,tem;
	int u;
	int r;
	int l;
	int d;
	int cutup[k];
	int cutdown[k];
	int cutleft[k];
	int cutright[k];
	while(t>=0)
	{
		index=nearest_tree(tr,x1,y1,min,k);
		int x3=tr[index].x;
     	int y3=tr[index].y;
		tem = time_calaculator(tr,index,x3,y3);
	    //index = pro_tree(tr,x1,y1,min,k,tem);
	    if(index<0)
	    {
	     	break;
	    } 
    
     	int incr = 0;
		int val1 = tr[index].x-x1;
		if(val1>=0)
		{
			if(t>abs(val1))
			{
				for(int j=0;j<abs(val1);j++)
				{
					cout<<"move right"<<endl;
					incr++;
				}
			}
			else
			{
				for(int j=0;j<t;j++)
				{
					cout<<"move right"<<endl;
					incr++;
				}
			}	
		}
	    else
	    {
	    	if(t>abs(val1))
	    	{
				for(int j=0;j<abs(val1);j++)
				{
					cout<<"move left"<<endl;
					incr++;
				}
			}
			else
			{
				for(int j=0;j<t;j++)
				{
					cout<<"move left"<<endl;
					incr++;
				}
			}	
	    }
	    t=t-incr;
	    incr = 0;
	    int val2 = tr[index].y-y1;
		if(val2>=0)
		{
			if(t>abs(val2))
			{
				for(int j=0;j<abs(val2);j++)
				{
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
	    else
	    {
	    	if(t>abs(val2))
	    	{
				for(int j=0;j<abs(val2);j++)
				{
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
	 t=t-incr;
	 int check = abs(tr[index].x-x1)+abs(tr[index].y-y1);
	 x1=x3;
     y1=y3;
     vector<float> v;
    	float cu=float(cut_up(tr,index,k,tem))/tem;
		float cd=float(cut_down(tr,index,k,tem))/tem;
		float cr=float(cut_right(tr,index,k,tem))/tem;
		float cl=float(cut_left(tr,index,k,tem))/tem;
     v.push_back(cu);
     v.push_back(cd);
      v.push_back(cr);
      v.push_back(cl);
      int pf;
     pf = gain(v);

     cout<<"t:"<<tem<<"\n";
     cout<<"cu:"<<cut_up(tr,index,k,tem)<<"\n";
     cout<<"cd:"<<cut_down(tr,index,k,tem)<<"\n";
     cout<<"cr:"<<cut_right(tr,index,k,tem)<<"\n";
     cout<<"cl:"<<cut_down(tr,index,k,tem)<<"\n";
     for(int j=0;j<4;j++)
     	cout<<v[j]<<",";
     	cout<<endl;
     cout<<pf<<endl;
  
     if(t-tr[index].d>=0)
     {
	    switch(pf)
	    {
	     	case 0:
	     	  	cout<<"cut up"<<endl;
	     	  	assign_up_cut(tr,index,k);
	     	  	break;
	     	case 1:
		     	cout<<"cut down"<<endl;
		     	assign_down_cut(tr,index,k);
		     	break;
	     	case 2:
	     	   cout<<"cut right"<<endl;
	     	   assign_right_cut(tr,index,k);
	     	   break;
	     	case 3:
	     	  	cout<<"cut left"<<endl;
	     	   	assign_left_cut(tr,index,k);
	     	   	break;
	     }
	    // tr[index].cut =1;
	  }
     v.resize(0);
     //cout<<t<<endl;
     t=t-tr[index].d;
	}
}