#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,p;
    cin>>n>>p;
    int a[n];
    for(int i=0;i<n;++i)cin>>a[i];
    int l[n],r[n],cur=LLONG_MAX;
    //template of pref-suf
    for(int i=0;i<n;++i)
    {
        if(!a[i])cur=0,l[i]=0;
        else if(cur!=LLONG_MAX)cur=max(cur,a[i]),l[i]=cur;
        else l[i]=LLONG_MAX;
    }
    cur=LLONG_MAX;
    for(int i=n-1;~i;--i)
    {
        if(!a[i])cur=0,r[i]=0;
        else if(cur!=LLONG_MAX)cur=max(cur,a[i]),r[i]=cur;
        else r[i]=LLONG_MAX;
    }
    for(int i=0;i<n;++i)
    {
        if(!a[i])cout<<0<<" ";
        else
        {
            int x=l[i]!=LLONG_MAX && r[i]!=LLONG_MAX?min(l[i],r[i]):l[i]!=LLONG_MAX?l[i]:r[i];
            cout<<(x+p-1)/p<<" ";
        }
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