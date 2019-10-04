#include <iostream>
using namespace std;
#include<bits/stdc++.h>
int main()
{
	int vert,edge;
	cin>>vert>>edge;
	vector <int> vect[vert];
	for(int i=0;i<edge;i++)
	{
		int a,b;
		cin>>a>>b;
		vect[a].push_back(b);
	
	}
	queue <int> q;
	vector <int> visited(vert,0);
	q.push(2);
	visited[2]=1;
	while(!q.empty())
	{
	    int s=q.front();
	    cout<<s<<endl;
	    q.pop();
	    
	    for(auto i=vect[s].begin();i<vect[s].end();i++)
	    {
	        if(visited[*i]==0)
	        {
	        q.push(*i);
	        visited[*i]=1;
	        }
	    }
	}
	return 0;
}