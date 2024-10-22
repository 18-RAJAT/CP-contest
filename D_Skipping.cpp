#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n),b(n);
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i<n;++i)
    {
        cin>>b[i];b[i]--;
    }
    vector<int>cost(n,1e18);
    cost[0]=0;
    priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>>pq;
    pq.push({0,0});
    while(!pq.empty())
    {
        array<int,2>t=pq.top();
        pq.pop();
        int dist=t[0],locate=t[1];
        if(cost[locate]<dist)continue;
        if(locate>0 && dist<cost[locate-1])
        {
            cost[locate-1]=dist;
            pq.push({cost[locate-1],locate-1});
        }
        if(locate<n-1 && dist+a[locate]<cost[b[locate]])
        {
            cost[b[locate]]=dist+a[locate];
            pq.push({cost[b[locate]],b[locate]});
        }
    }
    int ans=0,skip=0;
    for(int i=0;i<n;++i)
    {
        skip+=a[i];
        ans=max(ans,skip-cost[i]);
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