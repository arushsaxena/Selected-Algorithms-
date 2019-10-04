using namespace std;
#include<bits/stdc++.h>
struct tree
{
	int val;
	tree* left=NULL;
	tree* right=NULL;
};
tree* newnode(int data)
{
	tree* temp= new tree;
	temp->left=temp->right=NULL;
	temp->val=data;
	return temp;
}
tree* atobst(int arr[],int start,int end)
{
	if(start>end)
		return NULL;
	int mid=(start+end)/2;
	tree* root=newnode(arr[mid]);
	root->left=atobst(arr,start,mid-1);
	root->right=atobst(arr,mid+1,end);
	return root;
}
void preorder(tree* root)
{
	if(root==NULL)
		return;
	cout<<root->val<<endl;
	preorder(root->left);
	preorder(root->right);
}
int main()
{
	int arr[]={1,2,3,4,5,6,7,8};
	tree* root=atobst(arr,0,7);
	preorder(root);
}