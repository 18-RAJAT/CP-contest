#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<pair<int,int>>>adj(n+1);
    vector<int>w;
    for(int i=0;i<m;++i)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].emplace_back(v,wt);
        adj[v].emplace_back(u,wt);
        w.push_back(wt);
    }
    sort(w.begin(),w.end());
    vector<int>arr={w[0]};
    for(int i=1;i<w.size();++i)
    {
        if(w[i]!=arr.back())arr.push_back(w[i]);
    }
    int p=arr.size();
    vector<int>l(q,0),h(q,p-1),ans(q,arr[p-1]);
    vector<int>a(q),b(q),k(q);
    for(int i=0;i<q;++i)cin>>a[i]>>b[i]>>k[i];
    while(1)
    {
        vector<vector<int>>Q(p);
        int ok=0;
        for(int i=0;i<q;++i)
        {
            if(l[i]<h[i])
            {
                ok=1;
                int half=(l[i]+h[i])/2;
                Q[half].push_back(i);
            }
        }
        if(!ok)break;
        for(int i=0;i<p;++i)
        {
            if(Q[i].empty())continue;
            unordered_map<int,vector<int>>mp;
            for(auto itr:Q[i])mp[a[itr]].push_back(itr);
            for(auto& g:mp)
            {
                int F=g.first;
                vector<int>S=g.second;
                int W=arr[i];
                vector<int>dst(n+1,INT_MAX);
                //Rajat joshi template
                deque<int>dq;
                dst[F]=0;
                dq.push_back(F);
                while(!dq.empty())
                {
                    int u=dq.front();
                    dq.pop_front();
                    for(auto& it:adj[u])
                    {
                        int v=it.first,wt=it.second;
                        int cost=(wt>W)?1:0;
                        if(dst[v]>dst[u]+cost)
                        {
                            dst[v]=dst[u]+cost;
                            if(cost==0)dq.push_front(v);
                            else dq.push_back(v);
                        }
                    }
                }
                for(auto& itr:S)
                {
                    if(dst[b[itr]]<=(k[itr]-1))
                    {
                        h[itr]=i;
                        ans[itr]=min<int>(ans[itr],arr[i]);
                    }
                    else l[itr]=i+1;
                }
            }
        }
    }
    for(int i=0;i<q;++i)cout<<ans[i]<<(i<q-1?' ':'\n');
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