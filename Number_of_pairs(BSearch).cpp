using namespace std;
#include<bits/stdc++.h>
bool bsearch(int *p,int low ,int high ,int val)
{
    if(low>high)
    {
        return false;
    }
    else
    {
        int mid = (low+high)/2;
        if(p[mid]==val)
        {
            return true;
        }
        else if(p[mid]>val)
        {
            return bsearch(p,low,mid-1,val);
        }
        else
        return bsearch(p,mid+1,high,val);
    }
    
}
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int n,m;
       cin>>n>>m;
       int arr[n];
       for(int i=0;i<n;i++)
       {
           cin>>arr[i];
       }
       int count = 0;
       sort(arr,arr+n);
       for(int i=0;i<n-1;i++)
       {
           bool flag = bsearch(arr,i+1,n-1,m-arr[i]);
           if(flag==true)
           count++;
       }
       cout<<count<<endl;
   }
}