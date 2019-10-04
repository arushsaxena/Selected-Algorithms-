using namespace std;
#include<bits/stdc++.h>
struct tree
{
	int data;
	tree* left=NULL;
	tree* right=NULL;
};
tree* newnode(int val)
{
	tree* temp=new tree;
	temp->data=val;
	temp->left=temp->right=NULL;
	return temp;
}
tree* insert(tree* root,int val)
{
	if(root==NULL)
		return newnode(val);
	if(val>root->data)
	{
		root->right=insert(root->right,val);
	}
	else if(val<root->data)
	{
		root->left=insert(root->left,val);
	}
}
void inorder(tree* root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->data<<endl;
	inorder(root->right);
}
tree* search(tree* root,int x)
{
    if(root->data==x||root==NULL)
    {
        return root;
    }
    if(x>root->data)
    {
        search(root->right,x);
    }
    else
    {
        search(root->left,x);
    }
}
/*tree* successor(tree* root,int val)
{
	tree* temp=search(root,val);
	tree* succ=NULL;
	if(temp->right!=NULL)
	{
		while(temp->left!=NULL)
		{
			temp=temp->left;
		}
		cout<<temp->data;
	}
	else
	{
		
		while(root!=NULL)
		{
			if(root->data>temp->data)
			{
				succ=root;
				root=root->left;
			}
			else if(root->data<temp->data)
			{
				root=root->right;
			}
			else
				break;
		}
	}
	return succ;
}*/
tree* successor(tree* root,int val)
{
	tree* temp=search(val);
	if(temp->right!=NULL)
	{
		while(temp->left!=NULL)
			temp=temp->left;
		return temp;
	}
	else
	{
		tree* succ=root;
		while(root!=NULL)
		{
		if(root->data>val)
		{
			succ=root;
			root=root->left;
		}
		if(root->data<val)
		{
			root=root->right;
		}
		else
		{
			break;
		}
		}
	}
	return succ;
	
}
int main()
{
	tree* root=NULL;
	root=insert(root,20);
	insert(root,8);
	insert(root,22);
	insert(root,4);
	insert(root,12);
	insert(root,10);
	insert(root,14);
	inorder(root);
/*	tree* find=search(root,25);
	if(find==NULL)
	cout<<"not found"<<endl;*/
	tree* succc =successor(root,14);
	cout<<succc->data<<"hello"<<endl;
	return 0;
}