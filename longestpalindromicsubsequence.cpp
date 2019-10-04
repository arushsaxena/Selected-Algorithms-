using namespace std;
#include<bits/stdc++.h>
int main()
{
    string str;
    cin>>str;
    int size1=str.size();
    int size2=str.size();
    int mat[size1][size2];
    for(int i=0;i<size1;i++)
    {
        for(int j=0;j<size1;j++)
        {
            if(i==j)
            {
                mat[i][j]=1;
            }
        }
    }
    for(int w=2;w<=size1;w++)
    {
        for(int i=0;i<size1-w+1;i++)
        {
            int j=i+w-1;
            if(str[i]==str[j]&&w==2)
            {
                mat[i][j]=2;
            }
            else if(str[i]==str[j])
            {
                mat[i][j]=mat[i+1][j-1]+2;
            }
            else
            {
                mat[i][j]=max(mat[i][j-1],mat[i+1][j]);
            }
        }
    }
    cout<<mat[0][size1-1]<<endl;
    return 0;
}