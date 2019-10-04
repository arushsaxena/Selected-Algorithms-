#include<iostream>
using namespace std;
#include<bits/stdc++.h>
string ans(const string& str,const string& str1)
{
	int size1=str.size(),size2=str1.size();
	string ret="";
	for(int i=0;i<min(size1,size2);i++)
	{
		if(str[i]!=str1[i])
			break;
		ret+=str[i];
	}
	return ret;
}
int main()
{
	vector<string> vect;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string str;
		cin>>str;
		vect.push_back(str);
	}
	string res=vect[0];
	for(int i=1;i<n;i++)
	{
		res=ans(res,vect[i]);
	}
	cout<<res<<endl;
}