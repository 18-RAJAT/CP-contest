#include<bits/stdc++.h>
using namespace std;
#define int long long

class Trie
{
    public:
    Trie* left;
    Trie* right;
    Trie():left(NULL),right(NULL){};
};

int left_shift(int x,int k)
{
    return x<<k;
}
int right_shift(int x,int k)
{
    return x>>k;
}
int xor_(int x,int y)
{
    return x^y;
}
void insert(Trie* root,int x)
{
    Trie* curr=root;
    for(int i=31;i>=0;--i)
    {
        int b=right_shift(x,i)&1;
        if(b==0)
        {
            if(!curr->left)
            {
                curr->left=new Trie();
            }
            curr=curr->left;
        }
        else
        {
            if(!curr->right)
            {
                curr->right=new Trie();
            }
            curr=curr->right;
        }
    }
}
int query(Trie* root,int x)
{
    Trie* curr=root;
    int ans=0;
    for(int i=31;i>=0;--i)
    {
        int b=right_shift(x,i)&1;
        if(b==0)
        {
            if(curr->right)
            {
                ans+=left_shift(1,i);
                curr=curr->right;
            }
            else
            {
                curr=curr->left;
            }
        }
        else
        {
            if(curr->left)
            {
                ans+=left_shift(1,i);
                curr=curr->left;
            }
            else
            {
                curr=curr->right;
            }
        }
    }
    return ans;
}
void sol()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    Trie* root=new Trie();
    int ans=0;
    int pre_xor=0;
    insert(root,pre_xor);
    // cout<<query(root,pre_xor)<<"\n";
    for(int i=0;i<n;++i)
    {
        pre_xor=xor_(pre_xor,a[i]);
        // cout<<"pre_xor: "<<pre_xor<<"\n";
        insert(root,pre_xor);
        ans=max(ans,query(root,pre_xor));
    }
    cout<<ans-1;
}
signed main()
{
    sol();
    return 0;
}