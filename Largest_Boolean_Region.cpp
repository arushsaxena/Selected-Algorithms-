using namespace std;
#include<bits/stdc++.h>
int dfs(int a,int b,int visited[],int row,int col,int mat[][col],int& ct)
{
	
	mat[a][b]=true;
	ct++;
	static int rd[]={-1,-1,-1,0,0,1,1,1}
	static int cd[]={-1,0,1,1,-1,0,1,-1};
	for(int i=0;i<8;i++)
	{
		if(a+rd[i]<=row&&a+rd[i]>=0&&b+cd[i]<=col&&b+cd[i]>=0)
		{
			if(visited[a+rd[i]][b+cd[i]]==false)
			{
				dfs(a+rd[i],b+cd[i],visited,row,col,mat,ct);
			}
		}
	}
	return ct;
}
int main()
{
	int row,col;
	int count=1;
	cin>>row>>col;
	int mat[row][col];
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			cin>>mat[i][j];
		}
	}
	bool visited[row][col];
	memset(0,visited,sizeof(visited));
	int ans=0;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(visited[i][j]==false&&mat[i][j]==1)
			{
				ans=max(ans,dfs(i,j,visited,row,col,mat,&count));
			}
		}
	}
	cout<<ans<<endl;
}