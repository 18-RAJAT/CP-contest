#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<int>a(n,0);
    for(int i=0;i<n;++i)a[i]=(s[i]=='1')?1:-1;
    vector<int>suf(n+2,0);
    suf[n]=a[n-1];
    for(int i=n-1;i>=1;--i)suf[i]=suf[i+1]+a[i-1];
    vector<int>dp;
    for(int i=1;i<n;++i)dp.push_back(suf[i+1]);
    sort(dp.begin(),dp.end(),[&](const int a,const int b)->bool
    {
        return a>b;
    });
    int sza=dp.size();
    vector<int>pref(sza+1,0);
    for(int i=0;i<sza;++i)pref[i+1]=pref[i]+dp[i];
    int ans=-1;
    for(int i=1;i<=n;++i)
    {
        int diff=0;
        if(i==1)diff=0;
        else
        {
            if(i-1<=(int)sza)diff=pref[i-1];
            else diff=pref[sza];
        }
        if(diff>=k)
        {
            ans=i;
            break;
        }
    }
    cout<<((ans==-1)?-1:ans)<<endl;
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