#include <iostream>
using namespace std;
#include <bits/stdc++.h>
int main()
{
	int vert,edge;
	cin>>vert>>edge;
	int adjmat[vert][vert];
	for(int i=0;i<vert;i++)
	{
	    for(int j=0;j<vert;j++)
	    adjmat[i][j]=0;
	}
	for(int i=0;i<edge;i++)
	{
		int a,b,w;
		cin>>a>>b>>w;
		adjmat[a][b]=w;
	}
	 int dist[vert];
	for(int i=0;i<vert;i++) dist[i]=9999999;
	dist[0]=0;
//	int distnew[vert];
	
	for(int i=0;i<vert-1;i++)
	{
		for(int j=0;j<vert;j++)
		{
			for(int k=0;k<vert;k++)
			{
				if(adjmat[k][j]!=0 && dist[k]!=9999999)
				{
					dist[j]=min(dist[j],dist[k]+adjmat[k][j]);
				}
			}
			
		}
	}
	for(int m=0;m<vert;m++)
	{
	    cout<<dist[m]<<" ";
	}
	
}