#include<bits/stdc++.h>
using namespace std;
#define int long long
int Spf[10000005];
void sieve()
{
    for(int i=0;i<10000005;++i)Spf[i]=i;
    for(int i=2;i<10000005;++i)
    {
        if(Spf[i]==i)
        {
            for(int j=i*i;j<10000005;j+=i)
            {
                if(Spf[j]==j)Spf[j]=i;
            }
        }
    }
    for(int i=2;i<10000005;++i)assert(Spf[i]<=i);
}
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i<n;++i)assert(a[i]>0 && a[i]<10000005);
    vector<pair<int,int>>ans(10000005,{-1,-1});
    for(int i=0;i<n;++i)
    {
        if(~ans[a[i]].first)continue;
        vector<int>arr;
        int temp=a[i];
        while(temp>1)
        {
            if(arr.empty() || arr.back()!=Spf[temp])
            {
                assert(Spf[temp]>0 && Spf[temp]<=temp);
                arr.push_back(Spf[temp]);
            }
            temp/=Spf[temp];
        }
        if(arr.size()==1)continue;
        ans[a[i]].first=arr[0],ans[a[i]].second=1;
        for(int j=1;j<arr.size();++j)
        {
            ans[a[i]].second*=arr[j];
        }
    }
    for(int i=0;i<n;++i)
    {
        cout<<ans[a[i]].first<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;++i)
    {
        cout<<ans[a[i]].second<<" ";
    }
    cout<<endl;
}
signed main()
{
    sieve();
    sol();
    return 0;
}