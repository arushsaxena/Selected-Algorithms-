using namespace std;
#include<bits/stdc++.h>
int mat[5][5];
int row=5;
int column=5;
bool visited[5][5];

void dfs(int a,int b)
{
	static int row[] ={-1,-1,-1,0,0,1,1,1};
	static int col[] ={-1,0,1,-1,1,-1,0,1};
	visited[a][b]=true;
	for(int i=0;i<8;i++)
	{
		if((a+row[i]>=0)&&(a+row[i]<5)&&(b+col[i]>=0)&&(b+col[i]<5)&&mat[a+row[i]][b+col[i]])
		{
			if(!visited[a+row[i]][b+col[i]])
				dfs(a+row[i],b+col[i]);
		}
	}
}
int main()
{
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
		    visited[i][j]=false;
		}
	}
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
		    cin>>mat[i][j];
		}
	}
	int count=0;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(mat[i][j]==1&&visited[i][j]==0)
			{
				dfs(i,j);
				count++;
			}
		}
	}
	cout<<count<<endl;
}