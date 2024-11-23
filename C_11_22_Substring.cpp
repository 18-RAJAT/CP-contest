#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    string s;
    cin>>n>>s;
    vector<int>pref(n,0);
    pref[0]=(s[0]=='1')?1:0;
    for(int i=1;i<n;++i)
    {
        if(s[i]=='1')pref[i]=pref[i-1]+1;
        else pref[i]=0;
    }
    vector<int>suf(n,0);
    suf[n-1]=(s[n-1]=='2')?1:0;
    for(int i=n-2;~i;--i)
    {
        if(s[i]=='2')suf[i]=suf[i+1]+1;
        else suf[i]=0;
    }
    int ans=0;
    for(int i=0;i<n;++i)
    {
        if(s[i]=='/')
        {
            int l=(i>0)?pref[i-1]:0;
            int r=(i<n-1)?suf[i+1]:0;
            int k=min(l,r),cur=2*k+1;
            ans=max(ans,cur);
        }
    }
    cout<<ans;
}
signed main()
{
    sol();
    return 0;
}