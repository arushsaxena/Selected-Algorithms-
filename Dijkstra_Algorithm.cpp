#include<bits/stdc++.h>
using namespace std;

vector<vector< pair<int,int>> > adj;
vector<int> dis;

int dijkstra(int src,int des)
{
	priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int>> > q;
	q.push({0,src});
	while(!q.empty())
	{
		auto cur = q.top();q.pop();
		for(auto x:adj[cur.second])
		{
			if(dis[x.second]> dis[cur.second]+x.first)
			{
				dis[x.second] = dis[cur.second]+x.first;
				q.push({dis[x.second],x.first});
			}
		}
	}
	return dis[des];
}

int main()
{
	int n;cin>>n;
	adj.resize(n);
	dis.resize(n);
	dis.assign(n,1000000007);
	int src,des;cin>>src>>des;
	dis[src] = 0;
	int e;cin>>e;
	for(int i=0;i<e;i++)
	{
		int s,d,w;cin>>s>>d>>w;
		adj[s].push_back({w,d});
		adj[d].push_back({w,s});
	}
	dijkstra(src,des);
	cout<<dis[des]<<endl;
	return 0;
}