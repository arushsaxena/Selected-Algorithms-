using namespace std;
#include<bits/stdc++.j>
int row,col;
bool found(char grid[row][col],string find,int rd,int cl)
{
	int dx[]={-1,-1,-1,0,0,1,1,1};
	int dy[]={-1,0,1,1,-1,-1,0,1};
	int size1=find.size();
	if(grid[rd][cl]!=find[0])
		return false;
	for(int dir=0;dir<8;dir++)
	{
		int k;
		int row1=rd+dx[dir];
		int col1=cl+dy[dir];
		for(k=1;k<size1;k++)
		{
			if(row1<0||row1>=row||col1<0||col1>=col)
				break;
			if(grid[row1][col1]!=pat[k])
				break;
			row1+=dx[dir];
			col1+=dy[dir];
		}
		if(k==size1)
			return true;

	}
	return false;

}
void search(char grid[row][col],string pat)
{
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(found(grid,pat,i,j))
			{
				cout<<"pattern found at"<<i<<" "<<j<<endl;
			}
		}
	}
}
void main()
{
	cin>>row>>col;
	char grid[row][col];
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			cin>>grid[i][j];
		}
	}
	string word;
	cin>>word;
	search(grid,word);
}