#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    int dp[n+1];
    memset(dp,0,sizeof(dp));
    int ndp[n+1];
    memset(ndp,0,sizeof(ndp));
    for(int i=1;i<=n;++i)
    {
        dp[a[i]]++;
    }
    vector<int>ans;
    for(int i=1;i<=n;++i)
    {
        if(dp[i]==0)
        {
            ans.push_back(i);
        }
    }
    while(1)
    {
        if(ans.empty())
        {
            break;
        }
        set<int>st;
        for(auto&it:ans)
        {
            ndp[it]=1;
            st.insert(a[it]);
        }
        ans.clear();
        for(auto&it:st)
        {
            dp[it]=-1;
            int v=a[it];
            dp[v]--;
            if(dp[v]==0)
            {
                ans.push_back(v);
            }
        }
    }
    vector<int>ans2;
    for(int i=1;i<=n;++i)
    {
        if(dp[i]>0)
        {
            ans2.push_back(i);
        }
    }
    vector<int>ind;
    for(int i=1;i<=n;++i)
    {
        if(dp[i]<0)
        {
            ind.push_back(i);
        }
    }
    int vis[n+1];
    memset(vis,0,sizeof(vis));
    for(auto&it:ind)
    {
        int j=it;
        vector<int>v;
        while(vis[j]==0)
        {
            vis[j]=1;
            v.push_back(j);
            j=a[j];
        }
        int l=v.size();
        if(is_sorted(a,a+n))
        {
            cout<<"-1\n";
        }
        else if(l%2==1)
        {
            cout<<l<<"\n";
            for(auto&it:ind)
            {
                cout<<it<<" "<<a[it]<<" "<<a[a[it]]-1<<"\n";
            }
            return;
        }
        else
        {
            cout<<"-1\n";
        }
        for(int i2=0;i2<l;i2+=2)
        {
            int j2=v[i2];
            ndp[j2]=1;
        }
    }
    vector<int>ans3;
    for(int i=1;i<=n;++i)
    {
        if(ndp[i]==1)
        {
            ans3.push_back(i);
        }
    }
    cout<<ans3.size()<<"\n";
    for(auto&it:ans3)
    {
        cout<<it<<" ";
    }
    cout<<"\n";
}

signed main()
{
    sol();
    return 0;
}