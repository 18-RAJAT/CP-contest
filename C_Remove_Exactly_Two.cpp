#include<bits/stdc++.h>
using namespace std;
#define int long long
// map<pair<int,int>,int>mp;
map<array<int,2>,int>va;
void sol()
{
    int n;
    cin>>n;
    va.clear();
    // vector<pair<int,int>>deg(n+1,{0,0});
    vector<array<int,2>>deg(n+1);
    // vector<int>deg(n+1,0);
    // vector<vector<int>>adj(n+1);
    // for(int i=0;i<n-1;++i)
    for(int i=1;i<n;++i)
    {
        int u,v;
        cin>>u>>v;
        // deg[u]++,deg[v]++;
        // adj[u].push_back(v);
        // adj[v].push_back(u);
        // deg[u].first++,deg[v].second++;
        deg[u][0]++,deg[u][1]=v;
        deg[v][0]++,deg[v][1]=u;
        va[{u,v}]+=1,va[{v,u}]+=1;
    }
    // vector<pair<int,int>>vp;
    // vp.reserve(n);
    // for(int i=1;i<=n;++i)vp.push_back({deg[i],i});
    // sort(vp.rbegin(),vp.rend());
    // int k=min<int>(n,50);
    // vector<int>cand(k),idx(n+1,-1);
    // for(int i=0;i<k;++i)cand[i]=vp[i].second;
    // for(int i=0;i<k;++i)idx[cand[i]]=i;
    // vector<vector<int>>in(k,vector<int>(k,0));
    // for(int i=0;i<k;++i)
    // {
    //     int u=cand[i];
    //     for(auto & it:adj[u])
    //     {
    //         int j=idx[it];
    //         if(~j)in[i][j]=1;
    //     }
    // }
    sort(deg.begin()+1,deg.begin()+n+1);
    int ans=0;
    reverse(deg.begin()+1,deg.begin()+n+1);
    // for(int i=0;i<k;++i)
    // {
    //     for(int j=i+1;j<k;++j)
    //     {
    //         int u=cand[i],v=cand[j];
    //         int val=deg[u]+deg[v]-1-(in[i][j]?1:0);
    //         ans=max(ans,val);
    //     }
    // }
    int mn=min<int>(n,50);
    for(int i=1;i<=mn;++i)
    {
        for(int j=i+1;j<=n;++j)
        {
            int X=deg[i][1],Y=deg[j][1];
            if(va.find({X,Y})==va.end())
            {
                ans=max(ans,deg[i][0]+deg[j][0]-2);
            }
            // int val=deg[i][0]+deg[j][0]-1-va[{X,Y}];
            else
            {
                ans=max(ans,deg[i][0]+deg[j][0]-1);
            }
        }
    }
    cout<<ans<<endl;
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