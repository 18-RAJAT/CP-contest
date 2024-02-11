#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>adj[100001];
int visited[100001];
void sol()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n-1;++i)
    {
        int source,destination,weight;
        cin>>source>>destination>>weight;
        if(weight==0)
        {
            adj[source].push_back(destination);
            adj[destination].push_back(source);
        }
    }
    int count=0,ans=0;
    function<int(int,int)>power=[&](int a,int b)->int
    {
        int result=1;
        while(b)
        {
            if(b&1)
            {
                result=(result*a)%1000000007;
            }
            a=(a*a)%1000000007;
            b>>=1;
        }
        return result;
    };
    function<void(int)>dfs=[&](int node)->void
    {
        visited[node]=1;
        count++;
        for(auto& child:adj[node])
        {
            if(visited[child]==0)
            {
                dfs(child);
            }
        }
    };
    for(int i=1;i<=n;++i)
    {
        if(visited[i]==0)
        {
            count=0;
            dfs(i);
            ans+=(power(count,m))%1000000007;
        }
    }
    cout<<(power(n,m)%1000000007-ans%1000000007+1000000007)%1000000007<<endl;
}
signed main()
{
    sol();
    return 0;
}