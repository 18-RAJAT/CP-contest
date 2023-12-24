#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int l[n],r[n],c[n];
    for(int i=0;i<n;++i)
    {
        cin>>l[i];
    }
    for(int i=0;i<n;++i)
    {
        cin>>r[i];
    }
    for(int i=0;i<n;++i)
    {
        cin>>c[i];
    }
    sort(c,c+n,greater<int>());
    vector<pair<int,int>>event;
    for(int i=0;i<n;++i)
    {
        event.push_back({l[i],-1});
        event.push_back({r[i],1});
    }
    sort(event.begin(),event.end());
    vector<int>ans;
    stack<int>stk;
    for(auto& [it,itr]:event)
    {
        if(itr==-1)
        {
            // ans.push_back(it);
            stk.push(it);
        }
        else
        {
            int tp=stk.top();
            stk.pop();
            ans.push_back(it-tp);
        }
    }
    sort(ans.begin(),ans.end());
    int sum=0;
    for(int i=0;i<n;++i)
    {
        sum+=ans[i]*c[i];
    }
    cout<<sum<<"\n";
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