using namespace std;
#include<bits/stdc++.h>
void constructtree(vector <int> &vect1,vector <int> &segtree1 ,int low ,int high , int pos)
{
    if(low==high)
    {
        segtree1[pos]=vect1[low];
        return;
    }
    else
    {
        int mid=(low+high)/2;
        constructtree(vect1,segtree1,low,mid,2*pos+1);
        constructtree(vect1,segtree1,mid+1,high,2*pos+2);
        segtree1[pos]=min(segtree1[2*pos+1],segtree1[2*pos+2]);
    }
}
int rangeminquery(const vector <int> &vect1,vector <int> &segtree1,int qlow,int qhigh,int low,int high,int pos)
{
    if(qlow<=low&&qhigh>=high)
    {
        return segtree1[pos];
    }
    
    if(qlow>high||qhigh<low)
    {
        return 9999999;
            
    }
    int mid = (low+high)/2;
    return (min(rangeminquery(vect1,segtree1,qlow,qhigh,low,mid,2*pos+1),rangeminquery(vect1,segtree1,qlow,qhigh,mid+1,high,2*pos+2)));
    
}
int main()
{
    int n;
    cin>>n;
    vector <int> vect;
    vect.resize(n);
    vector <int> segtree;
    int k=1;
    while(k<n)
    {
        k=k*2;
    }
    segtree.resize(2*k-1);
    segtree.assign(2*k-1,INT_MAX);
    
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>vect[i];
    }
    constructtree(vect,segtree,0,n-1,0);
    cout<<endl;
    cout<<"enter number of queries"<<endl;
    int q;
    cin>>q;
    while(q--)
    {
        int qlow,qhigh;
        cin>>qlow>>qhigh;
        int ans= (rangeminquery(vect,segtree,qlow,qhigh,0,n-1,0));
        cout<<ans<<endl;
    }
    return 0;
}