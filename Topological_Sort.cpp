using namespace std;
#include<bits/stdc++.h>
vector <vector <int> > vect;
vector <int> visited;
vector <int> ans;
int n;
void dfs(int k)
{
    visited[k]=1;
    for(int u:vect[k])
    {
        if(visited[u]==0)
        {
            dfs(u);
        }
    }
    ans.push_back(k);
}
void toposort()
{
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0)
        {
            dfs(i);
        }
    }
}
int main()
{
    int m;
    cin>>n>>m;
    vect.resize(n);
    ans.resize(n);
    ans.clear();
    visited.resize(n);
    visited.assign(n,0);
    
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        vect[a-1].push_back(b-1);
    }
    toposort();
    
    reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]+1<<" ";
    }
    cout<<endl;
    return 0;
}