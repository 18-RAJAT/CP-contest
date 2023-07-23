#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;

int a[N],dp[N],ans[N];
vector<vector<pair<int,int>>>adj(N);
vector<pair<int,int>>vp;
int n;

int main()
{
    int t;cin>>t;
    while(t--)
    {
        vp.clear();
        function<void(int,int)>dfs=[&](int node,int parent)->void
        {
            dp[node]=1;
            for(auto& child:adj[node])
            {
                if(child.first==parent)
                {
                    continue;
                }
                dfs(child.first,node);
                dp[node]+=dp[child.first];
                vp.emplace_back((n-dp[child.first])*dp[child.first],child.second);
            }
            return;
        };
        cin>>n;
        for(int i=0;i<n-1;i+=1)
        {
            int src,dest;
            cin>>src>>dest;
            adj[src].emplace_back(dest,i);
            adj[dest].emplace_back(src,i);
        }

        dfs(1,-1);
        sort(vp.begin(),vp.end(),greater<pair<int,int>>());
        adj.clear();
        for(int i=0;i<vp.size();i+=1)
        {
            ans[vp[i].second]=i;
        }
        for(int i=0;i<n-1;i+=1)
        {
            cout<<ans[i]<<"\n";
        }
    }
}