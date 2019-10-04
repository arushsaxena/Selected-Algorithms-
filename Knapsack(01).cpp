#include<iostream>
using namespace std;
int main()
{
	int total,weight;
	cin>>total>>weight;
	int wt[total];
	int value[total];
	for(int i=0;i<total;i++)
	{
		cin>>wt[i];
		
	}
	for(int i=0;i<total;i++)
	{
		cin>>value[i];
		
	}
	int mat[total+1][weight+1];
	for(int i=0;i<=total;i++)
	{
		for(int j=0;j<=weight;j++)
		{
			if(i==0||j==0)
				mat[i][j]=0;
		}
	}
	for(int i=1;i<=total;i++)
	{
		for(int j=1;j<=weight;j++)
		{
			
			if(wt[i-1]<=j)
				mat[i][j]=max(mat[i-1][j],mat[i-1][j-wt[i-1]]+value[i-1]);
			else
				mat[i][j]=mat[i-1][j];
			
		}
	}
	cout<<mat[total][weight]<<endl;
}