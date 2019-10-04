using namespace std;
#include<bits/stdc++.h>
vector < vector <int> > adj;
vector <int> visited;
void dfs(int p)
{
	visited[p]=1;
	for(auto i=adj[p].begin();i!=adj[p].end();i++)
	{
		if(visited[*i]==0)
		{
			dfs(*i);
		}
	}
}
int main()
{
	int vert,edge;
	cin>>vert>>edge;
	adj.resize(vert);
	visited.resize(vert);
	visited.assign(vert,0);
	while(edge--)
	{
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int count=0;
	for(int i=0;i<vert;i++)
	{
		if(visited[i]==0)
		{
			dfs(i);
			count++;
		}
	}
	cout<<count<<endl;

}