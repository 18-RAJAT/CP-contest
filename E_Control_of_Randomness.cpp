#include<bits/stdc++.h>
using namespace std;
#define int long long

const int INF=1e9,Mod=998244353;
void sol()
{
    int n,q;
    cin>>n>>q;
    vector<vector<int>>adj(n+1,vector<int>());
    for(int i=0;i<n-1;++i)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>par(n+1,0),cnt(n+1,0);
    queue<int>que;
    que.push(1);
    par[1]=-1;
    while(!que.empty())
    {
        int u=que.front();
        que.pop();
        for(auto& v:adj[u])
        {
            if(par[v]==0 && v!=1)
            {
                par[v]=u,cnt[u]++;
                que.push(v);
            }
        }
    }
    vector<int>arr;
    que.push(1);
    vector<int>visited(n+1,0);
    visited[1]=1;
    while(!que.empty())
    {
        int u=que.front();
        que.pop();
        arr.push_back(u);
        for(auto &v:adj[u])
        {
            if(!visited[v])
            {
                visited[v]=1;
                que.push(v);
            }
        }
    }
    vector<pair<int,int>>vp(q);
    int mx=0;
    for(int i=0;i<q;++i)cin>>vp[i].first>>vp[i].second,mx=max(mx,vp[i].second);
    mx=min(mx,n);
    vector<vector<int>>dp(n+1,vector<int>(mx+1,INF)),ndp(n+1,vector<int>(mx+1,INF));
    for(int k=0;k<=mx;++k)
    {
        dp[1][k]=0,ndp[1][k]=0;
    }
    for(auto& u:arr)
    {
        if(u==1)continue;
        for(int k=0;k<=mx;++k)
        {
            if(par[u]==-1)dp[u][k]=INF;
            else dp[u][k]=1+ndp[par[u]][k];
            
            int tmp1=INF;
            if(k>=1)tmp1=1+dp[par[u]][k-1];

            int tmp2=1+2*cnt[u]+dp[par[u]][k];
            // cout<<tmp1<<" "<<tmp2<<endl;
            (k>=1)?ndp[u][k]=min(tmp1,tmp2):ndp[u][k]=tmp2;
        }
    }
    // for(auto& u:arr)
    // {
    //     if(u==1)continue;
    //     for(int k=0;k<=mx;++k)
    //     {
    //         cout<<dp[u][k]<<" ";
    //     }
    //     cout<<endl;
    // }
    // assert(dp[n][mx]<INF);
    for(int i=0;i<q;++i)
    {
        int v=vp[i].first,p=vp[i].second;
        if(mx<p)p=min(p,mx);
        cout<<dp[v][p]%Mod<<endl;
    }
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