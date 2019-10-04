#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int main()
{
	int vert,edge;
	cin>>vert>>edge;
	stack <int> s;
	vector <int> vect[vert];
	vector <int> visited(vert,0);
	for(int i=0;i<edge;i++)
	{
		int a,b;
		cin>>a>>b;
		vect[a].push_back(b);
		vect[b].push_back(a);
	}
	s.push(0);
	while(!s.empty())
	{
		int p=s.top();
		s.pop();
		if(visited[p]==0)
		{
			cout<<p<<endl;
			visited[p]=1;
		}
		for(auto i=vect[p].begin();i!=vect[p].end();i++)
		{
			if(visited[*i]==0)
			{
				s.push(*i);
			}
		}

	}
	return 0;

}