#include<iostream>
using namespace std;
#include<bits/stdc++.h>
struct TrieNode
{
 map <char,TrieNode*> mp;
	bool isend;
};
TrieNode* newnode(void)
{
	TrieNode* temp =new TrieNode;
	temp->isend=false;
	return temp;
}
void insert(TrieNode*& temp,const string& str)
{
	if(temp==nullptr)
	temp=newnode();
	
	TrieNode* temp1=temp;
	for(int i=0;str[i]!='\0';i++)
	{
		char x=str[i];
		if(temp1->mp.find(x)==temp1->mp.end())
		{
			temp1->mp[x]=newnode();
		}
		temp1=temp1->mp[x];

	}
	temp1->isend=true;

}
void search(TrieNode* temp,const string& str)
{
    if(temp==nullptr)
    {
        cout<<"NO"<<endl;
        return;
    }
    TrieNode* temp1=temp;
    for(int i=0;str[i]!='\0';i++)
    {
        temp1=temp1->mp[str[i]];
        if(temp1==nullptr)
        {
            cout<<"NO"<<endl;
            
        }
       
    }
     if(temp1->isend)
        {
            cout<<"YES"<<endl;
            
        }
        else
        {
            cout<<"NO"<<endl;
            
        }
}
void delete (TrieNode* temp;const string& str)
{
    
}
int main()
{
	TrieNode* root=nullptr;
	insert(root,"hello");
	insert(root,"arush");
	search(root,"Hello2");

}