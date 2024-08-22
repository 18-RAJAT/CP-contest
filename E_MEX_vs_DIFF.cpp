#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(auto& it:a)cin>>it;
    unordered_map<int,int>mp;
    for(auto& it:a)
    {
        mp[it]++;
    }
    int x=0,y=0;
    for(int i=1;i<=n;++i)
    {
        if(!mp.count(i-1))x++;
        if(k<x)break;
        y=i;
    }
    priority_queue<int,vector<int>,greater<int>>pq;
    for(auto& it:mp)
    {
        if(y<it.first)pq.push(it.second);
    }
    while(!pq.empty() && k>=1)
    {
        if(pq.top()<=k)
        {
            k-=pq.top();pq.pop();
        }
        else
        {
            break;
        }
    }
    cout<<pq.size()<<endl;
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