#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int a[n],b[n];
    vector<int>v[n+1],v1[n+1];
    int ans[n]={0};
    int maxi=0;
    map<int,int>mp;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        mp[a[i]]++;
    }
    for(int i=0;i<n;++i)
    {
        cin>>b[i];
    }
    for(int i=0;i<n;++i)
    {
        v[a[i]].push_back(b[i]);
    }
    for(int j=1;j<=n;++j)
    {
        int l=j;
        sort(v[l].begin(),v[l].end());
        while(v[l].size()>0)
        {
            int x=v[l].back();
            if(v1[l].size()==0)
            {
                v1[l].push_back(x);
            }
            else
            {
                v1[l].push_back(v1[l].back()+x);
            }
            v[l].pop_back();
        }
    }
    for(int j=1;j<=n;++j)
    {
        int l=j;
        int x=v1[l].size();
        for(int k=0;k<v1[l].size();++k)
        {
            int z=(x%(k+1));
            int mm=x-z;
            if(z==0)
            {
                ans[k]+=v1[l][mm-1];
            }
            else
            {
                ans[k]+=(v1[l][mm-1]);
            }
        }
    }
    for(int i=0;i<n;++i)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
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