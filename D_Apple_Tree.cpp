#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+5;
vector<long long>adj[N];
long long a[N];
void sol()
{
    long long n;cin>>n;

    for(long long i=1;i<=n;++i)
    {
        adj[i].clear();
    }
    for(long long i=1;i<=n;++i)
    {
        a[i]=0;
    }
    for(long long i=1;i<=n-1;++i)
    {
        long long src,dest;cin>>src>>dest;
        adj[src].push_back(dest);
        adj[dest].push_back(src);
    }
    function<void(long long,long long)>dfs=[&](long long node,long long parent)->void
    {
        a[node]=0;
        long long leaf=1;
        // if(adj[node].size()==1 and node!=0)
        // {
        //     dp[node]++;
        // }
        for(const auto&child:adj[node])
        {
            if(child==parent)
            {
                continue;
            }
            leaf=0;
            dfs(child,node);
            a[node]+=a[child];

            // cout<<child<<" -> "<<node<<" "<<a[child]<<"\n";
        }
        a[node]+=leaf;
    };
    dfs(1,-1);

    long long q;cin>>q;
    while(q--)
    {
        long long src,dest;
        cin>>src>>dest;
        // src--;dest--;
        cout<<a[src]*a[dest]<<"\n";

        // cout<<a[src]<<" -> "<<a[dest]<<"\n";
    }
}
int main()
{
    long long t;cin>>t;
    while(t--)
    {
        sol();
    }
    return 0;
}