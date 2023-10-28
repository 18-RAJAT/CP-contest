#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,c;
    cin>>n>>c;
    function<bool(int,int)>f=[&](int i,int j)->bool
    {
        return i*j*c?true:false;
    };
    //dfs
    vector<int>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vector<vector<int>>g(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            {
                continue;
            }
            if(f(a[i],a[j])>=a[i]+a[j])
            {
                g[i].push_back(j);
            }
        }
    }
    vector<bool>vis(n);
    function<void(int)>dfs=[&](int u)
    {
        vis[u]=true;
        for(auto v:g[u])
        {
            if(!vis[v])
            {
                dfs(v);
            }
        }
    };
    dfs(0);
    for(int i=0;i<n;i++)
    {
        if(!vis[i] || f(0,0))
        {
            cout<<"Yes"<<endl;
            return;
        }
    }
    cout<<"No"<<endl;
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