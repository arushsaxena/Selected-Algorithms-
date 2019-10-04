#include<bits/stdc++.h>
using namespace std;
int main()
{
	int days;
	cin>>days;
	int price[days];
	for(int i=0;i<days;i++)
	{
		cin>>price[i];
	}
	int k;
	cin>>k;
	int mat[k+1][days+1];
	for(int i=0;i<k+1;i++)
	{
		for(int j=0;j<days+1;j++)
		{
			if(i==0||j==0)
				mat[i][j]=0;
		}
	}
	for(int i=1;i<k+1;i++)
	{
		for(int j=1;j<days+1;j++)
		{
			int max1=INT_MIN;
			for(int m=0;m<j;m++)
			{
				max1=max(price[j]-price[m]+mat[i-1][m],max1);
			}
			mat[i][j]=max(mat[i][j-1],max1);
		}
	}
	cout<<mat[k][days-1]<<endl;
}