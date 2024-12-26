#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>p(n);
    for(auto& it:p)cin>>it;
    vector<int>vis(n,0),cycle;
    for(int i=0;i<n;++i)
    {
        if(!vis[i])
        {
            int cnt=0,j=i;
            while(!vis[j])
            {
                vis[j]=1;
                j=p[j]-1,cnt++;
            }
            cycle.push_back(cnt);
        }
    }
    if(cycle.size()==1)
    {
        cout<<0<<endl;
        return;
    }
    priority_queue<int,vector<int>,greater<int>>pq;
    for(auto& it:cycle)pq.push(it);
    int ans=0;
    while(pq.size()>=2)
    {
        int a=pq.top();pq.pop();
        int b=pq.top();pq.pop();
        ans+=a+b;
        pq.push(a+b);
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