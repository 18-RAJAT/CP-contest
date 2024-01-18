#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    vector<int>pref(n),suf(n);
    // pref.assign(n,0);
    // suf.assign(n,0);
    // for(int i=0;i<n-1;++i)
    // {
    //     pref[i+1]=(i==0)?1:(a[i]-a[i-1])<(a[i+1]-a[i])?pref[i]+(a[i+1]-a[i]):pref[i]+1;
        // cout<<pref[i+1]<<" ";
    // }
    // for(int i=n-1;~i;--i)
    // {
    //     suf[i-1]=(i==n-1)?1:(a[i]-a[i-1])<(a[i+1]-a[i])?suf[i]+1:suf[i]+(a[i]-a[i-1]);
        // cout<<suf[i-1]<<" ";
    // }
    for(int i=0;i<n-1;++i)
    {
        if(i==0)
        {
            pref[i+1]=1;
        }
        else
        {
            int left=a[i]-a[i-1],right=a[i+1]-a[i];
            (left<right)?pref[i+1]=pref[i]+right:pref[i+1]=pref[i]+1;
        }
    }
    for(int i=n-1;i>0;--i)
    {
        if(i==n-1)
        {
            suf[i-1]=1;
        }
        else
        {
            int left=a[i]-a[i-1],right=a[i+1]-a[i];
            (left<right)?suf[i-1]=suf[i]+1:suf[i-1]=suf[i]+left;
        }
    }
    int q;
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        if(l<=r)
        {
            cout<<pref[r]-pref[l]<<endl;
        }
        else
        {
            cout<<suf[r]-suf[l]<<endl;
        }
    }
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