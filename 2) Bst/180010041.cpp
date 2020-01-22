#include<iostream> 
#include<fstream> 
#include<string.h>
#include<stdlib.h>
using namespace std;

struct node
{
	int data;
	node *left;
	node *right;
	node *parent;
};

ofstream outf("bst.txt");

void inorder(node *x)
{
	if(x!=NULL)
	{
		inorder(x->left);
		outf<<x->data<<" ";
		inorder(x->right);
	}
}

void preorder(node *x)
{
	if(x!=NULL)
	{
		outf<<x->data<<" ";
		preorder(x->left);
		preorder(x->right);
	}
}

void postorder(node *x)
{
	if(x!=NULL)
	{
		postorder(x->left);
		postorder(x->right);
		outf<<x->data<<" ";
	}
}

node* min(node *x)
{
	while(x->left!=NULL)
	{
		x=x->left;
	}
	return x;	
} 

node* max(node *x)
{
	while(x->right!=NULL)
	{
		x=x->right;
	}
	return x;	
} 

void minimum(node *x)
{
	while(x->left!=NULL)
	{
		x=x->left;
	}
	outf<<x->data<<"\n";
}

void maximum(node *x)
{
	while(x->right!=NULL)
	{
		x=x->right;
	}
	outf<<x->data<<"\n";
}

node* search(node *x,int k)
{
	if(x==NULL || k==x->data){
		return x;
	}
	if(k<x->data){
		return search(x->left,k);
	}
	else
		return search(x->right,k);
	
}

node *successor(node *n) 
{ 
    if( n->right != NULL ) 
        return min(n->right); 
  
    node *y = n->parent; 
  
    while ((y!= NULL)&&(y->right == n)) 
    { 
        n=y;
        y=y->parent; 
    } 
    return y; 
} 

node *predecessor(node *n) 
{ 
    if( n->left != NULL ) 
        return max(n->left); 
  
    node *y = n->parent; 
  
    while ((y!= NULL)&&(y->left == n)) 
    { 
        n=y;
        y=y->parent; 
    } 
    return y; 
} 

node* deleteNode(node* root, int key) 
{ 
	node *temp;
		if (root == NULL) return root; 
		if (key < root->data) 
			root->left = deleteNode(root->left, key);
		else if (key > root->data) 
			root->right = deleteNode(root->right, key);
		else
		{ 
			if (root->left == NULL) 
			{ 
				node *temp = root->right; 
				//free(root); 
				return temp; 
			} 
			else if (root->right == NULL) 
			{ 
				node *temp = root->left; 
				//free(root); 
				return temp; 
			} 
			temp = min(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right, temp->data); 
		} 
	return root; 
} 

int main(int argc, char **argv)
{
	ifstream fp(argv[1]);
	int i=0,t=0,top=0,cnt=0,tmp=0;
	node *root =NULL;
	node *temp=NULL;
	string ch;
	int num;
	while(fp>>ch)
	{   if(ch=="insert")
		{
			fp>>num;
			outf<<num<<" inserted\n";
			node *y = root;
			node *temp;
			node *x = new node;
			x->data = num;
			x->left = NULL;
			x->right = NULL;
			x->parent = NULL;
			if (y==NULL)
			{
				root = x;
			}
			else
			{
				while(y!=NULL)
				{
					temp = y;
					if((x->data)<(y->data))
					{
						y=y->left;
					}
					else y=y->right;
				}
				if (x->data < temp->data)
				{
					temp->left = x;
				}
				else temp->right = x;
				x->parent = temp;
			}

		}
		else if(ch=="inorder")
		{
			if(root==NULL){
				outf<<endl;
			}
			else{
				inorder(root);
				outf<<endl;
			}
		}
		else if(ch=="preorder")
		{
			if(root==NULL){
				outf<<endl;
			}
			else{
				preorder(root);
				outf<<endl;
			}
		}
		else if(ch=="postorder")
		{
			if(root==NULL){
				outf<<endl;
			}
			else{
				postorder(root);
				outf<<endl;
			}
		}
		else if(ch=="search")
		{
			fp>>num;
			temp=search(root,num);
			if(temp==NULL)
			{
				outf<<num<<" not found\n";
			}
			else
			{
				outf<<num<<" found\n";
			}
		}
		else if(ch=="minimum")
		{
			if(root==NULL){
				outf<<endl;
			}
			else{
				minimum(root);
			}
		}
		else if(ch=="maximum")
		{
			if(root==NULL){
				outf<<endl;
			}
			else{
				maximum(root);
			}
		}
		else if(ch=="successor")
		{
			fp>>num;
			temp = search(root,num);
			if(temp!=NULL){
				temp = successor(search(root,num));
				if(temp!=NULL) outf<<temp->data<<endl;
				else outf<<"Successor not found\n";
			}
			else outf<<num<<" does not exist\n";
		}
		else if(ch=="predecessor")
		{
			fp>>num;
			temp = search(root,num);
			if(temp!=NULL){
				temp = predecessor(search(root,num));
				if(temp!=NULL) outf<<temp->data<<endl;
				else outf<<"predecessor not found\n";
			}
			else outf<<num<<" does not exist\n";
		}
		else if(ch=="delete")
		{
			fp>>num;
			temp=search(root,num);
			if(temp==NULL)
			{
				outf<<num<<" does not exist\n";
			}
			else
			{
				deleteNode(root,num);
				outf<<num<<" deleted\n";
			}
		}
	}
	return 0;
}
