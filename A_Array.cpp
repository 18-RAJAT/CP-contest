#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);;
    for(int i=0;i<a.size();++i)
    {
        cin>>a[i];
    }
    vector<int>p,q,r;
    vector<bool>vis(n,false);
    for(int i=0;i<n;++i)
    {
        if(p.empty())
        {
            if(a[i]>0)p.emplace_back(a[i]),vis[i]=true;
        }
        if(q.empty())
        {
            if(a[i]<0)q.emplace_back(a[i]),vis[i]=true;
        }
        if(r.empty())
        {
            if(a[i]==0)r.emplace_back(a[i]),vis[i]=true;
        }
    }
    if(p.empty())
    {
        for(int i=0;i<n;++i)
        {
            if(!vis[i]&&a[i]<0&&p.size()<2)
            {
                p.emplace_back(a[i]);
                vis[i]=true;
            }
        }
    }
    for(int i=0;i<n;++i)
    {
        if(!vis[i])r.emplace_back(a[i]);
    }
    cout<<1<<" ";
    cout<<q.front()<<endl;
    cout<<p.size();cout<<" ";
    for(auto &it:p)cout<<it<<" ";
    cout<<endl;
    cout<<n-1-(int)p.size();cout<<" ";
    for(auto &it:r)cout<<it<<" ";
}
signed main()
{
    sol();
    return 0;
}