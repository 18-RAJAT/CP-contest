#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e7+5,M=20;
int dp[N][20],arr[N];
vector<int>adj[N];
int dfs(int node,int state,int parent)
{
    int& res=dp[node][state];
    if(~res)return res;
    res=(state+1)*arr[node];
    for(auto& it:adj[node])
    {
        if(it==parent)continue;
        vector<int>temp(2,1e18);
        for(int i=0;i<2;++i)
        {
            if(state!=i)
            {
                temp[i]=dfs(it,i,node);
            }
        }
        res+=*min_element(temp.begin(),temp.end());
    }
    return res;
}
void sol()
{
    int n;
    cin>>n;
    vector<int>arr(n+1);
    vector<vector<int>>adj(n+1),dp(n+1,vector<int>(2,-1));
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        cin>>arr[i];
        ans+=arr[i];
    }
    for(int i=0;i<n-1;++i)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int>temp(2,1e18);
    for(int i=0;i<2;++i)
    {
        temp[i]=dfs(1,i,-1);
    }
    cout<<*min_element(temp.begin(),temp.end())<<endl;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
    return 0;
}