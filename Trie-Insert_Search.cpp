using namespace std;
#include<bits/stdc++.h>
struct TrieNode{
    unordered_map <char,TrieNode*> mp;
    bool isendofword;
};
TrieNode* newnode(void)
{
    TrieNode* temp = new TrieNode;
    temp->isendofword = false;
    return temp;
}
void insert(TrieNode* root,string str)
{
    if(root==nullptr)
    root = newnode();
    TrieNode* temp = root;
    for(int i=0;i<str.size();i++)
    {
        if(temp->mp[str[i]]==nullptr)
        {
            temp->mp[str[i]]=newnode();
            
        }
        temp = temp->mp[str[i]];
    }
    temp -> isendofword = true;
}
void search(TrieNode* root, string str)
{
    TrieNode* temp = root;
    for(int i = 0;i<str.size();i++)
    {
        temp = temp->mp[str[i]];
        if(temp==nullptr)
        {
            cout<<"NOT Found"<<endl;
            return;
        }
    }
    if(temp->isendofword)
    {
        cout<<"Found"<<endl;
    }
    else
    {
        cout<<"Not found"<<endl;
    }
    
}
int main()
{
    TrieNode* root = newnode();
    insert(root,"hello");
    insert(root,"hello1");
    search(root,"hello");
    search(root,"hello2");
    return 0;
}
