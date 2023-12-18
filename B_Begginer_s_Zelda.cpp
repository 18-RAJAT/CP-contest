#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int degree[n];
    memset(degree,0,sizeof(degree));
    for(int i=1;i<n;++i)
    {
        int u,v;
        cin>>u>>v;
        u--,v--;
        degree[u]++;
        degree[v]++;
    }
    int ans=0;
    for(auto &deg:degree)
    {
        if(deg==1)
        {
            ans++;
        }
    }
    cout<<(ans+1)/2<<endl;
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