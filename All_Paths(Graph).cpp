using namespace std;
#include<bits/stdc++.h>
vector < vector <int> > adj;
vector <int> visited;
vector <int> path;
int index1=0;
void dfs(int src,int dest)
{
	visited[src]=1;
	path[index1]=src;
	index1++;
	if(src==dest)
	{
		for(int i=0;i<index1;i++)
		{
			cout<<path[i]<<" ";
		}
		cout<<endl;
	}
	else
	{
		for(auto i=adj[src].begin();i!=adj[src].end();i++)
		{
			if(visited[*i]==0)
			{
				dfs(*i,dest);
			}
		}
	}
	index1--;
	visited[src]=false;
}
int main()
{
	int vert,edge;
	cin>>vert>>edge;
	visited.resize(vert);
	visited.assign(vert,0);
	adj.resize(vert);
	path.resize(vert);
	while(edge--)
	{
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
	}
	int src,dest;
	cin>>src>>dest;
	dfs(src,dest);

}