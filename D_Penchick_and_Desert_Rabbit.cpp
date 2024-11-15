#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int P[n];
    for(int i=0;i<n;++i)
    {
        cin>>P[i];
    }
    int a[n],b[n];
    map<int,int>mp;
    for(int i=0;i<n;++i)
    {
        a[i]=P[i];
        if(i==0)
        {
            continue;
        }
        a[i]=max(a[i],a[i-1]);
    }
    // for(int i=0;i<n;++i)
    // {
    //     b[i]=a[i];
    // }
    set<int>s;
    for(int i=0;i<n;++i)
    {
        if(i>0 && a[i]!=a[i-1])
        {
            s.clear();
        }
        s.insert(P[i]);
        mp[a[i]]=*s.begin();
    }
    //set
    for(int i=0;i<n;++i)
    {
        b[i]=mp[a[i]];
    }
    for(int i=n-2;~i;--i)
    {
        if(b[i+1]<a[i])
        {
            a[i]=a[i+1];
            b[i]=min(b[i],b[i+1]);
        }
    }
    for(int i=0;i<n;++i)
    {
        cout<<a[i]<<" ";
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