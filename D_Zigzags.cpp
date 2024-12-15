#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i)cin>>a[i];
    int ans=0,count;
    map<int,int>mp;
    for(int i=0;i<n;++i)
    {
        mp.clear();
        count=0;
        for(int j=i+1;j<n;++j)mp[a[j]]++;
        for(int j=i-1;~j;--j)
        {
            if(a[i]==a[j])ans+=count;
            count+=mp[a[j]];
        }
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