#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>>Tree;
vector<int>Dp,Ndp,Pruning1,Pruning2,Traversed;
void Init(int n)
{
    Tree.assign(n+1,vector<int>());
    Dp.assign(n+1,0);
    Ndp.assign(n+1,0);
    Pruning1.assign(n+1,0);
    Pruning2.assign(n+1,0);
    Traversed.assign(n+1,0);
}
void dfs(int Edges)
{
    Traversed[Edges]=1;
    Ndp[Edges]=Dp[Edges];
    for(auto& it:Tree[Edges])
    {
        if(Traversed[it])
        {
            continue;
        }
        Dp[it]=Dp[Edges]+1;
        dfs(it);
        Ndp[Edges]=max(Ndp[Edges],Ndp[it]);
    }
}
int TreePruning(int n)
{
    int Left=0,Right=0;
    dfs(1);
    for(int i=1;i<=n;++i)
    {
        Pruning1[Dp[i]]++,Pruning2[Ndp[i]]++;
    }
    for(int i=1;i<=n;++i)
    {
        Right+=Pruning1[i];
    }
    int ans=INT_MAX;
    for(int i=1;i<=n;++i)
    {
        Right-=Pruning1[i];
        int Edge_Cut=Left+Right;
        ans=min(ans,Edge_Cut);
        Left+=Pruning2[i];
    }
    return ans;
}
void sol()
{
    int n;
    cin>>n;
    Init(n);
    for(int i=1;i<n;++i)
    {
        int Left,Right;
        cin>>Left>>Right;
        Tree[Left].push_back(Right);
        Tree[Right].push_back(Left);
    }
    cout<<TreePruning(n)<<endl;
}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
    return 0;
}