#include<iostream>
#include<cstring>
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
	for(int i=0;i<k;i++){
			//cout<<tr[i].cut<<tr[i].x<<tr[i].y<<x1<<y1<<endl;
			if(tr[i].cut==0 && (tr[i].x != x1 || tr[i].y != y1))
			{
				 x2 =abs(tr[i].x - x1);
				 y2 = abs(tr[i].y - y1);
				 z2 = x2 + y2;
				 //check = 1;
				// cout<<x2<<"  "<<y2<<" coming"<<z2<<endl;
				if(z2<=min){
					 out = i;
					 min = z2;
				}
			}
		}
		return out;
}
/*int check_up(int index,tree *tr,int k){
	int x2 = tree[index].x;
	int y2=tree[index].y;
	int h2= tree[index].h;
	int min = h2;
	int profit =0;
	for(int i=0;i<k;i++){
		if(tr[i].cut==0 && tr[i].x==x2){
			if(abs(tr[i].y-y2)<=min){
				min = tr[i].y -y2;
				i = index;
			}
		if(min<h){
			
		}
		}
	}
}*/
int cut_up(tree *tr,int index,int k){
	int min = 1000;
	int value =0;
	int dot =-1;
	for(int i =0;i<k;i++){
		if(tr[i].cut ==0 && tr[i].x == tr[index].x && tr[i].y>tr[index].y){
			if(tr[i].y<min){
				min= tr[i].y;
				dot =i;
				cout<<dot<<endl;
			}
		}
	}
	if(min-tr[index].y<tr[index].h || min ==1000){
		value = tr[index].h*tr[index].d*tr[index].p;
		if(tr[dot].h*tr[dot].d*tr[dot].c<tr[index].h*tr[index].d*tr[index].c && dot>0){
      		value = value+cut_up(tr,dot,k);
      	}
	}
	//cout<<value<<endl;
	return value;
}
int cut_down(tree *tr,int index,int k){
	int min = 1000;
	int value =0;
	int dot =-1;
	for(int i =0;i<k;i++){
		if(tr[i].cut ==0 && tr[i].x == tr[index].x && tr[i].y<tr[index].y){
			if(tr[i].y<min){
				min= tr[i].y;
				dot =i;
				cout<<dot<<endl;
			}
		}
	}
	if(abs(min-tr[index].y)<tr[index].h || min ==1000){
		value = tr[index].h*tr[index].d*tr[index].p;
		if(tr[dot].h*tr[dot].d*tr[dot].c<tr[index].h*tr[index].d*tr[index].c && dot>0){
      		value = value+cut_up(tr,dot,k);
      	}
	}
	//cout<<value<<endl;
	return value;
}
int cut_right(tree *tr,int index,int k){
	int min = 1000;
	int value =0;
	int dot =-1;
	for(int i =0;i<k;i++){
		if(tr[i].cut ==0 && tr[i].y == tr[index].y && tr[i].x>tr[index].x){
			if(tr[i].x<min){
				min= tr[i].x;
				dot =i;
				cout<<dot<<endl;
			}
		}
	}
	if(abs(min-tr[index].x)<tr[index].h || min ==1000){
		value = tr[index].h*tr[index].d*tr[index].p;
		if(tr[dot].h*tr[dot].d*tr[dot].c<tr[index].h*tr[index].d*tr[index].c && dot>0){
      		value = value+cut_up(tr,dot,k);
      	}
	}
	//cout<<value<<endl;
	return value;
}
/*55 10 5
2 3 4 5 2 2
2 6 3 1 1 3
2 7 2 2 2 4
5 5 10 3 1 5
4 3 5 5 2 6*/
int cut_left(tree *tr,int index,int k){
	int min = 1000;
	int value =0;
	int dot =-1;
	for(int i =0;i<k;i++){
		if(tr[i].cut ==0 && tr[i].y == tr[index].y && tr[i].x<tr[index].x){
			if(tr[i].x<min){
				min= tr[i].x;
				dot =i;
				cout<<dot<<endl;
			}
		}
	}
	if(abs(min-tr[index].x)<tr[index].h || min ==1000){
		value = tr[index].h*tr[index].d*tr[index].p;
		if(tr[dot].h*tr[dot].d*tr[dot].c<tr[index].h*tr[index].d*tr[index].c && dot>0){
      		value = value+cut_up(tr,dot,k);
      	}
	}
	//cout<<value<<endl;
	return value;
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
	int index;
	int u;
	int r;
	int l;
	int d;
	int cutup[k];
	int cutdown[k];
	int cutleft[k];
	int cutright[k];
	while(t>=0){
	int cu=0;
	int cr=0;
	int cl=0;
	int cd=0;
     index = nearest_tree(tr,x1,y1,min,k);
     if(index<0){
     	break;
     } 
    tr[index].cut =1;
     t=t-(abs(tr[index].x-x1)+abs(tr[index].y-y1));
     x1=tr[index].x;
     y1=tr[index].y;
     t=t-tr[index].d;
     //cu = cut_up(tr,index,k);
     //cd = cut_down(tr,index,k);
     //cr = cut_right(tr,index,k);
     cl = cut_left(tr,index,k);
     cout<<cl<<endl;
     
	}
}