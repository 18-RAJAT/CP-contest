#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    map<int,int>mp;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        mp[x]++;
    }
    priority_queue<int>pq;
    for(auto& it:mp)
    {
        pq.push(it.second);
    }
    int card=0;
    while(!pq.empty())
    {
        int ele=pq.top();
        if(k<=card+ele)
        {
            card+=ele-1;
            pq.pop();
        }
        else
        {
            break;
        }
    }
    card=min(k-1,card);
    int ans=card;
    while(!pq.empty())
    {
        int ele=pq.top();
        pq.pop();
        ans+=ele;
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