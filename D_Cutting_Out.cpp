#include <bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    map<int,int>mp;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        mp[a[i]]++;
    }
    priority_queue<pair<int,int>>pq;
    for(map<int,int>::iterator it=mp.begin();it!=mp.end();++it)
    {
        for(int i=1;i<=it->second;++i)
        {
            pq.push(make_pair(it->second/i,it->first));
        }
    }
    vector<pair<int,int>>sorted;
    while(k--)
    {
        sorted.push_back(pq.top());
        pq.pop();
    }
    sort(sorted.begin(),sorted.end(),[&](const pair<int,int>& a,const pair<int,int>& b)->bool
    {
        return a.second<b.second?true:false;
    });
    for(auto& it:sorted)
    {
        cout<<it.second<<" ";
    }
}
signed main() {
    sol();
    return 0;
}
